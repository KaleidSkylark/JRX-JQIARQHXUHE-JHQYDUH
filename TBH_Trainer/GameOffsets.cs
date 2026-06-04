namespace TBH_Trainer;

/// <summary>
/// RVA offsets extracted from Il2Cpp HPP headers. All offsets are relative to
/// the GameAssembly.dll base address.
///
/// ACTk detector RVAs below are for TBH 1.00.09 (remapped from the 1.00.09
/// ACTk.Runtime.dll dump; the structure is identical to 1.00.07, only the RVAs
/// shifted). The Unit/Health/Currency field offsets and the gameplay RVAs
/// further down are STILL 1.00.07 (HP/ATK update pending — lower priority).
/// </summary>
internal static class GameOffsets
{
    // === ACTk Detector Methods (1.00.09) — patch entry to RET 0xC3 to disable ===

    // ObscuredCheatingDetector.Check
    public const int ObscuredCheatingDetector_Check = 0x6C1840;
    // ObscuredCheatingDetector.Compare
    public const int ObscuredCheatingDetector_Compare = 0x6C19D0;
    // ObscuredCheatingDetector.CompareExt
    public const int ObscuredCheatingDetector_CompareExt = 0x6C1AB0;

    // InjectionDetector.Check
    public const int InjectionDetector_Check = 0x6C0D60;

    // SpeedHackDetector - the REAL per-frame detection runs in Update().
    // Patching Update() to RET stops an already-running detector (the old
    // StartDetection/xvz was just a static getInstance and useless to patch
    // once the game already started the detector).
    public const int SpeedHackDetector_Update = 0x6C6750;          // void Update()
    public const int SpeedHackDetector_OnAppPause = 0x6C66C0;      // void OnApplicationPause(bool)
    public const int SpeedHackDetector_Compare = 0x6D26D0;         // bool xwn(int64,int64,int64)

    // ACTkDetectorBase.Start() - base detector start
    public const int DetectorBase_Start = 0x42DD80;

    // === ObscuredType Encrypt/Decrypt (for reference) ===

    // ObscuredInt: realValue = hiddenValue ^ cryptoKey
    public const int ObscuredInt_Encrypt = 0x69BEC0; // xcd(int a, int b) => a ^ b
    public const int ObscuredInt_Decrypt = 0x69BED0; // xce(int a, int b) => a ^ b
    public const int ObscuredInt_GenerateKey = 0x68F130; // xcg() => random key

    // ObscuredFloat: float bits XOR'd as int
    public const int ObscuredFloat_Encrypt = 0x68B1F0; // xab(float a, int b) => float2int(a) ^ b
    public const int ObscuredFloat_Decrypt = 0x68B220; // xac(int a, int b) => int2float(a ^ b)

    // ObscuredLong: realValue = hiddenValue ^ cryptoKey
    public const int ObscuredLong_Encrypt = 0x694CA0; // xcw(long a, long b) => a ^ b
    public const int ObscuredLong_Decrypt = 0x694CB0; // xcx(long a, long b) => a ^ b

    // === Unit Class Field Offsets (from object base) ===

    public const int Unit_b_isLive = 0x00D8;      // ObscuredBool
    public const int Unit_b_isHero = 0x0100;       // bool
    public const int Unit_Stat0 = 0x0104;          // ObscuredFloat bcex
    public const int Unit_Stat1 = 0x0118;          // ObscuredFloat bcey
    public const int Unit_Stat2 = 0x012C;          // ObscuredFloat bcez
    public const int Unit_Stat3 = 0x0140;          // ObscuredFloat bcfa
    public const int Unit_Stat4 = 0x0154;          // ObscuredFloat bcfb
    public const int Unit_Stat5 = 0x0168;          // ObscuredFloat bcfc
    public const int Unit_Stat6 = 0x017C;          // ObscuredFloat bcfd
    public const int Unit_Stat7 = 0x0190;          // ObscuredFloat bcfe
    public const int Unit_Stat8 = 0x01A4;          // ObscuredFloat bcff
    public const int Unit_Stat9 = 0x01B8;          // ObscuredFloat bcfg
    public const int Unit_Stat10 = 0x01CC;         // ObscuredFloat bcfh
    public const int Unit_Stat11 = 0x01E0;         // ObscuredFloat bcfi
    public const int Unit_IntStat0 = 0x01F4;       // ObscuredInt bcfj
    public const int Unit_IntStat1 = 0x0204;       // ObscuredInt bcfk
    public const int Unit_FloatStat12 = 0x0214;    // ObscuredFloat bcfl
    public const int Unit_IntStat2 = 0x0228;       // ObscuredInt bcfm

    // === UnitHealthController (pe) Field Offsets ===

    public const int Health_Unit = 0x0030;         // Unit* bcgv
    public const int Health_CurrentHP = 0x0038;    // float bcgw
    public const int Health_MaxHP = 0x003C;        // float bcgx

    // === Currency (su) Field Offsets ===

    public const int Currency_Amount = 0x0028;     // ObscuredLong bdwn (quantity)
    public const int Currency_IntField = 0x0048;   // ObscuredInt bdwo

    // === CurrencySaveData Field Offsets ===

    public const int CurrSave_Key = 0x0010;        // int32 Key
    public const int CurrSave_Quantity = 0x0018;    // int64 Quantity

    // === HeroSaveData Field Offsets ===

    public const int HeroSave_Key = 0x0010;        // int32 heroKey
    public const int HeroSave_Level = 0x0014;      // int32 HeroLevel
    public const int HeroSave_IsUnlock = 0x0018;   // bool IsUnLock
    public const int HeroSave_Exp = 0x001C;        // float HeroExp
    public const int HeroSave_AbilityPt = 0x0020;  // int32 AbilityPoint

    // === Key RVA Methods ===

    // su.iko(int64, EGoldCurrencySource) - add currency
    public const int Currency_Add = 0x876E20;
    // su.ikl() - get currency amount
    public const int Currency_Get = 0x876DD0;

    // Unit.gnl(DamageInfo, bool) - apply damage to unit
    public const int Unit_ApplyDamage = 0xB41940;

    // pe.gtp(float) - set HP
    public const int Health_SetHP = 0xB54D40;
    // pe.eex(float) - heal
    public const int Health_Heal = 0xB546A0;
}
