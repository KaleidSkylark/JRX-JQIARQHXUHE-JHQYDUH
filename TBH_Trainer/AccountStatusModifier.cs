using System;

namespace TBH_Trainer;

internal sealed class AccountStatusModifier
{
    private readonly GameMemory _mem;
    public AccountStatusModifier(GameMemory mem) => _mem = mem;

    private const int XgKbkrva = 0x95AD00;

    private IntPtr ReadIntPtr(IntPtr address)
    {
        long val = _mem.ReadInt64(address);
        return new IntPtr(val);
    }

    public IntPtr ResolveAccountStatusPtr()
    {
        if (!_mem.IsAttached || _mem.GameAssemblyBase == IntPtr.Zero) return IntPtr.Zero;

        IntPtr kbkAddr = _mem.GameAssemblyBase + XgKbkrva;
        
        // Read 64 bytes of kbk() method instructions
        byte[] code = _mem.ReadBytes(kbkAddr, 64);
        if (code.Length < 7) return IntPtr.Zero;

        // Search for: mov rax, [rip + offset] -> 48 8B 05 xx xx xx xx
        IntPtr typeInfoAddr = IntPtr.Zero;
        for (int i = 0; i < code.Length - 7; i++)
        {
            if (code[i] == 0x48 && code[i + 1] == 0x8B && code[i + 2] == 0x05)
            {
                int ripOffset = BitConverter.ToInt32(code, i + 3);
                IntPtr ripBase = kbkAddr + i + 7;
                IntPtr typeInfoPtrAddr = ripBase + ripOffset;
                typeInfoAddr = ReadIntPtr(typeInfoPtrAddr);
                break;
            }
        }

        if (typeInfoAddr == IntPtr.Zero) return IntPtr.Zero;

        IntPtr staticFields = ReadIntPtr(typeInfoAddr + 0xB8);
        if (staticFields == IntPtr.Zero) return IntPtr.Zero;

        // xg instance backing field is at staticFields + 0x0
        IntPtr xgInstance = ReadIntPtr(staticFields + 0x0);
        if (xgInstance == IntPtr.Zero) return IntPtr.Zero;

        // AccountStatus* beur is at xgInstance + 0x20
        IntPtr accountStatus = ReadIntPtr(xgInstance + 0x20);
        return accountStatus;
    }

    private IntPtr FindDictObscuredIntPtr(IntPtr dict, int targetKey)
    {
        if (dict == IntPtr.Zero) return IntPtr.Zero;

        IntPtr entriesArray = ReadIntPtr(dict + 0x18);
        if (entriesArray == IntPtr.Zero) return IntPtr.Zero;

        int capacity = _mem.ReadInt32(entriesArray + 0x18);
        if (capacity <= 0 || capacity > 1000) return IntPtr.Zero;

        // Try entry sizes: 28, 32, 24
        int[] entrySizes = { 28, 32, 24 };
        foreach (int size in entrySizes)
        {
            for (int i = 0; i < capacity; i++)
            {
                IntPtr entryAddr = entriesArray + 0x20 + (i * size);
                int key = _mem.ReadInt32(entryAddr + 0x8);
                if (key == targetKey)
                {
                    // Check 64-bit alignment first (offset 16), then fallback to 32-bit (offset 12)
                    int[] offsets = { 16, 12 };
                    foreach (int offset in offsets)
                    {
                        IntPtr valPtr = entryAddr + offset;
                        var data = ACTkCrypto.ReadObscuredInt(_mem, valPtr);
                        if (data.CryptoKey != 0 && (data.HiddenValue ^ data.CryptoKey) == data.FakeValue)
                        {
                            return valPtr;
                        }
                    }
                }
            }
        }
        return IntPtr.Zero;
    }

    public int? GetNormalChestChance() => ReadValue(4);
    public int? GetNormalChestPercent() => ReadValue(29);

    public bool SetNormalChestChance(int value) => WriteValue(4, value);
    public bool SetNormalChestPercent(int value) => WriteValue(29, value);

    private int? ReadValue(int targetKey)
    {
        IntPtr accStatus = ResolveAccountStatusPtr();
        if (accStatus == IntPtr.Zero) return null;

        // beuk dictionary pointer is at AccountStatus + 0x10
        IntPtr dict = ReadIntPtr(accStatus + 0x10);
        IntPtr valPtr = FindDictObscuredIntPtr(dict, targetKey);
        if (valPtr == IntPtr.Zero) return null;

        var data = ACTkCrypto.ReadObscuredInt(_mem, valPtr);
        return data.Decrypt();
    }

    private bool WriteValue(int targetKey, int value)
    {
        IntPtr accStatus = ResolveAccountStatusPtr();
        if (accStatus == IntPtr.Zero) return false;

        IntPtr dict = ReadIntPtr(accStatus + 0x10);
        IntPtr valPtr = FindDictObscuredIntPtr(dict, targetKey);
        if (valPtr == IntPtr.Zero) return false;

        var data = ACTkCrypto.ReadObscuredInt(_mem, valPtr);
        data.SetValue(value);
        ACTkCrypto.WriteObscuredInt(_mem, valPtr, data);
        return true;
    }
}
