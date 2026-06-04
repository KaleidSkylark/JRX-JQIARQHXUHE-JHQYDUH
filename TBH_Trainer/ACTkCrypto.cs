namespace TBH_Trainer;

/// <summary>
/// Handles ACTk (Anti-Cheat Toolkit) ObscuredType encryption/decryption.
///
/// Memory layout when embedded as a field in a managed object:
///
/// ObscuredInt (16 bytes):
///   +0x00: int32 hash
///   +0x04: int32 hiddenValue  (encrypted)
///   +0x08: int32 cryptoKey
///   +0x0C: int32 fakeValue    (plaintext, checked by detector)
///
/// ObscuredFloat (20 bytes):
///   +0x00: int32 hash
///   +0x04: int32 hiddenValue  (float bits XOR'd as int)
///   +0x08: int32 cryptoKey
///   +0x0C: float fakeValue
///   +0x10: int32 hiddenValueOldByte4
///
/// ObscuredLong (32 bytes):
///   +0x00: int32 hash
///   +0x04: (4 bytes padding for alignment)
///   +0x08: int64 hiddenValue  (encrypted)
///   +0x10: int64 cryptoKey
///   +0x18: int64 fakeValue
/// </summary>
internal static class ACTkCrypto
{
    public struct ObscuredIntData
    {
        public int Hash;
        public int HiddenValue;
        public int CryptoKey;
        public int FakeValue;

        public int Decrypt() => HiddenValue ^ CryptoKey;

        public void SetValue(int newValue)
        {
            HiddenValue = newValue ^ CryptoKey;
            FakeValue = newValue;
        }
    }

    public struct ObscuredFloatData
    {
        public int Hash;
        public int HiddenValue;
        public int CryptoKey;
        public float FakeValue;

        public float Decrypt()
        {
            int raw = HiddenValue ^ CryptoKey;
            return BitConverter.Int32BitsToSingle(raw);
        }

        public void SetValue(float newValue)
        {
            int raw = BitConverter.SingleToInt32Bits(newValue);
            HiddenValue = raw ^ CryptoKey;
            FakeValue = newValue;
        }
    }

    public struct ObscuredLongData
    {
        public int Hash;
        public long HiddenValue;
        public long CryptoKey;
        public long FakeValue;

        public long Decrypt() => HiddenValue ^ CryptoKey;

        public void SetValue(long newValue)
        {
            HiddenValue = newValue ^ CryptoKey;
            FakeValue = newValue;
        }
    }

    public static ObscuredIntData ReadObscuredInt(GameMemory mem, IntPtr address)
    {
        var buf = mem.ReadBytes(address, 16);
        return new ObscuredIntData
        {
            Hash = BitConverter.ToInt32(buf, 0),
            HiddenValue = BitConverter.ToInt32(buf, 4),
            CryptoKey = BitConverter.ToInt32(buf, 8),
            FakeValue = BitConverter.ToInt32(buf, 12)
        };
    }

    public static void WriteObscuredInt(GameMemory mem, IntPtr address, ObscuredIntData data)
    {
        var buf = new byte[16];
        BitConverter.GetBytes(data.Hash).CopyTo(buf, 0);
        BitConverter.GetBytes(data.HiddenValue).CopyTo(buf, 4);
        BitConverter.GetBytes(data.CryptoKey).CopyTo(buf, 8);
        BitConverter.GetBytes(data.FakeValue).CopyTo(buf, 12);
        mem.WriteBytes(address, buf);
    }

    public static ObscuredFloatData ReadObscuredFloat(GameMemory mem, IntPtr address)
    {
        var buf = mem.ReadBytes(address, 16);
        return new ObscuredFloatData
        {
            Hash = BitConverter.ToInt32(buf, 0),
            HiddenValue = BitConverter.ToInt32(buf, 4),
            CryptoKey = BitConverter.ToInt32(buf, 8),
            FakeValue = BitConverter.ToSingle(buf, 12)
        };
    }

    public static void WriteObscuredFloat(GameMemory mem, IntPtr address, ObscuredFloatData data)
    {
        var buf = new byte[16];
        BitConverter.GetBytes(data.Hash).CopyTo(buf, 0);
        BitConverter.GetBytes(data.HiddenValue).CopyTo(buf, 4);
        BitConverter.GetBytes(data.CryptoKey).CopyTo(buf, 8);
        BitConverter.GetBytes(data.FakeValue).CopyTo(buf, 12);
        mem.WriteBytes(address, buf);
    }

    public static ObscuredLongData ReadObscuredLong(GameMemory mem, IntPtr address)
    {
        var buf = mem.ReadBytes(address, 32);
        return new ObscuredLongData
        {
            Hash = BitConverter.ToInt32(buf, 0),
            HiddenValue = BitConverter.ToInt64(buf, 8),
            CryptoKey = BitConverter.ToInt64(buf, 16),
            FakeValue = BitConverter.ToInt64(buf, 24)
        };
    }

    public static void WriteObscuredLong(GameMemory mem, IntPtr address, ObscuredLongData data)
    {
        var buf = new byte[32];
        BitConverter.GetBytes(data.Hash).CopyTo(buf, 0);
        BitConverter.GetBytes(data.HiddenValue).CopyTo(buf, 8);
        BitConverter.GetBytes(data.CryptoKey).CopyTo(buf, 16);
        BitConverter.GetBytes(data.FakeValue).CopyTo(buf, 24);
        mem.WriteBytes(address, buf);
    }

    public static bool IsValidObscuredInt(byte[] buf, int offset, int expectedValue)
    {
        if (offset + 16 > buf.Length) return false;
        int hidden = BitConverter.ToInt32(buf, offset + 4);
        int key = BitConverter.ToInt32(buf, offset + 8);
        int fake = BitConverter.ToInt32(buf, offset + 12);
        if (key == 0) return false;
        int decrypted = hidden ^ key;
        return decrypted == expectedValue && fake == expectedValue;
    }

    public static bool IsValidObscuredFloat(byte[] buf, int offset, float expectedValue, float epsilon = 0.01f)
    {
        if (offset + 16 > buf.Length) return false;
        int hidden = BitConverter.ToInt32(buf, offset + 4);
        int key = BitConverter.ToInt32(buf, offset + 8);
        float fake = BitConverter.ToSingle(buf, offset + 12);
        if (key == 0) return false;
        float decrypted = BitConverter.Int32BitsToSingle(hidden ^ key);
        return MathF.Abs(decrypted - expectedValue) < epsilon && MathF.Abs(fake - expectedValue) < epsilon;
    }

    public static bool IsValidObscuredLong(byte[] buf, int offset, long expectedValue)
    {
        if (offset + 32 > buf.Length) return false;
        long hidden = BitConverter.ToInt64(buf, offset + 8);
        long key = BitConverter.ToInt64(buf, offset + 16);
        long fake = BitConverter.ToInt64(buf, offset + 24);
        if (key == 0) return false;
        long decrypted = hidden ^ key;
        return decrypted == expectedValue && fake == expectedValue;
    }

    public static bool LooksLikeObscuredInt(byte[] buf, int offset)
    {
        if (offset + 16 > buf.Length) return false;
        int hidden = BitConverter.ToInt32(buf, offset + 4);
        int key = BitConverter.ToInt32(buf, offset + 8);
        int fake = BitConverter.ToInt32(buf, offset + 12);
        if (key == 0) return false;
        int decrypted = hidden ^ key;
        return decrypted == fake && decrypted != 0;
    }

    public static bool LooksLikeObscuredLong(byte[] buf, int offset)
    {
        if (offset + 32 > buf.Length) return false;
        long hidden = BitConverter.ToInt64(buf, offset + 8);
        long key = BitConverter.ToInt64(buf, offset + 16);
        long fake = BitConverter.ToInt64(buf, offset + 24);
        if (key == 0) return false;
        long decrypted = hidden ^ key;
        return decrypted == fake && decrypted != 0;
    }
}
