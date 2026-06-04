using System;
using System.Collections.Generic;

namespace TBH_Trainer;

/// <summary>
/// External HP/ATK/Speed editing via static pointers.
/// Extended in 1.00.09 to resolve all active party heroes via StageManager and tc.bdxx,
/// allowing continuous locking of stats for multiple heroes across stages.
/// </summary>
internal sealed class HeroStats
{
    private readonly GameMemory _mem;
    public HeroStats(GameMemory mem) => _mem = mem;

    // Class tc static pointer offset (1.00.09)
    private const long TcStatic = 0x57BC700;

    // StageManager static base offset (1.00.09)
    private const long StageManagerStatic = 0x5AE4320;

    public struct HeroPointers
    {
        public IntPtr UgPtr;       // ug* wrapper
        public IntPtr HeroPtr;     // Hero* instance
        public IntPtr HealthCtrl;  // pf* UnitHealthController
        public IntPtr StatsDict1;  // beun* stats dictionary (at +0x18)
        public IntPtr StatsDict2;  // beuo* stats dictionary (at +0x20)
    }

    private IntPtr Resolve(long staticOffset, long[] offsets)
    {
        if (!_mem.IsAttached || _mem.GameAssemblyBase == IntPtr.Zero) return IntPtr.Zero;

        IntPtr addr = _mem.GameAssemblyBase + (int)staticOffset;
        foreach (long off in offsets)
        {
            long val = _mem.ReadInt64(addr);
            if (val == 0) return IntPtr.Zero; // chain broken (e.g. not in a run yet)
            addr = new IntPtr(val + off);
        }
        return addr;
    }



    // === Helper to read pointer fields ===
    private IntPtr ReadIntPtr(IntPtr address)
    {
        long val = _mem.ReadInt64(address);
        return new IntPtr(val);
    }

    // === Multi-Hero Pointer Resolution & Modification ===

    public List<HeroPointers> ResolveAllHeroes()
    {
        var list = new List<HeroPointers>();
        if (!_mem.IsAttached || _mem.GameAssemblyBase == IntPtr.Zero) return list;

        var uniqueUgs = new HashSet<IntPtr>();

        // 1. Try resolving from StageManager.HeroList (current active combat stage)
        IntPtr stageTypeInfo = ReadIntPtr(_mem.GameAssemblyBase + (int)StageManagerStatic);
        if (stageTypeInfo != IntPtr.Zero)
        {
            IntPtr staticFields = ReadIntPtr(stageTypeInfo + 0xB8);
            if (staticFields != IntPtr.Zero)
            {
                IntPtr stageMgr = ReadIntPtr(staticFields + 0x0); // bbwm
                if (stageMgr != IntPtr.Zero)
                {
                    IntPtr heroListOuter = ReadIntPtr(stageMgr + 0x30); // HeroList
                    if (heroListOuter != IntPtr.Zero)
                    {
                        int outerLen = _mem.ReadInt32(heroListOuter + 0x18);
                        if (outerLen > 0 && outerLen <= 100)
                        {
                            for (int i = 0; i < outerLen; i++)
                            {
                                IntPtr heroListInner = ReadIntPtr(heroListOuter + 0x20 + (i * 8));
                                if (heroListInner == IntPtr.Zero) continue;

                                int innerLen = _mem.ReadInt32(heroListInner + 0x18);
                                if (innerLen > 0 && innerLen <= 100)
                                {
                                    for (int j = 0; j < innerLen; j++)
                                    {
                                        IntPtr heroPtr = ReadIntPtr(heroListInner + 0x20 + (j * 8));
                                        if (heroPtr == IntPtr.Zero) continue;

                                        IntPtr ugPtr = ReadIntPtr(heroPtr + 0x03A0); // Hero.cache (ug*)
                                        if (ugPtr != IntPtr.Zero && uniqueUgs.Add(ugPtr))
                                        {
                                            list.Add(BuildHeroPointers(ugPtr, heroPtr));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // 2. Try resolving from tc.bdxx dictionary as supplemental / fallback
        IntPtr tcTypeInfo = ReadIntPtr(_mem.GameAssemblyBase + (int)TcStatic);
        if (tcTypeInfo != IntPtr.Zero)
        {
            IntPtr tcStatic = ReadIntPtr(tcTypeInfo + 0xB8);
            if (tcStatic != IntPtr.Zero)
            {
                // bdxx dictionary at +0x20
                IntPtr dict = ReadIntPtr(tcStatic + 0x20);
                if (dict != IntPtr.Zero)
                {
                    IntPtr entriesArray = ReadIntPtr(dict + 0x18);
                    if (entriesArray != IntPtr.Zero)
                    {
                        int capacity = _mem.ReadInt32(entriesArray + 0x18);
                        if (capacity > 0 && capacity <= 1000)
                        {
                            for (int i = 0; i < capacity; i++)
                            {
                                IntPtr entryAddr = entriesArray + 0x20 + (i * 0x18);
                                IntPtr ugPtr = ReadIntPtr(entryAddr + 0x10);
                                if (ugPtr != IntPtr.Zero && uniqueUgs.Add(ugPtr))
                                {
                                    IntPtr heroPtr = ReadIntPtr(ugPtr + 0x88); // ug.begc
                                    list.Add(BuildHeroPointers(ugPtr, heroPtr));
                                }
                            }
                        }
                    }
                }

                // Fallback to active lead hero bdyc at +0x40 if list is empty
                if (list.Count == 0)
                {
                    IntPtr leadUg = ReadIntPtr(tcStatic + 0x40);
                    if (leadUg != IntPtr.Zero && uniqueUgs.Add(leadUg))
                    {
                        IntPtr heroPtr = ReadIntPtr(leadUg + 0x88);
                        list.Add(BuildHeroPointers(leadUg, heroPtr));
                    }
                }
            }
        }

        return list;
    }

    private HeroPointers BuildHeroPointers(IntPtr ugPtr, IntPtr heroPtr)
    {
        IntPtr healthCtrl = IntPtr.Zero;
        IntPtr statsDict1 = IntPtr.Zero;
        IntPtr statsDict2 = IntPtr.Zero;

        if (heroPtr != IntPtr.Zero)
        {
            healthCtrl = ReadIntPtr(heroPtr + 0xB0); // Unit.UnitHealthController
        }

        if (ugPtr != IntPtr.Zero)
        {
            IntPtr xePtr = ReadIntPtr(ugPtr + 0x10); // up.<beib>k__BackingField
            if (xePtr != IntPtr.Zero)
            {
                statsDict1 = ReadIntPtr(xePtr + 0x18); // xe.beun
                statsDict2 = ReadIntPtr(xePtr + 0x20); // xe.beuo
            }
        }

        return new HeroPointers
        {
            UgPtr = ugPtr,
            HeroPtr = heroPtr,
            HealthCtrl = healthCtrl,
            StatsDict1 = statsDict1,
            StatsDict2 = statsDict2
        };
    }

    private IntPtr FindDictValuePtr(IntPtr dict, int targetKey)
    {
        if (dict == IntPtr.Zero) return IntPtr.Zero;

        IntPtr entriesArray = ReadIntPtr(dict + 0x18);
        if (entriesArray == IntPtr.Zero) return IntPtr.Zero;

        int capacity = _mem.ReadInt32(entriesArray + 0x18);
        if (capacity <= 0 || capacity > 1000) return IntPtr.Zero;

        for (int i = 0; i < capacity; i++)
        {
            IntPtr entryAddr = entriesArray + 0x20 + (i * 0x10);
            int key = _mem.ReadInt32(entryAddr + 0x8);
            if (key == targetKey)
            {
                return entryAddr + 0xC;
            }
        }
        return IntPtr.Zero;
    }

    public bool SetAllHeroesHp(float value)
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return false;

        bool success = false;
        foreach (var hero in heroes)
        {
            // 1. Write to stats dictionaries MaxHp (Key 5)
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 5);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(value));
                    success = true;
                }
            }
            if (hero.StatsDict2 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict2, 5);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(value));
                    success = true;
                }
            }

            // 2. Also write to UnitHealthController (pf*) if active in battle
            if (hero.HealthCtrl != IntPtr.Zero)
            {
                _mem.WriteBytes(hero.HealthCtrl + 0x38, BitConverter.GetBytes(value)); // CurrentHP
                _mem.WriteBytes(hero.HealthCtrl + 0x3C, BitConverter.GetBytes(value)); // MaxHP
                _mem.WriteBytes(hero.HealthCtrl + 0x40, BitConverter.GetBytes(value)); // bchs
                success = true;
            }
        }
        return success;
    }

    public bool SetAllHeroesAtk(float value)
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return false;

        bool success = false;
        foreach (var hero in heroes)
        {
            // Write to base stats dictionaries AttackDamage (Key 1)
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 1);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(value));
                    success = true;
                }
            }
            if (hero.StatsDict2 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict2, 1);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(value));
                    success = true;
                }
            }
        }
        return success;
    }

    public bool SetAllHeroesAtkSpeed(float value)
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return false;

        bool success = false;
        foreach (var hero in heroes)
        {
            // Write to base stats dictionaries AttackSpeed (Key 2)
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 2);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(value));
                    success = true;
                }
            }
            if (hero.StatsDict2 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict2, 2);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(value));
                    success = true;
                }
            }
        }
        return success;
    }

    public bool SetAllHeroesMoveSpeed(float value)
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return false;

        // Scale by 100 before writing (so displaying 20 in-game requires writing 0.20 to memory)
        float scaledValue = value / 100.0f;

        bool success = false;
        foreach (var hero in heroes)
        {
            // Write to base stats dictionaries MovementSpeed (Key 7)
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 7);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(scaledValue));
                    success = true;
                }
            }
            if (hero.StatsDict2 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict2, 7);
                if (valPtr != IntPtr.Zero)
                {
                    _mem.WriteBytes(valPtr, BitConverter.GetBytes(scaledValue));
                    success = true;
                }
            }
        }
        return success;
    }

    public float? GetAllHeroesHp()
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return null;
        foreach (var hero in heroes)
        {
            if (hero.HealthCtrl != IntPtr.Zero)
            {
                return _mem.ReadFloat(hero.HealthCtrl + 0x3C); // MaxHP
            }
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 5);
                if (valPtr != IntPtr.Zero) return _mem.ReadFloat(valPtr);
            }
        }
        return null;
    }

    public float? GetAllHeroesAtk()
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return null;
        foreach (var hero in heroes)
        {
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 1);
                if (valPtr != IntPtr.Zero) return _mem.ReadFloat(valPtr);
            }
        }
        return null;
    }

    public float? GetAllHeroesAtkSpeed()
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return null;
        foreach (var hero in heroes)
        {
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 2);
                if (valPtr != IntPtr.Zero) return _mem.ReadFloat(valPtr);
            }
        }
        return null;
    }

    public float? GetAllHeroesMoveSpeed()
    {
        var heroes = ResolveAllHeroes();
        if (heroes.Count == 0) return null;
        foreach (var hero in heroes)
        {
            if (hero.StatsDict1 != IntPtr.Zero)
            {
                IntPtr valPtr = FindDictValuePtr(hero.StatsDict1, 7);
                if (valPtr != IntPtr.Zero) return _mem.ReadFloat(valPtr) * 100.0f; // Scale back
            }
        }
        return null;
    }
}

