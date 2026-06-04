using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace TBH_Trainer;

internal static class StashItemSpawner
{
    // Resolved class offsets and constructors (TBH 1.00.09)
    private const int SaveManager_Awake = 0xA054C0;
    private const int ItemSaveData_ctor = 0x9499A0;
    private const int StashSaveData_ctor = 0x94DEF0;
    private const int LocalInventoryManager_kdd = 0x949D40;

    public static string ExportCatalog(GameMemory mem, string outputPath)
    {
        if (!mem.IsAttached || mem.GameAssemblyBase == IntPtr.Zero)
            return "Trainer not attached to process.";

        try
        {
            IntPtr gameAssemblyBase = mem.GameAssemblyBase;
            
            // Resolve LocalInventoryManager TypeInfo
            IntPtr limTypeInfoAddr = gameAssemblyBase + LocalInventoryManager_kdd + 0xF + 7 + 0x4EBCD82;
            IntPtr limTypeInfo = ReadIntPtr(mem, limTypeInfoAddr);
            if (limTypeInfo == IntPtr.Zero) return "Failed to resolve LocalInventoryManager TypeInfo.";

            IntPtr staticFields = ReadIntPtr(mem, limTypeInfo + 0xB8);
            if (staticFields == IntPtr.Zero) return "LocalInventoryManager static fields not found.";

            IntPtr lim = ReadIntPtr(mem, staticFields + 0); // bevg singleton instance
            if (lim == IntPtr.Zero) return "LocalInventoryManager instance is null. Please load into a save game first.";

            IntPtr dict = ReadIntPtr(mem, lim + 0x20); // bevh dictionary
            if (dict == IntPtr.Zero) return "LocalInventoryManager item dictionary is null.";

            IntPtr entriesArray = ReadIntPtr(mem, dict + 0x18);
            if (entriesArray == IntPtr.Zero) return "Dictionary entries array is null.";

            int capacity = mem.ReadInt32(entriesArray + 0x18);
            if (capacity <= 0 || capacity > 1000) return "Invalid dictionary capacity.";

            var items = new List<(int Key, int Grade, string Name)>();

            for (int i = 0; i < capacity; i++)
            {
                IntPtr entryAddr = entriesArray + 0x20 + (i * 0x18);
                IntPtr innerDict = ReadIntPtr(mem, entryAddr + 0x10);
                if (innerDict == IntPtr.Zero) continue;

                IntPtr innerEntries = ReadIntPtr(mem, innerDict + 0x18);
                if (innerEntries == IntPtr.Zero) continue;

                int innerCapacity = mem.ReadInt32(innerEntries + 0x18);
                for (int j = 0; j < innerCapacity; j++)
                {
                    IntPtr innerEntryAddr = innerEntries + 0x20 + (j * 0x18);
                    IntPtr itemInfo = ReadIntPtr(mem, innerEntryAddr + 0x10);
                    if (itemInfo == IntPtr.Zero) continue;

                    int itemKey = mem.ReadInt32(itemInfo + 0x30);
                    int grade = mem.ReadInt32(itemInfo + 0x38);
                    IntPtr nameStrPtr = ReadIntPtr(mem, itemInfo + 0x50);
                    string name = ReadManagedString(mem, nameStrPtr);

                    if (itemKey > 0 && !items.Exists(it => it.Key == itemKey))
                    {
                        items.Add((itemKey, grade, name));
                    }
                }
            }

            if (items.Count == 0) return "No items found in LocalInventoryManager database.";

            items.Sort((a, b) => a.Key.CompareTo(b.Key));

            var sb = new StringBuilder();
            sb.AppendLine("TASKBAR HERO - ITEM CATALOG");
            sb.AppendLine("===========================");
            sb.AppendLine("Format: [ItemKey] | [Grade] | [Name]");
            sb.AppendLine();
            foreach (var it in items)
            {
                string gradeName = GetGradeName(it.Grade);
                sb.AppendLine($"{it.Key,-8} | {gradeName,-12} | {it.Name}");
            }

            File.WriteAllText(outputPath, sb.ToString(), Encoding.UTF8);
            return $"Successfully exported {items.Count} items to '{Path.GetFileName(outputPath)}'.";
        }
        catch (Exception ex)
        {
            return $"Error: {ex.Message}";
        }
    }

    public static string ScanItems(GameMemory mem, out int count)
    {
        count = 0;
        if (!mem.IsAttached || mem.GameAssemblyBase == IntPtr.Zero)
            return "Trainer not attached to process.";

        try
        {
            IntPtr gameAssemblyBase = mem.GameAssemblyBase;
            
            // Resolve LocalInventoryManager TypeInfo
            IntPtr limTypeInfoAddr = gameAssemblyBase + LocalInventoryManager_kdd + 0xF + 7 + 0x4EBCD82;
            IntPtr limTypeInfo = ReadIntPtr(mem, limTypeInfoAddr);
            if (limTypeInfo == IntPtr.Zero) return "Failed to resolve LocalInventoryManager TypeInfo.";

            IntPtr staticFields = ReadIntPtr(mem, limTypeInfo + 0xB8);
            if (staticFields == IntPtr.Zero) return "LocalInventoryManager static fields not found.";

            IntPtr lim = ReadIntPtr(mem, staticFields + 0);
            if (lim == IntPtr.Zero) return "LocalInventoryManager instance is null. Please load into a save game first.";

            IntPtr dict = ReadIntPtr(mem, lim + 0x20); // bevh dictionary
            if (dict == IntPtr.Zero) return "LocalInventoryManager item dictionary is null.";

            IntPtr entriesArray = ReadIntPtr(mem, dict + 0x18);
            if (entriesArray == IntPtr.Zero) return "Dictionary entries array is null.";

            int capacity = mem.ReadInt32(entriesArray + 0x18);
            if (capacity <= 0 || capacity > 1000) return "Invalid dictionary capacity.";

            var items = new HashSet<int>();

            for (int i = 0; i < capacity; i++)
            {
                IntPtr entryAddr = entriesArray + 0x20 + (i * 0x18);
                IntPtr innerDict = ReadIntPtr(mem, entryAddr + 0x10);
                if (innerDict == IntPtr.Zero) continue;

                IntPtr innerEntries = ReadIntPtr(mem, innerDict + 0x18);
                if (innerEntries == IntPtr.Zero) continue;

                int innerCapacity = mem.ReadInt32(innerEntries + 0x18);
                for (int j = 0; j < innerCapacity; j++)
                {
                    IntPtr innerEntryAddr = innerEntries + 0x20 + (j * 0x18);
                    IntPtr itemInfo = ReadIntPtr(mem, innerEntryAddr + 0x10);
                    if (itemInfo == IntPtr.Zero) continue;

                    int itemKey = mem.ReadInt32(itemInfo + 0x30);
                    if (itemKey > 0)
                    {
                        items.Add(itemKey);
                    }
                }
            }

            count = items.Count;
            return $"Successfully scanned {count} unique items in game memory.";
        }
        catch (Exception ex)
        {
            return $"Error: {ex.Message}";
        }
    }

    private static string GetGradeName(int grade) => grade switch
    {
        0 => "Common",
        1 => "Uncommon",
        2 => "Rare",
        3 => "Epic",
        4 => "Legendary",
        5 => "Mythic",
        6 => "Ancient",
        7 => "Relic",
        8 => "Immortal",
        9 => "Cosmic",
        _ => $"Grade {grade}"
    };

    public static string SpawnItem(GameMemory mem, int itemKey, int targetGrade, int count)
    {
        if (!mem.IsAttached || mem.GameAssemblyBase == IntPtr.Zero)
            return "Trainer not attached to process.";

        if (count < 1) count = 1;

        try
        {
            IntPtr gameAssemblyBase = mem.GameAssemblyBase;

            // Resolve LocalInventoryManager to search grade override automatically
            // If user selected Cosmic but typed ItemKey for Legendary, we want to scan the catalog map for the Cosmic row!
            int finalItemKey = MatchGradeKey(mem, itemKey, targetGrade);

            // Resolve SaveManager TypeInfo
            IntPtr saveManagerTypeInfoAddr = gameAssemblyBase + SaveManager_Awake + 0x22 + 7 + 0x4E0B13F; // nn`1 TypeInfo
            IntPtr nnTypeInfo = ReadIntPtr(mem, saveManagerTypeInfoAddr);
            if (nnTypeInfo == IntPtr.Zero) return "Failed to resolve SaveManager (nn`1) TypeInfo.";

            IntPtr nnStaticFields = ReadIntPtr(mem, nnTypeInfo + 0xB8);
            if (nnStaticFields == IntPtr.Zero) return "SaveManager static fields not found.";

            IntPtr saveMgr = ReadIntPtr(mem, nnStaticFields + 0); // ys instance
            if (saveMgr == IntPtr.Zero) return "SaveManager instance is null. Please load a game save first.";

            IntPtr playerSave = ReadIntPtr(mem, saveMgr + 0x28); // PlayerSaveData (bfkm)
            if (playerSave == IntPtr.Zero) return "Active PlayerSaveData is null.";

            // Lists
            IntPtr stashList = ReadIntPtr(mem, playerSave + 0x60); // stashSaveDatas
            IntPtr itemList = ReadIntPtr(mem, playerSave + 0x80); // itemSaveDatas
            if (stashList == IntPtr.Zero || itemList == IntPtr.Zero) return "Save lists not loaded.";

            // Resolve ItemSaveData & StashSaveData TypeInfos from constructors
            IntPtr itemTypeInfo = ReadConstructorTypeInfo(mem, gameAssemblyBase + ItemSaveData_ctor);
            IntPtr stashTypeInfo = ReadConstructorTypeInfo(mem, gameAssemblyBase + StashSaveData_ctor);
            if (itemTypeInfo == IntPtr.Zero || stashTypeInfo == IntPtr.Zero) return "Failed to resolve item/stash TypeInfos.";

            // Find first unoccupied slot index in stash
            int occupiedCount = mem.ReadInt32(stashList + 0x18);
            var occupiedSlots = new HashSet<int>();
            IntPtr stashItemsArray = ReadIntPtr(mem, stashList + 0x10);
            if (stashItemsArray != IntPtr.Zero)
            {
                for (int i = 0; i < occupiedCount; i++)
                {
                    IntPtr stashSave = ReadIntPtr(mem, stashItemsArray + 0x20 + (i * 8));
                    if (stashSave != IntPtr.Zero)
                    {
                        int slotIdx = mem.ReadInt32(stashSave + 0x10); // Index
                        occupiedSlots.Add(slotIdx);
                    }
                }
            }

            int targetSlotIdx = 0;
            while (occupiedSlots.Contains(targetSlotIdx))
            {
                targetSlotIdx++;
            }

            // Create remote structures & append
            for (int c = 0; c < count; c++)
            {
                ulong uniqueId = GenerateUniqueId();

                // Allocate and write ItemSaveData
                IntPtr remoteItem = mem.AllocateNear(gameAssemblyBase, 0x50);
                if (remoteItem == IntPtr.Zero) return "Remote allocation failed.";

                mem.WriteInt64(remoteItem + 0x0, itemTypeInfo.ToInt64()); // Class TypeInfo pointer
                mem.WriteInt32(remoteItem + 0x10, finalItemKey); // ItemKey
                mem.WriteInt64(remoteItem + 0x18, (long)uniqueId); // UniqueId

                // Allocate and write StashSaveData
                IntPtr remoteStash = mem.AllocateNear(gameAssemblyBase, 0x30);
                if (remoteStash == IntPtr.Zero)
                {
                    mem.FreeRemote(remoteItem);
                    return "Remote allocation failed.";
                }

                mem.WriteInt64(remoteStash + 0x0, stashTypeInfo.ToInt64()); // Class TypeInfo pointer
                mem.WriteInt32(remoteStash + 0x10, targetSlotIdx + c); // Index
                mem.WriteInt64(remoteStash + 0x18, (long)uniqueId); // ItemUniqueId
                mem.WriteBytes(remoteStash + 0x20, new byte[] { 1 }); // IsUnLock = true

                // Append to C# / IL2CPP generic Lists
                AppendToList(mem, itemList, remoteItem, itemTypeInfo);
                AppendToList(mem, stashList, remoteStash, stashTypeInfo);
            }

            return $"Successfully spawned {count} item(s) in Stash slot(s) starting from slot index {targetSlotIdx + 1}!";
        }
        catch (Exception ex)
        {
            return $"Spawning failed: {ex.Message}";
        }
    }

    private static int MatchGradeKey(GameMemory mem, int itemKey, int targetGrade)
    {
        try
        {
            IntPtr gameAssemblyBase = mem.GameAssemblyBase;
            IntPtr limTypeInfoAddr = gameAssemblyBase + LocalInventoryManager_kdd + 0xF + 7 + 0x4EBCD82;
            IntPtr limTypeInfo = ReadIntPtr(mem, limTypeInfoAddr);
            if (limTypeInfo == IntPtr.Zero) return itemKey;

            IntPtr staticFields = ReadIntPtr(mem, limTypeInfo + 0xB8);
            if (staticFields == IntPtr.Zero) return itemKey;

            IntPtr lim = ReadIntPtr(mem, staticFields + 0);
            if (lim == IntPtr.Zero) return itemKey;

            IntPtr dict = ReadIntPtr(mem, lim + 0x20); // bevh
            if (dict == IntPtr.Zero) return itemKey;

            IntPtr entriesArray = ReadIntPtr(mem, dict + 0x18);
            if (entriesArray == IntPtr.Zero) return itemKey;

            int capacity = mem.ReadInt32(entriesArray + 0x18);

            // Find current name for typed key
            string? targetName = null;
            for (int i = 0; i < capacity; i++)
            {
                IntPtr entryAddr = entriesArray + 0x20 + (i * 0x18);
                IntPtr innerDict = ReadIntPtr(mem, entryAddr + 0x10);
                if (innerDict == IntPtr.Zero) continue;

                IntPtr innerEntries = ReadIntPtr(mem, innerDict + 0x18);
                if (innerEntries == IntPtr.Zero) continue;

                int innerCapacity = mem.ReadInt32(innerEntries + 0x18);
                for (int j = 0; j < innerCapacity; j++)
                {
                    IntPtr innerEntryAddr = innerEntries + 0x20 + (j * 0x18);
                    IntPtr itemInfo = ReadIntPtr(mem, innerEntryAddr + 0x10);
                    if (itemInfo == IntPtr.Zero) continue;

                    int key = mem.ReadInt32(itemInfo + 0x30);
                    if (key == itemKey)
                    {
                        IntPtr nameStrPtr = ReadIntPtr(mem, itemInfo + 0x50);
                        targetName = ReadManagedString(mem, nameStrPtr);
                        break;
                    }
                }
                if (targetName != null) break;
            }

            if (targetName == null) return itemKey; // Not found

            // Find key with same name but selected grade rarity
            for (int i = 0; i < capacity; i++)
            {
                IntPtr entryAddr = entriesArray + 0x20 + (i * 0x18);
                IntPtr innerDict = ReadIntPtr(mem, entryAddr + 0x10);
                if (innerDict == IntPtr.Zero) continue;

                IntPtr innerEntries = ReadIntPtr(mem, innerDict + 0x18);
                if (innerEntries == IntPtr.Zero) continue;

                int innerCapacity = mem.ReadInt32(innerEntries + 0x18);
                for (int j = 0; j < innerCapacity; j++)
                {
                    IntPtr innerEntryAddr = innerEntries + 0x20 + (j * 0x18);
                    IntPtr itemInfo = ReadIntPtr(mem, innerEntryAddr + 0x10);
                    if (itemInfo == IntPtr.Zero) continue;

                    IntPtr nameStrPtr = ReadIntPtr(mem, itemInfo + 0x50);
                    string name = ReadManagedString(mem, nameStrPtr);
                    if (name == targetName)
                    {
                        int grade = mem.ReadInt32(itemInfo + 0x38);
                        if (grade == targetGrade)
                        {
                            return mem.ReadInt32(itemInfo + 0x30); // Key match found!
                        }
                    }
                }
            }
        }
        catch {}
        return itemKey;
    }

    private static IntPtr ReadConstructorTypeInfo(GameMemory mem, IntPtr ctorAddr)
    {
        byte[] code = mem.ReadBytes(ctorAddr, 64);
        for (int i = 0; i < code.Length - 7; i++)
        {
            if (code[i] == 0x48 && code[i + 1] == 0x8D && code[i + 2] == 0x0D)
            {
                int ripOffset = BitConverter.ToInt32(code, i + 3);
                IntPtr ripBase = ctorAddr + i + 7;
                return ReadIntPtr(mem, ripBase + ripOffset);
            }
        }
        return IntPtr.Zero;
    }

    private static void AppendToList(GameMemory mem, IntPtr listPtr, IntPtr itemPtr, IntPtr klassTypeInfo)
    {
        IntPtr arrayPtr = ReadIntPtr(mem, listPtr + 0x10);
        int size = mem.ReadInt32(listPtr + 0x18);
        int version = mem.ReadInt32(listPtr + 0x1C);

        if (arrayPtr == IntPtr.Zero) return;

        int capacity = mem.ReadInt32(arrayPtr + 0x18);
        if (size >= capacity)
        {
            int newCapacity = capacity == 0 ? 4 : capacity * 2;
            IntPtr newArray = mem.AllocateNear(mem.GameAssemblyBase, 0x20 + (newCapacity * 8));
            
            IntPtr arrayKlass = ReadIntPtr(mem, arrayPtr + 0x0);
            mem.WriteInt64(newArray + 0x0, arrayKlass.ToInt64());
            mem.WriteInt32(newArray + 0x18, newCapacity);

            if (size > 0)
            {
                byte[] oldData = mem.ReadBytes(arrayPtr + 0x20, size * 8);
                mem.WriteBytes(newArray + 0x20, oldData);
            }

            mem.WriteInt64(listPtr + 0x10, newArray.ToInt64());
            arrayPtr = newArray;
        }

        mem.WriteInt64(arrayPtr + 0x20 + (size * 8), itemPtr.ToInt64());
        mem.WriteInt32(listPtr + 0x18, size + 1);
        mem.WriteInt32(listPtr + 0x1C, version + 1);
    }

    private static ulong GenerateUniqueId()
    {
        var buf = new byte[8];
        new Random().NextBytes(buf);
        return BitConverter.ToUInt64(buf, 0);
    }

    private static IntPtr ReadIntPtr(GameMemory mem, IntPtr address)
    {
        return new IntPtr(mem.ReadInt64(address));
    }

    private static string ReadManagedString(GameMemory mem, IntPtr stringAddr)
    {
        if (stringAddr == IntPtr.Zero) return string.Empty;
        int len = mem.ReadInt32(stringAddr + 0x10);
        if (len <= 0 || len > 1024) return string.Empty;
        byte[] bytes = mem.ReadBytes(stringAddr + 0x14, len * 2);
        return Encoding.Unicode.GetString(bytes);
    }
}
