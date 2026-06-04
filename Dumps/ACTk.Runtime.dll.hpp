// ============================================================
// Image: ACTk.Runtime.dll
// ============================================================

namespace Microsoft.CodeAnalysis
{

    // Namespace: Microsoft.CodeAnalysis
    class EmbeddedAttribute : public Attribute
    {
    public:
    
        // Methods
        void .ctor();  // RVA: 0x66DDF0
    };

} // namespace Microsoft.CodeAnalysis

namespace System.Runtime.CompilerServices
{

    // Namespace: System.Runtime.CompilerServices
    class IsUnmanagedAttribute : public Attribute
    {
    public:
    
        // Methods
        void .ctor();  // RVA: 0x66DDF0
    };

} // namespace System.Runtime.CompilerServices

// Namespace: <global>
struct MonoScriptData
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Byte[][] FilePathsData; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Byte[][] TypesData; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    int32_t TotalTypes; // 0x0020
    uint8_t pad_0021[0x3]; // 0x0021
    int32_t TotalFiles; // 0x0024
    uint8_t pad_0025[0x3]; // 0x0025
    bool IsEditorOnly; // 0x0028
};

// Namespace: <global>
class dan
{
public:

    // Methods
    static MonoScriptData gnk();  // RVA: 0x66EAA0
    void .ctor();  // RVA: 0x628380
    static MonoScriptData vza();  // RVA: 0x66EB80
};

// Namespace: <global>
class dao
{
public:

    // Methods
    static void vzc();  // RVA: 0x632CB0
    static void eew();  // RVA: 0x632CB0
    static void faq();  // RVA: 0x632CB0
    static void kee();  // RVA: 0x632CB0
    static void vzb();  // RVA: 0x632CB0
};

// Namespace: <global>
class ApplicationFocusEventHandler : public MulticastDelegate
{
public:

    // Methods
    void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x66DCE0
    void Invoke(bool hasFocus);  // RVA: 0x66DCD0
    IAsyncResult* BeginInvoke(bool hasFocus, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x66DC60
    void EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
};

// Namespace: <global>
class ApplicationPauseEventHandler : public MulticastDelegate
{
public:

    // Methods
    void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x66DCE0
    void Invoke(bool pauseStatus);  // RVA: 0x66DCD0
    IAsyncResult* BeginInvoke(bool pauseStatus, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x66DC60
    void EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
};

// Namespace: <global>
class dap : public MonoBehaviour
{
public:
    // Static fields
    // static dap* bmod;

    uint8_t pad_0000[0x20]; // 0x0000
    ApplicationFocusEventHandler* bmob; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    ApplicationPauseEventHandler* bmoc; // 0x0028

    // Methods
    void igb(bool hasFocus);  // RVA: 0x66ED00
    void vze(ApplicationFocusEventHandler* a);  // RVA: 0x66EE80
    void Awake();  // RVA: 0x66EC60
    void vzf(ApplicationPauseEventHandler* a);  // RVA: 0x66EF20
    static dap* vzh();  // RVA: 0x66F060
    void OnApplicationPause(bool pauseStatus);  // RVA: 0x66ED20
    void OnApplicationFocus(bool hasFocus);  // RVA: 0x66ED00
    void vzg(ApplicationPauseEventHandler* a);  // RVA: 0x66EFC0
    void .ctor();  // RVA: 0x628650
    void nmi();  // RVA: 0x66ED40
    void vzd(ApplicationFocusEventHandler* a);  // RVA: 0x66EDE0
    void dot(bool hasFocus);  // RVA: 0x66ED00
};

// Namespace: <global>
class daq
{
public:

    // Methods
    static Il2CppString* vzk(Il2CppString* a);  // RVA: 0x66FD00
    static Char[][] vzj(Il2CppString* a);  // RVA: 0x66FC60
    static Il2CppString* bvw(Il2CppString* a);  // RVA: 0x66F190
    static Il2CppString* vzi(Il2CppString* a);  // RVA: 0x66FBC0
    static Char[][] eho(Il2CppString* a);  // RVA: 0x66F580
    static Il2CppString* hoa(Char[][] a);  // RVA: 0x66F620
    static Il2CppString* mta(Il2CppString* a);  // RVA: 0x66FAA0
    static Il2CppString* mor(Char[][] a);  // RVA: 0x66F990
    static Il2CppString* vzl(Char[][] a);  // RVA: 0x66FE20
    static Il2CppString* dlq(Char[][] a);  // RVA: 0x66F470
    static Il2CppString* ikt(Il2CppString* a);  // RVA: 0x66F730
    static Il2CppString* lku(Il2CppString* a);  // RVA: 0x66F8F0
    static Il2CppString* ktp(Il2CppString* a);  // RVA: 0x66F850
    static Il2CppString* cl(Il2CppString* a);  // RVA: 0x66F350
    static Char[][] byf(Il2CppString* a);  // RVA: 0x66F2B0
};

// Namespace: <global>
class dar
{
public:
    // Static fields
    // static int32_t bmoe;
    // static uint8_t bmof;
    // static uint8_t bmog;
    // static uint8_t bmoh;
    // static uint8_t bmoi;
    // static uint8_t bmoj;


    // Methods
    static void vzq(Stream* a, Stream* b, Byte[][] c, uint8_t d);  // RVA: 0x563E10
    static void vzm(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x670160
    static void eoe(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x66FF30
    static void vzo(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x670240
    static void vzp(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x6702B0
    static void vzr(Stream* a, Stream* b, Byte[][] c, uint8_t d, uint8_t e);  // RVA: 0x4367D0
    static void imb(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x670080
    static void hlh(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x66FFA0
    static void igs(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x670010
    static void vzn(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x6701D0
    static void nmg(Stream* a, Stream* b, Byte[][] c);  // RVA: 0x6700F0
};

// Namespace: <global>
class das
{
public:
    // Static fields
    // static int32_t bmok;


    // Methods
    static bool vm(Decimal a, int32_t b);  // RVA: 0x670750
    static int32_t waj(a a);  // RVA: 0x563E10
    static bool igj(uint64_t a, int32_t b);  // RVA: 0x671090
    static bool wab(Vector2Int a, int32_t b);  // RVA: 0x672B90
    static int32_t jxl(Vector3Int a);  // RVA: 0x671A70
    static bool vzs(BigInteger a, int32_t b);  // RVA: 0x672B60
    static bool vzy(uint64_t a, int32_t b);  // RVA: 0x671090
    static bool vzz(Quaternion a, int32_t b);  // RVA: 0x670E00
    static bool waa(Vector2 a, int32_t b);  // RVA: 0x6706A0
    static bool dq(int64_t a, int32_t b);  // RVA: 0x670320
    static bool wac(Vector3 a, int32_t b);  // RVA: 0x670C00
    static int32_t wbb(Char[][] a);  // RVA: 0x673930
    static bool dow(float a, int32_t b);  // RVA: 0x6707B0
    static int32_t jwf(Decimal a);  // RVA: 0x671840
    static int32_t eoz(float a);  // RVA: 0x670B80
    static int32_t waw(Quaternion a);  // RVA: 0x670420
    static int32_t ia(int64_t a);  // RVA: 0x671000
    static bool jnq(DateTimeOffset a, int32_t b);  // RVA: 0x6717B0
    static int32_t nhz(uint64_t a);  // RVA: 0x672740
    static int32_t cek(Char[][] a);  // RVA: 0x670650
    static int32_t frt(DateTime a);  // RVA: 0x670D10
    static int32_t ofe(DateTimeOffset a);  // RVA: 0x672A80
    static bool brt(int64_t a, int32_t b);  // RVA: 0x670320
    static bool mep(Vector2 a, int32_t b);  // RVA: 0x6706A0
    static bool ego(Vector3Int a, int32_t b);  // RVA: 0x6708B0
    static int32_t dxd(Vector2Int a);  // RVA: 0x670810
    static bool wad(Vector3Int a, int32_t b);  // RVA: 0x6708B0
    static int32_t wat(uint64_t a);  // RVA: 0x6735E0
    static int32_t way(Vector2Int a);  // RVA: 0x670810
    static int32_t ixm(BigInteger a);  // RVA: 0x6714C0
    static int32_t jwu(Vector3Int a);  // RVA: 0x671970
    static int32_t nth(BigInteger a);  // RVA: 0x672790
    static int32_t wau(float a);  // RVA: 0x670B80
    static int32_t waz(Vector3 a);  // RVA: 0x673740
    static int32_t bxt(Char[][] a);  // RVA: 0x6703D0
    static int32_t hyz(DateTimeOffset a);  // RVA: 0x670F20
    static bool nyo(float a, int32_t b);  // RVA: 0x6707B0
    static int32_t wal(bool a);  // RVA: 0x672F30
    static bool ixy(DateTimeOffset a, int32_t b);  // RVA: 0x6717B0
    static bool vzx(uint32_t a, int32_t b);  // RVA: 0x670EB0
    static int32_t eor(Guid a);  // RVA: 0x670900
    static int32_t lds(Il2CppString* a);  // RVA: 0x671DD0
    static int32_t wao(DateTime a);  // RVA: 0x673110
    static int32_t wav(double a);  // RVA: 0x673680
    static bool joa(Char[][] a, int32_t b);  // RVA: 0x6717E0
    static int32_t cb(Quaternion a);  // RVA: 0x670420
    static bool hds(double a, int32_t b);  // RVA: 0x670780
    static bool mwr(Quaternion a, int32_t b);  // RVA: 0x670E00
    static int32_t cdt(Quaternion a);  // RVA: 0x670420
    static bool cvm(Decimal a, int32_t b);  // RVA: 0x670750
    static int32_t lo(Char[][] a);  // RVA: 0x671EA0
    static int32_t ipq(Guid a);  // RVA: 0x671240
    static bool ilb(Guid a, int32_t b);  // RVA: 0x670BD0
    static int32_t wan(int32_t a);  // RVA: 0x671E50
    static int32_t mkd(float a);  // RVA: 0x670B80
    static int32_t was(uint32_t a);  // RVA: 0x671E50
    static int32_t lej(uint32_t a);  // RVA: 0x671E50
    static int32_t wam(Decimal a);  // RVA: 0x672F40
    static int32_t ktz(DateTimeOffset a);  // RVA: 0x671CF0
    static int32_t mlx(BigInteger a);  // RVA: 0x6720C0
    static int32_t wak(BigInteger a);  // RVA: 0x672C40
    static bool fil(double a, int32_t b);  // RVA: 0x670780
    static int32_t kjg(Il2CppString* a);  // RVA: 0x671B80
    static int32_t lpj(DateTimeOffset a);  // RVA: 0x671EF0
    static bool euz(Guid a, int32_t b);  // RVA: 0x670BD0
    static int32_t wax(Vector2 a);  // RVA: 0x6736A0
    static bool fwe(Quaternion a, int32_t b);  // RVA: 0x670E00
    static bool vzt(bool a, int32_t b);  // RVA: 0x670F00
    static int32_t waq(Guid a);  // RVA: 0x6732E0
    static bool khb(bool a, int32_t b);  // RVA: 0x670F00
    static bool ntu(Decimal a, int32_t b);  // RVA: 0x670750
    static int32_t oja(Quaternion a);  // RVA: 0x670420
    static bool wah(DateTimeOffset a, int32_t b);  // RVA: 0x6717B0
    static int32_t kik(bool a);  // RVA: 0x671B70
    static int32_t ilu(bool a);  // RVA: 0x671230
    static bool vzv(int32_t a, int32_t b);  // RVA: 0x670EB0
    static int32_t th(Quaternion a);  // RVA: 0x670420
    static int32_t nem(uint64_t a);  // RVA: 0x6726A0
    static int32_t ktb(DateTime a);  // RVA: 0x671C00
    static int32_t wba(Vector3Int a);  // RVA: 0x673830
    static bool fmo(Vector3 a, int32_t b);  // RVA: 0x670C00
    static int32_t wbc(Il2CppString* a);  // RVA: 0x673980
    static int32_t cee(Vector3Int a);  // RVA: 0x670560
    static bool hgq(bool a, int32_t b);  // RVA: 0x670F00
    static int32_t fwq(Il2CppString* a);  // RVA: 0x670E30
    static int32_t mti(BigInteger a);  // RVA: 0x6723B0
    static int32_t kmi(int64_t a);  // RVA: 0x671000
    static bool jwj(int64_t a, int32_t b);  // RVA: 0x670320
    static bool kvv(Vector3 a, int32_t b);  // RVA: 0x670C00
    static int32_t ihz(DateTime a);  // RVA: 0x671140
    static bool cif(Vector2 a, int32_t b);  // RVA: 0x6706A0
    static bool dls(double a, int32_t b);  // RVA: 0x670780
    static bool kyo(Guid a, int32_t b);  // RVA: 0x670BD0
    static int32_t war(int64_t a);  // RVA: 0x673540
    static bool exv(Vector3 a, int32_t b);  // RVA: 0x670C00
    static bool wae(float a, int32_t b);  // RVA: 0x6707B0
    static bool hpn(int64_t a, int32_t b);  // RVA: 0x670320
    static bool gem(uint32_t a, int32_t b);  // RVA: 0x670EB0
    static bool knz(Guid a, int32_t b);  // RVA: 0x670BD0
    static bool wai(Guid a, int32_t b);  // RVA: 0x670BD0
    static bool hdr(double a, int32_t b);  // RVA: 0x670780
    static bool wag(Char[][] a, int32_t b);  // RVA: 0x6717E0
    static bool vzu(Decimal a, int32_t b);  // RVA: 0x670750
    static int32_t ekc(double a);  // RVA: 0x6708E0
    static int32_t wap(DateTimeOffset a);  // RVA: 0x673200
    static bool waf(double a, int32_t b);  // RVA: 0x670780
    static int32_t maf(DateTime a);  // RVA: 0x671FD0
    static bool vzw(int64_t a, int32_t b);  // RVA: 0x670320
};

// Namespace: <global>
class dat : public CertificateHandler
{
public:

    // Methods
    bool ValidateCertificate(Byte[][] certificateData);  // RVA: 0x673A00
    void .ctor();  // RVA: 0x673A10
};

// Namespace: <global>
class dau
{
public:

    // Methods
    static bool hut(float a, float b, float c);  // RVA: 0x673A20
    static bool ooe(double a, double b, double c);  // RVA: 0x673D30
    static bool wbe(double a, double b, double c);  // RVA: 0x673F10
    static bool mza(double a, double b, double c);  // RVA: 0x673C00
    static bool kjo(double a, double b, double c);  // RVA: 0x673AD0
    static bool wbd(float a, float b, float c);  // RVA: 0x673E60
};

// Namespace: <global>
class dav
{
public:

    // Methods
    static void wbf(System.IProgress<CodeStage.AntiCheat.Genuine.CodeHash.FilesProgress> a, int32_t b, int32_t c, int64_t d, Il2CppString* e);  // RVA: 0x674040
};

// Namespace: <global>
class daw
{
public:

    // Methods
    static void jhw(Char[][] a);  // RVA: 0x674920
    static uint16_t wbl();  // RVA: 0x674ED0
    static int32_t wbm();  // RVA: 0x6746F0
    static wchar_t wbj();  // RVA: 0x674E30
    static int64_t obv();  // RVA: 0x674C60
    static int64_t wbo();  // RVA: 0x6748C0
    static int64_t hof();  // RVA: 0x6746A0
    static uint8_t djv();  // RVA: 0x6742F0
    static void wbq(Char[][] a);  // RVA: 0x674F20
    static Il2CppString* wbg(int32_t a);  // RVA: 0x674CB0
    static uint32_t ieh();  // RVA: 0x6746F0
    static wchar_t gxw();  // RVA: 0x674600
    static uint64_t wbp();  // RVA: 0x6748C0
    static uint8_t biv();  // RVA: 0x674170
    static uint8_t wbh();  // RVA: 0x674D90
    static void nhd(Char[][] a);  // RVA: 0x674BD0
    static int16_t kro();  // RVA: 0x674A90
    static int32_t epv();  // RVA: 0x674420
    static int8_t mda();  // RVA: 0x674B30
    static int8_t gwn();  // RVA: 0x6745B0
    static int8_t bwi();  // RVA: 0x6741C0
    static uint8_t inu();  // RVA: 0x674820
    static Il2CppString* kla(int32_t a);  // RVA: 0x6749B0
    static wchar_t mtk();  // RVA: 0x674B80
    static int16_t llb();  // RVA: 0x674AE0
    static int16_t gpl();  // RVA: 0x674510
    static int8_t wbi();  // RVA: 0x674DE0
    static uint32_t wbn();  // RVA: 0x6746F0
    static uint16_t fsh();  // RVA: 0x674470
    static int8_t hec();  // RVA: 0x674650
    static int32_t ios();  // RVA: 0x674870
    static uint32_t ktp();  // RVA: 0x6746F0
    static uint8_t gcw();  // RVA: 0x6744C0
    static uint32_t nbl();  // RVA: 0x6746F0
    static Il2CppString* dun(int32_t a);  // RVA: 0x674340
    static Il2CppString* iia(int32_t a);  // RVA: 0x674740
    static int16_t wbk();  // RVA: 0x674E80
    static uint64_t ivp();  // RVA: 0x6748C0
    static wchar_t gwd();  // RVA: 0x674560
    static int64_t cfh();  // RVA: 0x674210
    static void dim(Char[][] a);  // RVA: 0x674260
};

// Namespace: <global>
class dax
{
public:
    // Static fields
    // static Char[][] bmol;


    // Methods
    static Byte[][] lru(Il2CppString* a);  // RVA: 0x6750E0
    static Il2CppString* htg(Byte[][] a);  // RVA: 0x675170
    static Il2CppString* low(Byte[][] a);  // RVA: 0x675170
    static Il2CppString* lod(Byte[][] a, int32_t b, int32_t c);  // RVA: 0x675040
    static Il2CppString* wbv(Byte[][] a, int32_t b, int32_t c);  // RVA: 0x675040
    static Il2CppString* dgj(Byte[][] a, int32_t b, int32_t c);  // RVA: 0x675040
    static Char[][] wbt(Byte[][] a);  // RVA: 0x675130
    static Il2CppString* jjp(Byte[][] a);  // RVA: 0x675170
    static void .cctor();  // RVA: 0x674FB0
    static Byte[][] kml(Char[][] a);  // RVA: 0x6750A0
    static Il2CppString* wbu(Byte[][] a);  // RVA: 0x675170
    static Byte[][] dkf(Char[][] a);  // RVA: 0x6750A0
    static Byte[][] wbs(Il2CppString* a);  // RVA: 0x6750E0
    static Char[][] mbf(Byte[][] a);  // RVA: 0x675130
    static Il2CppString* bfc(Byte[][] a, int32_t b, int32_t c);  // RVA: 0x675040
    static Il2CppString* mes(Byte[][] a);  // RVA: 0x675170
    static Byte[][] fdg(Il2CppString* a);  // RVA: 0x6750E0
    static Byte[][] wbr(Char[][] a);  // RVA: 0x6750A0
    static Char[][] gmh(Byte[][] a);  // RVA: 0x675130
    static Byte[][] nzm(Char[][] a);  // RVA: 0x6750A0
    static Il2CppString* wbw(Byte[][] a);  // RVA: 0x6751B0
};

// Namespace: <global>
class day`1
{
public:
    System.Collections.Concurrent.ConcurrentBag<a> bmom; // 0x0000
    System.Func<a> bmon; // 0x0000

    // Methods
    void wbz();  // RVA: 0x42DF20
    a wbx();  // RVA: 0x563E10
    void jwm();  // RVA: 0x42DF20
    void .ctor(System.Func<a> a);  // RVA: 0x4186E0
    void wby(a a);  // RVA: 0x563E10
};

// Namespace: <global>
class daz
{
public:
    // Static fields
    // static Random* bmoo;
    // static Random* bmop;


    // Methods
    static int32_t wca(int32_t a, int32_t b);  // RVA: 0x676AF0
    static void bjm(Byte[][] a);  // RVA: 0x6753B0
    static void wcc(Byte[][] a);  // RVA: 0x676F80
    static void fgd(Byte[][] a);  // RVA: 0x675C40
    static int64_t wce(Random* a, int64_t b, int64_t c);  // RVA: 0x677520
    static void dio(Char[][] a);  // RVA: 0x675930
    static void .cctor();  // RVA: 0x675330
    static void wcd(Char[][] a);  // RVA: 0x677210
    static int64_t cyi(int64_t a, int64_t b);  // RVA: 0x6756C0
    static int64_t hxg(Random* a, int64_t b, int64_t c);  // RVA: 0x6761B0
    static int64_t xc(Random* a, int64_t b, int64_t c);  // RVA: 0x677630
    static void wcf(Random* a, Char[][] b);  // RVA: 0x6775A0
    static void inc(Char[][] a);  // RVA: 0x676220
    static void ir(Random* a, Char[][] b);  // RVA: 0x676530
    static int64_t byp(Random* a, int64_t b, int64_t c);  // RVA: 0x675640
    static void lvm(Byte[][] a);  // RVA: 0x676860
    static void lrw(Byte[][] a);  // RVA: 0x6765D0
    static int64_t fpc(int64_t a, int64_t b);  // RVA: 0x675ED0
    static int64_t wcb(int64_t a, int64_t b);  // RVA: 0x676D10
    static int64_t gxg(Random* a, int64_t b, int64_t c);  // RVA: 0x676140
};

// Namespace: <global>
class dba
{
public:
    // Static fields
    // static int64_t bmoq;


    // Methods
    static double wch();  // RVA: 0x6778E0
    static double osc();  // RVA: 0x677810
    static int64_t wck();  // RVA: 0x677990
    static int64_t wci();  // RVA: 0x677950
    static int64_t iyb();  // RVA: 0x677760
    static int64_t wcg();  // RVA: 0x677880
    static int64_t wcj();  // RVA: 0x677970
    static int64_t iet();  // RVA: 0x677740
    static double omt();  // RVA: 0x6777A0
    static int64_t koy();  // RVA: 0x677780
    static double fxo();  // RVA: 0x6776D0
    static int64_t bod();  // RVA: 0x6776B0
};

// Namespace: <global>
class dbb
{
public:
    // Static fields
    // static uint32_t bmor;
    // static uint32_t bmos;
    // static uint32_t bmot;
    // static uint32_t bmou;
    // static uint32_t bmov;


    // Methods
    static uint32_t ksu(Stream* a, int64_t b, uint32_t c);  // RVA: 0x677BF0
    static uint32_t low(Stream* a, int64_t b, uint32_t c);  // RVA: 0x677F40
    static uint32_t gob(Byte[][] a, int32_t b, uint32_t c);  // RVA: 0x6779B0
    static uint32_t ohb(Byte[][] a, int32_t b, uint32_t c);  // RVA: 0x678230
    static uint32_t wcm(Stream* a, int64_t b, uint32_t c);  // RVA: 0x6787C0
    static uint32_t wcl(Byte[][] a, int32_t b, uint32_t c);  // RVA: 0x678390
};

// Namespace: <global>
class dbc : public dcy`1
{
public:
    // Static fields
    // static bool bmow;
    // static bool bmox;
    // static float bmoy;
    // static float bmoz;
    // static float bmpa;
    // static float bmpb;
    // static float bmpc;
    // static float bmpd;
    // static bool bmpe;

    uint8_t pad_0000[0x30]; // 0x0000
    int64_t bmpf; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    int64_t bmpg; // 0x0038
    uint8_t pad_0039[0x7]; // 0x0039
    int64_t bmph; // 0x0040

    // Methods
    void Update();  // RVA: 0x678C20
    bool wcx();  // RVA: 0x67A190
    bool hot();  // RVA: 0x679690
    static void dew();  // RVA: 0x679240
    void mtm();  // RVA: 0x679940
    static float wcr();  // RVA: 0x679E70
    void doo();  // RVA: 0x6792B0
    static void wco();  // RVA: 0x679AC0
    static float wcv();  // RVA: 0x67A170
    static float wct();  // RVA: 0x679FF0
    static void wcn();  // RVA: 0x679A50
    static float wcs();  // RVA: 0x679F30
    static float wcp();  // RVA: 0x679CF0
    void wda();  // RVA: 0x67A580
    static void flk();  // RVA: 0x679460
    void icp();  // RVA: 0x6798A0
    void .ctor();  // RVA: 0x678E80
    void cgj();  // RVA: 0x679170
    static void wcw(float a);  // RVA: 0x67A180
    void bhg();  // RVA: 0x678EC0
    bool zt();  // RVA: 0x67A6A0
    void wcy();  // RVA: 0x67A3A0
    bool bvm();  // RVA: 0x678F60
    static float wcu();  // RVA: 0x67A0B0
    void esu();  // RVA: 0x679350
    static float wcq();  // RVA: 0x679DB0
    void wdb(Scene a, LoadSceneMode b);  // RVA: 0x67A620
    void wcz();  // RVA: 0x67A470
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct StorageDataType
    {
    public:
        // Static fields
        // static StorageDataType Unknown;
        // static StorageDataType SByte;
        // static StorageDataType Byte;
        // static StorageDataType Int16;
        // static StorageDataType UInt16;
        // static StorageDataType Int32;
        // static StorageDataType UInt32;
        // static StorageDataType Int64;
        // static StorageDataType UInt64;
        // static StorageDataType Char;
        // static StorageDataType Single;
        // static StorageDataType Double;
        // static StorageDataType Decimal;
        // static StorageDataType BigInteger;
        // static StorageDataType Boolean;
        // static StorageDataType String;
        // static StorageDataType DateTime;
        // static StorageDataType ByteArray;
        // static StorageDataType Vector2;
        // static StorageDataType Vector2Int;
        // static StorageDataType Vector3;
        // static StorageDataType Vector3Int;
        // static StorageDataType Vector4;
        // static StorageDataType Quaternion;
        // static StorageDataType Color;
        // static StorageDataType Color32;
        // static StorageDataType Rect;
        // static StorageDataType RectInt;
        // static StorageDataType RangeInt;
        // static StorageDataType Matrix4x4;
        // static StorageDataType Ray;
        // static StorageDataType Ray2D;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t value__; // 0x0010
    };

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredPrefsData
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        StorageDataType type; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        Byte[][] data; // 0x0018
    
        // Methods
        void .ctor(StorageDataType type, Byte[][] data);  // RVA: 0x66E980
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbd
{
public:

    // Methods
    static f wdi(StorageDataType a, Byte[][] b);  // RVA: 0x563E10
    static d wdg(StorageDataType a, Byte[][] b);  // RVA: 0x563E10
    static T wdk(Byte[][] a);  // RVA: 0x563E10
    static Color32 nab(Byte[][] a);  // RVA: 0x67A8E0
    static Byte[][] wdj(T a);  // RVA: 0x563E10
    static c wdf(Byte[][] a);  // RVA: 0x563E10
    static Color32 wdc(Byte[][] a);  // RVA: 0x67A920
    static b wde(ObscuredPrefsData a);  // RVA: 0x563E10
    static Color32 lzu(Byte[][] a);  // RVA: 0x67A8B0
    static Byte[][] wdh(StorageDataType a, e b);  // RVA: 0x563E10
    static ObscuredPrefsData wdd(a a);  // RVA: 0x563E10
};

// Namespace: <global>
class dbe
{
public:
    // Static fields
    // static Type* bmpi;
    // static Type* bmpj;
    // static Type* bmpk;
    // static Type* bmpl;
    // static Type* bmpm;
    // static Type* bmpn;
    // static Type* bmpo;
    // static Type* bmpp;
    // static Type* bmpq;
    // static Type* bmpr;
    // static Type* bmps;
    // static Type* bmpt;
    // static Type* bmpu;
    // static Type* bmpv;
    // static Type* bmpw;
    // static Type* bmpx;
    // static Type* bmpy;
    // static Type* bmpz;
    // static Type* bmqa;
    // static Type* bmqb;
    // static Type* bmqc;
    // static Type* bmqd;
    // static Type* bmqe;
    // static Type* bmqf;
    // static Type* bmqg;
    // static Type* bmqh;
    // static Type* bmqi;
    // static Type* bmqj;
    // static Type* bmqk;
    // static Type* bmql;
    // static Type* bmqm;


    // Methods
    static StorageDataType wdl();  // RVA: 0x421400
    static void .cctor();  // RVA: 0x67A960
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    class UnsupportedDataTypeException : public Exception
    {
    public:
    
        // Methods
        void .ctor(Type* type);  // RVA: 0x66EA00
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class HashCheckSumModifierDelegate : public MulticastDelegate
{
public:

    // Methods
    void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x66DE30
    Byte[][] Invoke(Il2CppString* input);  // RVA: 0x66DCD0
    IAsyncResult* BeginInvoke(Il2CppString* input, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x66DE00
    Byte[][] EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
};

// Namespace: <global>
class dbf
{
public:
    // Static fields
    // static Il2CppString* bmqn;

    uint8_t pad_0000[0x10]; // 0x0000
    uint32_t bmqo; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    uint32_t bmqp; // 0x0014
    uint8_t pad_0015[0x3]; // 0x0015
    HashCheckSumModifierDelegate* bmqq; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    bool <bmqr>k__BackingField; // 0x0020

    // Methods
    void wdr(bool a);  // RVA: 0x67BA10
    void me(HashCheckSumModifierDelegate* a);  // RVA: 0x67B580
    uint32_t wdw(Il2CppString* a);  // RVA: 0x67BB80
    static Il2CppString* wdp();  // RVA: 0x67B9D0
    void .ctor(uint32_t a);  // RVA: 0x67B210
    void wdt(HashCheckSumModifierDelegate* a);  // RVA: 0x67B580
    uint32_t hdn(Il2CppString* a);  // RVA: 0x67B450
    uint32_t nmz(Il2CppString* a);  // RVA: 0x67B690
    void wdu(bool a);  // RVA: 0x67BB70
    void lcm(HashCheckSumModifierDelegate* a);  // RVA: 0x67B580
    static void kmg();  // RVA: 0x67B590
    static void fju();  // RVA: 0x67B340
    static void exa();  // RVA: 0x67B240
    bool wdq();  // RVA: 0x66E5D0
    uint32_t wds();  // RVA: 0x67BA20
    static void wdn(Il2CppString* a);  // RVA: 0x67B870
    void wdv();  // RVA: 0x67B440
    void hxk(HashCheckSumModifierDelegate* a);  // RVA: 0x67B580
    void gxp();  // RVA: 0x67B440
    static Il2CppString* wdm();  // RVA: 0x67B7C0
    static void wdo();  // RVA: 0x67B8D0
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct DeviceLockLevel
    {
    public:
        // Static fields
        // static DeviceLockLevel None;
        // static DeviceLockLevel Soft;
        // static DeviceLockLevel Strict;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t value__; // 0x0010
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbg
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    DeviceLockLevel <bmqs>k__BackingField; // 0x0010
    DeviceLockTamperingSensitivity <bmqt>k__BackingField; // 0x0011

    // Methods
    DeviceLockLevel wdx();  // RVA: 0x66E8B0
    void wdy(DeviceLockLevel a);  // RVA: 0x67BCF0
    DeviceLockTamperingSensitivity wdz();  // RVA: 0x67BD00
    void wea(DeviceLockTamperingSensitivity a);  // RVA: 0x67BD10
    void .ctor(DeviceLockLevel a, DeviceLockTamperingSensitivity b);  // RVA: 0x67BCB0
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct DeviceLockTamperingSensitivity
    {
    public:
        // Static fields
        // static DeviceLockTamperingSensitivity Disabled;
        // static DeviceLockTamperingSensitivity Low;
        // static DeviceLockTamperingSensitivity Normal;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t value__; // 0x0010
    };

    // Namespace: CodeStage.AntiCheat.Storage
    class DeviceUniqueIdentifierException : public BackgroundThreadAccessException
    {
    public:
    
        // Methods
        void .ctor();  // RVA: 0x66DD90
    };

    // Namespace: CodeStage.AntiCheat.Storage
    class PersistentDataPathException : public BackgroundThreadAccessException
    {
    public:
    
        // Methods
        void .ctor();  // RVA: 0x66E9A0
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbh
{
public:
    // Static fields
    // static Il2CppString* bmqu;
    // static Il2CppString* bmqv;
    // static dbf* bmqw;

    uint8_t pad_0000[0x10]; // 0x0000
    Action* bmqx; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Action* bmqy; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    dbr* <bmqz>k__BackingField; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    Il2CppString* <bmra>k__BackingField; // 0x0028

    // Methods
    void lxd(Stream* a);  // RVA: 0x67DA30
    void .ctor(Il2CppString* a, dbr* b);  // RVA: 0x67BFA0
    ObscuredFileHeader huq(Stream* a);  // RVA: 0x67D6B0
    void web(Action* a);  // RVA: 0x680740
    dbr* wef();  // RVA: 0x63C8B0
    ObscuredFileReadResult dfc();  // RVA: 0x67C000
    Il2CppString* wer(Il2CppString* a);  // RVA: 0x681CE0
    void wee(Action* a);  // RVA: 0x680920
    ObscuredFileWriteResult wek(Byte[][] a);  // RVA: 0x67DA00
    ObscuredFileHeader wen(Stream* a);  // RVA: 0x67D6B0
    Il2CppString* msk(Il2CppString* a);  // RVA: 0x67F380
    void wec(Action* a);  // RVA: 0x6807E0
    ObscuredFileReadResult wel();  // RVA: 0x67C000
    ObscuredFileWriteResult weo(Byte[][] a);  // RVA: 0x6816E0
    ObscuredFileReadResult otl();  // RVA: 0x67FAD0
    ObscuredFileHeader isc(Stream* a);  // RVA: 0x67D6B0
    void .ctor(Il2CppString* a);  // RVA: 0x67BE40
    void hqu();  // RVA: 0x67D680
    void .ctor(dbs* a);  // RVA: 0x67BDA0
    Il2CppString* hku(Il2CppString* a);  // RVA: 0x67D400
    void jfj();  // RVA: 0x67D680
    static void .cctor();  // RVA: 0x67BD20
    ObscuredFileReadResult erk();  // RVA: 0x67C040
    ObscuredFileWriteResult jsr(Byte[][] a);  // RVA: 0x67DA00
    void weq(Stream* a, DeviceLockLevel b);  // RVA: 0x681C50
    ObscuredFileHeader kny(Stream* a);  // RVA: 0x67D6B0
    Il2CppString* jen(Il2CppString* a);  // RVA: 0x67D710
    ObscuredFileReadResult mea();  // RVA: 0x67C000
    void wed(Action* a);  // RVA: 0x680880
    ObscuredFileWriteResult nsg(Byte[][] a);  // RVA: 0x67F5D0
    ObscuredFileReadResult mgq();  // RVA: 0x67DAA0
    void wej();  // RVA: 0x67D680
    bool weg();  // RVA: 0x6809C0
    void .ctor();  // RVA: 0x67BEE0
    void wep(Stream* a);  // RVA: 0x681BE0
    static void wei(Il2CppString* a);  // RVA: 0x6809E0
    ObscuredFileWriteResult ftn(Byte[][] a);  // RVA: 0x67CCB0
    ObscuredFileReadResult mod();  // RVA: 0x67E710
    ObscuredFileHeader ngq(Stream* a);  // RVA: 0x67D6B0
    Il2CppString* weh();  // RVA: 0x6809D0
    ObscuredFileReadResult wem();  // RVA: 0x680A70
    Il2CppString* hfk(Il2CppString* a);  // RVA: 0x67D1B0
    void jpm(Stream* a);  // RVA: 0x67D990
    void hvi();  // RVA: 0x67D680
};

// Namespace: <global>
class dbi
{
public:
    // Static fields
    // static int32_t bmrb;
    // static int32_t bmrc;
    // static Byte[][] bmrd;


    // Methods
    static void wes(Stream* a, Stream* b, dbq* c);  // RVA: 0x682320
    static void hxv(Stream* a, Stream* b, dbq* c);  // RVA: 0x682240
    static uint32_t weu(Stream* a);  // RVA: 0x6820A0
    static uint32_t hyp(Stream* a);  // RVA: 0x6820A0
    static uint32_t mjx(Byte[][] a);  // RVA: 0x682300
    static uint32_t che(Stream* a);  // RVA: 0x682010
    static uint32_t cwi(Stream* a);  // RVA: 0x6820A0
    static void gfa(Stream* a, Stream* b, dbq* c);  // RVA: 0x682170
    static uint32_t gby(Stream* a);  // RVA: 0x6820A0
    static void nio(Stream* a, Stream* b, dbq* c);  // RVA: 0x682320
    static void wet(Stream* a, Stream* b, dbq* c);  // RVA: 0x682240
    static void wfa(Stream* a, Stream* b, dbq* c);  // RVA: 0x682560
    static void cco(Stream* a, Stream* b, dbq* c);  // RVA: 0x681F60
    static void wey(Stream* a, Stream* b, dbq* c);  // RVA: 0x682320
    static uint32_t ehq(Stream* a);  // RVA: 0x6820E0
    static uint32_t obr(Stream* a);  // RVA: 0x6820A0
    static uint32_t hcw(Byte[][] a);  // RVA: 0x682220
    static uint32_t wex(Stream* a);  // RVA: 0x6820A0
    static uint32_t wev(Stream* a);  // RVA: 0x6823D0
    static void wew(Stream* a, uint32_t b);  // RVA: 0x682460
    static uint32_t wez(Byte[][] a);  // RVA: 0x682540
    static void ibk(Stream* a, Stream* b, dbq* c);  // RVA: 0x682240
    static void lwg(Stream* a, Stream* b, dbq* c);  // RVA: 0x682250
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredFileHeader
    {
    public:
        // Static fields
        // static uint8_t HeaderByte1;
        // static uint8_t HeaderByte2;
        // static uint8_t HeaderByte3;
        // static uint8_t HeaderByte4;
        // static uint8_t HeaderVersion;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t <Byte1>k__BackingField; // 0x0010
        uint8_t <Byte2>k__BackingField; // 0x0011
        uint8_t <Byte3>k__BackingField; // 0x0012
        uint8_t <Byte4>k__BackingField; // 0x0013
        uint8_t <Version>k__BackingField; // 0x0014
        ObscurationMode <ObscurationMode>k__BackingField; // 0x0015
    
        // Methods
        uint8_t get_Byte1();  // RVA: 0x66E000
        void set_Byte1(uint8_t value);  // RVA: 0x66E0A0
        uint8_t get_Byte2();  // RVA: 0x66E050
        void set_Byte2(uint8_t value);  // RVA: 0x66E0B0
        uint8_t get_Byte3();  // RVA: 0x66E060
        void set_Byte3(uint8_t value);  // RVA: 0x66E0C0
        uint8_t get_Byte4();  // RVA: 0x66E070
        void set_Byte4(uint8_t value);  // RVA: 0x66E0D0
        uint8_t get_Version();  // RVA: 0x66E090
        void set_Version(uint8_t value);  // RVA: 0x66E0F0
        ObscurationMode get_ObscurationMode();  // RVA: 0x66E080
        void set_ObscurationMode(ObscurationMode value);  // RVA: 0x66E0E0
        bool IsValid();  // RVA: 0x66E020
        void wfb(Stream* a);  // RVA: 0x66E100
        static void wfc(Stream* a, ObscurationMode b);  // RVA: 0x66E1C0
    };

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredFileErrorCode
    {
    public:
        // Static fields
        // static ObscuredFileErrorCode NoError;
        // static ObscuredFileErrorCode FileNotFound;
        // static ObscuredFileErrorCode FileDamaged;
        // static ObscuredFileErrorCode DataIsNotLocked;
        // static ObscuredFileErrorCode NotInitialized;
        // static ObscuredFileErrorCode OtherException;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t value__; // 0x0010
    };

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredFileError
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        ObscuredFileErrorCode <ErrorCode>k__BackingField; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        Exception* <Exception>k__BackingField; // 0x0018
    
        // Methods
        ObscuredFileErrorCode get_ErrorCode();  // RVA: 0x66E000
        Exception* get_Exception();  // RVA: 0x66E010
        void .ctor(ObscuredFileErrorCode code);  // RVA: 0x66DFE0
        void .ctor(Exception* exception);  // RVA: 0x66DFD0
        Il2CppString* ToString();  // RVA: 0x66DEF0
    };

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredFileReadResult
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        Byte[][] <Data>k__BackingField; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        bool <DataIsNotGenuine>k__BackingField; // 0x0018
        bool <DataFromAnotherDevice>k__BackingField; // 0x0019
        uint8_t pad_001A[0x6]; // 0x001A
        ObscuredFileError <Error>k__BackingField; // 0x0020
        uint8_t pad_0021[0xF]; // 0x0021
        bool <IsValid>k__BackingField; // 0x0030
    
        // Methods
        bool wfd();  // RVA: 0x66E5E0
        Byte[][] get_Data();  // RVA: 0x66E5B0
        bool wfe();  // RVA: 0x66E610
        bool get_DataIsNotGenuine();  // RVA: 0x66E5A0
        bool get_DataFromAnotherDevice();  // RVA: 0x66E590
        ObscuredFileError get_Error();  // RVA: 0x66E5C0
        bool get_IsValid();  // RVA: 0x66E5D0
        void .ctor(Byte[][] data, bool dataIsNotGenuine, bool dataFromAnotherDevice);  // RVA: 0x66E540
        void .ctor(ObscuredFileError error);  // RVA: 0x66E4F0
        static ObscuredFileReadResult wff(Exception* a);  // RVA: 0x66E620
        static ObscuredFileReadResult wfg(ObscuredFileErrorCode a);  // RVA: 0x66E6A0
        Il2CppString* ToString();  // RVA: 0x66E280
    };

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredFileWriteResult
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        ObscuredFileError <Error>k__BackingField; // 0x0010
        uint8_t pad_0011[0xF]; // 0x0011
        bool <IsValid>k__BackingField; // 0x0020
    
        // Methods
        bool wfh();  // RVA: 0x66E8C0
        ObscuredFileError get_Error();  // RVA: 0x66E8A0
        bool get_IsValid();  // RVA: 0x66E8B0
        void .ctor(ObscuredFileErrorCode result);  // RVA: 0x66E850
        void .ctor(ObscuredFileError error);  // RVA: 0x66E820
        static ObscuredFileWriteResult wfi(Exception* a);  // RVA: 0x66E8D0
        static ObscuredFileWriteResult wfj(ObscuredFileErrorCode a);  // RVA: 0x66E920
        Il2CppString* ToString();  // RVA: 0x66E720
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbj
{
public:
    // Static fields
    // static Il2CppString* bmre;
    // static Il2CppString* bmrf;
    // static Action* bmrg;
    // static Action* bmrh;
    // static dbh* bmri;
    // static System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> bmrj;
    // static Il2CppObject* bmrk;
    // static bool <bmrl>k__BackingField;
    // static bool <bmrm>k__BackingField;
    // static bool <bmrn>k__BackingField;
    // static ObscuredFileReadResult <bmro>k__BackingField;
    // static ObscuredFileWriteResult <bmrp>k__BackingField;
    // static dbm* <bmrq>k__BackingField;


    // Methods
    static ObscuredBigInteger ivm(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x685C40
    static void wfy(Il2CppString* a, ObscuredShort b);  // RVA: 0x689880
    static dbh* kep(Il2CppString* a, dbr* b);  // RVA: 0x686530
    static ObscuredULong wgy(Il2CppString* a, ObscuredULong b);  // RVA: 0x68AAF0
    static void wik(Il2CppString* a, a b);  // RVA: 0x563E10
    static void wfp(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x6892F0
    static void cil();  // RVA: 0x683230
    static Il2CppString* whr();  // RVA: 0x68B700
    static void gxn(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x6851B0
    static ObscuredDecimal wgm(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x68A170
    static void mzv();  // RVA: 0x687F90
    static void bmu();  // RVA: 0x682B80
    static ObscuredChar nkr(Il2CppString* a, ObscuredChar b);  // RVA: 0x688280
    static void wfx(Il2CppString* a, ObscuredSByte b);  // RVA: 0x689800
    static ObscuredFileWriteResult myf(Byte[][] a);  // RVA: 0x687D70
    static void wge(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x689BD0
    static ObscuredBool wgh(Il2CppString* a, ObscuredBool b);  // RVA: 0x689DC0
    static void wga(Il2CppString* a, ObscuredUInt b);  // RVA: 0x689990
    static void wfk(Il2CppString* a, ObscuredBool b);  // RVA: 0x689010
    static void wfq(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x6893A0
    static void fph(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x6842E0
    static void gld();  // RVA: 0x684DD0
    static void wfm(Il2CppString* a, ObscuredChar b);  // RVA: 0x689120
    static void fri(bool a);  // RVA: 0x684390
    static void wfr(Il2CppString* a, ObscuredDouble b);  // RVA: 0x689450
    static void miz(Il2CppString* a, ObscuredByte b);  // RVA: 0x687790
    static void jhw();  // RVA: 0x685EA0
    static void wgg(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x689D10
    static void wft(Il2CppString* a, ObscuredGuid b);  // RVA: 0x689590
    static void wgf(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x689C60
    static b wil(Il2CppString* a, b b);  // RVA: 0x563E10
    static ObscuredFileWriteResult xw(Byte[][] a);  // RVA: 0x68D680
    static void nre();  // RVA: 0x6883F0
    static void kmg(Il2CppString* a, ObscuredInt b);  // RVA: 0x6866E0
    static ObscuredLong wgs(Il2CppString* a, ObscuredLong b);  // RVA: 0x68A6C0
    static System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> wip();  // RVA: 0x68CC90
    static dbr* whi();  // RVA: 0x68B3E0
    static bool Save();  // RVA: 0x682660
    static void ly(Il2CppString* a, ObscuredULong b);  // RVA: 0x687220
    static ObscuredDateTime gel(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x684AA0
    static void nr(Il2CppString* a, ObscuredGuid b);  // RVA: 0x688340
    static ObscuredBool drv(Il2CppString* a, ObscuredBool b);  // RVA: 0x683820
    static void gjp(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x684D20
    static ObscuredVector2Int whb(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x68AD40
    static ObscuredChar wgj(Il2CppString* a, ObscuredChar b);  // RVA: 0x689F00
    static ObscuredDouble ilv(Il2CppString* a, ObscuredDouble b);  // RVA: 0x685790
    static ObscuredFileWriteResult ceo();  // RVA: 0x683040
    static ObscuredFileWriteResult wiu(Byte[][] a);  // RVA: 0x68D460
    static bool whj();  // RVA: 0x68B430
    static void whh(Action* a);  // RVA: 0x68B2E0
    static void kke(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x686650
    static void wic(Il2CppString* a, dbr* b, bool c);  // RVA: 0x68BD00
    static void wfw(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x689750
    static bool whl();  // RVA: 0x68B4E0
    static bool whm();  // RVA: 0x68B540
    static c wir(Il2CppString* a, c b);  // RVA: 0x563E10
    static void whk(bool a);  // RVA: 0x68B480
    static ObscuredBigInteger itw(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x685B40
    static void whq(bool a);  // RVA: 0x68B6A0
    static void wis(Il2CppString* a, d b);  // RVA: 0x563E10
    static ObscuredFileReadResult whs();  // RVA: 0x68B750
    static ObscuredVector3 whc(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x68AE00
    static void wfv(Il2CppString* a, ObscuredLong b);  // RVA: 0x6896C0
    static void ieu(Il2CppString* a, ObscuredGuid b);  // RVA: 0x6856E0
    static void ebw(Il2CppString* a, ObscuredFloat b);  // RVA: 0x683AA0
    static void whz(bool a);  // RVA: 0x68BB10
    static ObscuredVector3Int ocj(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x688520
    static ObscuredUInt iok(Il2CppString* a, ObscuredUInt b);  // RVA: 0x685870
    static void wfn(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x6891B0
    static void hig(Il2CppString* a, ObscuredULong b);  // RVA: 0x685260
    static ObscuredBigInteger wgn(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x68A270
    static void jsp(Il2CppString* a, ObscuredFloat b);  // RVA: 0x6862D0
    static ObscuredVector2 wha(Il2CppString* a, ObscuredVector2 b);  // RVA: 0x68AC70
    static void kve(Il2CppString* a, ObscuredDouble b);  // RVA: 0x6868C0
    static void byw(Il2CppString* a, ObscuredFloat b);  // RVA: 0x682F10
    static ObscuredVector3 mfe(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x687610
    static bool wig(Il2CppString* a);  // RVA: 0x68C650
    static void wij();  // RVA: 0x68C8A0
    static void iot(Il2CppString* a, ObscuredDouble b);  // RVA: 0x685920
    static void mit(Il2CppString* a, ObscuredSByte b);  // RVA: 0x687710
    static void may(Il2CppString* a, ObscuredInt b);  // RVA: 0x687470
    static ObscuredFileWriteResult hod();  // RVA: 0x6853F0
    static void end(Il2CppString* a, ObscuredDouble b);  // RVA: 0x683FD0
    static ObscuredVector3Int whd(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x68AF00
    static void bx();  // RVA: 0x682EA0
    static ObscuredFileWriteResult wiq();  // RVA: 0x68D090
    static void wfz(Il2CppString* a, ObscuredString* b);  // RVA: 0x689910
    static void wie();  // RVA: 0x68C240
    static void whx(dbm* a);  // RVA: 0x68B990
    static ObscuredDateTimeOffset wgl(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x68A080
    static ObscuredUInt lel(Il2CppString* a, ObscuredUInt b);  // RVA: 0x686A80
    static void krr(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x686810
    static void erk(Il2CppString* a, ObscuredByte b);  // RVA: 0x684070
    static ObscuredVector2Int dat(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x683590
    static ObscuredInt jow(Il2CppString* a, ObscuredInt b);  // RVA: 0x686140
    static void ies(Il2CppString* a, ObscuredInt b);  // RVA: 0x685660
    static void po(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x688EC0
    static ObscuredDecimal hnz(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x6852F0
    static void gan(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x6849F0
    static dbm* whw();  // RVA: 0x68B940
    static void dz(Il2CppString* a, ObscuredChar b);  // RVA: 0x683980
    static ObscuredBool pu(Il2CppString* a, ObscuredBool b);  // RVA: 0x688F50
    static ObscuredDateTime wgk(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x689FC0
    static void eho(Il2CppString* a, bool b);  // RVA: 0x683C30
    static ObscuredByte jzg(Il2CppString* a, ObscuredByte b);  // RVA: 0x686420
    static void who(bool a);  // RVA: 0x68B5F0
    static void wid();  // RVA: 0x68C080
    static dbh* ejs(Il2CppString* a, dbr* b);  // RVA: 0x683EB0
    static void okg(Il2CppString* a, ObscuredGuid b);  // RVA: 0x688850
    static void okx(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x6889B0
    static void whg(Action* a);  // RVA: 0x68B1E0
    static void oro(Il2CppString* a, ObscuredGuid b);  // RVA: 0x688E10
    static void wia(Il2CppString* a, bool b);  // RVA: 0x68BBD0
    static void jfq(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x685D40
    static ObscuredInt wgr(Il2CppString* a, ObscuredInt b);  // RVA: 0x68A610
    static bool etq(Il2CppString* a);  // RVA: 0x6840F0
    static System.Collections.Generic.ICollection<System.String> ctk();  // RVA: 0x683320
    static void jim(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x686090
    static ObscuredUInt wgx(Il2CppString* a, ObscuredUInt b);  // RVA: 0x68AA40
    static void lwf();  // RVA: 0x687030
    static void oke();  // RVA: 0x6887E0
    static bool mqy();  // RVA: 0x687910
    static System.Collections.Generic.ICollection<System.String> lyp();  // RVA: 0x6872B0
    static void wfo(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x689240
    static ObscuredUInt okr(Il2CppString* a, ObscuredUInt b);  // RVA: 0x688900
    static ObscuredFileReadResult wit();  // RVA: 0x68D280
    static void wif(bool a);  // RVA: 0x68C570
    static void jyq(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x686370
    static dbh* why();  // RVA: 0x68BA00
    static void dgw(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x6836E0
    static void lyr(Il2CppString* a, ObscuredByte b);  // RVA: 0x687330
    static ObscuredUShort wgz(Il2CppString* a, ObscuredUShort b);  // RVA: 0x68ABB0
    static ObscuredString* wgw(Il2CppString* a, ObscuredString* b);  // RVA: 0x68A9C0
    static ObscuredGuid mml(Il2CppString* a, ObscuredGuid b);  // RVA: 0x687810
    static void oqu(Il2CppString* a, ObscuredSByte b);  // RVA: 0x688D90
    static ObscuredVector2 iqe(Il2CppString* a, ObscuredVector2 b);  // RVA: 0x6859C0
    static ObscuredVector2Int nsj(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x688460
    static void hxf(Il2CppString* a, ObscuredString* b);  // RVA: 0x6855E0
    static void win();  // RVA: 0x68CBB0
    static void dsq(Il2CppString* a, ObscuredFloat b);  // RVA: 0x6838E0
    static ObscuredDouble wgo(Il2CppString* a, ObscuredDouble b);  // RVA: 0x68A370
    static bool whp();  // RVA: 0x68B650
    static void ccx(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x682FB0
    static void wii(Il2CppString* a);  // RVA: 0x68C750
    static ObscuredDecimal gnb(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x684E40
    static void wgc(Il2CppString* a, ObscuredUShort b);  // RVA: 0x689AA0
    static ObscuredDecimal fuu(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x684550
    static void wgd(Il2CppString* a, ObscuredVector2 b);  // RVA: 0x689B30
    static ObscuredSByte wgu(Il2CppString* a, ObscuredSByte b);  // RVA: 0x68A880
    static void dfm(Il2CppString* a, ObscuredULong b);  // RVA: 0x683650
    static ObscuredDouble jqo(Il2CppString* a, ObscuredDouble b);  // RVA: 0x6861F0
    static void gwt(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x684F40
    static void kqi(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x686760
    static void wgb(Il2CppString* a, ObscuredULong b);  // RVA: 0x689A10
    static ObscuredShort ock(Il2CppString* a, ObscuredShort b);  // RVA: 0x688620
    static void kbx(Il2CppString* a, ObscuredLong b);  // RVA: 0x6864A0
    static ObscuredUInt dpg(Il2CppString* a, ObscuredUInt b);  // RVA: 0x683770
    static ObscuredInt iqh(Il2CppString* a, ObscuredInt b);  // RVA: 0x685A90
    static ObscuredLong gih(Il2CppString* a, ObscuredLong b);  // RVA: 0x684C60
    static dbh* mev(Il2CppString* a, dbr* b);  // RVA: 0x6874F0
    static ObscuredQuaternion fvs(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x684650
    static void fbk(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x684170
    static ObscuredVector3Int nby(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x688180
    static dbh* ldv(Il2CppString* a, dbr* b);  // RVA: 0x686960
    static ObscuredDateTimeOffset efr(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x683B40
    static void jgs(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x685DF0
    static ObscuredFileWriteResult whu();  // RVA: 0x68B850
    static ObscuredVector2Int lzq(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x6873B0
    static void whv(ObscuredFileWriteResult a);  // RVA: 0x68B8C0
    static ObscuredVector2Int brb(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x682C70
    static System.Collections.Generic.ICollection<System.String> wih();  // RVA: 0x68C6D0
    static ObscuredFileReadResult gxc();  // RVA: 0x684FD0
    static ObscuredByte wgi(Il2CppString* a, ObscuredByte b);  // RVA: 0x689E80
    static void buu(Il2CppString* a, ObscuredByte b);  // RVA: 0x682D30
    static ObscuredVector3Int gfv(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x684B60
    static ObscuredQuaternion wgt(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x68A780
    static ObscuredGuid ocx(Il2CppString* a, ObscuredGuid b);  // RVA: 0x6886E0
    static void whf(Action* a);  // RVA: 0x68B0F0
    static void wfs(Il2CppString* a, ObscuredFloat b);  // RVA: 0x6894F0
    static void whe(Action* a);  // RVA: 0x68B000
    static void wfl(Il2CppString* a, ObscuredByte b);  // RVA: 0x6890A0
    static ObscuredShort wgv(Il2CppString* a, ObscuredShort b);  // RVA: 0x68A900
    static ObscuredFloat mse(Il2CppString* a, ObscuredFloat b);  // RVA: 0x687CB0
    static void fh(bool a);  // RVA: 0x684220
    static ObscuredFileWriteResult eih();  // RVA: 0x683CC0
    static void cuv();  // RVA: 0x6833A0
    static System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> lif();  // RVA: 0x686B30
    static void wio();  // RVA: 0x68CC20
    static void clz(Il2CppString* a, ObscuredSByte b);  // RVA: 0x6832A0
    static void wib(dbr* a, bool b);  // RVA: 0x68BC60
    static void .cctor();  // RVA: 0x682A00
    static void eao(Il2CppString* a, ObscuredChar b);  // RVA: 0x683A10
    static ObscuredBool zr(Il2CppString* a, ObscuredBool b);  // RVA: 0x68D8A0
    static ObscuredDateTimeOffset bvu(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x682DB0
    static void wfu(Il2CppString* a, ObscuredInt b);  // RVA: 0x689640
    static ObscuredInt fzf(Il2CppString* a, ObscuredInt b);  // RVA: 0x684940
    static void okz();  // RVA: 0x688A60
    static ObscuredGuid wgq(Il2CppString* a, ObscuredGuid b);  // RVA: 0x68A510
    static ObscuredFloat wgp(Il2CppString* a, ObscuredFloat b);  // RVA: 0x68A450
    static ObscuredGuid lrw(Il2CppString* a, ObscuredGuid b);  // RVA: 0x686F30
    static ObscuredQuaternion bc(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x682A80
    static dbh* wim(Il2CppString* a, dbr* b);  // RVA: 0x68CA90
    static ObscuredFileWriteResult fxk();  // RVA: 0x684750
    static bool bpq(Il2CppString* a);  // RVA: 0x682BF0
    static bool whn();  // RVA: 0x68B5A0
    static ObscuredVector3 fuf(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x684450
    static void wht(ObscuredFileReadResult a);  // RVA: 0x68B7C0
};

// Namespace: <global>
class dbk
{
public:
    // Static fields
    // static bool bmrr;


    // Methods
    static void don(bool a);  // RVA: 0x68DBF0
    static void wiy(bool a);  // RVA: 0x68DF60
    static void wix(bool a);  // RVA: 0x68DF50
    static void wiz(bool a);  // RVA: 0x68DF70
    static bool wiw();  // RVA: 0x68DBD0
    static void wja();  // RVA: 0x68E060
    static bool cly();  // RVA: 0x68DBD0
    static bool glc();  // RVA: 0x68DBD0
    static void bjv();  // RVA: 0x68D960
    static void wiv();  // RVA: 0x68DCE0
};

// Namespace: <global>
class dbl
{
public:

    // Methods
    static Byte[][] jvx(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a, dbm* b);  // RVA: 0x68E260
    static Byte[][] krq(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a, dbm* b);  // RVA: 0x68E2D0
    static Byte[][] wjd(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a, dbm* b);  // RVA: 0x68E3B0
    static ObscuredPrefsData wjb(a a, dbm* b);  // RVA: 0x563E10
    static dbo* wjf(dbm* a);  // RVA: 0x68E1C0
    static dbo* gij(dbm* a);  // RVA: 0x68E1C0
    static dbo* jfu(dbm* a);  // RVA: 0x68E1C0
    static dbo* cxk(dbm* a);  // RVA: 0x68E1C0
    static Byte[][] fwc(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a, dbm* b);  // RVA: 0x68E1F0
    static b wjc(ObscuredPrefsData a, dbm* b);  // RVA: 0x563E10
    static System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> wje(Byte[][] a, dbm* b);  // RVA: 0x68E420
    static Byte[][] kts(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a, dbm* b);  // RVA: 0x68E340
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct ACTkSerializationKind
    {
    public:
        // Static fields
        // static ACTkSerializationKind Binary;
    
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t value__; // 0x0010
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbm
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    ACTkSerializationKind <bmrs>k__BackingField; // 0x0010

    // Methods
    ACTkSerializationKind wjg();  // RVA: 0x66DB40
    void .ctor(ACTkSerializationKind a);  // RVA: 0x67B210
};

// Namespace: <global>
class dbn
{
public:
    // Static fields
    // static uint8_t bmrt;
    // static dbn* bmru;


    // Methods
    Byte[][] wjk(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a);  // RVA: 0x68E750
    System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> wjl(Byte[][] a);  // RVA: 0x68EB40
    static dbo* wjh();  // RVA: 0x68E6C0
    b wjj(ObscuredPrefsData a);  // RVA: 0x563E10
    System.ValueTuple<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> wjn(BinaryReader* a);  // RVA: 0x68EF50
    static dbo* jn();  // RVA: 0x68E630
    void wjm(BinaryWriter* a, Il2CppString* b, ObscuredPrefsData c);  // RVA: 0x68E590
    ObscuredPrefsData wji(a a);  // RVA: 0x563E10
    void .ctor();  // RVA: 0x628380
    void omo(BinaryWriter* a, Il2CppString* b, ObscuredPrefsData c);  // RVA: 0x68E590
    void org(BinaryWriter* a, Il2CppString* b, ObscuredPrefsData c);  // RVA: 0x68E590
    static dbo* dwh();  // RVA: 0x68E500
    void not(BinaryWriter* a, Il2CppString* b, ObscuredPrefsData c);  // RVA: 0x68E590
    void izl(BinaryWriter* a, Il2CppString* b, ObscuredPrefsData c);  // RVA: 0x68E590
};

// Namespace: <global>
class dbo
{
public:

    // Methods
    ObscuredPrefsData wji(a a);  // RVA: 0x563E10
    b wjj(ObscuredPrefsData a);  // RVA: 0x563E10
    Byte[][] wjk(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a);  // RVA: 0x419570
    System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> wjl(Byte[][] a);  // RVA: 0x419570
};

// Namespace: <global>
class dbp
{
public:
    // Static fields
    // static dbp* bmrv;


    // Methods
    Byte[][] wjk(System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> a);  // RVA: 0x68F210
    void .ctor();  // RVA: 0x628380
    static dbo* wjo();  // RVA: 0x68F290
    ObscuredPrefsData wji(a a);  // RVA: 0x563E10
    System.Collections.Generic.Dictionary<System.String,CodeStage.AntiCheat.Storage.ObscuredPrefsData> wjl(Byte[][] a);  // RVA: 0x68F250
    static dbo* oci();  // RVA: 0x68F180
    static dbo* lnj();  // RVA: 0x68F0F0
    static dbo* hze();  // RVA: 0x68F060
    b wjj(ObscuredPrefsData a);  // RVA: 0x563E10
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscurationMode
    {
    public:
        // Static fields
        // static ObscurationMode Plain;
        // static ObscurationMode Encrypted;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t value__; // 0x0010
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbq
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    ObscurationMode <bmrw>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Byte[][] <bmrx>k__BackingField; // 0x0018

    // Methods
    ObscurationMode wjp();  // RVA: 0x66E8B0
    Byte[][] wjq();  // RVA: 0x68F440
    void .ctor(Il2CppString* a);  // RVA: 0x68F320
    void .ctor(Byte[][] a);  // RVA: 0x68F3F0
};

// Namespace: <global>
class dbr
{
public:

    // Methods
    ObscuredFileLocation wjr();  // RVA: 0x421380
    dbq* wjs();  // RVA: 0x41C380
    dbg* wjt();  // RVA: 0x41C380
    bool wju();  // RVA: 0x421380
    bool wjv();  // RVA: 0x421380
};

namespace CodeStage.AntiCheat.Storage
{

    // Namespace: CodeStage.AntiCheat.Storage
    struct ObscuredFileLocation
    {
    public:
        // Static fields
        // static ObscuredFileLocation PersistentData;
        // static ObscuredFileLocation Custom;
    
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t value__; // 0x0010
    };

} // namespace CodeStage.AntiCheat.Storage

// Namespace: <global>
class dbs
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    ObscuredFileLocation <bmry>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    dbq* <bmrz>k__BackingField; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    dbg* <bmsa>k__BackingField; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    bool <bmsb>k__BackingField; // 0x0028
    bool <bmsc>k__BackingField; // 0x0029

    // Methods
    ObscuredFileLocation wjr();  // RVA: 0x66E8B0
    void wjw(ObscuredFileLocation a);  // RVA: 0x67BCF0
    dbq* wjs();  // RVA: 0x68F440
    void wjx(dbq* a);  // RVA: 0x67B580
    dbg* wjt();  // RVA: 0x63C8B0
    void wjy(dbg* a);  // RVA: 0x63C8C0
    bool wju();  // RVA: 0x63C8D0
    void wjz(bool a);  // RVA: 0x63C8E0
    bool wjv();  // RVA: 0x68F730
    void wka(bool a);  // RVA: 0x68F740
    void .ctor();  // RVA: 0x68F450
    void .ctor(ObscuredFileLocation a);  // RVA: 0x68F650
    void .ctor(dbg* a);  // RVA: 0x68F5A0
    void .ctor(dbq* a, dbg* b, ObscuredFileLocation c, bool d, bool e);  // RVA: 0x68F520
};

// Namespace: <global>
class dbt
{
public:
    // Static fields
    // static Char[][] bmsd;
    // static Il2CppString* bmse;
    // static Il2CppString* bmsf;
    // static Il2CppString* bmsg;
    // static uint8_t bmsh;
    // static bool bmsi;
    // static bool bmsj;
    // static Il2CppString* bmsk;
    // static Il2CppString* bmsl;
    // static dbf* bmsm;
    // static Action* bmsn;
    // static Action* bmso;
    // static Action* bmsp;
    // static Action* bmsq;
    // static bool bmsr;
    // static dbg* <bmss>k__BackingField;


    // Methods
    static void igr();  // RVA: 0x693E00
    static Byte[][] lyr(Il2CppString* a, Il2CppString* b);  // RVA: 0x696590
    static void wkh(Il2CppString* a, uint32_t b);  // RVA: 0x699350
    static void ihj(Il2CppString* a, float b);  // RVA: 0x693EA0
    static e wov(Il2CppString* a, e b);  // RVA: 0x563E10
    static ObscuredDouble wmp(Il2CppString* a, ObscuredDouble b);  // RVA: 0x69B8E0
    static void wom();  // RVA: 0x67B8D0
    static ObscuredGuid mmm(Il2CppString* a, ObscuredGuid b);  // RVA: 0x696FD0
    static void hjr();  // RVA: 0x693260
    static void wob(Action* a);  // RVA: 0x69EAD0
    static ObscuredDateTimeOffset kkj(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x6951B0
    static void woq(Il2CppString* a);  // RVA: 0x69F490
    static void jpo();  // RVA: 0x694990
    static Byte[][] wnq(Byte[][] a, int32_t b, Il2CppString* c);  // RVA: 0x69E130
    static void wkp(Il2CppString* a, uint64_t b);  // RVA: 0x699710
    static ObscuredInt wms(Il2CppString* a, ObscuredInt b);  // RVA: 0x69BB80
    static bool dzx(Il2CppString* a, Il2CppString* b);  // RVA: 0x690DD0
    static bool wks(Il2CppString* a, bool b);  // RVA: 0x699860
    static void ncv(Il2CppString* a, ObscuredShort b);  // RVA: 0x697E10
    static void kib(Il2CppString* a, ObscuredChar b);  // RVA: 0x695060
    static void obm(Il2CppString* a, ObscuredByte b);  // RVA: 0x6989A0
    static StorageDataType wnh(Il2CppString* a);  // RVA: 0x69C8B0
    static Vector2 wkx(Il2CppString* a);  // RVA: 0x699C80
    static ObscuredDateTime gxh(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x693010
    static ObscuredShort wmw(Il2CppString* a, ObscuredShort b);  // RVA: 0x69BE70
    static ObscuredVector3Int ixt(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x694120
    static Vector3 wlb(Il2CppString* a, Vector3 b);  // RVA: 0x699F60
    static void wlc(Il2CppString* a, Quaternion b);  // RVA: 0x69A010
    static Il2CppString* kjq(Il2CppString* a);  // RVA: 0x6950F0
    static void wmc(Il2CppString* a, ObscuredULong b);  // RVA: 0x69AF80
    static void wlz(Il2CppString* a, ObscuredShort b);  // RVA: 0x69ADF0
    static void wnv(Il2CppString* a);  // RVA: 0x69E480
    static ObscuredChar fpb(Il2CppString* a, ObscuredChar b);  // RVA: 0x691E30
    static void woe(Action* a);  // RVA: 0x69EDD0
    static void kdd(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x694C00
    static void lun(Il2CppString* a, ObscuredShort b);  // RVA: 0x696390
    static ObscuredChar wmk(Il2CppString* a, ObscuredChar b);  // RVA: 0x69B470
    static ObscuredByte fhb(Il2CppString* a, ObscuredByte b);  // RVA: 0x691BD0
    static Decimal wkm(Il2CppString* a, Decimal defaultValue);  // RVA: 0x699590
    static void dlp();  // RVA: 0x690290
    static ObscuredBigInteger nyr(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x6987C0
    static void wma(Il2CppString* a, ObscuredString* b);  // RVA: 0x69AE80
    static void wmd(Il2CppString* a, ObscuredUShort b);  // RVA: 0x69B010
    static void gna(Il2CppString* a, Il2CppString* b);  // RVA: 0x692330
    static ObscuredGuid htu(Il2CppString* a, ObscuredGuid b);  // RVA: 0x693840
    static ObscuredFloat wmq(Il2CppString* a, ObscuredFloat b);  // RVA: 0x69B9C0
    static void flx(Il2CppString* a, ObscuredULong b);  // RVA: 0x691C50
    static ObscuredVector3Int lna(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x695CD0
    static Quaternion wle(Il2CppString* a, Quaternion b);  // RVA: 0x69A180
    static ObscuredGuid wmr(Il2CppString* a, ObscuredGuid b);  // RVA: 0x69BA80
    static DeviceLockLevel wog();  // RVA: 0x69EF20
    static void iv(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x694090
    static int32_t wkc(Il2CppString* a, int32_t b);  // RVA: 0x699120
    static bool hpz(Il2CppString* a, Il2CppString* b);  // RVA: 0x6933B0
    static void wlr(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x69A910
    static void wme(Il2CppString* a, ObscuredVector2 b);  // RVA: 0x69B0A0
    static void fad(Il2CppString* a, ObscuredLong b);  // RVA: 0x691A40
    static Il2CppString* mwc(Il2CppString* a, Il2CppString* b);  // RVA: 0x697C80
    static int32_t mqq(Il2CppString* a, int32_t b);  // RVA: 0x697800
    static dbf* wnw();  // RVA: 0x69E4E0
    static void kgo(Il2CppString* a, Il2CppString* b);  // RVA: 0x695000
    static void gsv(Il2CppString* a, ObscuredULong b);  // RVA: 0x6929C0
    static Rect wlk(Il2CppString* a, Rect b);  // RVA: 0x69A4E0
    static ObscuredDateTimeOffset wmm(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x69B5F0
    static ObscuredUShort dyv(Il2CppString* a, ObscuredUShort b);  // RVA: 0x690D10
    static Char[][] nyc(Il2CppString* a, Il2CppString* b);  // RVA: 0x698540
    static void wlp(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x69A7B0
    static ObscuredChar dnl(Il2CppString* a, ObscuredChar b);  // RVA: 0x690840
    static ObscuredGuid nnq(Il2CppString* a, ObscuredGuid b);  // RVA: 0x6981E0
    static void wpa();  // RVA: 0x69F7E0
    static Byte[][] lec(Byte[][] a, int32_t b, Char[][] c);  // RVA: 0x695940
    static Il2CppString* kwi(Il2CppString* a);  // RVA: 0x695690
    static void wll(Il2CppString* a, ObscuredBool b);  // RVA: 0x69A580
    static bool woi();  // RVA: 0x69F050
    static void wow(Il2CppString* a, Il2CppString* b);  // RVA: 0x6948B0
    static uint32_t wki(Il2CppString* a, uint32_t b);  // RVA: 0x6993C0
    static int32_t ghr(Il2CppString* a, int32_t b);  // RVA: 0x692040
    static ObscuredBool ifv(Il2CppString* a, ObscuredBool b);  // RVA: 0x693D40
    static ObscuredSByte lcq(Il2CppString* a, ObscuredSByte b);  // RVA: 0x695860
    static void wlu(Il2CppString* a, ObscuredGuid b);  // RVA: 0x69AB00
    static ObscuredVector3 wnd(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x69C370
    static void mde(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x696C70
    static void wol(bool a);  // RVA: 0x69F210
    static Il2CppString* wng(Il2CppString* a);  // RVA: 0x69C7F0
    static void jsj(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x694A20
    static void wnx(Action* a);  // RVA: 0x69E6D0
    static int32_t nwc(Il2CppString* a, int32_t b);  // RVA: 0x6984D0
    static float mt(Il2CppString* a, float b);  // RVA: 0x697AA0
    static void wkb(Il2CppString* a, int32_t b);  // RVA: 0x6990B0
    static void fsf(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x691EF0
    static ObscuredQuaternion wmu(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x69BCF0
    static ObscuredChar lxs(Il2CppString* a, ObscuredChar b);  // RVA: 0x696420
    static void bix(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x68FCD0
    static void wnz(Action* a);  // RVA: 0x69E8D0
    static Vector2 wky(Il2CppString* a, Vector2 b);  // RVA: 0x699D60
    static void jbo(Il2CppString* a, Il2CppString* b);  // RVA: 0x694220
    static ObscuredSByte wmv(Il2CppString* a, ObscuredSByte b);  // RVA: 0x69BDF0
    static ObscuredULong wmz(Il2CppString* a, ObscuredULong b);  // RVA: 0x69C060
    static ObscuredBool wmi(Il2CppString* a, ObscuredBool b);  // RVA: 0x69B330
    static Color32 wlg(Il2CppString* a);  // RVA: 0x69A290
    static void huo(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x693940
    static ObscuredVector2Int wnc(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x69C2B0
    static void wkf(Il2CppString* a, float b);  // RVA: 0x699270
    static void wkr(Il2CppString* a, bool b);  // RVA: 0x6997F0
    static void klr();  // RVA: 0x695360
    static void woc(Action* a);  // RVA: 0x69EBD0
    static void dtd(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x690BE0
    static ObscuredGuid ru(Il2CppString* a, ObscuredGuid b);  // RVA: 0x698E60
    static dbg* wof();  // RVA: 0x69EED0
    static void wlf(Il2CppString* a, Color32 b);  // RVA: 0x69A220
    static ObscuredInt bfv(Il2CppString* a, ObscuredInt b);  // RVA: 0x68FC20
    static void fxs(Il2CppString* a, ObscuredUInt b);  // RVA: 0x691FC0
    static Il2CppString* wnu();  // RVA: 0x69E470
    static void te(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x698F60
    static void wot(Il2CppString* a, c b);  // RVA: 0x563E10
    static void woj(bool a);  // RVA: 0x69F0E0
    static void wor();  // RVA: 0x69F510
    static void hfi(Il2CppString* a, ObscuredFloat b);  // RVA: 0x6930D0
    static bool wop(Il2CppString* a);  // RVA: 0x69F3D0
    static void kpe(Il2CppString* a, Il2CppString* b);  // RVA: 0x6948B0
    static bool htc(Il2CppString* a);  // RVA: 0x693780
    static ObscuredBigInteger wmo(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x69B7E0
    static void Save();  // RVA: 0x68F750
    static Byte[][] ut(Il2CppString* a, Il2CppString* b, uint8_t c, int32_t d);  // RVA: 0x699010
    static d wou(Il2CppString* a, d b);  // RVA: 0x563E10
    static ObscuredBool ezc(Il2CppString* a, ObscuredBool b);  // RVA: 0x691980
    static ObscuredString* wmx(Il2CppString* a, ObscuredString* b);  // RVA: 0x69BF30
    static bool wox(Il2CppString* a, Il2CppString* b);  // RVA: 0x69F660
    static ObscuredDateTime orc(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x698C80
    static void ngz(Il2CppString* a, Il2CppString* b);  // RVA: 0x697FC0
    static void wln(Il2CppString* a, ObscuredChar b);  // RVA: 0x69A690
    static Vector3 wla(Il2CppString* a);  // RVA: 0x699E50
    static void wlo(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x69A720
    static void wmh(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x69B280
    static void wlm(Il2CppString* a, ObscuredByte b);  // RVA: 0x69A610
    static int32_t mrr(Il2CppString* a, int32_t b);  // RVA: 0x697870
    static Byte[][] wnr(Il2CppString* a);  // RVA: 0x69E220
    static Byte[][] wku(Il2CppString* a, uint8_t b, int32_t c);  // RVA: 0x699940
    static Il2CppString* kzk(Il2CppString* a, Il2CppString* b);  // RVA: 0x695750
    static void wmg(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x69B1D0
    static void mvz(Il2CppString* a, float b);  // RVA: 0x697C10
    static Byte[][] dre(Il2CppString* a);  // RVA: 0x690A50
    static void ce(Il2CppString* a, ObscuredULong b);  // RVA: 0x68FFB0
    static Byte[][] dxg(uint8_t a, int32_t b);  // RVA: 0x690C90
    static ObscuredDouble nyz(Il2CppString* a, ObscuredDouble b);  // RVA: 0x6988C0
    static Byte[][] msf(Byte[][] a, int32_t b, Il2CppString* c);  // RVA: 0x6979B0
    static void wos();  // RVA: 0x69F5D0
    static void nj(Il2CppString* a, ObscuredFloat b);  // RVA: 0x698020
    static Byte[][] wnk(Il2CppString* a, Il2CppString* b, uint8_t c, int32_t d);  // RVA: 0x69C950
    static void hus(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x6939F0
    static void wkj(Il2CppString* a, double b);  // RVA: 0x699430
    static void fee(Il2CppString* a, ObscuredString* b);  // RVA: 0x691AD0
    static void mgn(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x696D00
    static ObscuredShort hmb(Il2CppString* a, ObscuredShort b);  // RVA: 0x6932F0
    static void woh(DeviceLockLevel a);  // RVA: 0x69EFB0
    static ObscuredUInt eqa(Il2CppString* a, ObscuredUInt b);  // RVA: 0x6911A0
    static void mqc(Il2CppString* a, ObscuredVector3 b);  // RVA: 0x697750
    static void kug();  // RVA: 0x6955F0
    static bool wok();  // RVA: 0x69F180
    static void won(Il2CppString* a, Il2CppString* b);  // RVA: 0x69F2B0
    static Byte[][] wnm(Il2CppString* a, Il2CppString* b);  // RVA: 0x69CE10
    static void dph(Il2CppString* a, ObscuredDouble b);  // RVA: 0x690900
    static void kaq(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x694B50
    static bool gsm(Il2CppString* a, Il2CppString* b);  // RVA: 0x692530
    static void iai();  // RVA: 0x693B20
    static float wkg(Il2CppString* a, float b);  // RVA: 0x6992E0
    static void jns(Il2CppString* a, Il2CppString* b);  // RVA: 0x6948B0
    static void kah(Il2CppString* a, ObscuredInt b);  // RVA: 0x694AD0
    static void nkb(Il2CppString* a, ObscuredLong b);  // RVA: 0x6980C0
    static void nly(Il2CppString* a, ObscuredLong b);  // RVA: 0x698150
    static void wod(Action* a);  // RVA: 0x69ECD0
    static void onv(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x698A80
    static void cyk(Il2CppString* a, ObscuredBool b);  // RVA: 0x690170
    static Byte[][] lqf(Il2CppString* a);  // RVA: 0x696200
    static void wlq(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x69A860
    static Byte[][] ese(Il2CppString* a, Il2CppString* b);  // RVA: 0x691360
    static void csp();  // RVA: 0x6900D0
    static void dqa(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x6909A0
    static void jcx(Il2CppString* a, ObscuredShort b);  // RVA: 0x694280
    static ObscuredUShort mcn(Il2CppString* a, ObscuredUShort b);  // RVA: 0x696BB0
    static void wmb(Il2CppString* a, ObscuredUInt b);  // RVA: 0x69AF00
    static Il2CppString* mad(Il2CppString* a, Il2CppString* b);  // RVA: 0x691FA0
    static ObscuredDecimal bxb(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x68FD80
    static void fmm(Il2CppString* a, ObscuredUInt b);  // RVA: 0x691CE0
    static Il2CppString* wnt();  // RVA: 0x69E420
    static Il2CppString* wni(Il2CppString* a, a b);  // RVA: 0x563E10
    static bool wnp(Il2CppString* a, Il2CppString* b);  // RVA: 0x69D630
    static Quaternion wld(Il2CppString* a);  // RVA: 0x69A090
    static bool gtg(Il2CppString* a, Il2CppString* b);  // RVA: 0x692A50
    static void wlt(Il2CppString* a, ObscuredFloat b);  // RVA: 0x69AA60
    static void cip(Il2CppString* a, ObscuredLong b);  // RVA: 0x690040
    static void iki(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x693F70
    static ObscuredBigInteger esn(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x691880
    static bool kmh(Il2CppString* a, Il2CppString* b, Il2CppString* c);  // RVA: 0x695400
    static ObscuredSByte erd(Il2CppString* a, ObscuredSByte b);  // RVA: 0x691250
    static ObscuredUShort oog(Il2CppString* a, ObscuredUShort b);  // RVA: 0x698B30
    static Il2CppString* wke(Il2CppString* a, Il2CppString* b);  // RVA: 0x699200
    static ObscuredBool mng(Il2CppString* a, ObscuredBool b);  // RVA: 0x6970D0
    static void wlx(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x69ACC0
    static Byte[][] jdd(Il2CppString* a, Il2CppString* b);  // RVA: 0x694310
    static void wly(Il2CppString* a, ObscuredSByte b);  // RVA: 0x69AD70
    static ObscuredChar mxa(Il2CppString* a, ObscuredChar b);  // RVA: 0x697CF0
    static Char[][] bdn(Il2CppString* a, Il2CppString* b);  // RVA: 0x68F9A0
    static int64_t wko(Il2CppString* a, int64_t b);  // RVA: 0x6996A0
    static Color32 wlh(Il2CppString* a, Color32 b);  // RVA: 0x69A330
    static void djd(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x690200
    static void ksk(Il2CppString* a, ObscuredString* b);  // RVA: 0x6954C0
    static ObscuredVector3Int wne(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x69C470
    static void mig(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x696DB0
    static ObscuredDateTimeOffset hfy(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x693170
    static void wkl(Il2CppString* a, Decimal b);  // RVA: 0x699510
    static Char[][] wnf(Il2CppString* a, Il2CppString* b);  // RVA: 0x69C570
    static ObscuredDecimal eha(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x690FA0
    static void .cctor();  // RVA: 0x68F7F0
    static void bzr();  // RVA: 0x68FEF0
    static void nrd();  // RVA: 0x6982E0
    static ObscuredDecimal mtp(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x697B10
    static void woa(Action* a);  // RVA: 0x69E9D0
    static void wkt(Il2CppString* a, Byte[][] b);  // RVA: 0x6998D0
    static ObscuredBigInteger leh(Il2CppString* a, ObscuredBigInteger b);  // RVA: 0x695A10
    static void lgp(Il2CppString* a, ObscuredDateTimeOffset b);  // RVA: 0x695B10
    static bool oem(Il2CppString* a, Il2CppString* b);  // RVA: 0x698A20
    static void gxd();  // RVA: 0x692EF0
    static Byte[][] moy(Il2CppString* a, Il2CppString* b);  // RVA: 0x697220
    static ObscuredVector3Int ifl(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x693C40
    static ObscuredVector2 wnb(Il2CppString* a, ObscuredVector2 b);  // RVA: 0x69C1E0
    static ObscuredVector2 mru(Il2CppString* a, ObscuredVector2 b);  // RVA: 0x6978E0
    static ObscuredUShort wna(Il2CppString* a, ObscuredUShort b);  // RVA: 0x69C120
    static void osk();  // RVA: 0x698D40
    static ObscuredString* ffx(Il2CppString* a, ObscuredString* b);  // RVA: 0x691B50
    static Byte[][] wkv(uint8_t a, int32_t b);  // RVA: 0x699B90
    static void wkd(Il2CppString* a, Il2CppString* b);  // RVA: 0x699190
    static void wns(Il2CppString* a);  // RVA: 0x69E3B0
    static ObscuredByte wmj(Il2CppString* a, ObscuredByte b);  // RVA: 0x69B3F0
    static bool klk(Il2CppString* a);  // RVA: 0x6952A0
    static void ecm(Il2CppString* a, ObscuredQuaternion b);  // RVA: 0x690E30
    static ObscuredInt lyi(Il2CppString* a, ObscuredInt b);  // RVA: 0x6964E0
    static void lbu(Il2CppString* a, ObscuredDouble b);  // RVA: 0x6957C0
    static bool woo(Il2CppString* a, Il2CppString* b, Il2CppString* c);  // RVA: 0x69F310
    static void wlv(Il2CppString* a, ObscuredInt b);  // RVA: 0x69ABB0
    static bool lcv(Il2CppString* a, Il2CppString* b);  // RVA: 0x6958E0
    static Char[][] gkr(Il2CppString* a, Il2CppString* b);  // RVA: 0x6920B0
    static ObscuredDateTime wml(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x69B530
    static void wlw(Il2CppString* a, ObscuredLong b);  // RVA: 0x69AC30
    static Il2CppString* woy(Il2CppString* a, Il2CppString* b);  // RVA: 0x691FA0
    static void oqb(Il2CppString* a, ObscuredUShort b);  // RVA: 0x698BF0
    static Il2CppString* lnv(Il2CppString* a, Byte[][] b, StorageDataType c);  // RVA: 0x695DD0
    static ObscuredVector3Int eja(Il2CppString* a, ObscuredVector3Int b);  // RVA: 0x6910A0
    static void wls(Il2CppString* a, ObscuredDouble b);  // RVA: 0x69A9C0
    static Il2CppString* wno(Il2CppString* a, Il2CppString* b);  // RVA: 0x69D4B0
    static void jpi(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x694900
    static ObscuredDateTime ecp(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x690EE0
    static void mlw(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x696F20
    static Byte[][] fms(Byte[][] a, int32_t b, Char[][] c);  // RVA: 0x691D60
    static Il2CppString* dnh(Il2CppString* a, Byte[][] b, StorageDataType c);  // RVA: 0x690410
    static void ndj();  // RVA: 0x697EA0
    static b wnj(Il2CppString* a, Il2CppString* b, b c, Il2CppString* d);  // RVA: 0x563E10
    static ObscuredDecimal wmn(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x69B6E0
    static ObscuredByte liz(Il2CppString* a, ObscuredByte b);  // RVA: 0x695C50
    static void wmf(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x69B140
    static void wny(Action* a);  // RVA: 0x69E7D0
    static void wkz(Il2CppString* a, Vector3 b);  // RVA: 0x699DD0
    static Byte[][] gqg(Il2CppString* a);  // RVA: 0x6923A0
    static void ktf(Il2CppString* a, ObscuredGuid b);  // RVA: 0x695540
    static void woz();  // RVA: 0x69F6C0
    static void wli(Il2CppString* a, Rect b);  // RVA: 0x69A3A0
    static Il2CppString* wnl(Il2CppString* a, Byte[][] b, StorageDataType c);  // RVA: 0x69C9F0
    static Byte[][] wnn(Byte[][] a, int32_t b, Char[][] c);  // RVA: 0x69D3E0
    static void gtu(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x692E60
    static void ere(Il2CppString* a, ObscuredVector2Int b);  // RVA: 0x6912D0
    static void inq(Il2CppString* a, ObscuredChar b);  // RVA: 0x694000
    static bool iji(Il2CppString* a, Il2CppString* b);  // RVA: 0x693F10
    static void mzs(Il2CppString* a, Il2CppString* b);  // RVA: 0x697DB0
    static void wkn(Il2CppString* a, int64_t b);  // RVA: 0x699630
    static double wkk(Il2CppString* a, double b);  // RVA: 0x6994A0
    static uint64_t wkq(Il2CppString* a, uint64_t b);  // RVA: 0x699780
    static void wkw(Il2CppString* a, Vector2 b);  // RVA: 0x699C10
    static bool keo(Il2CppString* a, Il2CppString* b);  // RVA: 0x694CB0
    static ObscuredDateTime bbs(Il2CppString* a, ObscuredDateTime b);  // RVA: 0x68F8E0
    static ObscuredLong wmt(Il2CppString* a, ObscuredLong b);  // RVA: 0x69BC30
    static void hxn(Il2CppString* a, ObscuredInt b);  // RVA: 0x693AA0
    static Il2CppString* byg(Il2CppString* a, Il2CppString* b);  // RVA: 0x68FE80
    static Rect wlj(Il2CppString* a);  // RVA: 0x69A420
    static ObscuredUShort mit(Il2CppString* a, ObscuredUShort b);  // RVA: 0x696E60
    static Il2CppString* fvd(Il2CppString* a, Il2CppString* b);  // RVA: 0x691FA0
    static ObscuredShort dmp(Il2CppString* a, ObscuredShort b);  // RVA: 0x690350
    static ObscuredUInt wmy(Il2CppString* a, ObscuredUInt b);  // RVA: 0x69BFB0
    static void mou(Il2CppString* a, ObscuredULong b);  // RVA: 0x697190
    static void lhg(Il2CppString* a, ObscuredShort b);  // RVA: 0x695BC0
    static Byte[][] nuy(Byte[][] a, int32_t b, Char[][] c);  // RVA: 0x698400
    static ObscuredDecimal lzz(Il2CppString* a, ObscuredDecimal b);  // RVA: 0x696AB0
};

// Namespace: <global>
class dbu
{
public:

    // Methods
    int32_t wpb();  // RVA: 0x4203B0
    void wpc();  // RVA: 0x42DF20
};

// Namespace: <global>
class dbv
{
public:
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredBigInteger
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        SerializableBigInteger hiddenValue; // 0x0018
        uint8_t pad_0019[0xF]; // 0x0019
        uint32_t currentCryptoKey; // 0x0028
        uint8_t pad_0029[0x7]; // 0x0029
        BigInteger fakeValue; // 0x0030
    
        // Methods
        static ObscuredBigInteger op_Implicit(BigInteger value);  // RVA: 0x6A1640
        static ObscuredBigInteger op_Implicit(uint8_t value);  // RVA: 0x6A1A10
        static ObscuredBigInteger op_Implicit(int8_t value);  // RVA: 0x6A1830
        static ObscuredBigInteger op_Implicit(int16_t value);  // RVA: 0x6A15B0
        static ObscuredBigInteger op_Implicit(uint16_t value);  // RVA: 0x6A1AA0
        static ObscuredBigInteger op_Implicit(int32_t value);  // RVA: 0x6A1490
        static ObscuredBigInteger op_Implicit(uint32_t value);  // RVA: 0x6A1520
        static ObscuredBigInteger op_Implicit(int64_t value);  // RVA: 0x6A18F0
        static ObscuredBigInteger op_Implicit(uint64_t value);  // RVA: 0x6A17A0
        static ObscuredBigInteger op_Implicit(float value);  // RVA: 0x6A1680
        static ObscuredBigInteger op_Implicit(double value);  // RVA: 0x6A1710
        static ObscuredBigInteger op_Implicit(Decimal value);  // RVA: 0x6A1980
        static BigInteger op_Implicit(ObscuredBigInteger value);  // RVA: 0x6A18C0
        static uint8_t wpd(ObscuredBigInteger a);  // RVA: 0x6A1B90
        static int8_t wpe(ObscuredBigInteger a);  // RVA: 0x6A1C00
        static int16_t wpf(ObscuredBigInteger a);  // RVA: 0x6A1C70
        static uint16_t wpg(ObscuredBigInteger a);  // RVA: 0x6A1CE0
        static int32_t wph(ObscuredBigInteger a);  // RVA: 0x6A1D50
        static uint32_t wpi(ObscuredBigInteger a);  // RVA: 0x6A1DC0
        static int64_t wpj(ObscuredBigInteger a);  // RVA: 0x6A1E30
        static uint64_t wpk(ObscuredBigInteger a);  // RVA: 0x6A1EA0
        static float wpl(ObscuredBigInteger a);  // RVA: 0x6A1F10
        static double wpm(ObscuredBigInteger a);  // RVA: 0x6A1F80
        static Decimal wpn(ObscuredBigInteger a);  // RVA: 0x6A1FF0
        static ObscuredBigInteger wpo(ObscuredBigInteger a, int32_t b);  // RVA: 0x6A2080
        static ObscuredBigInteger wpp(ObscuredBigInteger a, int32_t b);  // RVA: 0x6A2180
        static ObscuredBigInteger wpq(ObscuredBigInteger a);  // RVA: 0x6A2280
        static ObscuredBigInteger wpr(ObscuredBigInteger a);  // RVA: 0x6A2370
        static ObscuredBigInteger wps(ObscuredBigInteger a);  // RVA: 0x6A2460
        static ObscuredBigInteger wpt(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2550
        static ObscuredBigInteger wpu(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2680
        static ObscuredBigInteger wpv(ObscuredBigInteger a);  // RVA: 0x6A27C0
        static ObscuredBigInteger wpw(ObscuredBigInteger a);  // RVA: 0x6A2960
        static bool wpx(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2B00
        static bool wpy(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2BC0
        static bool wpz(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2C80
        static bool wqa(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2D20
        static bool wqb(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2DC0
        static bool wqc(ObscuredBigInteger a, int64_t b);  // RVA: 0x6A2E60
        static bool wqd(ObscuredBigInteger a, uint64_t b);  // RVA: 0x6A2F00
        static bool wqe(ObscuredBigInteger a, uint64_t b);  // RVA: 0x6A2FC0
        static bool wqf(ObscuredBigInteger a, uint64_t b);  // RVA: 0x6A3080
        static bool wqg(ObscuredBigInteger a, uint64_t b);  // RVA: 0x6A3120
        static bool wqh(ObscuredBigInteger a, uint64_t b);  // RVA: 0x6A31C0
        static bool wqi(ObscuredBigInteger a, uint64_t b);  // RVA: 0x6A3260
        static bool wqj(int64_t a, ObscuredBigInteger b);  // RVA: 0x6A3300
        static bool wqk(int64_t a, ObscuredBigInteger b);  // RVA: 0x6A33A0
        static bool wql(int64_t a, ObscuredBigInteger b);  // RVA: 0x6A3440
        static bool wqm(int64_t a, ObscuredBigInteger b);  // RVA: 0x6A34E0
        static bool wqn(int64_t a, ObscuredBigInteger b);  // RVA: 0x6A3580
        static bool wqo(int64_t a, ObscuredBigInteger b);  // RVA: 0x6A3620
        static bool wqp(uint64_t a, ObscuredBigInteger b);  // RVA: 0x6A36C0
        static bool wqq(uint64_t a, ObscuredBigInteger b);  // RVA: 0x6A3760
        static bool wqr(uint64_t a, ObscuredBigInteger b);  // RVA: 0x6A3800
        static bool wqs(uint64_t a, ObscuredBigInteger b);  // RVA: 0x6A38A0
        static bool wqt(uint64_t a, ObscuredBigInteger b);  // RVA: 0x6A3940
        static bool wqu(uint64_t a, ObscuredBigInteger b);  // RVA: 0x6A39E0
        static ObscuredBigInteger wqv(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A3A80
        static ObscuredBigInteger wqw(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A3BC0
        static ObscuredBigInteger wqx(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A3D00
        static ObscuredBigInteger wqy(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A3E40
        static ObscuredBigInteger wqz(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A3F80
        static ObscuredBigInteger wra(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A40C0
        static ObscuredBigInteger wrb(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A4200
        static ObscuredBigInteger wrc(ObscuredBigInteger a, ObscuredBigInteger b);  // RVA: 0x6A4340
        static ObscuredBigInteger wrd(ObscuredBigInteger a, int32_t b);  // RVA: 0x6A4480
        int32_t GetHashCode();  // RVA: 0x6A1110
        Il2CppString* ToString();  // RVA: 0x6A11E0
        Il2CppString* wre(Il2CppString* a);  // RVA: 0x6A4570
        Il2CppString* wrf(IFormatProvider* a);  // RVA: 0x6A45F0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6A1250
        bool Equals(Il2CppObject* other);  // RVA: 0x6A0E50
        bool Equals(BigInteger other);  // RVA: 0x6A0DC0
        bool Equals(ObscuredBigInteger obj);  // RVA: 0x6A0FE0
        int32_t CompareTo(ObscuredBigInteger other);  // RVA: 0x6A0C80
        int32_t CompareTo(BigInteger other);  // RVA: 0x6A0D30
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6A0C00
        int32_t wrg(int64_t a);  // RVA: 0x6A4670
        int32_t wrh(uint64_t a);  // RVA: 0x6A46F0
        Byte[][] wri();  // RVA: 0x6A4770
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6A1180
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(BigInteger value);  // RVA: 0x6A1300
        static BigInteger wrj(BigInteger a, uint32_t b);  // RVA: 0x6A47E0
        static BigInteger wrk(BigInteger a, uint32_t b);  // RVA: 0x6A4940
        static ObscuredBigInteger wrl(BigInteger a, uint32_t b);  // RVA: 0x6A49A0
        static uint32_t wrm();  // RVA: 0x6A4A70
        BigInteger wrn(uint32_t a);  // RVA: 0x6A4A80
        void wro(BigInteger a, uint32_t b);  // RVA: 0x6A4B60
        BigInteger wrp();  // RVA: 0x6A18C0
        void wpc();  // RVA: 0x6A1B40
        static bool wrq(BigInteger a, int32_t b);  // RVA: 0x6A4C20
        void wrr(BigInteger a);  // RVA: 0x6A4C40
        BigInteger wrs();  // RVA: 0x6A4D20
        bool wrt();  // RVA: 0x6A4F40
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct BigIntegerContents
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t sign; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    UInt32[][] bits; // 0x0018

    // Methods
    bool Equals(BigIntegerContents other);  // RVA: 0x6A07F0
    bool Equals(Il2CppObject* obj);  // RVA: 0x6A0870
    int32_t GetHashCode();  // RVA: 0x6A0950
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct SerializableBigInteger
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        BigInteger value; // 0x0010
        BigIntegerContents raw; // 0x0010
    
        // Methods
        SerializableBigInteger wru(uint32_t a);  // RVA: 0x6BF790
        BigInteger wrv(uint32_t a);  // RVA: 0x6BF830
        SerializableBigInteger wrw(uint32_t a);  // RVA: 0x6BF790
        static BigInteger op_Implicit(SerializableBigInteger value);  // RVA: 0x6BF740
        bool Equals(SerializableBigInteger other);  // RVA: 0x6BF5A0
        bool Equals(Il2CppObject* obj);  // RVA: 0x6BF610
        int32_t GetHashCode();  // RVA: 0x6BF6F0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredBool
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        int32_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x3]; // 0x0015
        uint8_t currentCryptoKey; // 0x0018
        bool _fakeValue; // 0x0019
        bool _fakeValueActive; // 0x001A
    
        // Methods
        static ObscuredBool op_Implicit(bool value);  // RVA: 0x6A5460
        static bool op_Implicit(ObscuredBool value);  // RVA: 0x6A54E0
        int32_t GetHashCode();  // RVA: 0x6A5320
        Il2CppString* ToString();  // RVA: 0x6A53B0
        bool Equals(Il2CppObject* other);  // RVA: 0x6A50C0
        bool Equals(ObscuredBool obj);  // RVA: 0x6A52B0
        bool Equals(bool other);  // RVA: 0x6A5260
        int32_t CompareTo(ObscuredBool other);  // RVA: 0x6A4FC0
        int32_t CompareTo(bool other);  // RVA: 0x6A5020
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6A5070
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6A5360
        int32_t wpb();  // RVA: 0x6A1B30
        void wrx(bool a);  // RVA: 0x6A5550
        bool wry();  // RVA: 0x66E590
        void .ctor(bool value);  // RVA: 0x6A53F0
        static int32_t wrz(bool a, uint8_t b);  // RVA: 0x6A5560
        static bool wsa(int32_t a, uint8_t b);  // RVA: 0x6A5580
        static ObscuredBool wsb(int32_t a, uint8_t b);  // RVA: 0x6A55A0
        static uint8_t wsc();  // RVA: 0x6A5610
        int32_t wsd(uint8_t a);  // RVA: 0x6A5620
        void wse(int32_t a, uint8_t b);  // RVA: 0x6A56C0
        bool wsf();  // RVA: 0x6A5720
        void wpc();  // RVA: 0x6A54F0
        static bool wsg(bool a, int32_t b);  // RVA: 0x6A5730
        void wsh(bool a);  // RVA: 0x6A5740
        bool wsi();  // RVA: 0x6A5780
        bool wsj();  // RVA: 0x6A58C0
        static void wsk(uint8_t a);  // RVA: 0x632CB0
        void wsl();  // RVA: 0x632CB0
        static bool wsm(int32_t a, uint8_t b);  // RVA: 0x6A58E0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredByte
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        uint8_t hiddenValue; // 0x0014
        uint8_t currentCryptoKey; // 0x0015
        uint8_t fakeValue; // 0x0016
    
        // Methods
        static ObscuredByte op_Implicit(uint8_t value);  // RVA: 0x6A5CC0
        static uint8_t op_Implicit(ObscuredByte value);  // RVA: 0x6A5D20
        static ObscuredByte wsn(ObscuredByte a);  // RVA: 0x6A5D80
        static ObscuredByte wso(ObscuredByte a);  // RVA: 0x6A5DE0
        static ObscuredByte wsp(ObscuredByte a, int32_t b);  // RVA: 0x6A5E40
        int32_t GetHashCode();  // RVA: 0x6A5B70
        Il2CppString* ToString();  // RVA: 0x6A5BF0
        Il2CppString* wsq(Il2CppString* a);  // RVA: 0x6A5EA0
        Il2CppString* wsr(IFormatProvider* a);  // RVA: 0x6A5ED0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6A5C20
        bool Equals(Il2CppObject* other);  // RVA: 0x6A59C0
        bool Equals(ObscuredByte obj);  // RVA: 0x6A5B10
        bool Equals(uint8_t other);  // RVA: 0x6A5990
        int32_t CompareTo(ObscuredByte other);  // RVA: 0x6A58F0
        int32_t CompareTo(uint8_t other);  // RVA: 0x6A5960
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6A5930
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6A5BA0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(uint8_t value);  // RVA: 0x6A5C60
        static uint8_t wss(uint8_t a, uint8_t b);  // RVA: 0x6A5F00
        static void wst(Byte[][] a, uint8_t b);  // RVA: 0x6A5F10
        static uint8_t wsu(uint8_t a, uint8_t b);  // RVA: 0x6A5F70
        static void wsv(Byte[][] a, uint8_t b);  // RVA: 0x6A5F80
        static ObscuredByte wsw(uint8_t a, uint8_t b);  // RVA: 0x6A5FE0
        static uint8_t wsx();  // RVA: 0x6A5610
        uint8_t wsy(uint8_t a);  // RVA: 0x6A6030
        void wsz(uint8_t a, uint8_t b);  // RVA: 0x6A60B0
        uint8_t wta();  // RVA: 0x6A6100
        void wpc();  // RVA: 0x6A5D40
        static bool wtb(uint8_t a, int32_t b);  // RVA: 0x6A6110
        void wtc(uint8_t a);  // RVA: 0x6A6120
        uint8_t wtd();  // RVA: 0x6A6150
        bool wte();  // RVA: 0x6A6250
        static void wtf(uint8_t a);  // RVA: 0x632CB0
        void wtg();  // RVA: 0x632CB0
        static uint8_t wth(uint8_t a, uint8_t b);  // RVA: 0x6A6270
        static void wti(Byte[][] a, uint8_t b);  // RVA: 0x6A62B0
        static uint8_t wtj(uint8_t a, uint8_t b);  // RVA: 0x6A62F0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredChar
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        wchar_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x1]; // 0x0015
        wchar_t currentCryptoKey; // 0x0016
        uint8_t pad_0017[0x1]; // 0x0017
        wchar_t fakeValue; // 0x0018
    
        // Methods
        static ObscuredChar op_Implicit(wchar_t value);  // RVA: 0x6A6790
        static wchar_t op_Implicit(ObscuredChar value);  // RVA: 0x6A6780
        static ObscuredChar wtk(ObscuredChar a);  // RVA: 0x6A6840
        static ObscuredChar wtl(ObscuredChar a);  // RVA: 0x6A68D0
        static ObscuredChar wtm(ObscuredChar a, int32_t b);  // RVA: 0x6A6960
        int32_t GetHashCode();  // RVA: 0x6A66A0
        Il2CppString* ToString();  // RVA: 0x6A66E0
        Il2CppString* wtn(IFormatProvider* a);  // RVA: 0x6A69E0
        bool Equals(Il2CppObject* other);  // RVA: 0x6A6450
        bool Equals(ObscuredChar other);  // RVA: 0x6A6610
        bool Equals(wchar_t other);  // RVA: 0x6A6400
        int32_t CompareTo(ObscuredChar other);  // RVA: 0x6A6300
        int32_t CompareTo(wchar_t other);  // RVA: 0x6A6360
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6A63B0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(wchar_t value);  // RVA: 0x6A6720
        static wchar_t wto(wchar_t a, wchar_t b);  // RVA: 0x6A6A30
        static wchar_t wtp(wchar_t a, wchar_t b);  // RVA: 0x6A6A40
        static ObscuredChar wtq(wchar_t a, wchar_t b);  // RVA: 0x6A6A50
        static wchar_t wtr();  // RVA: 0x6A6AB0
        wchar_t wts(wchar_t a);  // RVA: 0x6A6AC0
        void wtt(wchar_t a, wchar_t b);  // RVA: 0x6A6B70
        wchar_t wtu();  // RVA: 0x6A6BC0
        void wpc();  // RVA: 0x6A67F0
        static bool wtv(wchar_t a, int32_t b);  // RVA: 0x6A6BD0
        void wtw(wchar_t a);  // RVA: 0x6A6BE0
        wchar_t wtx();  // RVA: 0x6A6C10
        bool wty();  // RVA: 0x6A6D50
        static void wtz(wchar_t a);  // RVA: 0x632CB0
        void wua();  // RVA: 0x632CB0
        static wchar_t wub(wchar_t a, wchar_t b);  // RVA: 0x6A6DA0
        static wchar_t wuc(wchar_t a, wchar_t b);  // RVA: 0x6A6DA0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredDateTime
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        int64_t hiddenValue; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        int64_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        int64_t fakeValue; // 0x0028
    
        // Methods
        int64_t wud();  // RVA: 0x6AB260
        static ObscuredDateTime op_Implicit(DateTime value);  // RVA: 0x6AB180
        static DateTime op_Implicit(ObscuredDateTime value);  // RVA: 0x6AB1B0
        int32_t GetHashCode();  // RVA: 0x6AAD50
        Il2CppString* ToString();  // RVA: 0x6AB030
        Il2CppString* wue(Il2CppString* a);  // RVA: 0x6AB310
        TypeCode GetTypeCode();  // RVA: 0x6AAE00
        bool wuf(IFormatProvider* a);  // RVA: 0x6AB3D0
        wchar_t wug(IFormatProvider* a);  // RVA: 0x6AB410
        int8_t wuh(IFormatProvider* a);  // RVA: 0x6AB450
        uint8_t wui(IFormatProvider* a);  // RVA: 0x6AB490
        int16_t wuj(IFormatProvider* a);  // RVA: 0x6AB4D0
        uint16_t wuk(IFormatProvider* a);  // RVA: 0x6AB510
        int32_t wul(IFormatProvider* a);  // RVA: 0x6AB550
        uint32_t wum(IFormatProvider* a);  // RVA: 0x6AB590
        int64_t wun(IFormatProvider* a);  // RVA: 0x6AB5D0
        uint64_t wuo(IFormatProvider* a);  // RVA: 0x6AB610
        float wup(IFormatProvider* a);  // RVA: 0x6AB650
        double wuq(IFormatProvider* a);  // RVA: 0x6AB690
        Decimal wur(IFormatProvider* a);  // RVA: 0x6AB6D0
        DateTime wus(IFormatProvider* a);  // RVA: 0x6AB710
        Il2CppObject* wut(Type* a, IFormatProvider* b);  // RVA: 0x6AB780
        Il2CppString* ToString(IFormatProvider* provider);  // RVA: 0x6AAEA0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6AAF60
        bool Equals(Il2CppObject* other);  // RVA: 0x6AAB30
        bool Equals(ObscuredDateTime other);  // RVA: 0x6AAAD0
        bool Equals(DateTime other);  // RVA: 0x6AAC90
        int32_t CompareTo(ObscuredDateTime other);  // RVA: 0x6AA910
        int32_t CompareTo(DateTime other);  // RVA: 0x6AA850
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6AAA10
        static DateTime wuu(ObscuredDateTime a, TimeSpan b);  // RVA: 0x6AB980
        static DateTime wuv(ObscuredDateTime a, TimeSpan b);  // RVA: 0x6ABA40
        static TimeSpan wuw(ObscuredDateTime a, DateTime b);  // RVA: 0x6ABB00
        static TimeSpan wux(DateTime a, ObscuredDateTime b);  // RVA: 0x6ABBC0
        static bool wuy(ObscuredDateTime a, DateTime b);  // RVA: 0x6ABC80
        static bool wuz(DateTime a, ObscuredDateTime b);  // RVA: 0x6ABD40
        static bool wva(ObscuredDateTime a, DateTime b);  // RVA: 0x6ABE00
        static bool wvb(DateTime a, ObscuredDateTime b);  // RVA: 0x6ABEC0
        static bool wvc(ObscuredDateTime a, DateTime b);  // RVA: 0x6ABF80
        static bool wvd(DateTime a, ObscuredDateTime b);  // RVA: 0x6AC040
        static bool wve(ObscuredDateTime a, DateTime b);  // RVA: 0x6AC100
        static bool wvf(DateTime a, ObscuredDateTime b);  // RVA: 0x6AC1C0
        static bool wvg(ObscuredDateTime a, DateTime b);  // RVA: 0x6AC280
        static bool wvh(DateTime a, ObscuredDateTime b);  // RVA: 0x6AC340
        static bool wvi(ObscuredDateTime a, DateTime b);  // RVA: 0x6AC400
        static bool wvj(DateTime a, ObscuredDateTime b);  // RVA: 0x6AC4C0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6AAE10
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(DateTime value);  // RVA: 0x6AB0E0
        static int64_t wvk(DateTime a, int64_t b);  // RVA: 0x6AC580
        static DateTime wvl(int64_t a, int64_t b);  // RVA: 0x6AC5E0
        static ObscuredDateTime wvm(int64_t a, int64_t b);  // RVA: 0x6AC6D0
        static int64_t wvn();  // RVA: 0x6AA2B0
        int64_t wvo(int64_t a);  // RVA: 0x6AC700
        void wvp(int64_t a, int64_t b);  // RVA: 0x6AC800
        DateTime wvq();  // RVA: 0x6AC8B0
        void wpc();  // RVA: 0x6AB210
        static bool wvr(DateTime a, int32_t b);  // RVA: 0x6AC910
        static bool wvs(int64_t a, int32_t b);  // RVA: 0x6AA5A0
        void wvt(int64_t a);  // RVA: 0x6AA5B0
        static int64_t wvu(int64_t a, int64_t b);  // RVA: 0x6AA5E0
        static int64_t wvv(int64_t a, int64_t b);  // RVA: 0x6AA5F0
        DateTime wvw();  // RVA: 0x6AB1B0
        int64_t wvx();  // RVA: 0x6AC970
        bool wvy();  // RVA: 0x6AA830
        static DateTime wvz(int64_t a, int64_t b);  // RVA: 0x6ACB00
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredDateTimeOffset
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        int64_t hiddenValue; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        int64_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        int64_t fakeValue; // 0x0028
    
        // Methods
        int64_t wwa();  // RVA: 0x6A7950
        DateTime wwb();  // RVA: 0x6A7A20
        DateTime wwc();  // RVA: 0x6A7AF0
        int32_t wwd();  // RVA: 0x6A7BC0
        DayOfWeek wwe();  // RVA: 0x6A7C90
        int32_t wwf();  // RVA: 0x6A7D60
        int32_t wwg();  // RVA: 0x6A7E30
        int32_t wwh();  // RVA: 0x6A7F00
        int32_t wwi();  // RVA: 0x6A7FD0
        int32_t wwj();  // RVA: 0x6A80A0
        TimeSpan wwk();  // RVA: 0x6A8170
        int32_t wwl();  // RVA: 0x6A8240
        TimeSpan wwm();  // RVA: 0x6A8310
        DateTime wwn();  // RVA: 0x6A83E0
        int32_t wwo();  // RVA: 0x6A84B0
        static ObscuredDateTimeOffset op_Implicit(DateTimeOffset value);  // RVA: 0x6A77B0
        static DateTimeOffset op_Implicit(ObscuredDateTimeOffset value);  // RVA: 0x6A7860
        int32_t GetHashCode();  // RVA: 0x6A73D0
        Il2CppString* ToString();  // RVA: 0x6A7640
        Il2CppString* wwp(Il2CppString* a);  // RVA: 0x6A8580
        Il2CppString* wwq(IFormatProvider* a);  // RVA: 0x6A8660
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6A7550
        bool Equals(Il2CppObject* other);  // RVA: 0x6A7210
        bool Equals(ObscuredDateTimeOffset other);  // RVA: 0x6A7370
        bool Equals(DateTimeOffset other);  // RVA: 0x6A7120
        int32_t CompareTo(ObscuredDateTimeOffset other);  // RVA: 0x6A6EA0
        int32_t CompareTo(DateTimeOffset other);  // RVA: 0x6A6DB0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6A7000
        static DateTimeOffset wwr(ObscuredDateTimeOffset a, TimeSpan b);  // RVA: 0x6A8740
        static DateTimeOffset wws(ObscuredDateTimeOffset a, TimeSpan b);  // RVA: 0x6A8840
        static TimeSpan wwt(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A8940
        static TimeSpan wwu(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A8A30
        static TimeSpan wwv(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A8B20
        static bool www(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A8CA0
        static bool wwx(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A8D90
        static bool wwy(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A8E80
        static bool wwz(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A9000
        static bool wxa(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A90F0
        static bool wxb(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A91E0
        static bool wxc(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A9360
        static bool wxd(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A9450
        static bool wxe(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A9540
        static bool wxf(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A96C0
        static bool wxg(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A97B0
        static bool wxh(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A98A0
        static bool wxi(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A9A20
        static bool wxj(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A9B10
        static bool wxk(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A9C00
        static bool wxl(ObscuredDateTimeOffset a, DateTimeOffset b);  // RVA: 0x6A9D80
        static bool wxm(DateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A9E70
        static bool wxn(ObscuredDateTimeOffset a, ObscuredDateTimeOffset b);  // RVA: 0x6A9F60
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6A74A0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(DateTimeOffset value);  // RVA: 0x6A7710
        static int64_t wxo(DateTimeOffset a, int64_t b);  // RVA: 0x6AA0E0
        static DateTimeOffset wxp(int64_t a, int64_t b);  // RVA: 0x6AA140
        static ObscuredDateTimeOffset wxq(int64_t a, int64_t b);  // RVA: 0x6AA280
        static int64_t wxr();  // RVA: 0x6AA2B0
        int64_t wxs(int64_t a);  // RVA: 0x6AA2C0
        void wxt(int64_t a, int64_t b);  // RVA: 0x6AA3D0
        DateTimeOffset wxu();  // RVA: 0x6AA4A0
        void wpc();  // RVA: 0x6A7900
        static bool wxv(DateTimeOffset a, int32_t b);  // RVA: 0x6AA530
        static bool wxw(int64_t a, int32_t b);  // RVA: 0x6AA5A0
        void wxx(int64_t a);  // RVA: 0x6AA5B0
        static int64_t wxy(int64_t a, int64_t b);  // RVA: 0x6AA5E0
        static int64_t wxz(int64_t a, int64_t b);  // RVA: 0x6AA5F0
        DateTimeOffset wya();  // RVA: 0x6AA600
        int64_t wyb();  // RVA: 0x6AA690
        bool wyc();  // RVA: 0x6AA830
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredDecimal
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        ACTkByte16 hiddenValue; // 0x0014
        uint8_t pad_0015[0x13]; // 0x0015
        int64_t currentCryptoKey; // 0x0028
        uint8_t pad_0029[0x7]; // 0x0029
        Decimal fakeValue; // 0x0030
    
        // Methods
        static ObscuredDecimal op_Implicit(Decimal value);  // RVA: 0x6AD330
        static Decimal op_Implicit(ObscuredDecimal value);  // RVA: 0x6AD370
        static ObscuredDecimal wyd(ObscuredFloat a);  // RVA: 0x6AD410
        static ObscuredDecimal wye(ObscuredDecimal a);  // RVA: 0x6AD560
        static ObscuredDecimal wyf(ObscuredDecimal a);  // RVA: 0x6AD6D0
        static ObscuredDecimal wyg(ObscuredDecimal a, Decimal b);  // RVA: 0x6AD840
        int32_t GetHashCode();  // RVA: 0x6AD070
        Il2CppString* ToString();  // RVA: 0x6AD160
        Il2CppString* wyh(Il2CppString* a);  // RVA: 0x6AD940
        Il2CppString* wyi(IFormatProvider* a);  // RVA: 0x6AD9C0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6AD1D0
        bool Equals(Il2CppObject* other);  // RVA: 0x6ACD50
        bool Equals(ObscuredDecimal other);  // RVA: 0x6ACEE0
        bool Equals(Decimal other);  // RVA: 0x6ACFE0
        int32_t CompareTo(ObscuredDecimal other);  // RVA: 0x6ACB90
        int32_t CompareTo(Decimal other);  // RVA: 0x6ACCC0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6ACC40
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6AD0E0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Decimal value);  // RVA: 0x6AD260
        static Decimal wyj(Decimal a, int64_t b);  // RVA: 0x6A09A0
        static Decimal wyk(Decimal a, int64_t b);  // RVA: 0x6A09A0
        static ObscuredDecimal wyl(Decimal a, int64_t b);  // RVA: 0x6ADA40
        static int64_t wym();  // RVA: 0x6AA2B0
        Decimal wyn(int64_t a);  // RVA: 0x6ADAC0
        void wyo(Decimal a, int64_t b);  // RVA: 0x6ADC40
        Decimal wyp();  // RVA: 0x6AD370
        void wpc();  // RVA: 0x6AD3A0
        static bool wyq(Decimal a, int32_t b);  // RVA: 0x6ADCB0
        void wyr(Decimal a);  // RVA: 0x6ADCD0
        static ACTkByte16 wys(Decimal a, int64_t b);  // RVA: 0x6A09A0
        Decimal wyt();  // RVA: 0x6ADD20
        bool wyu();  // RVA: 0x6AE020
        static void wyv(int64_t a);  // RVA: 0x632CB0
        void wyw();  // RVA: 0x632CB0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct DecimalLongBytesUnion
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        Decimal d; // 0x0010
        int64_t l1; // 0x0010
        ACTkByte16 b16; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        int64_t l2; // 0x0018
    
        // Methods
        static Decimal wyx(Decimal a, int64_t b);  // RVA: 0x6A09A0
        static ACTkByte16 wyy(Decimal a, int64_t b);  // RVA: 0x6A09A0
        static Decimal wyz(ACTkByte16 a, int64_t b);  // RVA: 0x6A09A0
        static Decimal wza(ACTkByte16 a);  // RVA: 0x66E8A0
        static ACTkByte16 wzb(Decimal a);  // RVA: 0x66E8A0
        static DecimalLongBytesUnion wzc(Decimal a);  // RVA: 0x66E8A0
        static DecimalLongBytesUnion wzd(ACTkByte16 a);  // RVA: 0x66E8A0
        DecimalLongBytesUnion wze(int64_t a);  // RVA: 0x6A09D0
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct DoubleLongBytesUnion
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    double d; // 0x0010
    int64_t l; // 0x0010
    ACTkByte8 b8; // 0x0010

    // Methods
    static int64_t wzf(int64_t a, uint8_t b, uint8_t c);  // RVA: 0x6A09F0
    static int64_t wzg(double a, int64_t b);  // RVA: 0x6A0A30
    static double wzh(int64_t a, int64_t b);  // RVA: 0x6A0A60
    static DoubleLongBytesUnion wzi(double a);  // RVA: 0x6A0A90
    static DoubleLongBytesUnion wzj(int64_t a);  // RVA: 0x6A0AA0
    DoubleLongBytesUnion wzk(int64_t a);  // RVA: 0x6A0AB0
    DoubleLongBytesUnion wzl(int64_t a);  // RVA: 0x6A0AD0
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredDouble
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        int64_t hiddenValue; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        int64_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        double fakeValue; // 0x0028
        uint8_t pad_0029[0x7]; // 0x0029
        ACTkByte8 hiddenValueOldByte8; // 0x0030
    
        // Methods
        static ObscuredDouble op_Implicit(double value);  // RVA: 0x6AE550
        static double op_Implicit(ObscuredDouble value);  // RVA: 0x6AE540
        static ObscuredDouble wzm(ObscuredFloat a);  // RVA: 0x6AE5E0
        static ObscuredDouble wzn(ObscuredDouble a);  // RVA: 0x6AE6A0
        static ObscuredDouble wzo(ObscuredDouble a);  // RVA: 0x6AE760
        static ObscuredDouble wzp(ObscuredDouble a, double b);  // RVA: 0x6AE820
        int32_t GetHashCode();  // RVA: 0x6AE380
        Il2CppString* ToString();  // RVA: 0x6AE490
        Il2CppString* wzq(Il2CppString* a);  // RVA: 0x6AE8D0
        Il2CppString* wzr(IFormatProvider* a);  // RVA: 0x6AE910
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6AE440
        bool Equals(Il2CppObject* other);  // RVA: 0x6AE130
        bool Equals(ObscuredDouble other);  // RVA: 0x6AE2E0
        bool Equals(double other);  // RVA: 0x6AE340
        int32_t CompareTo(ObscuredDouble other);  // RVA: 0x6AE0F0
        int32_t CompareTo(double other);  // RVA: 0x6AE070
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6AE0B0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6AE3D0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(double value);  // RVA: 0x6AE4C0
        static int64_t wzs(double a, int64_t b);  // RVA: 0x6A0A30
        static double wzt(int64_t a, int64_t b);  // RVA: 0x6A0A60
        static int64_t wzu(int64_t a, uint8_t b, uint8_t c);  // RVA: 0x6A09F0
        static ObscuredDouble wzv(int64_t a, int64_t b);  // RVA: 0x6AE950
        static int64_t wzw();  // RVA: 0x6AA2B0
        int64_t wzx(int64_t a);  // RVA: 0x6AE9E0
        void wzy(int64_t a, int64_t b);  // RVA: 0x6AEAA0
        double wzz();  // RVA: 0x6AEB20
        void wpc();  // RVA: 0x6AE580
        static bool xaa(double a, int32_t b);  // RVA: 0x6AEB30
        void xab(double a);  // RVA: 0x6AEB40
        static bool xac(double a, double b);  // RVA: 0x6AEBA0
        double xad();  // RVA: 0x6AEC60
        bool xae();  // RVA: 0x6AA830
        static void xaf(int64_t a);  // RVA: 0x632CB0
        void xag();  // RVA: 0x632CB0
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct FloatIntBytesUnion
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    float f; // 0x0010
    int32_t i; // 0x0010
    ACTkByte4 b4; // 0x0010

    // Methods
    static int32_t xah(int32_t a, uint8_t b, uint8_t c);  // RVA: 0x6A0B00
    static int32_t xai(float a, int32_t b);  // RVA: 0x6A0B30
    static float xaj(int32_t a, int32_t b);  // RVA: 0x6A0B60
    static FloatIntBytesUnion xak(float a);  // RVA: 0x6A0B90
    static FloatIntBytesUnion xal(int32_t a);  // RVA: 0x6A0BA0
    FloatIntBytesUnion xam(int32_t a);  // RVA: 0x6A0BB0
    FloatIntBytesUnion xan(int32_t a);  // RVA: 0x6A0BD0
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredFloat
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        int32_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x3]; // 0x0015
        int32_t currentCryptoKey; // 0x0018
        uint8_t pad_0019[0x3]; // 0x0019
        float fakeValue; // 0x001C
        uint8_t pad_001D[0x3]; // 0x001D
        ACTkByte4 hiddenValueOldByte4; // 0x0020
    
        // Methods
        static ObscuredFloat op_Implicit(float value);  // RVA: 0x6AF320
        static float op_Implicit(ObscuredFloat value);  // RVA: 0x6AF310
        static ObscuredFloat xao(ObscuredFloat a);  // RVA: 0x6AF3B0
        static ObscuredFloat xap(ObscuredFloat a);  // RVA: 0x6AF450
        static ObscuredFloat xaq(ObscuredFloat a, int32_t b);  // RVA: 0x6AF4F0
        int32_t GetHashCode();  // RVA: 0x6AF180
        Il2CppString* ToString();  // RVA: 0x6AF260
        Il2CppString* xar(Il2CppString* a);  // RVA: 0x6AF590
        Il2CppString* xas(IFormatProvider* a);  // RVA: 0x6AF5D0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6AF210
        bool Equals(Il2CppObject* other);  // RVA: 0x6AEF70
        bool Equals(ObscuredFloat other);  // RVA: 0x6AF120
        bool Equals(float other);  // RVA: 0x6AF0E0
        int32_t CompareTo(ObscuredFloat other);  // RVA: 0x6AEF30
        int32_t CompareTo(float other);  // RVA: 0x6AEEF0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6AEEB0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6AF1B0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(float value);  // RVA: 0x6AF290
        static int32_t xat(float a, int32_t b);  // RVA: 0x6A0B30
        static float xau(int32_t a, int32_t b);  // RVA: 0x6A0B60
        static ObscuredFloat xav(int32_t a, int32_t b);  // RVA: 0x6AF610
        static int32_t xaw();  // RVA: 0x6A4A70
        int32_t xax(int32_t a);  // RVA: 0x6AF690
        void xay(int32_t a, int32_t b);  // RVA: 0x6AF730
        float xaz();  // RVA: 0x6AF7A0
        void wpc();  // RVA: 0x6AF350
        static bool xba(float a, int32_t b);  // RVA: 0x6AF7B0
        void xbb(float a);  // RVA: 0x6AF7C0
        static bool xbc(float a, float b);  // RVA: 0x6AF810
        float xbd();  // RVA: 0x6AF8D0
        bool xbe();  // RVA: 0x6AFAD0
        static void xbf(int32_t a);  // RVA: 0x632CB0
        void xbg();  // RVA: 0x632CB0
        static int32_t xbh(int32_t a, uint8_t b, uint8_t c);  // RVA: 0x6A0B00
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredGuid
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        int64_t hiddenValue1; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        int64_t hiddenValue2; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        int64_t currentCryptoKey; // 0x0028
        uint8_t pad_0029[0x7]; // 0x0029
        Guid fakeValue; // 0x0030
    
        // Methods
        static ObscuredGuid op_Implicit(Guid value);  // RVA: 0x6B0070
        static Guid op_Implicit(ObscuredGuid value);  // RVA: 0x6B0040
        int32_t GetHashCode();  // RVA: 0x6AFE30
        Il2CppString* ToString();  // RVA: 0x6AFF30
        Il2CppString* xbi(Il2CppString* a);  // RVA: 0x6B0180
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6AFEE0
        bool Equals(Il2CppObject* other);  // RVA: 0x6AFCE0
        bool Equals(ObscuredGuid other);  // RVA: 0x6AFC30
        bool Equals(Guid other);  // RVA: 0x6AFBE0
        int32_t CompareTo(ObscuredGuid other);  // RVA: 0x6AFB80
        int32_t CompareTo(Guid other);  // RVA: 0x6AFAF0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6AFB40
        static bool xbj(ObscuredGuid a, Guid b);  // RVA: 0x6B01C0
        static bool xbk(Guid a, ObscuredGuid b);  // RVA: 0x6B0220
        static bool xbl(ObscuredGuid a, ObscuredGuid b);  // RVA: 0x6B0280
        static bool xbm(ObscuredGuid a, Guid b);  // RVA: 0x6B0320
        static bool xbn(Guid a, ObscuredGuid b);  // RVA: 0x6B0380
        static bool xbo(ObscuredGuid a, ObscuredGuid b);  // RVA: 0x6B03E0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6AFE70
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Guid value);  // RVA: 0x6AFF70
        static void xbp(Guid a, int64_t b, int64_t c, int64_t d);  // RVA: 0x6B0480
        static Guid xbq(int64_t a, int64_t b, int64_t c);  // RVA: 0x6B0500
        static ObscuredGuid xbr(int64_t a, int64_t b, int64_t c);  // RVA: 0x6B06F0
        static int64_t xbs();  // RVA: 0x6AA2B0
        static int32_t xbt(int64_t a, int64_t b);  // RVA: 0x6B0720
        void xbu(int64_t a, int64_t b, int64_t c);  // RVA: 0x6B0760
        void xbv(int64_t a, int64_t b, int64_t c);  // RVA: 0x6B08C0
        Guid xbw();  // RVA: 0x6B0040
        void wpc();  // RVA: 0x6B00B0
        static bool xbx(Guid a, int32_t b);  // RVA: 0x6B0980
        static bool xby(System.ReadOnlySpan<System.Byte> a, int32_t b);  // RVA: 0x6B0A40
        void xbz(Guid a);  // RVA: 0x6B0B30
        static int64_t xca(int64_t a, int64_t b);  // RVA: 0x6AA5E0
        static int64_t xcb(int64_t a, int64_t b);  // RVA: 0x6AA5F0
        Guid xcc();  // RVA: 0x6B0BD0
        static bool xcd(Byte[][] a, Byte[][] b);  // RVA: 0x6B0F60
        bool xce();  // RVA: 0x6B0FD0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredInt
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        int32_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x3]; // 0x0015
        int32_t currentCryptoKey; // 0x0018
        uint8_t pad_0019[0x3]; // 0x0019
        int32_t fakeValue; // 0x001C
    
        // Methods
        static ObscuredInt op_Implicit(int32_t value);  // RVA: 0x6B14D0
        static int32_t op_Implicit(ObscuredInt value);  // RVA: 0x6B15E0
        static ObscuredFloat op_Implicit(ObscuredInt value);  // RVA: 0x6B1430
        static ObscuredDouble op_Implicit(ObscuredInt value);  // RVA: 0x6B1530
        static ObscuredUInt op_Explicit(ObscuredInt value);  // RVA: 0x6B13C0
        static ObscuredInt xcf(ObscuredInt a);  // RVA: 0x6B1630
        static ObscuredInt xcg(ObscuredInt a);  // RVA: 0x6B16A0
        static ObscuredInt xch(ObscuredInt a, int32_t b);  // RVA: 0x6B1710
        int32_t GetHashCode();  // RVA: 0x6B1270
        Il2CppString* ToString();  // RVA: 0x6B1340
        Il2CppString* xci(Il2CppString* a);  // RVA: 0x6B1780
        Il2CppString* xcj(IFormatProvider* a);  // RVA: 0x6B17C0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B12F0
        bool Equals(Il2CppObject* other);  // RVA: 0x6B10D0
        bool Equals(ObscuredInt other);  // RVA: 0x6B1210
        bool Equals(int32_t other);  // RVA: 0x6B10A0
        int32_t CompareTo(ObscuredInt other);  // RVA: 0x6B1060
        int32_t CompareTo(int32_t other);  // RVA: 0x6B0FF0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B1020
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B12A0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(int32_t value);  // RVA: 0x6B1370
        static int32_t xck(int32_t a, int32_t b);  // RVA: 0x6B1800
        static int32_t xcl(int32_t a, int32_t b);  // RVA: 0x6B1810
        static ObscuredInt xcm(int32_t a, int32_t b);  // RVA: 0x6B1820
        static int32_t xcn();  // RVA: 0x6A4A70
        int32_t xco(int32_t a);  // RVA: 0x6B1870
        void xcp(int32_t a, int32_t b);  // RVA: 0x6B18E0
        int32_t xcq();  // RVA: 0x6B1920
        void wpc();  // RVA: 0x6B15F0
        static bool xcr(int32_t a, int32_t b);  // RVA: 0x6B1930
        void xcs(int32_t a);  // RVA: 0x6B1940
        int32_t xct();  // RVA: 0x6B1970
        bool xcu();  // RVA: 0x6AFAD0
        static void xcv(int32_t a);  // RVA: 0x632CB0
        void xcw();  // RVA: 0x632CB0
        static int32_t xcx(int32_t a, int32_t b);  // RVA: 0x6B1A60
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredLong
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        int64_t hiddenValue; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        int64_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        int64_t fakeValue; // 0x0028
    
        // Methods
        static ObscuredLong op_Implicit(int64_t value);  // RVA: 0x6B1E80
        static int64_t op_Implicit(ObscuredLong value);  // RVA: 0x6B1EE0
        static ObscuredLong xcy(ObscuredLong a);  // RVA: 0x6B1F30
        static ObscuredLong xcz(ObscuredLong a);  // RVA: 0x6B1FC0
        static ObscuredLong xda(ObscuredLong a, int32_t b);  // RVA: 0x6B2050
        int32_t GetHashCode();  // RVA: 0x6B1D20
        Il2CppString* ToString();  // RVA: 0x6B1DA0
        Il2CppString* xdb(Il2CppString* a);  // RVA: 0x6B20C0
        Il2CppString* xdc(IFormatProvider* a);  // RVA: 0x6B2100
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B1DD0
        bool Equals(Il2CppObject* other);  // RVA: 0x6B1BD0
        bool Equals(ObscuredLong other);  // RVA: 0x6B1B30
        bool Equals(int64_t other);  // RVA: 0x6B1B90
        int32_t CompareTo(ObscuredLong other);  // RVA: 0x6B1AB0
        int32_t CompareTo(int64_t other);  // RVA: 0x6B1AF0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B1A70
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B1D50
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(int64_t value);  // RVA: 0x6B1E20
        static int64_t xdd(int64_t a, int64_t b);  // RVA: 0x6AA5E0
        static int64_t xde(int64_t a, int64_t b);  // RVA: 0x6AA5F0
        static ObscuredLong xdf(int64_t a, int64_t b);  // RVA: 0x6B2140
        static int64_t xdg();  // RVA: 0x6AA2B0
        int64_t xdh(int64_t a);  // RVA: 0x6B2190
        void xdi(int64_t a, int64_t b);  // RVA: 0x6B2220
        int64_t xdj();  // RVA: 0x6B2270
        void wpc();  // RVA: 0x6B1EF0
        static bool xdk(int64_t a, int32_t b);  // RVA: 0x6AA5A0
        void xdl(int64_t a);  // RVA: 0x6AA5B0
        int64_t xdm();  // RVA: 0x6B2280
        bool xdn();  // RVA: 0x6AA830
        static void xdo(int64_t a);  // RVA: 0x632CB0
        void xdp();  // RVA: 0x632CB0
        static int64_t xdq(int64_t a, int64_t b);  // RVA: 0x6B23A0
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct RawEncryptedQuaternion
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t x; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    int32_t y; // 0x0014
    uint8_t pad_0015[0x3]; // 0x0015
    int32_t z; // 0x0018
    uint8_t pad_0019[0x3]; // 0x0019
    int32_t w; // 0x001C

    // Methods
    bool Equals(RawEncryptedQuaternion other);  // RVA: 0x6BF260
    bool Equals(Il2CppObject* obj);  // RVA: 0x6BF290
    int32_t GetHashCode();  // RVA: 0x6BF340
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredQuaternion
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        RawEncryptedQuaternion hiddenValue; // 0x0014
        uint8_t pad_0015[0xF]; // 0x0015
        int32_t currentCryptoKey; // 0x0024
        uint8_t pad_0025[0x3]; // 0x0025
        Quaternion fakeValue; // 0x0028
    
        // Methods
        static ObscuredQuaternion op_Implicit(Quaternion value);  // RVA: 0x6B2BB0
        static Quaternion op_Implicit(ObscuredQuaternion value);  // RVA: 0x6B2B80
        static ObscuredQuaternion xdr(ObscuredQuaternion a, ObscuredQuaternion b);  // RVA: 0x6B2D10
        static ObscuredQuaternion xds(ObscuredQuaternion a, Quaternion b);  // RVA: 0x6B2F10
        bool Equals(Il2CppObject* other);  // RVA: 0x6B24F0
        bool Equals(ObscuredQuaternion other);  // RVA: 0x6B23B0
        bool Equals(Quaternion other);  // RVA: 0x6B2690
        int32_t GetHashCode();  // RVA: 0x6B2740
        Il2CppString* ToString();  // RVA: 0x6B2910
        Il2CppString* xdt(Il2CppString* a);  // RVA: 0x6B30F0
        void xdu();  // RVA: 0x6B3140
        Quaternion xdv();  // RVA: 0x6B3260
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B27D0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Quaternion value);  // RVA: 0x6B2950
        void .ctor(float x, float y, float z, float w);  // RVA: 0x6B2A50
        float xdw();  // RVA: 0x6B32A0
        void xdx(float a);  // RVA: 0x6B32C0
        float xdy();  // RVA: 0x6B3360
        void xdz(float a);  // RVA: 0x6B3380
        float xea();  // RVA: 0x6B3420
        void xeb(float a);  // RVA: 0x6B3440
        float xec();  // RVA: 0x6B34E0
        void xed(float a);  // RVA: 0x6B3500
        float get_Item(int32_t index);  // RVA: 0x6B2A90
        void set_Item(int32_t index, float value);  // RVA: 0x6B2BF0
        static RawEncryptedQuaternion xee(Quaternion a, int32_t b);  // RVA: 0x6B35A0
        static RawEncryptedQuaternion xef(float a, float b, float c, float d, int32_t e);  // RVA: 0x6B3660
        static Quaternion xeg(RawEncryptedQuaternion a, int32_t b);  // RVA: 0x6B3720
        static ObscuredQuaternion xeh(RawEncryptedQuaternion a, int32_t b);  // RVA: 0x6B37C0
        static int32_t xei();  // RVA: 0x6A4A70
        static bool xej(Quaternion a, Quaternion b);  // RVA: 0x6B3800
        RawEncryptedQuaternion xek(int32_t a);  // RVA: 0x6B3920
        void xel(RawEncryptedQuaternion a, int32_t b);  // RVA: 0x6B39D0
        Quaternion xem();  // RVA: 0x6B2B80
        void wpc();  // RVA: 0x6B2CC0
        static bool xen(Quaternion a, int32_t b);  // RVA: 0x6B3AF0
        void xeo(Quaternion a);  // RVA: 0x6B3B10
        Quaternion xep();  // RVA: 0x6B3BF0
        bool xeq();  // RVA: 0x6B3F50
        static void xer(int32_t a);  // RVA: 0x632CB0
        void xes();  // RVA: 0x632CB0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredSByte
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        int8_t hiddenValue; // 0x0014
        int8_t currentCryptoKey; // 0x0015
        int8_t fakeValue; // 0x0016
    
        // Methods
        static ObscuredSByte op_Implicit(int8_t value);  // RVA: 0x6B4300
        static int8_t op_Implicit(ObscuredSByte value);  // RVA: 0x6B4360
        static ObscuredSByte xet(ObscuredSByte a);  // RVA: 0x6B43C0
        static ObscuredSByte xeu(ObscuredSByte a);  // RVA: 0x6B4420
        static ObscuredSByte xev(ObscuredSByte a, int32_t b);  // RVA: 0x6B4480
        int32_t GetHashCode();  // RVA: 0x6B4200
        Il2CppString* ToString();  // RVA: 0x6B4230
        Il2CppString* xew(Il2CppString* a);  // RVA: 0x6B44E0
        Il2CppString* xex(IFormatProvider* a);  // RVA: 0x6B4510
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B4260
        bool Equals(Il2CppObject* other);  // RVA: 0x6B40B0
        bool Equals(ObscuredSByte obj);  // RVA: 0x6B4050
        bool Equals(int8_t other);  // RVA: 0x6B4020
        int32_t CompareTo(ObscuredSByte other);  // RVA: 0x6B3FE0
        int32_t CompareTo(int8_t other);  // RVA: 0x6B3FB0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B3F80
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6A5BA0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(int8_t value);  // RVA: 0x6B42A0
        static int8_t xey(int8_t a, int8_t b);  // RVA: 0x6A5F00
        static int8_t xez(int8_t a, int8_t b);  // RVA: 0x6A5F70
        static ObscuredSByte xfa(int8_t a, int8_t b);  // RVA: 0x6B4540
        static int8_t xfb();  // RVA: 0x6B4590
        int8_t xfc(int8_t a);  // RVA: 0x6B45A0
        void xfd(int8_t a, int8_t b);  // RVA: 0x6B4620
        int8_t xfe();  // RVA: 0x6B4670
        void wpc();  // RVA: 0x6B4380
        static bool xff(int8_t a, int32_t b);  // RVA: 0x6B4680
        void xfg(int8_t a);  // RVA: 0x6B4690
        int8_t xfh();  // RVA: 0x6B46C0
        bool xfi();  // RVA: 0x6A6250
        static void xfj(int8_t a);  // RVA: 0x632CB0
        void xfk();  // RVA: 0x632CB0
        static int8_t xfl(int8_t a, int8_t b);  // RVA: 0x6A62F0
        static int8_t xfm(int8_t a, int8_t b);  // RVA: 0x6A62F0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredShort
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        int16_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x1]; // 0x0015
        int16_t currentCryptoKey; // 0x0016
        uint8_t pad_0017[0x1]; // 0x0017
        int16_t fakeValue; // 0x0018
    
        // Methods
        static ObscuredShort op_Implicit(int16_t value);  // RVA: 0x6B4C00
        static int16_t op_Implicit(ObscuredShort value);  // RVA: 0x6B4BF0
        static ObscuredShort xfn(ObscuredShort a);  // RVA: 0x6B4CB0
        static ObscuredShort xfo(ObscuredShort a);  // RVA: 0x6B4D40
        static ObscuredShort xfp(ObscuredShort a, int32_t b);  // RVA: 0x6B4DD0
        int32_t GetHashCode();  // RVA: 0x6B4A90
        Il2CppString* ToString();  // RVA: 0x6B4B10
        Il2CppString* xfq(Il2CppString* a);  // RVA: 0x6B4E50
        Il2CppString* xfr(IFormatProvider* a);  // RVA: 0x6B4E90
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B4B40
        bool Equals(Il2CppObject* other);  // RVA: 0x6B4920
        bool Equals(ObscuredShort obj);  // RVA: 0x6B4880
        bool Equals(int16_t other);  // RVA: 0x6B48E0
        int32_t CompareTo(ObscuredShort other);  // RVA: 0x6B4840
        int32_t CompareTo(int16_t other);  // RVA: 0x6B4800
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B47C0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B4AC0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(int16_t value);  // RVA: 0x6B4B90
        static int16_t xfs(int16_t a, int16_t b);  // RVA: 0x6A6A30
        static int16_t xft(int16_t a, int16_t b);  // RVA: 0x6A6A40
        static ObscuredShort xfu(int16_t a, int16_t b);  // RVA: 0x6B4ED0
        static int16_t xfv();  // RVA: 0x6B4F30
        int16_t xfw(int16_t a);  // RVA: 0x6B4F40
        void xfx(int16_t a, int16_t b);  // RVA: 0x6B4FD0
        int16_t xfy();  // RVA: 0x6B5020
        void wpc();  // RVA: 0x6B4C60
        static bool xfz(int16_t a, int32_t b);  // RVA: 0x6B5030
        void xga(int16_t a);  // RVA: 0x6B5040
        int16_t xgb();  // RVA: 0x6B5070
        bool xgc();  // RVA: 0x6B5190
        static void xgd(int16_t a);  // RVA: 0x632CB0
        void xge();  // RVA: 0x632CB0
        static int16_t xgf(int16_t a, int16_t b);  // RVA: 0x6A6DA0
        static int16_t xgg(int16_t a, int16_t b);  // RVA: 0x6A6DA0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    class ObscuredString
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        Char[][] cryptoKey; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        Char[][] hiddenChars; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        Il2CppString* bmst; // 0x0028
        uint8_t pad_0029[0x7]; // 0x0029
        Il2CppString* currentCryptoKey; // 0x0030
        uint8_t pad_0031[0x7]; // 0x0031
        Byte[][] hiddenValue; // 0x0038
    
        // Methods
        int32_t xgh();  // RVA: 0x6B5940
        wchar_t get_Item(int32_t index);  // RVA: 0x6B57C0
        static ObscuredString* op_Implicit(Il2CppString* value);  // RVA: 0x6B5840
        static Il2CppString* op_Implicit(ObscuredString* value);  // RVA: 0x6B58B0
        static bool xgi(ObscuredString* a, ObscuredString* b);  // RVA: 0x6B5960
        static bool xgj(ObscuredString* a, ObscuredString* b);  // RVA: 0x6B5AA0
        Il2CppString* xgk(int32_t a);  // RVA: 0x6B5AC0
        Il2CppString* xgl(int32_t a, int32_t b);  // RVA: 0x6B5B20
        bool xgm(Il2CppString* a, StringComparison b);  // RVA: 0x6B5B70
        bool xgn(Il2CppString* a, StringComparison b);  // RVA: 0x6B5BC0
        int32_t GetHashCode();  // RVA: 0x6B54D0
        Il2CppString* ToString();  // RVA: 0x6B5650
        static bool xgo(ObscuredString* a);  // RVA: 0x6B5C10
        static bool xgp(ObscuredString* a);  // RVA: 0x6B5C60
        bool Equals(Il2CppObject* other);  // RVA: 0x6B53F0
        bool Equals(ObscuredString* obj);  // RVA: 0x6B52E0
        bool xgq(ObscuredString* a, StringComparison b);  // RVA: 0x6B5D60
        bool Equals(Il2CppString* other);  // RVA: 0x6B52A0
        int32_t CompareTo(ObscuredString* other);  // RVA: 0x6B51B0
        int32_t CompareTo(Il2CppString* other);  // RVA: 0x6B5260
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B5220
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B5510
        int32_t wpb();  // RVA: 0x66DB40
        void .ctor();  // RVA: 0x6B5670
        void .ctor(Il2CppString* value);  // RVA: 0x6B56B0
        static Char[][] xgr();  // RVA: 0x6B5DE0
        static Char[][] xgs(Il2CppString* a, Il2CppString* b);  // RVA: 0x6B5E40
        static Char[][] xgt(Il2CppString* a, Char[][] b);  // RVA: 0x6B5EA0
        static Char[][] xgu(Char[][] a, Char[][] b);  // RVA: 0x6B5ED0
        static Il2CppString* xgv(Char[][] a, Il2CppString* b);  // RVA: 0x6B5EE0
        static Il2CppString* xgw(Char[][] a, Char[][] b);  // RVA: 0x6B5F30
        static ObscuredString* xgx(Char[][] a, Char[][] b);  // RVA: 0x6B5F60
        static Char[][] xgy();  // RVA: 0x6B5FF0
        static void xgz(Char[][] a);  // RVA: 0x6B6050
        Char[][] xha(Char[][] a);  // RVA: 0x6B6060
        void xhb(Char[][] a, Char[][] b);  // RVA: 0x6B6140
        Il2CppString* xhc();  // RVA: 0x6B5650
        Char[][] xhd();  // RVA: 0x6B61D0
        void wpc();  // RVA: 0x6B58E0
        static bool xhe(Char[][] a, int32_t b);  // RVA: 0x6B61E0
        void xhf(Char[][] a);  // RVA: 0x6B61F0
        static Char[][] xhg(Char[][] a, Char[][] b);  // RVA: 0x6B6240
        static wchar_t xhh(Char[][] a, Char[][] b, int32_t c);  // RVA: 0x6B63B0
        static bool xhi(ObscuredString* a);  // RVA: 0x6B5C60
        Il2CppString* xhj();  // RVA: 0x6B5650
        Char[][] xhk();  // RVA: 0x6B6400
        bool xhl();  // RVA: 0x6B6720
        bool xhm(Char[][] a, Il2CppString* b);  // RVA: 0x6B6750
        static void xhn(Il2CppString* a);  // RVA: 0x632CB0
        void xho();  // RVA: 0x632CB0
        static Il2CppString* xhp(Il2CppString* a);  // RVA: 0x6B68B0
        static Il2CppString* xhq(Il2CppString* a, Il2CppString* b);  // RVA: 0x6B68F0
        Il2CppString* xhr();  // RVA: 0x6B6900
        void xhs(Il2CppString* a);  // RVA: 0x632CB0
        static ObscuredString* xht(Il2CppString* a, Il2CppString* b);  // RVA: 0x6B6940
        void xhu(Il2CppString* a, Il2CppString* b);  // RVA: 0x6B6AA0
        static Char[][] xhv(Char[][] a);  // RVA: 0x6B6BB0
        static Il2CppString* xhw(Il2CppString* a, Il2CppString* b);  // RVA: 0x6B6BD0
        static Il2CppString* xhx(Byte[][] a);  // RVA: 0x6B6DA0
        static Byte[][] xhy(Il2CppString* a);  // RVA: 0x6B6E30
        static bool xhz(Char[][] a, Char[][] b);  // RVA: 0x6B6EC0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredUInt
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        uint32_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x3]; // 0x0015
        uint32_t currentCryptoKey; // 0x0018
        uint8_t pad_0019[0x3]; // 0x0019
        uint32_t fakeValue; // 0x001C
    
        // Methods
        static ObscuredUInt op_Implicit(uint32_t value);  // RVA: 0x6B14D0
        static uint32_t op_Implicit(ObscuredUInt value);  // RVA: 0x6B7270
        static ObscuredInt xia(ObscuredUInt a);  // RVA: 0x6B72C0
        static ObscuredUInt xib(ObscuredUInt a);  // RVA: 0x6B7330
        static ObscuredUInt xic(ObscuredUInt a);  // RVA: 0x6B73A0
        static ObscuredUInt xid(ObscuredUInt a, int32_t b);  // RVA: 0x6B7410
        int32_t GetHashCode();  // RVA: 0x6B71C0
        Il2CppString* ToString();  // RVA: 0x6B71F0
        Il2CppString* xie(Il2CppString* a);  // RVA: 0x6B7480
        Il2CppString* xif(IFormatProvider* a);  // RVA: 0x6B74C0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B7220
        bool Equals(Il2CppObject* other);  // RVA: 0x6B7020
        bool Equals(ObscuredUInt obj);  // RVA: 0x6B7160
        bool Equals(uint32_t other);  // RVA: 0x6B6FF0
        int32_t CompareTo(ObscuredUInt other);  // RVA: 0x6B6F80
        int32_t CompareTo(uint32_t other);  // RVA: 0x6B6FC0
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B6F40
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B12A0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(uint32_t value);  // RVA: 0x6B1370
        static uint32_t xig(uint32_t a, uint32_t b);  // RVA: 0x6B1800
        static uint32_t xih(uint32_t a, uint32_t b);  // RVA: 0x6B1810
        static ObscuredUInt xii(uint32_t a, uint32_t b);  // RVA: 0x6B1820
        static uint32_t xij();  // RVA: 0x6A4A70
        uint32_t xik(uint32_t a);  // RVA: 0x6B1870
        void xil(uint32_t a, uint32_t b);  // RVA: 0x6B18E0
        uint32_t xim();  // RVA: 0x6B7500
        void wpc();  // RVA: 0x6B7280
        static bool xin(uint32_t a, int32_t b);  // RVA: 0x6B1930
        void xio(uint32_t a);  // RVA: 0x6B1940
        uint32_t xip();  // RVA: 0x6B7510
        bool xiq();  // RVA: 0x6AFAD0
        static void xir(uint32_t a);  // RVA: 0x632CB0
        void xis();  // RVA: 0x632CB0
        static uint32_t xit(uint32_t a, uint32_t b);  // RVA: 0x6B1A60
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredULong
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        uint64_t hiddenValue; // 0x0018
        uint8_t pad_0019[0x7]; // 0x0019
        uint64_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x7]; // 0x0021
        uint64_t fakeValue; // 0x0028
    
        // Methods
        static ObscuredULong op_Implicit(uint64_t value);  // RVA: 0x6B79D0
        static uint64_t op_Implicit(ObscuredULong value);  // RVA: 0x6B79C0
        static ObscuredULong xiu(ObscuredULong a);  // RVA: 0x6B7A70
        static ObscuredULong xiv(ObscuredULong a);  // RVA: 0x6B7B00
        static ObscuredULong xiw(ObscuredULong a, bool b);  // RVA: 0x6B7B90
        int32_t GetHashCode();  // RVA: 0x6B78B0
        Il2CppString* ToString();  // RVA: 0x6B7930
        Il2CppString* xix(Il2CppString* a);  // RVA: 0x6B7C10
        Il2CppString* xiy(IFormatProvider* a);  // RVA: 0x6B7C50
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B78E0
        bool Equals(Il2CppObject* other);  // RVA: 0x6B76C0
        bool Equals(ObscuredULong obj);  // RVA: 0x6B7850
        bool Equals(uint64_t other);  // RVA: 0x6B7810
        int32_t CompareTo(ObscuredULong other);  // RVA: 0x6B7680
        int32_t CompareTo(uint64_t other);  // RVA: 0x6B7600
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B7640
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B1D50
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(uint64_t value);  // RVA: 0x6B7960
        static uint64_t xiz(uint64_t a, uint64_t b);  // RVA: 0x6AA5E0
        static uint64_t xja(uint64_t a, uint64_t b);  // RVA: 0x6AA5F0
        static ObscuredULong xjb(uint64_t a, uint64_t b);  // RVA: 0x6B7C90
        static uint64_t xjc();  // RVA: 0x6AA2B0
        uint64_t xjd(uint64_t a);  // RVA: 0x6B7CE0
        void xje(uint64_t a, uint64_t b);  // RVA: 0x6B7D70
        uint64_t xjf();  // RVA: 0x6B7DC0
        void wpc();  // RVA: 0x6B7A30
        static bool xjg(uint64_t a, int32_t b);  // RVA: 0x6B7DD0
        void xjh(uint64_t a);  // RVA: 0x6B7DE0
        uint64_t xji();  // RVA: 0x6B7E10
        bool xjj();  // RVA: 0x6AA830
        static void xjk(uint64_t a);  // RVA: 0x632CB0
        void xjl();  // RVA: 0x632CB0
        static uint64_t xjm(uint64_t a, uint64_t b);  // RVA: 0x6B23A0
    };

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredUShort
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        uint16_t hiddenValue; // 0x0014
        uint8_t pad_0015[0x1]; // 0x0015
        uint16_t currentCryptoKey; // 0x0016
        uint8_t pad_0017[0x1]; // 0x0017
        uint16_t fakeValue; // 0x0018
    
        // Methods
        static ObscuredUShort op_Implicit(uint16_t value);  // RVA: 0x6B8320
        static uint16_t op_Implicit(ObscuredUShort value);  // RVA: 0x6B8310
        static ObscuredUShort xjn(ObscuredUShort a);  // RVA: 0x6B83D0
        static ObscuredUShort xjo(ObscuredUShort a);  // RVA: 0x6B8460
        static ObscuredUShort xjp(ObscuredUShort a, int32_t b);  // RVA: 0x6B84F0
        int32_t GetHashCode();  // RVA: 0x6B8200
        Il2CppString* ToString();  // RVA: 0x6B8230
        Il2CppString* xjq(Il2CppString* a);  // RVA: 0x6B8570
        Il2CppString* xjr(IFormatProvider* a);  // RVA: 0x6B85B0
        Il2CppString* ToString(Il2CppString* format, IFormatProvider* provider);  // RVA: 0x6B8260
        bool Equals(Il2CppObject* other);  // RVA: 0x6B8090
        bool Equals(ObscuredUShort obj);  // RVA: 0x6B7FF0
        bool Equals(uint16_t other);  // RVA: 0x6B8050
        int32_t CompareTo(ObscuredUShort other);  // RVA: 0x6B7FB0
        int32_t CompareTo(uint16_t other);  // RVA: 0x6B7F30
        int32_t CompareTo(Il2CppObject* obj);  // RVA: 0x6B7F70
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B4AC0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(uint16_t value);  // RVA: 0x6B82B0
        static uint16_t xjs(uint16_t a, uint16_t b);  // RVA: 0x6A6A30
        static uint16_t xjt(uint16_t a, uint16_t b);  // RVA: 0x6A6A40
        static ObscuredUShort xju(uint16_t a, uint16_t b);  // RVA: 0x6A6A50
        static uint16_t xjv();  // RVA: 0x6B85F0
        uint16_t xjw(uint16_t a);  // RVA: 0x6B8600
        void xjx(uint16_t a, uint16_t b);  // RVA: 0x6A6B70
        uint16_t xjy();  // RVA: 0x6B8680
        void wpc();  // RVA: 0x6B8380
        static bool xjz(uint16_t a, int32_t b);  // RVA: 0x6A6BD0
        void xka(uint16_t a);  // RVA: 0x6A6BE0
        uint16_t xkb();  // RVA: 0x6B8690
        bool xkc();  // RVA: 0x6B5190
        static void xkd(uint16_t a);  // RVA: 0x632CB0
        void xke();  // RVA: 0x632CB0
        static uint16_t xkf(uint16_t a, uint16_t b);  // RVA: 0x6A6DA0
        static uint16_t xkg(uint16_t a, uint16_t b);  // RVA: 0x6A6DA0
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct RawEncryptedVector2
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t x; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    int32_t y; // 0x0014

    // Methods
    bool Equals(RawEncryptedVector2 other);  // RVA: 0x6BF3F0
    bool Equals(Il2CppObject* obj);  // RVA: 0x6BF420
    int32_t GetHashCode();  // RVA: 0x6BF410
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredVector2
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        RawEncryptedVector2 hiddenValue; // 0x0014
        uint8_t pad_0015[0x7]; // 0x0015
        int32_t currentCryptoKey; // 0x001C
        uint8_t pad_001D[0x3]; // 0x001D
        Vector2 fakeValue; // 0x0020
    
        // Methods
        static ObscuredVector2 op_Implicit(Vector2 value);  // RVA: 0x6BA260
        static Vector2 op_Implicit(ObscuredVector2 value);  // RVA: 0x6BA250
        static Vector3 op_Implicit(ObscuredVector2 value);  // RVA: 0x6BA290
        static ObscuredVector2 xkh(ObscuredVector2 a, ObscuredVector2 b);  // RVA: 0x6BA400
        static ObscuredVector2 xki(Vector2 a, ObscuredVector2 b);  // RVA: 0x6BA490
        static ObscuredVector2 xkj(ObscuredVector2 a, Vector2 b);  // RVA: 0x6BA510
        static ObscuredVector2 xkk(ObscuredVector2 a, ObscuredVector2 b);  // RVA: 0x6BA590
        static ObscuredVector2 xkl(Vector2 a, ObscuredVector2 b);  // RVA: 0x6BA620
        static ObscuredVector2 xkm(ObscuredVector2 a, Vector2 b);  // RVA: 0x6BA6A0
        static ObscuredVector2 xkn(ObscuredVector2 a);  // RVA: 0x6BA720
        static ObscuredVector2 xko(ObscuredVector2 a, float b);  // RVA: 0x6BA7A0
        static ObscuredVector2 xkp(ObscuredVector2 a, ObscuredVector2 b);  // RVA: 0x6BA820
        static ObscuredVector2 xkq(float a, ObscuredVector2 b);  // RVA: 0x6BA8B0
        static ObscuredVector2 xkr(ObscuredVector2 a, float b);  // RVA: 0x6BA930
        static bool xks(ObscuredVector2 a, ObscuredVector2 b);  // RVA: 0x6BA9B0
        static bool xkt(Vector2 a, ObscuredVector2 b);  // RVA: 0x6BAA10
        static bool xku(ObscuredVector2 a, Vector2 b);  // RVA: 0x6BAA70
        static bool xkv(ObscuredVector2 a, ObscuredVector2 b);  // RVA: 0x6BAAC0
        static bool xkw(Vector2 a, ObscuredVector2 b);  // RVA: 0x6BAB20
        static bool xkx(ObscuredVector2 a, Vector2 b);  // RVA: 0x6BAB80
        bool Equals(Il2CppObject* other);  // RVA: 0x6B9E00
        bool Equals(ObscuredVector2 other);  // RVA: 0x6B9D20
        bool Equals(Vector2 other);  // RVA: 0x6B9DB0
        int32_t GetHashCode();  // RVA: 0x6B9FE0
        Il2CppString* ToString();  // RVA: 0x6BA090
        Il2CppString* xky(Il2CppString* a);  // RVA: 0x6BABD0
        void xkz();  // RVA: 0x6BAC10
        Vector2 xla();  // RVA: 0x6BACE0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6BA020
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Vector2 value);  // RVA: 0x6BA0D0
        void .ctor(float x, float y);  // RVA: 0x6BA0C0
        float xlb();  // RVA: 0x6BAD20
        void xlc(float a);  // RVA: 0x6BAD40
        float xld();  // RVA: 0x6BADB0
        void xle(float a);  // RVA: 0x6BADD0
        float get_Item(int32_t index);  // RVA: 0x6BA1A0
        void set_Item(int32_t index, float value);  // RVA: 0x6BA2D0
        static RawEncryptedVector2 xlf(Vector2 a, int32_t b);  // RVA: 0x6BAE40
        static RawEncryptedVector2 xlg(float a, float b, int32_t c);  // RVA: 0x6BAEA0
        static Vector2 xlh(RawEncryptedVector2 a, int32_t b);  // RVA: 0x6BAF00
        static ObscuredVector2 xli(RawEncryptedVector2 a, int32_t b);  // RVA: 0x6BAF60
        static int32_t xlj();  // RVA: 0x6A4A70
        static bool xlk(Vector2 a, Vector2 b);  // RVA: 0x6BAF90
        static bool xll(float a, float b);  // RVA: 0x6BAFE0
        RawEncryptedVector2 xlm(int32_t a);  // RVA: 0x6BB0A0
        void xln(RawEncryptedVector2 a, int32_t b);  // RVA: 0x6BB120
        Vector2 xlo();  // RVA: 0x6BB1D0
        void wpc();  // RVA: 0x6BA3C0
        static bool xlp(Vector2 a, int32_t b);  // RVA: 0x6BB1E0
        void xlq(Vector2 a);  // RVA: 0x6BB1F0
        Vector2 xlr();  // RVA: 0x6BB280
        bool xls();  // RVA: 0x6B9CE0
        static void xlt(int32_t a);  // RVA: 0x632CB0
        void xlu();  // RVA: 0x632CB0
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct RawEncryptedVector2Int
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t x; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    int32_t y; // 0x0014

    // Methods
    bool Equals(RawEncryptedVector2Int other);  // RVA: 0x6BF3F0
    bool Equals(Il2CppObject* obj);  // RVA: 0x6BF360
    int32_t GetHashCode();  // RVA: 0x6BF410
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredVector2Int
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        RawEncryptedVector2Int hiddenValue; // 0x0014
        uint8_t pad_0015[0x7]; // 0x0015
        int32_t currentCryptoKey; // 0x001C
        uint8_t pad_001D[0x3]; // 0x001D
        Vector2Int fakeValue; // 0x0020
    
        // Methods
        static ObscuredVector2Int op_Implicit(Vector2Int value);  // RVA: 0x6B8E60
        static Vector2Int op_Implicit(ObscuredVector2Int value);  // RVA: 0x6B8EE0
        static Vector3Int op_Explicit(ObscuredVector2Int v);  // RVA: 0x6B8DE0
        static Vector2 op_Implicit(ObscuredVector2Int value);  // RVA: 0x6B8E30
        static ObscuredVector2Int xlv(ObscuredVector2Int a);  // RVA: 0x6B8FF0
        static ObscuredVector2Int xlw(ObscuredVector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9060
        static ObscuredVector2Int xlx(Vector2Int a, ObscuredVector2Int b);  // RVA: 0x6B90F0
        static ObscuredVector2Int xly(ObscuredVector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9170
        static ObscuredVector2Int xlz(ObscuredVector2Int a, Vector2Int b);  // RVA: 0x6B9200
        static ObscuredVector2Int xma(ObscuredVector2Int a, Vector2Int b);  // RVA: 0x6B9280
        static ObscuredVector2Int xmb(Vector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9300
        static ObscuredVector2Int xmc(ObscuredVector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9380
        static ObscuredVector2Int xmd(Vector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9410
        static ObscuredVector2Int xme(ObscuredVector2Int a, Vector2Int b);  // RVA: 0x6B9490
        static ObscuredVector2Int xmf(int32_t a, ObscuredVector2Int b);  // RVA: 0x6B9510
        static ObscuredVector2Int xmg(ObscuredVector2Int a, int32_t b);  // RVA: 0x6B9590
        static ObscuredVector2Int xmh(ObscuredVector2Int a, int32_t b);  // RVA: 0x6B9610
        static bool xmi(ObscuredVector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9690
        static bool xmj(ObscuredVector2Int a, ObscuredVector2Int b);  // RVA: 0x6B9710
        bool Equals(Il2CppObject* other);  // RVA: 0x6B87E0
        bool Equals(ObscuredVector2Int other);  // RVA: 0x6B8960
        bool Equals(Vector2Int other);  // RVA: 0x6B87A0
        int32_t GetHashCode();  // RVA: 0x6B89F0
        Il2CppString* ToString();  // RVA: 0x6B8A90
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6B8A20
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Vector2Int value);  // RVA: 0x6B8CD0
        void .ctor(int32_t x, int32_t y);  // RVA: 0x6B8C40
        int32_t xmk();  // RVA: 0x6B97A0
        void xml(int32_t a);  // RVA: 0x6B97B0
        int32_t xmm();  // RVA: 0x6B9850
        void xmn(int32_t a);  // RVA: 0x6B9870
        int32_t get_Item(int32_t index);  // RVA: 0x6B8D40
        void set_Item(int32_t index, int32_t value);  // RVA: 0x6B8EF0
        static RawEncryptedVector2Int xmo(Vector2Int a, int32_t b);  // RVA: 0x6B9910
        static RawEncryptedVector2Int xmp(int32_t a, int32_t b, int32_t c);  // RVA: 0x6B9930
        static Vector2Int xmq(RawEncryptedVector2Int a, int32_t b);  // RVA: 0x6B9950
        static ObscuredVector2Int xmr(RawEncryptedVector2Int a, int32_t b);  // RVA: 0x6B9970
        static int32_t xms();  // RVA: 0x6A4A70
        RawEncryptedVector2Int xmt(int32_t a);  // RVA: 0x6B99E0
        void xmu(RawEncryptedVector2Int a, int32_t b);  // RVA: 0x6B9A80
        Vector2Int xmv();  // RVA: 0x6B9AE0
        void wpc();  // RVA: 0x6B8F90
        static bool xmw(Vector2Int a, int32_t b);  // RVA: 0x6B9AF0
        void xmx(Vector2Int a);  // RVA: 0x6B9B00
        Vector2Int xmy();  // RVA: 0x6B9B50
        bool xmz();  // RVA: 0x6B9CE0
        static void xna(int32_t a);  // RVA: 0x632CB0
        void xnb();  // RVA: 0x632CB0
        static Vector2Int xnc(RawEncryptedVector2Int a, int32_t b);  // RVA: 0x6B9D00
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct RawEncryptedVector3
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t x; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    int32_t y; // 0x0014
    uint8_t pad_0015[0x3]; // 0x0015
    int32_t z; // 0x0018

    // Methods
    bool Equals(RawEncryptedVector3 other);  // RVA: 0x6BF4B0
    bool Equals(Il2CppObject* obj);  // RVA: 0x6BF4D0
    int32_t GetHashCode();  // RVA: 0x6BF580
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredVector3
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        RawEncryptedVector3 hiddenValue; // 0x0014
        uint8_t pad_0015[0xB]; // 0x0015
        int32_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x3]; // 0x0021
        Vector3 fakeValue; // 0x0024
    
        // Methods
        static ObscuredVector3 op_Implicit(Vector3 value);  // RVA: 0x6BDA10
        static Vector3 op_Implicit(ObscuredVector3 value);  // RVA: 0x6BDA50
        static ObscuredVector3 xnd(ObscuredVector3 a, ObscuredVector3 b);  // RVA: 0x6BDB90
        static ObscuredVector3 xne(Vector3 a, ObscuredVector3 b);  // RVA: 0x6BDC50
        static ObscuredVector3 xnf(ObscuredVector3 a, Vector3 b);  // RVA: 0x6BDCF0
        static ObscuredVector3 xng(ObscuredVector3 a, ObscuredVector3 b);  // RVA: 0x6BDDA0
        static ObscuredVector3 xnh(Vector3 a, ObscuredVector3 b);  // RVA: 0x6BDE60
        static ObscuredVector3 xni(ObscuredVector3 a, Vector3 b);  // RVA: 0x6BDF00
        static ObscuredVector3 xnj(ObscuredVector3 a);  // RVA: 0x6BDFB0
        static ObscuredVector3 xnk(ObscuredVector3 a, float b);  // RVA: 0x6BE030
        static ObscuredVector3 xnl(float a, ObscuredVector3 b);  // RVA: 0x6BE0C0
        static ObscuredVector3 xnm(ObscuredVector3 a, float b);  // RVA: 0x6BE150
        static bool xnn(ObscuredVector3 a, ObscuredVector3 b);  // RVA: 0x6BE1E0
        static bool xno(Vector3 a, ObscuredVector3 b);  // RVA: 0x6BE280
        static bool xnp(ObscuredVector3 a, Vector3 b);  // RVA: 0x6BE2F0
        static bool xnq(ObscuredVector3 a, ObscuredVector3 b);  // RVA: 0x6BE370
        static bool xnr(Vector3 a, ObscuredVector3 b);  // RVA: 0x6BE410
        static bool xns(ObscuredVector3 a, Vector3 b);  // RVA: 0x6BE480
        bool Equals(Il2CppObject* other);  // RVA: 0x6BD4A0
        bool Equals(ObscuredVector3 other);  // RVA: 0x6BD3B0
        bool Equals(Vector3 other);  // RVA: 0x6BD600
        int32_t GetHashCode();  // RVA: 0x6BD660
        Il2CppString* ToString();  // RVA: 0x6BD7C0
        Il2CppString* xnt(Il2CppString* a);  // RVA: 0x6BE4F0
        void xnu();  // RVA: 0x6BE540
        Vector3 xnv();  // RVA: 0x6BE6C0
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6BD6E0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Vector3 value);  // RVA: 0x6BD840
        void .ctor(float x, float y, float z);  // RVA: 0x6BD810
        float xnw();  // RVA: 0x6BE7F0
        void xnx(float a);  // RVA: 0x6BE810
        float xny();  // RVA: 0x6BE890
        void xnz(float a);  // RVA: 0x6BE8B0
        float xoa();  // RVA: 0x6BE930
        void xob(float a);  // RVA: 0x6BE950
        float get_Item(int32_t index);  // RVA: 0x6BD940
        void set_Item(int32_t index, float value);  // RVA: 0x6BDA80
        static RawEncryptedVector3 xoc(Vector3 a, int32_t b);  // RVA: 0x6BE9E0
        static RawEncryptedVector3 xod(float a, float b, float c, int32_t d);  // RVA: 0x6BEA80
        static Vector3 xoe(RawEncryptedVector3 a, int32_t b);  // RVA: 0x6BEB20
        static ObscuredVector3 xof(RawEncryptedVector3 a, int32_t b);  // RVA: 0x6BEBB0
        static int32_t xog();  // RVA: 0x6A4A70
        static bool xoh(Vector3 a, Vector3 b);  // RVA: 0x6BEBF0
        static bool xoi(float a, float b);  // RVA: 0x6BEC60
        RawEncryptedVector3 xoj(int32_t a);  // RVA: 0x6BED20
        void xok(RawEncryptedVector3 a, int32_t b);  // RVA: 0x6BEDD0
        Vector3 xol();  // RVA: 0x6BDA50
        void wpc();  // RVA: 0x6BDB30
        static bool xom(Vector3 a, int32_t b);  // RVA: 0x6BEED0
        void xon(Vector3 a);  // RVA: 0x6BEF00
        Vector3 xoo();  // RVA: 0x6BEFD0
        bool xop();  // RVA: 0x6BD360
        static void xoq(int32_t a);  // RVA: 0x632CB0
        void xor();  // RVA: 0x632CB0
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
struct RawEncryptedVector3Int
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t x; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    int32_t y; // 0x0014
    uint8_t pad_0015[0x3]; // 0x0015
    int32_t z; // 0x0018

    // Methods
    bool Equals(RawEncryptedVector3Int other);  // RVA: 0x6BF4B0
    bool Equals(Il2CppObject* obj);  // RVA: 0x6C6610
    int32_t GetHashCode();  // RVA: 0x6BF580
};

namespace CodeStage.AntiCheat.ObscuredTypes
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes
    struct ObscuredVector3Int
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t hash; // 0x0010
        uint8_t pad_0011[0x3]; // 0x0011
        RawEncryptedVector3Int hiddenValue; // 0x0014
        uint8_t pad_0015[0xB]; // 0x0015
        int32_t currentCryptoKey; // 0x0020
        uint8_t pad_0021[0x3]; // 0x0021
        Vector3Int fakeValue; // 0x0024
    
        // Methods
        static ObscuredVector3Int op_Implicit(Vector3Int value);  // RVA: 0x6BBB00
        static Vector3Int op_Implicit(ObscuredVector3Int value);  // RVA: 0x6BBB40
        static Vector2Int xos(ObscuredVector3Int a);  // RVA: 0x6BBCC0
        static Vector3 op_Implicit(ObscuredVector3Int value);  // RVA: 0x6BBAA0
        static ObscuredVector3Int xot(ObscuredVector3Int a, ObscuredVector3Int b);  // RVA: 0x6BBD00
        static ObscuredVector3Int xou(Vector3Int a, ObscuredVector3Int b);  // RVA: 0x6BBE10
        static ObscuredVector3Int xov(ObscuredVector3Int a, Vector3Int b);  // RVA: 0x6BBF20
        static ObscuredVector3Int xow(ObscuredVector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC020
        static ObscuredVector3Int xox(Vector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC130
        static ObscuredVector3Int xoy(ObscuredVector3Int a, Vector3Int b);  // RVA: 0x6BC240
        static ObscuredVector3Int xoz(ObscuredVector3Int a, int32_t b);  // RVA: 0x6BC340
        static ObscuredVector3Int xpa(int32_t a, ObscuredVector3Int b);  // RVA: 0x6BC450
        static ObscuredVector3Int xpb(ObscuredVector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC560
        static ObscuredVector3Int xpc(ObscuredVector3Int a, int32_t b);  // RVA: 0x6BC610
        static bool xpd(ObscuredVector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC6A0
        static bool xpe(Vector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC730
        static bool xpf(ObscuredVector3Int a, Vector3Int b);  // RVA: 0x6BC7A0
        static bool xpg(ObscuredVector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC800
        static bool xph(Vector3Int a, ObscuredVector3Int b);  // RVA: 0x6BC890
        static bool xpi(ObscuredVector3Int a, Vector3Int b);  // RVA: 0x6BC900
        bool Equals(Il2CppObject* other);  // RVA: 0x6BB580
        bool Equals(ObscuredVector3Int other);  // RVA: 0x6BB4A0
        bool Equals(Vector3Int other);  // RVA: 0x6BB6D0
        int32_t GetHashCode();  // RVA: 0x6BB740
        Il2CppString* ToString();  // RVA: 0x6BB870
        Il2CppString* xpj(Il2CppString* a);  // RVA: 0x6BC970
        void OnBeforeSerialize();  // RVA: 0x632CB0
        void OnAfterDeserialize();  // RVA: 0x6BB7E0
        int32_t wpb();  // RVA: 0x6A1B30
        void .ctor(Vector3Int value);  // RVA: 0x6BB8B0
        void .ctor(int32_t x, int32_t y, int32_t z);  // RVA: 0x6BB980
        int32_t xpk();  // RVA: 0x6BC9C0
        void xpl(int32_t a);  // RVA: 0x6BC9F0
        int32_t xpm();  // RVA: 0x6BCAE0
        void xpn(int32_t a);  // RVA: 0x6BCB10
        int32_t xpo();  // RVA: 0x6BCC00
        void xpp(int32_t a);  // RVA: 0x6BCC20
        int32_t get_Item(int32_t index);  // RVA: 0x6BB9B0
        void set_Item(int32_t index, int32_t value);  // RVA: 0x6BBB70
        static RawEncryptedVector3Int xpq(Vector3Int a, int32_t b);  // RVA: 0x6BCD10
        static RawEncryptedVector3Int xpr(int32_t a, int32_t b, int32_t c, int32_t d);  // RVA: 0x6BCD50
        static Vector3Int xps(RawEncryptedVector3Int a, int32_t b);  // RVA: 0x6BCD80
        static ObscuredVector3Int xpt(RawEncryptedVector3Int a, int32_t b);  // RVA: 0x6BCDB0
        static int32_t xpu();  // RVA: 0x6A4A70
        RawEncryptedVector3Int xpv(int32_t a);  // RVA: 0x6BCE70
        void xpw(RawEncryptedVector3Int a, int32_t b);  // RVA: 0x6BCF80
        Vector3Int xpx();  // RVA: 0x6BBB40
        void wpc();  // RVA: 0x6BBC20
        static bool xpy(Vector3Int a, int32_t b);  // RVA: 0x6BD030
        void xpz(Vector3Int a);  // RVA: 0x6BD060
        Vector3Int xqa();  // RVA: 0x6BD0E0
        bool xqb();  // RVA: 0x6BD360
        static void xqc(int32_t a);  // RVA: 0x632CB0
        void xqd();  // RVA: 0x632CB0
        static Vector3Int xqe(RawEncryptedVector3Int a, int32_t b);  // RVA: 0x6BD390
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes

// Namespace: <global>
class <>c
{
public:
    // Static fields
    // static <>c* <>9;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_0;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_1;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_2;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_3;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_4;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_5;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_6;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_7;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_8;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_9;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_10;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_11;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_12;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_13;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_14;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_15;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_16;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_17;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_18;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_19;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_20;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_21;
    // static System.Action<Newtonsoft.Json.JsonWriter,System.Object> <>9__14_22;


    // Methods
    static void .cctor();  // RVA: 0x6CC830
    void .ctor();  // RVA: 0x628380
    void xqf(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CC980
    void xqg(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCA70
    void xqh(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCB10
    void xqi(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCBA0
    void xqj(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCC40
    void xqk(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCCE0
    void xql(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCDA0
    void xqm(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCE60
    void xqn(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCF10
    void xqo(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CCFB0
    void xqp(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD070
    void xqq(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD110
    void xqr(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD1B0
    void xqs(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD400
    void xqt(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD490
    void xqu(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD530
    void xqv(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD5C0
    void xqw(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD660
    void xqx(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD700
    void xqy(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD7A0
    void xqz(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CD950
    void xra(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CDAF0
    void xrb(JsonWriter* a, Il2CppObject* b);  // RVA: 0x6CDCF0
};

namespace CodeStage.AntiCheat.ObscuredTypes.Converters
{

    // Namespace: CodeStage.AntiCheat.ObscuredTypes.Converters
    class ObscuredTypesNewtonsoftConverter : public JsonConverter
    {
    public:
        // Static fields
        // static Il2CppString* bmsu;
        // static Il2CppString* bmsv;
        // static Il2CppString* bmsw;
        // static Il2CppString* bmsx;
    
        uint8_t pad_0000[0x10]; // 0x0000
        System.Collections.Generic.HashSet<System.Type> bmsy; // 0x0010
        uint8_t pad_0011[0x7]; // 0x0011
        System.Collections.Generic.Dictionary<System.Type,System.Action<Newtonsoft.Json.JsonWriter,System.Object>> bmsz; // 0x0018
    
        // Methods
        void WriteJson(JsonWriter* writer, Il2CppObject* value, JsonSerializer* serializer);  // RVA: 0x6C3ED0
        static void xrc(JsonWriter* a, Quaternion b);  // RVA: 0x6C5C20
        static void xrd(JsonWriter* a, Vector2 b);  // RVA: 0x6C5DC0
        static void xre(JsonWriter* a, Vector2Int b);  // RVA: 0x6C5ED0
        static void xrf(JsonWriter* a, Vector3 b);  // RVA: 0x6C5FE0
        static void xrg(JsonWriter* a, Vector3Int b);  // RVA: 0x6C6140
        Il2CppObject* ReadJson(JsonReader* reader, Type* objectType, Il2CppObject* existingValue, JsonSerializer* serializer);  // RVA: 0x6C1E00
        bool CanConvert(Type* objectType);  // RVA: 0x6C1DA0
        void .ctor();  // RVA: 0x6C41B0
        static void .cctor();  // RVA: 0x6C4070
    };

} // namespace CodeStage.AntiCheat.ObscuredTypes.Converters

// Namespace: <global>
class <>c
{
public:
    // Static fields
    // static <>c* <>9;
    // static System.Comparison<dbz> <>9__13_0;


    // Methods
    static void .cctor();  // RVA: 0x6CC8A0
    void .ctor();  // RVA: 0x628380
    int32_t xrh(dbz* a, dbz* b);  // RVA: 0x6CDEE0
};

// Namespace: <global>
class dbw
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Il2CppString* <bmta>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    System.Collections.Generic.IReadOnlyList<dbz> <bmtb>k__BackingField; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    Il2CppString* <bmtc>k__BackingField; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    double <bmtd>k__BackingField; // 0x0028

    // Methods
    Il2CppString* xri();  // RVA: 0x6C6500
    void fpr();  // RVA: 0x6D2520
    void xro();  // RVA: 0x6D2EF0
    void .ctor(Il2CppString* a, dbz[][] b, Il2CppString* c);  // RVA: 0x6D24B0
    System.Collections.Generic.IReadOnlyList<dbz> xrj();  // RVA: 0x68F440
    bool okz(Il2CppString* a);  // RVA: 0x6D2BD0
    bool myf(Il2CppString* a);  // RVA: 0x6D2A50
    bool xrn(Il2CppString* a);  // RVA: 0x6D2D70
    Il2CppString* xy(dbz[][] a);  // RVA: 0x6D3790
    Il2CppString* xrp(dbz[][] a);  // RVA: 0x6D3420
    void xrm(double a);  // RVA: 0x6D2D60
    double xrl();  // RVA: 0x6D2D50
    void .ctor(Il2CppString* a, dbz[][] b);  // RVA: 0x6D2330
    Il2CppString* xrk();  // RVA: 0x63C8B0
};

// Namespace: <global>
class dbx
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmte; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmtf; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    dby* bmtg; // 0x0020

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    void xrq();  // RVA: 0x632CB0
    bool MoveNext();  // RVA: 0x6D3B00
    Il2CppObject* xrr();  // RVA: 0x68F440
    void xrs();  // RVA: 0x6D3C00
    Il2CppObject* xrt();  // RVA: 0x68F440
};

// Namespace: <global>
struct <GenerateInternalAsync>d__20
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t <>1__state; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    System.Runtime.CompilerServices.AsyncTaskMethodBuilder<dcd> <>t__builder; // 0x0018
    uint8_t pad_0019[0x17]; // 0x0019
    dby* <>4__this; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    int32_t maxThreads; // 0x0038
    uint8_t pad_0039[0x7]; // 0x0039
    System.Runtime.CompilerServices.TaskAwaiter<System.Boolean> <>u__1; // 0x0040

    // Methods
    void MoveNext();  // RVA: 0x6CB130
    void SetStateMachine(IAsyncStateMachine* stateMachine);  // RVA: 0x6CB3D0
};

// Namespace: <global>
class dby : public dcy`1
{
public:
    // Static fields
    // static int32_t bmth;
    // static HashGeneratorResultHandler* bmti;

    uint8_t pad_0000[0x30]; // 0x0000
    dcd* <bmtj>k__BackingField; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    WaitForSeconds* bmtk; // 0x0038
    uint8_t pad_0039[0x7]; // 0x0039
    dcg* bmtl; // 0x0040
    uint8_t pad_0041[0x7]; // 0x0041
    SemaphoreSlim* bmtm; // 0x0048

    // Methods
    static System.Threading.Tasks.Task<dcd> obj(int32_t a);  // RVA: 0x6D4150
    static bool xry();  // RVA: 0x673A00
    static dce* hlv(int32_t a);  // RVA: 0x6D3F90
    System.Threading.Tasks.Task<dcd> xsf(int32_t a);  // RVA: 0x6D44D0
    static dce* klh(int32_t a);  // RVA: 0x6D4030
    static void xrv(HashGeneratorResultHandler* a);  // RVA: 0x6D4260
    static System.Threading.Tasks.Task<dcd> kzn(int32_t a);  // RVA: 0x6D4100
    dce* xsd(int32_t a);  // RVA: 0x6D4430
    bool xsc();  // RVA: 0x6D4410
    void .ctor();  // RVA: 0x6D3CB0
    System.Threading.Tasks.Task<dcd> xse(int32_t a);  // RVA: 0x6D4480
    IEnumerator* xsh();  // RVA: 0x6D47A0
    void xrx(dcd* a);  // RVA: 0x6D4330
    dce* xsg(int32_t a);  // RVA: 0x6D45E0
    static dce* knt();  // RVA: 0x6D4080
    static dce* glt(int32_t a);  // RVA: 0x6D3EF0
    dcd* xrw();  // RVA: 0x6D4320
    static void xru(HashGeneratorResultHandler* a);  // RVA: 0x6D41A0
    static System.Threading.Tasks.Task<dcd> gxn(int32_t a);  // RVA: 0x6D3F40
    static dce* xsa(int32_t a);  // RVA: 0x6D4370
    static dce* kpz(int32_t a);  // RVA: 0x6D40B0
    static dce* xrz();  // RVA: 0x6D4340
    static bool fik();  // RVA: 0x673A00
    void OnDestroy();  // RVA: 0x6D3C40
    static System.Threading.Tasks.Task<dcd> htl(int32_t a);  // RVA: 0x6D3FE0
    static bool izj();  // RVA: 0x673A00
    static System.Threading.Tasks.Task<dcd> xsb(int32_t a);  // RVA: 0x6D43C0
    dce* byd(int32_t a);  // RVA: 0x6D3D30
};

// Namespace: <global>
class dbz
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Il2CppString* <bmtn>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppString* <bmto>k__BackingField; // 0x0018

    // Methods
    Il2CppString* xsi();  // RVA: 0x6C6500
    Il2CppString* xsj();  // RVA: 0x68F440
    void .ctor(Il2CppString* a, Stream* b, day<dcf> c);  // RVA: 0x6D48D0
    void .ctor(Il2CppString* a, Il2CppString* b);  // RVA: 0x6D4880
    Il2CppString* ToString();  // RVA: 0x6D4810
};

// Namespace: <global>
class <>c
{
public:
    // Static fields
    // static <>c* <>9;
    // static System.Action<CodeStage.AntiCheat.Genuine.CodeHash.FilesProgress> <>9__2_0;


    // Methods
    static void .cctor();  // RVA: 0x6CC910
    void .ctor();  // RVA: 0x628380
    void xsk(FilesProgress a);  // RVA: 0x632CB0
};

namespace CodeStage.AntiCheat.Genuine.CodeHash
{

    // Namespace: CodeStage.AntiCheat.Genuine.CodeHash
    struct FilesProgress
    {
    public:
    
        // Methods
        static FilesProgress xsl(float a, Il2CppString* b);  // RVA: 0x628660
        static FilesProgress None();  // RVA: 0x628660
        static System.IProgress<CodeStage.AntiCheat.Genuine.CodeHash.FilesProgress> xsm(Il2CppString* a);  // RVA: 0x6C09E0
    };

} // namespace CodeStage.AntiCheat.Genuine.CodeHash

// Namespace: <global>
class dca
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    bool bmtp; // 0x0010
    bool bmtq; // 0x0011
    bool bmtr; // 0x0012
    bool bmts; // 0x0013
    uint8_t pad_0014[0x4]; // 0x0014
    Il2CppString* bmtt; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    Il2CppString* bmtu; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    Il2CppString* bmtv; // 0x0028

    // Methods
    static bool xso(Il2CppString* a, Il2CppString* b, bool c, bool d);  // RVA: 0x6D58E0
    void .ctor();  // RVA: 0x628380
    bool cae(Il2CppString* a);  // RVA: 0x6D4C10
    Il2CppString* ToString();  // RVA: 0x6D49D0
    bool ndz(Il2CppString* a);  // RVA: 0x6D52E0
    bool gjr(Il2CppString* a);  // RVA: 0x6D4FE0
    static bool czc(Il2CppString* a, Il2CppString* b, bool c, bool d);  // RVA: 0x6D4F10
    static bool zg(Il2CppString* a, Il2CppString* b, bool c, bool d);  // RVA: 0x6D59B0
    bool xsn(Il2CppString* a);  // RVA: 0x6D55E0
};

namespace CodeStage.AntiCheat.Genuine.CodeHash
{

    // Namespace: CodeStage.AntiCheat.Genuine.CodeHash
    struct FilterGroup
    {
    public:
        // Static fields
        // static FilterGroup Code;
        // static FilterGroup Content;
        // static FilterGroup All;
    
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t value__; // 0x0010
    };

} // namespace CodeStage.AntiCheat.Genuine.CodeHash

// Namespace: <global>
class dcb
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    dca[][] <bmtw>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    dca[][] <bmtx>k__BackingField; // 0x0018

    // Methods
    dca[][] xsp();  // RVA: 0x6C6500
    bool cne(Il2CppString* a);  // RVA: 0x6D5A80
    void .ctor(dca[][] a, dca[][] b);  // RVA: 0x6D4880
    bool xss(Il2CppString* a);  // RVA: 0x6D5A80
    dcb* ee(dcb* a);  // RVA: 0x6D5B10
    dcb* xst(dcb* a);  // RVA: 0x6D5C60
    bool xsu(Il2CppString* a, dca[][] b);  // RVA: 0x6D5D30
    a[][] xsv(a[][] a, a[][] b);  // RVA: 0x42CF30
    dca[][] xsq();  // RVA: 0x68F440
    bool cmf(Il2CppString* a);  // RVA: 0x6D5A80
    bool kgs(Il2CppString* a);  // RVA: 0x6D5A80
    bool zo(Il2CppString* a);  // RVA: 0x6D5A80
    bool xsr(Il2CppString* a);  // RVA: 0x6D5BE0
};

namespace CodeStage.AntiCheat.Genuine.CodeHash
{

    // Namespace: CodeStage.AntiCheat.Genuine.CodeHash
    class FilteringSettings : public ScriptableObject
    {
    public:
        uint8_t pad_0000[0x18]; // 0x0000
        FilterGroup <DefaultGroup>k__BackingField; // 0x0018
    
        // Methods
        FilterGroup get_DefaultGroup();  // RVA: 0x6C0B10
        void set_DefaultGroup(FilterGroup value);  // RVA: 0x6C0B20
        void .ctor();  // RVA: 0x6C0B00
    };

} // namespace CodeStage.AntiCheat.Genuine.CodeHash

// Namespace: <global>
class dcc
{
public:

    // Methods
    static dcb* xtb(bool a);  // RVA: 0x6D6D10
    static FilteringSettings* xsw();  // RVA: 0x6D72A0
    static dcb* xsy(bool a);  // RVA: 0x6D7410
    static dcb* xtc(bool a);  // RVA: 0x6D7A90
    static FilteringSettings* dbe();  // RVA: 0x6D6340
    static dcb* nvd(bool a);  // RVA: 0x6D6000
    static dcb* fef(bool a);  // RVA: 0x6D64B0
    static dcb* fej(bool a);  // RVA: 0x6D65F0
    static dcb* ier(bool a);  // RVA: 0x6D6BD0
    static dcb* bym(bool a);  // RVA: 0x6D6000
    static dcb* fqe(bool a);  // RVA: 0x6D68E0
    static dcb* xte(bool a);  // RVA: 0x6D6000
    static dcb* djz(bool a);  // RVA: 0x6D6370
    static dcb* bge(bool a);  // RVA: 0x6D5DB0
    static dcb* xsz(bool a);  // RVA: 0x6D7550
    static dcb* lco(bool a);  // RVA: 0x6D6D60
    static dcb* co(bool a);  // RVA: 0x6D6050
    static dcb* lnm(bool a);  // RVA: 0x6D6D10
    static dcb* man(bool a);  // RVA: 0x6D6000
    static dcb* xta(bool a);  // RVA: 0x6D7840
    static dcb* xsx(bool a);  // RVA: 0x6D72D0
    static dcb* xtd(bool a);  // RVA: 0x6D7E10
    static dcb* jrv(bool a);  // RVA: 0x6D6D10
    static dcb* lwu(bool a);  // RVA: 0x6D7050
};

// Namespace: <global>
class dcd
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Il2CppString* <bmty>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppString* bmtz; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    dbw* bmua; // 0x0020

    // Methods
    Il2CppString* xtf();  // RVA: 0x6D84A0
    System.Collections.Generic.IReadOnlyList<dbz> xth();  // RVA: 0x6D84C0
    static dcd* nkv(Il2CppString* a);  // RVA: 0x6D8430
    static dcd* mwm(dbw* a);  // RVA: 0x6D83C0
    void klb();  // RVA: 0x6D8330
    bool xtk();  // RVA: 0x6D84F0
    Il2CppString* xti();  // RVA: 0x6C6500
    void ixy();  // RVA: 0x6D8250
    static dcd* xtm(Il2CppString* a);  // RVA: 0x6D8520
    static dcd* xtn(dbw* a);  // RVA: 0x6D8590
    bool xto(Il2CppString* a);  // RVA: 0x6D83A0
    void fsd();  // RVA: 0x6D8170
    void xtj(Il2CppString* a);  // RVA: 0x6D84E0
    bool lxn(Il2CppString* a);  // RVA: 0x6D83A0
    static dcd* jnb(dbw* a);  // RVA: 0x6D82C0
    static dcd* hei(Il2CppString* a);  // RVA: 0x6D81E0
    Il2CppString* xtg();  // RVA: 0x6D84A0
    void .ctor();  // RVA: 0x628380
    double xtl();  // RVA: 0x6D8500
    static dcd* dmd(dbw* a);  // RVA: 0x6D8100
    void xtp();  // RVA: 0x6D8600
};

namespace CodeStage.AntiCheat.Genuine.CodeHash
{

    // Namespace: CodeStage.AntiCheat.Genuine.CodeHash
    class HashGeneratorResultHandler : public MulticastDelegate
    {
    public:
    
        // Methods
        void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x6C0B30
        void Invoke(dcd* result);  // RVA: 0x66DCD0
        IAsyncResult* BeginInvoke(dcd* result, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x66DE00
        void EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
    };

} // namespace CodeStage.AntiCheat.Genuine.CodeHash

// Namespace: <global>
class dce
{
public:

    // Methods
    dcd* xrw();  // RVA: 0x41C380
    bool xsc();  // RVA: 0x421380
    dce* xtq(int32_t a);  // RVA: 0x41C9C0
    System.Threading.Tasks.Task<dcd> xtr(int32_t a);  // RVA: 0x41C9C0
};

// Namespace: <global>
class dcf
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    SHA1Managed* bmub; // 0x0010

    // Methods
    Byte[][] yc(Byte[][] a);  // RVA: 0x6D8720
    Byte[][] xts(Stream* a);  // RVA: 0x6D8700
    Byte[][] ewb(Stream* a);  // RVA: 0x6D8700
    void Dispose();  // RVA: 0x6D8670
    Byte[][] edw(Stream* a);  // RVA: 0x6D8700
    Byte[][] hnj(Stream* a);  // RVA: 0x6D8700
    Byte[][] xtt(Byte[][] a);  // RVA: 0x6D8720
    void .ctor();  // RVA: 0x6D8690
    Byte[][] huv(Byte[][] a);  // RVA: 0x6D8720
    Byte[][] hot(Byte[][] a);  // RVA: 0x6D8720
    Byte[][] mod(Stream* a);  // RVA: 0x6D8700
};

// Namespace: <global>
class dcg
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    dcd* <bmuc>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    bool <bmud>k__BackingField; // 0x0018
    uint8_t pad_0019[0x3]; // 0x0019
    int32_t bmue; // 0x001C

    // Methods
    dcd* xtu();  // RVA: 0x6C6500
    void xtv(dcd* a);  // RVA: 0x6D84E0
    bool xtw();  // RVA: 0x6D8780
    void xtx(bool a);  // RVA: 0x6D8790
    void .ctor(int32_t a);  // RVA: 0x6D8750
    void Execute();  // RVA: 0x6D8740
    void xty(dcd* a);  // RVA: 0x6D87A0
};

// Namespace: <global>
class <>c
{
public:
    // Static fields
    // static <>c* <>9;
    // static System.Func<dcf> <>9__1_0;


    // Methods
    static void .cctor();  // RVA: 0x6CC7C0
    void .ctor();  // RVA: 0x628380
    dcf* xtz();  // RVA: 0x6CDF20
};

// Namespace: <global>
class dch
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    dcb* bmuf; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    System.Collections.Concurrent.ConcurrentBag<dbz> bmug; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    day<dcf> bmuh; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    Il2CppString* bmui; // 0x0028
    uint8_t pad_0029[0x7]; // 0x0029
    int32_t bmuj; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    System.IProgress<CodeStage.AntiCheat.Genuine.CodeHash.FilesProgress> bmuk; // 0x0038
    uint8_t pad_0039[0x7]; // 0x0039
    int32_t bmul; // 0x0040
    uint8_t pad_0041[0x3]; // 0x0041
    int32_t bmum; // 0x0044

    // Methods
    void hct(Il2CppString* a, ParallelLoopState* b);  // RVA: 0x6D9750
    void fks(Il2CppString* a, ParallelLoopState* b);  // RVA: 0x6D8CF0
    void fvu(Il2CppString* a, ParallelLoopState* b);  // RVA: 0x6D9220
    void dfp(Il2CppString* a, ParallelLoopState* b);  // RVA: 0x6D87C0
    void .ctor();  // RVA: 0x628380
    void xua(Il2CppString* a, ParallelLoopState* b);  // RVA: 0x6D9C80
};

// Namespace: <global>
class dci
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    dcj* bmun; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppString* bmuo; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    dcb* bmup; // 0x0020

    // Methods
    void .ctor();  // RVA: 0x628380
    void hxu();  // RVA: 0x6DA1B0
    void nxo();  // RVA: 0x6DA1B0
    void xub();  // RVA: 0x6DA1B0
    void jye();  // RVA: 0x6DA1B0
};

// Namespace: <global>
class dcj : public dcg
{
public:
    // Static fields
    // static Il2CppObject* bmuq;


    // Methods
    static dbw* xuc(Il2CppString* a, dcb* b, int32_t c, System.IProgress<CodeStage.AntiCheat.Genuine.CodeHash.FilesProgress> d);  // RVA: 0x6DAA50
    void .ctor(int32_t a);  // RVA: 0x6D8750
    void xud(Il2CppString* a, dcb* b);  // RVA: 0x6DAEF0
    static void .cctor();  // RVA: 0x6DA530
    void Execute();  // RVA: 0x6DA1E0
    static dbw* ciq(Il2CppString* a, dcb* b, int32_t c, System.IProgress<CodeStage.AntiCheat.Genuine.CodeHash.FilesProgress> d);  // RVA: 0x6DA5B0
};

namespace CodeStage.AntiCheat.Genuine.Android
{

    // Namespace: CodeStage.AntiCheat.Genuine.Android
    struct AndroidAppSource
    {
    public:
        // Static fields
        // static AndroidAppSource PackageInstaller;
        // static AndroidAppSource GooglePlayStore;
        // static AndroidAppSource AmazonAppStore;
        // static AndroidAppSource HuaweiAppGallery;
        // static AndroidAppSource SamsungGalaxyStore;
        // static AndroidAppSource Other;
        // static AndroidAppSource AccessError;
    
        uint8_t pad_0000[0x10]; // 0x0000
        int32_t value__; // 0x0010
    };

} // namespace CodeStage.AntiCheat.Genuine.Android

// Namespace: <global>
class dck
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Il2CppString* <bmur>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    AndroidAppSource <bmus>k__BackingField; // 0x0018

    // Methods
    AndroidAppSource iit(Il2CppString* a);  // RVA: 0x6DB260
    AndroidAppSource noe(Il2CppString* a);  // RVA: 0x6DB5A0
    Il2CppString* xue();  // RVA: 0x6C6500
    AndroidAppSource iqx(Il2CppString* a);  // RVA: 0x6DB400
    void .ctor(Il2CppString* a);  // RVA: 0x6DB080
    AndroidAppSource xug(Il2CppString* a);  // RVA: 0x6DB740
    AndroidAppSource xuf();  // RVA: 0x6C0B10
};

// Namespace: <global>
class dcl
{
public:

    // Methods
    static bool xui();  // RVA: 0x6DB8E0
    static bool ewy();  // RVA: 0x6DB8E0
    static dck* xuh();  // RVA: 0x6DB910
    static bool hls();  // RVA: 0x6DB8E0
    static bool hol();  // RVA: 0x6DB8E0
};

namespace CodeStage.AntiCheat.Detectors
{

    // Namespace: CodeStage.AntiCheat.Detectors
    class ACTkDetectorBase`1 : public dcy`1
    {
    public:
        // Static fields
        // static Il2CppString* bmut;
    
        bool autoStart; // 0x0000
        bool autoDispose; // 0x0000
        Action* bmuu; // 0x0000
        bool <bmuv>k__BackingField; // 0x0000
        UnityEvent* detectionEvent; // 0x0000
        bool detectionEventHasListener; // 0x0000
        bool <bmuw>k__BackingField; // 0x0000
        bool <bmux>k__BackingField; // 0x0000
        dcm* <bmuy>k__BackingField; // 0x0000
    
        // Methods
        void xuj(Action* a);  // RVA: 0x4186E0
        void xuk(Action* a);  // RVA: 0x4186E0
        bool xul();  // RVA: 0x421380
        void xum(bool a);  // RVA: 0x41C430
        bool xun();  // RVA: 0x421380
        void xuo(bool a);  // RVA: 0x41C430
        bool xup();  // RVA: 0x421380
        void xuq(bool a);  // RVA: 0x41C430
        dcm* xur();  // RVA: 0x41C380
        void xus(dcm* a);  // RVA: 0x4186E0
        void Start();  // RVA: 0x42DF20
        void OnEnable();  // RVA: 0x42DF20
        void OnDisable();  // RVA: 0x42DF20
        void OnApplicationQuit();  // RVA: 0x42DF20
        void OnDestroy();  // RVA: 0x42DF20
        void xut(dcm* a);  // RVA: 0x4186E0
        void xuu();  // RVA: 0x42DF20
        bool xuv();  // RVA: 0x421380
        void xuw();  // RVA: 0x42DF20
        void xux();  // RVA: 0x42DF20
        bool xuy();  // RVA: 0x421380
        bool xuz();  // RVA: 0x421380
        void xva();  // RVA: 0x42DF20
        void .ctor();  // RVA: 0x42DF20
    };

} // namespace CodeStage.AntiCheat.Detectors

// Namespace: <global>
class dcm
{
public:

    // Methods
    Il2CppString* xvb();  // RVA: 0x41C380
};

// Namespace: <global>
class dcn
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Il2CppString* <bmuz>k__BackingField; // 0x0010

    // Methods
    Il2CppString* xvc();  // RVA: 0x6C6500
    void .ctor(Il2CppString* a);  // RVA: 0x6DB9F0
    Il2CppString* xvb();  // RVA: 0x6DB990
    Il2CppString* ToString();  // RVA: 0x6DB990
};

// Namespace: <global>
class InjectionDetectedEventHandler : public MulticastDelegate
{
public:

    // Methods
    void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x6C0C60
    void Invoke(Il2CppString* reason);  // RVA: 0x66DCD0
    IAsyncResult* BeginInvoke(Il2CppString* reason, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x66DE00
    void EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
};

namespace CodeStage.AntiCheat.Detectors
{

    // Namespace: CodeStage.AntiCheat.Detectors
    class InjectionDetector : public ACTkDetectorBase`1
    {
    public:
        // Static fields
        // static Il2CppString* ComponentName;
        // static Il2CppString* bmva;
    
    
        // Methods
        dcn* xvd();  // RVA: 0x6C0DE0
        static InjectionDetector* xve();  // RVA: 0x6C0E60
        static void xvf();  // RVA: 0x6C0EE0
        static void xvg(System.Action<System.String> a);  // RVA: 0x6C0F60
        static void xvh();  // RVA: 0x6C0FE0
        static void xvi();  // RVA: 0x6C1060
        void xva();  // RVA: 0x6C0D60
        void .ctor();  // RVA: 0x6C0D20
    };

} // namespace CodeStage.AntiCheat.Detectors

// Namespace: <global>
class dco
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    Type* <bmvb>k__BackingField; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    bool <bmvc>k__BackingField; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    Il2CppObject* <bmvd>k__BackingField; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    Il2CppObject* <bmve>k__BackingField; // 0x0028

    // Methods
    Type* xvj();  // RVA: 0x6C6500
    bool xvk();  // RVA: 0x6D8780
    Il2CppObject* xvl();  // RVA: 0x63C8B0
    Il2CppObject* xvm();  // RVA: 0x6809D0
    void .ctor(Type* a, bool b, Il2CppObject* c, Il2CppObject* d);  // RVA: 0x6DBB30
    Il2CppString* xvb();  // RVA: 0x6DBA30
    Il2CppString* ToString();  // RVA: 0x6DBA30
};

namespace CodeStage.AntiCheat.Detectors
{

    // Namespace: CodeStage.AntiCheat.Detectors
    class ObscuredCheatingDetector : public ACTkDetectorBase`1
    {
    public:
        // Static fields
        // static Il2CppString* ComponentName;
        // static Il2CppString* bmvf;
    
        uint8_t pad_0000[0x60]; // 0x0000
        bool honeyPot; // 0x0060
        uint8_t pad_0061[0x7]; // 0x0061
        double doubleEpsilon; // 0x0068
        uint8_t pad_0069[0x7]; // 0x0069
        float floatEpsilon; // 0x0070
        uint8_t pad_0071[0x3]; // 0x0071
        float vector2Epsilon; // 0x0074
        uint8_t pad_0075[0x3]; // 0x0075
        float vector3Epsilon; // 0x0078
        uint8_t pad_0079[0x3]; // 0x0079
        float quaternionEpsilon; // 0x007C
    
        // Methods
        dco* xvn();  // RVA: 0x6C1160
        static ObscuredCheatingDetector* xvo();  // RVA: 0x6C11E0
        static ObscuredCheatingDetector* xvp();  // RVA: 0x6C1210
        static ObscuredCheatingDetector* xvq(Action* a);  // RVA: 0x6C1360
        static void xvr();  // RVA: 0x6C13B0
        static void xvs();  // RVA: 0x6C14C0
        static bool xvt();  // RVA: 0x6C15D0
        static bool xvu();  // RVA: 0x6C16D0
        void .ctor();  // RVA: 0x6C10E0
        void xvv();  // RVA: 0x6C1840
        void xvw(dbu* a, Il2CppObject* b, Il2CppObject* c);  // RVA: 0x6C19D0
        void xvx(dbu* a, bool b, Il2CppObject* c, Il2CppObject* d);  // RVA: 0x6C1AB0
        ObscuredCheatingDetector* xvy(Action* a);  // RVA: 0x6C1BA0
        void xva();  // RVA: 0x6C1150
        static void xvz(b a, bool b, c c, bool d, a e, d f);  // RVA: 0x563E10
    };

} // namespace CodeStage.AntiCheat.Detectors

// Namespace: <global>
class dcp
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    bool <bmvg>k__BackingField; // 0x0010
    bool <bmvh>k__BackingField; // 0x0011
    bool <bmvi>k__BackingField; // 0x0012
    bool <bmvj>k__BackingField; // 0x0013
    bool <bmvk>k__BackingField; // 0x0014

    // Methods
    bool xwa();  // RVA: 0x66E8B0
    bool xwb();  // RVA: 0x67BD00
    bool xwc();  // RVA: 0x6DBDC0
    bool xwd();  // RVA: 0x6DBDD0
    bool xwe();  // RVA: 0x6DBDE0
    void .ctor(bool a, bool b, bool c, bool d, bool e);  // RVA: 0x6DBBC0
    Il2CppString* xvb();  // RVA: 0x6DBC20
    Il2CppString* ToString();  // RVA: 0x6DBBB0
};

namespace CodeStage.AntiCheat.Detectors
{

    // Namespace: CodeStage.AntiCheat.Detectors
    class SpeedHackDetector : public ACTkDetectorBase`1
    {
    public:
        // Static fields
        // static Il2CppString* ComponentName;
        // static Il2CppString* bmvl;
    
        uint8_t pad_0000[0x60]; // 0x0000
        float interval; // 0x0060
        uint8_t pad_0061[0x3]; // 0x0061
        float threshold; // 0x0064
        uint8_t pad_0065[0x3]; // 0x0065
        uint8_t maxFalsePositives; // 0x0068
        uint8_t pad_0069[0x3]; // 0x0069
        int32_t coolDown; // 0x006C
        uint8_t pad_006D[0x3]; // 0x006D
        int32_t <TimeJumpThreshold>k__BackingField; // 0x0070
        uint8_t pad_0071[0x3]; // 0x0071
        bool <UseDsp>k__BackingField; // 0x0074
        bool <WatchTimeScale>k__BackingField; // 0x0075
        uint8_t bmvm; // 0x0076
        uint8_t pad_0077[0x1]; // 0x0077
        int32_t bmvn; // 0x0078
        uint8_t pad_0079[0x7]; // 0x0079
        int64_t bmvo; // 0x0080
        uint8_t pad_0081[0x7]; // 0x0081
        int64_t bmvp; // 0x0088
        uint8_t pad_0089[0x7]; // 0x0089
        int64_t bmvq; // 0x0090
        uint8_t pad_0091[0x7]; // 0x0091
        int64_t bmvr; // 0x0098
        uint8_t pad_0099[0x7]; // 0x0099
        bool bmvs; // 0x00A0
        uint8_t pad_00A1[0x3]; // 0x00A1
        float bmvt; // 0x00A4
        uint8_t pad_00A5[0x3]; // 0x00A5
        bool bmvu; // 0x00A8
        uint8_t pad_00A9[0x7]; // 0x00A9
        double bmvv; // 0x00B0
        uint8_t pad_00B1[0x7]; // 0x00B1
        bool bmvw; // 0x00B8
    
        // Methods
        dcp* xwf();  // RVA: 0x6C6C60
        int32_t get_TimeJumpThreshold();  // RVA: 0x6C6B70
        void set_TimeJumpThreshold(int32_t value);  // RVA: 0x6C6BA0
        bool get_UseDsp();  // RVA: 0x6C6B80
        void set_UseDsp(bool value);  // RVA: 0x6C6BB0
        bool get_WatchTimeScale();  // RVA: 0x6C6B90
        void set_WatchTimeScale(bool value);  // RVA: 0x6C6BC0
        static SpeedHackDetector* xwg();  // RVA: 0x6C6CE0
        static SpeedHackDetector* xwh();  // RVA: 0x6C6D10
        static SpeedHackDetector* xwi(Action* a);  // RVA: 0x6C6F80
        static SpeedHackDetector* xwj(Action* a, float b);  // RVA: 0x6C70A0
        static SpeedHackDetector* xwk(Action* a, float b, uint8_t c);  // RVA: 0x6C7190
        static SpeedHackDetector* xwl(Action* a, float b, uint8_t c, int32_t d);  // RVA: 0x6C7250
        static void xwm();  // RVA: 0x6C72E0
        static void xwn();  // RVA: 0x6C73F0
        static void xwo(float a);  // RVA: 0x6C7500
        static void xwp(float a);  // RVA: 0x6C7660
        static void xwq();  // RVA: 0x6C77A0
        static void xwr();  // RVA: 0x6C78D0
        void xws();  // RVA: 0x6C79F0
        void .ctor();  // RVA: 0x6C6AF0
        void OnApplicationPause(bool pause);  // RVA: 0x6C66C0
        void Update();  // RVA: 0x6C6750
        SpeedHackDetector* xwt(Action* a, float b, uint8_t c, int32_t d);  // RVA: 0x6C7AE0
        void xva();  // RVA: 0x6C6C30
        void xuw();  // RVA: 0x6C6BD0
        bool xwu(int64_t a, int64_t b, int64_t c);  // RVA: 0x6C7D50
        void xwv(float a);  // RVA: 0x6C7E10
        bool xww();  // RVA: 0x6C7E60
        void xwx(float a);  // RVA: 0x6C7F00
        void xwy();  // RVA: 0x6C7F40
        void xwz();  // RVA: 0x6C7F60
    };

} // namespace CodeStage.AntiCheat.Detectors

// Namespace: <global>
class dcq
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    CheckResult <bmvx>k__BackingField; // 0x0010
    uint8_t pad_0011[0x3]; // 0x0011
    ErrorKind <bmvy>k__BackingField; // 0x0014

    // Methods
    CheckResult xxa();  // RVA: 0x66DB40
    ErrorKind xxb();  // RVA: 0x6DBF40
    void .ctor(CheckResult a, ErrorKind b);  // RVA: 0x6DBF00
    Il2CppString* xvb();  // RVA: 0x6DBDF0
    Il2CppString* ToString();  // RVA: 0x6DBDF0
};

// Namespace: <global>
class OnlineTimeCallback : public MulticastDelegate
{
public:

    // Methods
    void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x6C6350
    void Invoke(OnlineTimeResult result);  // RVA: 0x6C6310
    IAsyncResult* BeginInvoke(OnlineTimeResult result, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x6C6290
    void EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
};

// Namespace: <global>
class TimeCheatingDetectorEventHandler : public MulticastDelegate
{
public:

    // Methods
    void .ctor(Il2CppObject* object, intptr_t method);  // RVA: 0x6C8060
    void Invoke(CheckResult result, ErrorKind error);  // RVA: 0x6C8050
    IAsyncResult* BeginInvoke(CheckResult result, ErrorKind error, AsyncCallback* callback, Il2CppObject* object);  // RVA: 0x6C7FB0
    void EndInvoke(IAsyncResult* result);  // RVA: 0x66DCC0
};

// Namespace: <global>
struct OnlineTimeResult
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    bool success; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppString* error; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    int64_t errorResponseCode; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    double onlineSecondsUtc; // 0x0028
    uint8_t pad_0029[0x7]; // 0x0029
    DateTime onlineDateTimeUtc; // 0x0030

    // Methods
    bool xxc();  // RVA: 0x66E000
    Il2CppString* xxd();  // RVA: 0x66E010
    int64_t xxe();  // RVA: 0x6C6500
    double xxf();  // RVA: 0x6C6510
    DateTime xxg();  // RVA: 0x63C8B0
    OnlineTimeResult xxh(double a, DateTime b);  // RVA: 0x6C6520
    OnlineTimeResult xxi(Il2CppString* a, int64_t b);  // RVA: 0x6C65A0
    Il2CppString* ToString();  // RVA: 0x6C6400
};

// Namespace: <global>
struct CheckResult
{
public:
    // Static fields
    // static CheckResult Unknown;
    // static CheckResult CheckPassed;
    // static CheckResult WrongTimeDetected;
    // static CheckResult CheatDetected;
    // static CheckResult Error;

    uint8_t pad_0000[0x10]; // 0x0000
    int32_t value__; // 0x0010
};

// Namespace: <global>
struct ErrorKind
{
public:
    // Static fields
    // static ErrorKind NoError;
    // static ErrorKind IncorrectUri;
    // static ErrorKind OnlineTimeError;
    // static ErrorKind NotStarted;
    // static ErrorKind AlreadyCheckingForCheat;
    // static ErrorKind Unknown;

    uint8_t pad_0000[0x10]; // 0x0000
    int32_t value__; // 0x0010
};

// Namespace: <global>
struct RequestMethod
{
public:
    // Static fields
    // static RequestMethod Head;
    // static RequestMethod Get;

    uint8_t pad_0000[0x10]; // 0x0000
    int32_t value__; // 0x0010
};

// Namespace: <global>
class dcr
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmvz; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmwa; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    TimeCheatingDetector* bmwb; // 0x0020

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    void xxj();  // RVA: 0x632CB0
    bool MoveNext();  // RVA: 0x6DBF50
    Il2CppObject* xxk();  // RVA: 0x68F440
    void xxl();  // RVA: 0x6DC370
    Il2CppObject* xxm();  // RVA: 0x68F440
};

// Namespace: <global>
struct <ForceCheckAwaitable>d__77
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t <>1__state; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    UnityEngine.Awaitable.AwaitableAsyncMethodBuilder<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.CheckResult> <>t__builder; // 0x0018
    uint8_t pad_0019[0xF]; // 0x0019
    TimeCheatingDetector* <>4__this; // 0x0028
    uint8_t pad_0029[0x7]; // 0x0029
    Awaiter <>u__1; // 0x0030

    // Methods
    void MoveNext();  // RVA: 0x6CAAF0
    void SetStateMachine(IAsyncStateMachine* stateMachine);  // RVA: 0x6CAD80
};

// Namespace: <global>
class dcs
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmwc; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmwd; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    TimeCheatingDetector* bmwe; // 0x0020

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    void xxn();  // RVA: 0x632CB0
    bool MoveNext();  // RVA: 0x6DC3B0
    Il2CppObject* xxo();  // RVA: 0x68F440
    void xxp();  // RVA: 0x6DC4C0
    Il2CppObject* xxq();  // RVA: 0x68F440
};

// Namespace: <global>
struct <ForceCheckTask>d__76
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t <>1__state; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    System.Runtime.CompilerServices.AsyncTaskMethodBuilder<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.CheckResult> <>t__builder; // 0x0018
    uint8_t pad_0019[0x17]; // 0x0019
    TimeCheatingDetector* <>4__this; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    TaskAwaiter <>u__1; // 0x0038

    // Methods
    void MoveNext();  // RVA: 0x6CADB0
    void SetStateMachine(IAsyncStateMachine* stateMachine);  // RVA: 0x6CB0C0
};

// Namespace: <global>
struct <GetOnlineTimeAwaitable>d__67
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t <>1__state; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    UnityEngine.Awaitable.AwaitableAsyncMethodBuilder<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> <>t__builder; // 0x0018
    uint8_t pad_0019[0xF]; // 0x0019
    CancellationToken cancellationToken; // 0x0028
    uint8_t pad_0029[0x7]; // 0x0029
    Uri* uri; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    RequestMethod method; // 0x0038
    uint8_t pad_0039[0x7]; // 0x0039
    OnlineTimeResult <result>5__2; // 0x0040
    uint8_t pad_0041[0x27]; // 0x0041
    Awaiter <>u__1; // 0x0068
    uint8_t pad_0069[0x7]; // 0x0069
    UnityWebRequest* <wr>5__3; // 0x0070

    // Methods
    void MoveNext();  // RVA: 0x6CB440
    void SetStateMachine(IAsyncStateMachine* stateMachine);  // RVA: 0x6CBD30
};

// Namespace: <global>
class dct
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmwf; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmwg; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    Il2CppString* bmwh; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    OnlineTimeCallback* bmwi; // 0x0028
    uint8_t pad_0029[0x7]; // 0x0029
    RequestMethod bmwj; // 0x0030

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    void xxr();  // RVA: 0x632CB0
    bool MoveNext();  // RVA: 0x6DC500
    Il2CppObject* xxs();  // RVA: 0x68F440
    void xxt();  // RVA: 0x6DC5B0
    Il2CppObject* xxu();  // RVA: 0x68F440
};

// Namespace: <global>
class dcu
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmwk; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmwl; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    Uri* bmwm; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    RequestMethod bmwn; // 0x0028
    uint8_t pad_0029[0x7]; // 0x0029
    OnlineTimeCallback* bmwo; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    OnlineTimeResult bmwp; // 0x0038
    uint8_t pad_0039[0x27]; // 0x0039
    UnityWebRequest* bmwq; // 0x0060

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    Il2CppObject* xxx();  // RVA: 0x68F440
    void xxw();  // RVA: 0x6DCB00
    void gwy();  // RVA: 0x6DC9D0
    Il2CppObject* xxz();  // RVA: 0x68F440
    void dqy();  // RVA: 0x6DC930
    void gqn();  // RVA: 0x6DC980
    void mvg();  // RVA: 0x6DCA20
    bool MoveNext();  // RVA: 0x6DC5F0
    void xxv();  // RVA: 0x6DCA70
    void xxy();  // RVA: 0x6DCB50
};

// Namespace: <global>
struct <GetOnlineTimeTask>d__63
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t <>1__state; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    System.Runtime.CompilerServices.AsyncTaskMethodBuilder<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> <>t__builder; // 0x0018
    uint8_t pad_0019[0x17]; // 0x0019
    CancellationToken cancellationToken; // 0x0030
    uint8_t pad_0031[0x7]; // 0x0031
    Uri* uri; // 0x0038
    uint8_t pad_0039[0x7]; // 0x0039
    RequestMethod method; // 0x0040
    uint8_t pad_0041[0x7]; // 0x0041
    OnlineTimeResult <result>5__2; // 0x0048
    uint8_t pad_0049[0x27]; // 0x0049
    TaskAwaiter <>u__1; // 0x0070
    uint8_t pad_0071[0x7]; // 0x0071
    UnityWebRequest* <wr>5__3; // 0x0078
    uint8_t pad_0079[0x7]; // 0x0079
    UnityWebRequestAsyncOperation* <asyncOperation>5__4; // 0x0080

    // Methods
    void MoveNext();  // RVA: 0x6CBD60
    void SetStateMachine(IAsyncStateMachine* stateMachine);  // RVA: 0x6CC750
};

namespace CodeStage.AntiCheat.Detectors
{

    // Namespace: CodeStage.AntiCheat.Detectors
    class TimeCheatingDetector : public ACTkDetectorBase`1
    {
    public:
        // Static fields
        // static Il2CppString* ComponentName;
        // static Il2CppString* bmwr;
        // static int32_t bmws;
        // static WaitForEndOfFrame* bmwt;
        // static System.Lazy<dat> <bmwu>k__BackingField;
        // static bool bmwv;
    
        uint8_t pad_0000[0x60]; // 0x0000
        TimeCheatingDetectorEventHandler* bmww; // 0x0060
        uint8_t pad_0061[0x7]; // 0x0061
        Il2CppString* requestUrl; // 0x0068
        uint8_t pad_0069[0x7]; // 0x0069
        RequestMethod requestMethod; // 0x0070
        uint8_t pad_0071[0x3]; // 0x0071
        int32_t timeoutSeconds; // 0x0074
        uint8_t pad_0075[0x3]; // 0x0075
        float interval; // 0x0078
        uint8_t pad_0079[0x3]; // 0x0079
        int32_t realCheatThreshold; // 0x007C
        uint8_t pad_007D[0x3]; // 0x007D
        int32_t wrongTimeThreshold; // 0x0080
        uint8_t pad_0081[0x3]; // 0x0081
        bool ignoreSetCorrectTime; // 0x0084
        uint8_t pad_0085[0x3]; // 0x0085
        ErrorKind <bmwx>k__BackingField; // 0x0088
        uint8_t pad_0089[0x3]; // 0x0089
        CheckResult <bmwy>k__BackingField; // 0x008C
        uint8_t pad_008D[0x3]; // 0x008D
        OnlineTimeResult <bmwz>k__BackingField; // 0x0090
        uint8_t pad_0091[0x27]; // 0x0091
        bool <bmxa>k__BackingField; // 0x00B8
        uint8_t pad_00B9[0x7]; // 0x00B9
        Il2CppString* bmxb; // 0x00C0
        uint8_t pad_00C1[0x7]; // 0x00C1
        Uri* bmxc; // 0x00C8
        uint8_t pad_00C9[0x7]; // 0x00C9
        TimeCheatingDetectorEventHandler* bmxd; // 0x00D0
        uint8_t pad_00D1[0x7]; // 0x00D1
        float bmxe; // 0x00D8
        uint8_t pad_00D9[0x3]; // 0x00D9
        bool bmxf; // 0x00DC
        uint8_t pad_00DD[0x3]; // 0x00DD
        double bmxg; // 0x00E0
        uint8_t pad_00E1[0x7]; // 0x00E1
        System.Action<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.ErrorKind> bmxh; // 0x00E8
        uint8_t pad_00E9[0x7]; // 0x00E9
        Action* bmxi; // 0x00F0
        uint8_t pad_00F1[0x7]; // 0x00F1
        int32_t threshold; // 0x00F8
        uint8_t pad_00F9[0x7]; // 0x00F9
        Il2CppString* timeServer; // 0x0100
    
        // Methods
        dcq* xya();  // RVA: 0x6C85D0
        static System.Lazy<dat> xyb();  // RVA: 0x6C8650
        void xyc(TimeCheatingDetectorEventHandler* a);  // RVA: 0x6C86A0
        void xyd(TimeCheatingDetectorEventHandler* a);  // RVA: 0x6C8740
        Il2CppString* xye();  // RVA: 0x6C87E0
        void xyf(Il2CppString* a);  // RVA: 0x6C87F0
        ErrorKind xyg();  // RVA: 0x6C88B0
        void xyh(ErrorKind a);  // RVA: 0x6C88C0
        CheckResult xyi();  // RVA: 0x6C88D0
        void xyj(CheckResult a);  // RVA: 0x6C88E0
        OnlineTimeResult xyk();  // RVA: 0x6C88F0
        void xyl(OnlineTimeResult a);  // RVA: 0x6C8920
        bool xym();  // RVA: 0x6C8950
        void xyn(bool a);  // RVA: 0x6C8960
        void OnApplicationPause(bool pauseStatus);  // RVA: 0x6C8110
        void Update();  // RVA: 0x6C8190
        static TimeCheatingDetector* xyo();  // RVA: 0x6C8970
        static TimeCheatingDetector* xyp(TimeCheatingDetectorEventHandler* a);  // RVA: 0x6C89A0
        static TimeCheatingDetector* xyq(float a, TimeCheatingDetectorEventHandler* b);  // RVA: 0x6C8B90
        static void xyr();  // RVA: 0x6C8BF0
        static void xys();  // RVA: 0x6C8D00
        static IEnumerator* xyt(Il2CppString* a, OnlineTimeCallback* b, RequestMethod c);  // RVA: 0x6C8E10
        static IEnumerator* xyu(Uri* a, OnlineTimeCallback* b, RequestMethod c);  // RVA: 0x6C8EB0
        static System.Threading.Tasks.Task<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xyv(Il2CppString* a, RequestMethod b);  // RVA: 0x6C8F50
        static System.Threading.Tasks.Task<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xyw(Il2CppString* a, CancellationToken b, RequestMethod c);  // RVA: 0x6C9020
        static System.Threading.Tasks.Task<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xyx(Uri* a, RequestMethod b);  // RVA: 0x6C90A0
        static System.Threading.Tasks.Task<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xyy(Uri* a, CancellationToken b, RequestMethod c);  // RVA: 0x6C9130
        static UnityEngine.Awaitable<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xyz(Il2CppString* a, RequestMethod b);  // RVA: 0x6C9280
        static UnityEngine.Awaitable<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xza(Il2CppString* a, CancellationToken b, RequestMethod c);  // RVA: 0x6C9350
        static UnityEngine.Awaitable<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xzb(Uri* a, RequestMethod b);  // RVA: 0x6C93D0
        static UnityEngine.Awaitable<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.OnlineTimeResult> xzc(Uri* a, CancellationToken b, RequestMethod c);  // RVA: 0x6C9460
        static dat* xzd();  // RVA: 0x6C9570
        static UnityWebRequest* xze(Uri* a, RequestMethod b);  // RVA: 0x6C95C0
        static void xzf(UnityWebRequest* a, OnlineTimeResult b);  // RVA: 0x6C9800
        static Uri* xzg(Il2CppString* a);  // RVA: 0x6C9AD0
        static bool xzh(Il2CppString* a, DateTime b);  // RVA: 0x6C9BA0
        void xzi();  // RVA: 0x6C9F10
        bool xzj();  // RVA: 0x6C9FC0
        IEnumerator* xzk();  // RVA: 0x6CA050
        System.Threading.Tasks.Task<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.CheckResult> xzl();  // RVA: 0x6CA0C0
        UnityEngine.Awaitable<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.CheckResult> xzm();  // RVA: 0x6CA1B0
        bool xzn();  // RVA: 0x6CA270
        TimeCheatingDetector* xzo(float a, TimeCheatingDetectorEventHandler* b);  // RVA: 0x6CA3A0
        bool xzp(TimeCheatingDetector* a);  // RVA: 0x6CA4F0
        void xva();  // RVA: 0x6C85C0
        bool xuv();  // RVA: 0x6C84A0
        void xux();  // RVA: 0x6C8570
        void xuw();  // RVA: 0x6C8500
        IEnumerator* xzq();  // RVA: 0x6CA5C0
        void xzr();  // RVA: 0x6CA630
        void xzs(OnlineTimeResult a);  // RVA: 0x6CA770
        void xzt(System.Action<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.ErrorKind> a);  // RVA: 0x6CA800
        void xzu(System.Action<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.ErrorKind> a);  // RVA: 0x6CA8C0
        void xzv(Action* a);  // RVA: 0x6CA980
        void xzw(Action* a);  // RVA: 0x6CAA30
        static double xzx(Il2CppString* a);  // RVA: 0x6CAAE0
        static void xzy(System.Action<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.ErrorKind> a);  // RVA: 0x632CB0
        static void xzz(Action* a, int32_t b);  // RVA: 0x632CB0
        static void yaa(Action* a, System.Action<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.ErrorKind> b, int32_t c);  // RVA: 0x632CB0
        static void yab(float a, Action* b, System.Action<CodeStage.AntiCheat.Detectors.TimeCheatingDetector.ErrorKind> c, Action* d);  // RVA: 0x632CB0
        void .ctor();  // RVA: 0x6C8380
        static void .cctor();  // RVA: 0x6C8260
    };

} // namespace CodeStage.AntiCheat.Detectors

// Namespace: <global>
class dcv
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    bool <bmxj>k__BackingField; // 0x0010
    bool <bmxk>k__BackingField; // 0x0011
    bool <bmxl>k__BackingField; // 0x0012
    bool <bmxm>k__BackingField; // 0x0013

    // Methods
    bool yac();  // RVA: 0x66E8B0
    bool yad();  // RVA: 0x67BD00
    bool yae();  // RVA: 0x6DBDC0
    bool yaf();  // RVA: 0x6DBDD0
    void .ctor(bool a, bool b, bool c, bool d);  // RVA: 0x6DCD00
    Il2CppString* xvb();  // RVA: 0x6DCB90
    Il2CppString* ToString();  // RVA: 0x6DCB90
};

// Namespace: <global>
class dcw
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmxn; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmxo; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    WallHackDetector* bmxp; // 0x0020
    uint8_t pad_0021[0x7]; // 0x0021
    RenderTexture* bmxq; // 0x0028

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    void yag();  // RVA: 0x632CB0
    bool MoveNext();  // RVA: 0x6EFF20
    Il2CppObject* yah();  // RVA: 0x68F440
    void yai();  // RVA: 0x6F0550
    Il2CppObject* yaj();  // RVA: 0x68F440
};

// Namespace: <global>
class dcx
{
public:
    uint8_t pad_0000[0x10]; // 0x0000
    int32_t bmxr; // 0x0010
    uint8_t pad_0011[0x7]; // 0x0011
    Il2CppObject* bmxs; // 0x0018
    uint8_t pad_0019[0x7]; // 0x0019
    WallHackDetector* bmxt; // 0x0020

    // Methods
    void .ctor(int32_t a);  // RVA: 0x67B210
    void yak();  // RVA: 0x632CB0
    bool MoveNext();  // RVA: 0x6F0590
    Il2CppObject* yal();  // RVA: 0x68F440
    void yam();  // RVA: 0x6F0650
    Il2CppObject* yan();  // RVA: 0x68F440
};

namespace CodeStage.AntiCheat.Detectors
{

    // Namespace: CodeStage.AntiCheat.Detectors
    class WallHackDetector : public ACTkDetectorBase`1
    {
    public:
        // Static fields
        // static int32_t bmxy;
        // static float bmya;
        // static int32_t bmxz;
        // static int32_t bmxx;
        // static Il2CppString* bmxw;
        // static Il2CppString* bmxv;
        // static Il2CppString* bmxu;
        // static Il2CppString* ComponentName;
    
        uint8_t pad_0000[0x60]; // 0x0000
        Vector3 bmyb; // 0x0060
        uint8_t pad_0061[0xF]; // 0x0061
        WaitForEndOfFrame* bmyc; // 0x0070
        uint8_t pad_0071[0x7]; // 0x0071
        bool checkRigidbody; // 0x0078
        bool checkController; // 0x0079
        bool checkWireframe; // 0x007A
        bool checkRaycast; // 0x007B
        int32_t wireframeDelay; // 0x007C
        uint8_t pad_007D[0x3]; // 0x007D
        int32_t raycastDelay; // 0x0080
        uint8_t pad_0081[0x3]; // 0x0081
        Vector3 spawnPosition; // 0x0084
        uint8_t pad_0085[0xB]; // 0x0085
        uint8_t maxFalsePositives; // 0x0090
        uint8_t pad_0091[0x7]; // 0x0091
        GameObject* bmyd; // 0x0098
        uint8_t pad_0099[0x7]; // 0x0099
        GameObject* bmye; // 0x00A0
        uint8_t pad_00A1[0x7]; // 0x00A1
        GameObject* bmyf; // 0x00A8
        uint8_t pad_00A9[0x7]; // 0x00A9
        Camera* bmyg; // 0x00B0
        uint8_t pad_00B1[0x7]; // 0x00B1
        MeshRenderer* bmyh; // 0x00B8
        uint8_t pad_00B9[0x7]; // 0x00B9
        MeshRenderer* bmyi; // 0x00C0
        uint8_t pad_00C1[0x7]; // 0x00C1
        Color bmyj; // 0x00C8
        uint8_t pad_00C9[0xF]; // 0x00C9
        Color bmyk; // 0x00D8
        uint8_t pad_00D9[0xF]; // 0x00D9
        Shader* bmyl; // 0x00E8
        uint8_t pad_00E9[0x7]; // 0x00E9
        Material* bmym; // 0x00F0
        uint8_t pad_00F1[0x7]; // 0x00F1
        Texture2D* bmyn; // 0x00F8
        uint8_t pad_00F9[0x7]; // 0x00F9
        Texture2D* bmyo; // 0x0100
        uint8_t pad_0101[0x7]; // 0x0101
        RenderTexture* bmyp; // 0x0108
        uint8_t pad_0109[0x7]; // 0x0109
        int32_t bmyq; // 0x0110
        uint8_t pad_0111[0x3]; // 0x0111
        int32_t bmyr; // 0x0114
        uint8_t pad_0115[0x3]; // 0x0115
        Rigidbody* bmys; // 0x0118
        uint8_t pad_0119[0x7]; // 0x0119
        CharacterController* bmyt; // 0x0120
        uint8_t pad_0121[0x7]; // 0x0121
        float bmyu; // 0x0128
        uint8_t pad_0129[0x3]; // 0x0129
        uint8_t bmyv; // 0x012C
        uint8_t bmyw; // 0x012D
        uint8_t bmyx; // 0x012E
        uint8_t bmyy; // 0x012F
        bool bmyz; // 0x0130
        uint8_t pad_0131[0x7]; // 0x0131
        RaycastHit[][] bmza; // 0x0138
    
        // Methods
        dcv* yao();  // RVA: 0x6CF100
        bool yap();  // RVA: 0x6CF180
        void yaq(bool a);  // RVA: 0x6CF190
        bool yar();  // RVA: 0x6CF260
        void yas(bool a);  // RVA: 0x6CF270
        bool yat();  // RVA: 0x6CF340
        void yau(bool a);  // RVA: 0x6CF350
        bool yav();  // RVA: 0x6CF420
        void yaw(bool a);  // RVA: 0x6CF430
        static WallHackDetector* yax();  // RVA: 0x6CF500
        static WallHackDetector* yay();  // RVA: 0x6CF530
        static WallHackDetector* yaz(Action* a);  // RVA: 0x6CF760
        static WallHackDetector* yba(Action* a, Vector3 b);  // RVA: 0x6CF860
        static WallHackDetector* ybb(Action* a, Vector3 b, uint8_t c);  // RVA: 0x6CF920
        static void ybc();  // RVA: 0x6CF9B0
        static void ybd();  // RVA: 0x6CFAC0
        void ybe();  // RVA: 0x6CFBD0
        void .ctor();  // RVA: 0x6CED90
        void OnDestroy();  // RVA: 0x6CE0B0
        void FixedUpdate();  // RVA: 0x6CDFC0
        void Update();  // RVA: 0x6CEC10
        WallHackDetector* ybf(Action* a, Vector3 b, uint8_t c);  // RVA: 0x6CFCB0
        void xva();  // RVA: 0x6CF0C0
        void xux();  // RVA: 0x6CEF30
        bool xuy();  // RVA: 0x6CF030
        void xuw();  // RVA: 0x6CEEC0
        void ybg();  // RVA: 0x6CFF50
        IEnumerator* ybh();  // RVA: 0x6D15E0
        void StartRigidModule();  // RVA: 0x6CE790
        void StartControllerModule();  // RVA: 0x6CE540
        void ybi();  // RVA: 0x6D1650
        void ShootWireframeModule();  // RVA: 0x6CE470
        IEnumerator* ybj();  // RVA: 0x6D1720
        bool ybk(Color a, Color b);  // RVA: 0x6D1790
        void ybl();  // RVA: 0x6D1880
        void ShootRaycastModule();  // RVA: 0x6CE260
        void ybm();  // RVA: 0x6D1940
        void ybn();  // RVA: 0x6D1A30
        void ybo();  // RVA: 0x6D1AD0
        void ybp();  // RVA: 0x6D1B60
        void ybq();  // RVA: 0x6D1BC0
        void ybr();  // RVA: 0x6D1C20
        void ybs();  // RVA: 0x6D1DC0
        void ybt();  // RVA: 0x6D1F90
        void ybu();  // RVA: 0x6D2050
        bool ybv();  // RVA: 0x6D2110
        static Color32 ybw();  // RVA: 0x6D21F0
        static bool ybx(Color32 a, Color32 b, int32_t c);  // RVA: 0x6D2240
    };

} // namespace CodeStage.AntiCheat.Detectors

namespace CodeStage.AntiCheat.Common
{

    // Namespace: CodeStage.AntiCheat.Common
    class ACTk
    {
    public:
        // Static fields
        // static Il2CppString* bmzb;
        // static Il2CppString* bmzc;
        // static Il2CppString* bmzd;
        // static Il2CppString* bmze;
        // static Char[][] bmzf;
        // static Il2CppString* bmzg;
        // static Il2CppString* bmzh;
    
    
        // Methods
        static void GetUnityInfo();  // RVA: 0x6DD1A0
        static void yby(Il2CppString* a, Exception* b);  // RVA: 0x6DD330
        static void ybz(Il2CppString* a, Il2CppString* b, Exception* c);  // RVA: 0x6DD410
        static Il2CppString* yca(Il2CppString* a, Il2CppString* b, Exception* c);  // RVA: 0x6DD4D0
        static Il2CppString* ycb(Exception* a);  // RVA: 0x6DD6E0
        static void .cctor();  // RVA: 0x6DD2A0
    };

    // Namespace: CodeStage.AntiCheat.Common
    struct ACTkByte16
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t b1; // 0x0010
        uint8_t b2; // 0x0011
        uint8_t b3; // 0x0012
        uint8_t b4; // 0x0013
        uint8_t b5; // 0x0014
        uint8_t b6; // 0x0015
        uint8_t b7; // 0x0016
        uint8_t b8; // 0x0017
        uint8_t b9; // 0x0018
        uint8_t b10; // 0x0019
        uint8_t b11; // 0x001A
        uint8_t b12; // 0x001B
        uint8_t b13; // 0x001C
        uint8_t b14; // 0x001D
        uint8_t b15; // 0x001E
        uint8_t b16; // 0x001F
    
        // Methods
        bool Equals(ACTkByte16 other);  // RVA: 0x6DCEC0
        bool Equals(Il2CppObject* obj);  // RVA: 0x6DCD60
        int32_t GetHashCode();  // RVA: 0x6DCF60
    };

    // Namespace: CodeStage.AntiCheat.Common
    struct ACTkByte4
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t b1; // 0x0010
        uint8_t b2; // 0x0011
        uint8_t b3; // 0x0012
        uint8_t b4; // 0x0013
    
        // Methods
        void ycc();  // RVA: 0x6DD120
        void ycd();  // RVA: 0x6DD130
    };

    // Namespace: CodeStage.AntiCheat.Common
    struct ACTkByte8
    {
    public:
        uint8_t pad_0000[0x10]; // 0x0000
        uint8_t b1; // 0x0010
        uint8_t b2; // 0x0011
        uint8_t b3; // 0x0012
        uint8_t b4; // 0x0013
        uint8_t b5; // 0x0014
        uint8_t b6; // 0x0015
        uint8_t b7; // 0x0016
        uint8_t b8; // 0x0017
    
        // Methods
        void yce();  // RVA: 0x6DD140
        void ycf();  // RVA: 0x6DD170
    };

    // Namespace: CodeStage.AntiCheat.Common
    class BackgroundThreadAccessException : public Exception
    {
    public:
        uint8_t pad_0000[0x90]; // 0x0000
        Il2CppString* <bmzi>k__BackingField; // 0x0090
    
        // Methods
        Il2CppString* ycg();  // RVA: 0x6DDCC0
        void .ctor(Il2CppString* apiName);  // RVA: 0x6DDAD0
    };

    // Namespace: CodeStage.AntiCheat.Common
    class ContainerHolder
    {
    public:
        // Static fields
        // static Il2CppString* bmzj;
        // static GameObject* container;
        // static bool bmzk;
    
    
        // Methods
        static void AfterAssembliesLoaded();  // RVA: 0x6DDCD0
        static void BeforeSplashScreen();  // RVA: 0x6DDE90
        static void BeforeSceneLoad();  // RVA: 0x6DDDB0
        static void ych(Il2CppString* a);  // RVA: 0x6DDF70
        static a yci();  // RVA: 0x563E10
        static void ycj(GameObject* a);  // RVA: 0x6DE150
    };

} // namespace CodeStage.AntiCheat.Common

// Namespace: <global>
class dcy`1 : public MonoBehaviour
{
public:
    // Static fields
    // static a <bmzo>k__BackingField;

    bool keepAlive; // 0x0000
    int32_t bmzl; // 0x0000
    bool bmzm; // 0x0000
    Scene bmzn; // 0x0000

    // Methods
    static a yck();  // RVA: 0x563E10
    static void ycl(a a);  // RVA: 0x563E10
    static a ycm();  // RVA: 0x563E10
    void Awake();  // RVA: 0x42DF20
    void Start();  // RVA: 0x42DF20
    void OnDestroy();  // RVA: 0x42DF20
    void wdb(Scene a, LoadSceneMode b);
    void ycn(Scene a);
    bool xzp(a a);  // RVA: 0x563E10
    void yco();  // RVA: 0x42DF20
    void .ctor();  // RVA: 0x42DF20
};

// Namespace: <global>
class dcz
{
public:
    // Static fields
    // static Il2CppString* bmzp;
    // static Il2CppString* bmzq;
    // static System.Nullable<System.Boolean> bmzr;


    // Methods
    static Il2CppString* lih();  // RVA: 0x6F0DD0
    static bool ycs();  // RVA: 0x6F1210
    static Il2CppString* ycr();  // RVA: 0x6F1110
    static Il2CppString* dko();  // RVA: 0x6F0890
    static void ycp(bool a);  // RVA: 0x6F0ED0
    static void fpo(bool a);  // RVA: 0x6F0990
    static Il2CppString* yct();  // RVA: 0x6F12F0
    static Il2CppString* khf();  // RVA: 0x6F0BD0
    static Il2CppString* jyg();  // RVA: 0x6F0AD0
    static Il2CppString* ctw();  // RVA: 0x6F0790
    static Il2CppString* ki();  // RVA: 0x6F0CD0
    static Il2CppString* ceg();  // RVA: 0x6F0690
    static Il2CppString* ycq();  // RVA: 0x6F1010
};

// Namespace: <global>
struct __StaticArrayInitTypeSize=10
{
public:
};

// Namespace: <global>
struct __StaticArrayInitTypeSize=32
{
public:
};

// Namespace: <global>
struct __StaticArrayInitTypeSize=8908
{
public:
};

// Namespace: <global>
struct __StaticArrayInitTypeSize=16301
{
public:
};

// Namespace: <global>
class <PrivateImplementationDetails>
{
public:
    // Static fields
    // static __StaticArrayInitTypeSize=32 2EF83B43314F8CD03190EEE30ECCF048DA37791237F27C62A579F23EACE9FD70;
    // static __StaticArrayInitTypeSize=10 506D5506D226B0865AAC3B4C2D1BD1C1E96B7A1FEBEF4E1EF21BAB4BF2DC0DC1;
    // static __StaticArrayInitTypeSize=8908 612E7B8C70814984DDE70F0FAE08D1F0E0DACA659396C8E67CC62D26C6F52F21;
    // static __StaticArrayInitTypeSize=16301 E9E9A74FDD13D111B1E042A0AE8C8E40E3F5499621A7CDEC03ACF40350023F30;

};

// Namespace: <global>
struct a_
{
public:
};

namespace <PrivateImplementationDetails>{6CDD5085-30BD-40AD-81A6-F8C9391CA445}
{

    // Namespace: <PrivateImplementationDetails>{6CDD5085-30BD-40AD-81A6-F8C9391CA445}
    class a
    {
    public:
        // Static fields
        // static a_ a_;
        // static Byte[][] a__;
        // static String[][] a___;
    
    
        // Methods
        static Il2CppString* a_(int32_t param0, int32_t param1, int32_t param2);  // RVA: 0x6DE460
        static Il2CppString* a();  // RVA: 0x6DE550
        static Il2CppString* b();  // RVA: 0x6DE5E0
        static Il2CppString* c();  // RVA: 0x6DF6C0
        static Il2CppString* d();  // RVA: 0x6E07A0
        static Il2CppString* e();  // RVA: 0x6E1880
        static Il2CppString* f();  // RVA: 0x6E2960
        static Il2CppString* g();  // RVA: 0x6E3A40
        static Il2CppString* h();  // RVA: 0x6E4B20
        static Il2CppString* i();  // RVA: 0x6E5C00
        static Il2CppString* j();  // RVA: 0x6E6CE0
        static Il2CppString* k();  // RVA: 0x6E7DC0
        static Il2CppString* l();  // RVA: 0x6E8EA0
        static Il2CppString* m();  // RVA: 0x6E9F80
        static Il2CppString* n();  // RVA: 0x6EB060
        static Il2CppString* o();  // RVA: 0x6EC140
        static Il2CppString* p();  // RVA: 0x6ED220
        static Il2CppString* q();  // RVA: 0x6EE300
        static Il2CppString* r();  // RVA: 0x6EF3E0
        static Il2CppString* s();  // RVA: 0x6EFA20
        static Il2CppString* t();  // RVA: 0x6EFAC0
        static Il2CppString* u();  // RVA: 0x6EFB60
        static Il2CppString* v();  // RVA: 0x6EFC00
        static Il2CppString* w();  // RVA: 0x6EFCA0
        static Il2CppString* x();  // RVA: 0x6EFD40
        static Il2CppString* y();  // RVA: 0x6EFDE0
        static Il2CppString* z();  // RVA: 0x6EFE80
        static Il2CppString* ba();  // RVA: 0x6DE680
        static Il2CppString* bb();  // RVA: 0x6DE720
        static Il2CppString* bc();  // RVA: 0x6DE7C0
        static Il2CppString* bd();  // RVA: 0x6DE860
        static Il2CppString* be();  // RVA: 0x6DE900
        static Il2CppString* bf();  // RVA: 0x6DE9A0
        static Il2CppString* bg();  // RVA: 0x6DEA40
        static Il2CppString* bh();  // RVA: 0x6DEAE0
        static Il2CppString* bi();  // RVA: 0x6DEB80
        static Il2CppString* bj();  // RVA: 0x6DEC20
        static Il2CppString* bk();  // RVA: 0x6DECC0
        static Il2CppString* bl();  // RVA: 0x6DED60
        static Il2CppString* bm();  // RVA: 0x6DEE00
        static Il2CppString* bn();  // RVA: 0x6DEEA0
        static Il2CppString* bo();  // RVA: 0x6DEF40
        static Il2CppString* bp();  // RVA: 0x6DEFE0
        static Il2CppString* bq();  // RVA: 0x6DF080
        static Il2CppString* br();  // RVA: 0x6DF120
        static Il2CppString* bs();  // RVA: 0x6DF1C0
        static Il2CppString* bt();  // RVA: 0x6DF260
        static Il2CppString* bu();  // RVA: 0x6DF300
        static Il2CppString* bv();  // RVA: 0x6DF3A0
        static Il2CppString* bw();  // RVA: 0x6DF440
        static Il2CppString* bx();  // RVA: 0x6DF4E0
        static Il2CppString* by();  // RVA: 0x6DF580
        static Il2CppString* bz();  // RVA: 0x6DF620
        static Il2CppString* ca();  // RVA: 0x6DF760
        static Il2CppString* cb();  // RVA: 0x6DF800
        static Il2CppString* cc();  // RVA: 0x6DF8A0
        static Il2CppString* cd();  // RVA: 0x6DF940
        static Il2CppString* ce();  // RVA: 0x6DF9E0
        static Il2CppString* cf();  // RVA: 0x6DFA80
        static Il2CppString* cg();  // RVA: 0x6DFB20
        static Il2CppString* ch();  // RVA: 0x6DFBC0
        static Il2CppString* ci();  // RVA: 0x6DFC60
        static Il2CppString* cj();  // RVA: 0x6DFD00
        static Il2CppString* ck();  // RVA: 0x6DFDA0
        static Il2CppString* cl();  // RVA: 0x6DFE40
        static Il2CppString* cm();  // RVA: 0x6DFEE0
        static Il2CppString* cn();  // RVA: 0x6DFF80
        static Il2CppString* co();  // RVA: 0x6E0020
        static Il2CppString* cp();  // RVA: 0x6E00C0
        static Il2CppString* cq();  // RVA: 0x6E0160
        static Il2CppString* cr();  // RVA: 0x6E0200
        static Il2CppString* cs();  // RVA: 0x6E02A0
        static Il2CppString* ct();  // RVA: 0x6E0340
        static Il2CppString* cu();  // RVA: 0x6E03E0
        static Il2CppString* cv();  // RVA: 0x6E0480
        static Il2CppString* cw();  // RVA: 0x6E0520
        static Il2CppString* cx();  // RVA: 0x6E05C0
        static Il2CppString* cy();  // RVA: 0x6E0660
        static Il2CppString* cz();  // RVA: 0x6E0700
        static Il2CppString* da();  // RVA: 0x6E0840
        static Il2CppString* db();  // RVA: 0x6E08E0
        static Il2CppString* dc();  // RVA: 0x6E0980
        static Il2CppString* dd();  // RVA: 0x6E0A20
        static Il2CppString* de();  // RVA: 0x6E0AC0
        static Il2CppString* df();  // RVA: 0x6E0B60
        static Il2CppString* dg();  // RVA: 0x6E0C00
        static Il2CppString* dh();  // RVA: 0x6E0CA0
        static Il2CppString* di();  // RVA: 0x6E0D40
        static Il2CppString* dj();  // RVA: 0x6E0DE0
        static Il2CppString* dk();  // RVA: 0x6E0E80
        static Il2CppString* dl();  // RVA: 0x6E0F20
        static Il2CppString* dm();  // RVA: 0x6E0FC0
        static Il2CppString* dn();  // RVA: 0x6E1060
        static Il2CppString* do();  // RVA: 0x6E1100
        static Il2CppString* dp();  // RVA: 0x6E11A0
        static Il2CppString* dq();  // RVA: 0x6E1240
        static Il2CppString* dr();  // RVA: 0x6E12E0
        static Il2CppString* ds();  // RVA: 0x6E1380
        static Il2CppString* dt();  // RVA: 0x6E1420
        static Il2CppString* du();  // RVA: 0x6E14C0
        static Il2CppString* dv();  // RVA: 0x6E1560
        static Il2CppString* dw();  // RVA: 0x6E1600
        static Il2CppString* dx();  // RVA: 0x6E16A0
        static Il2CppString* dy();  // RVA: 0x6E1740
        static Il2CppString* dz();  // RVA: 0x6E17E0
        static Il2CppString* ea();  // RVA: 0x6E1920
        static Il2CppString* eb();  // RVA: 0x6E19C0
        static Il2CppString* ec();  // RVA: 0x6E1A60
        static Il2CppString* ed();  // RVA: 0x6E1B00
        static Il2CppString* ee();  // RVA: 0x6E1BA0
        static Il2CppString* ef();  // RVA: 0x6E1C40
        static Il2CppString* eg();  // RVA: 0x6E1CE0
        static Il2CppString* eh();  // RVA: 0x6E1D80
        static Il2CppString* ei();  // RVA: 0x6E1E20
        static Il2CppString* ej();  // RVA: 0x6E1EC0
        static Il2CppString* ek();  // RVA: 0x6E1F60
        static Il2CppString* el();  // RVA: 0x6E2000
        static Il2CppString* em();  // RVA: 0x6E20A0
        static Il2CppString* en();  // RVA: 0x6E2140
        static Il2CppString* eo();  // RVA: 0x6E21E0
        static Il2CppString* ep();  // RVA: 0x6E2280
        static Il2CppString* eq();  // RVA: 0x6E2320
        static Il2CppString* er();  // RVA: 0x6E23C0
        static Il2CppString* es();  // RVA: 0x6E2460
        static Il2CppString* et();  // RVA: 0x6E2500
        static Il2CppString* eu();  // RVA: 0x6E25A0
        static Il2CppString* ev();  // RVA: 0x6E2640
        static Il2CppString* ew();  // RVA: 0x6E26E0
        static Il2CppString* ex();  // RVA: 0x6E2780
        static Il2CppString* ey();  // RVA: 0x6E2820
        static Il2CppString* ez();  // RVA: 0x6E28C0
        static Il2CppString* fa();  // RVA: 0x6E2A00
        static Il2CppString* fb();  // RVA: 0x6E2AA0
        static Il2CppString* fc();  // RVA: 0x6E2B40
        static Il2CppString* fd();  // RVA: 0x6E2BE0
        static Il2CppString* fe();  // RVA: 0x6E2C80
        static Il2CppString* ff();  // RVA: 0x6E2D20
        static Il2CppString* fg();  // RVA: 0x6E2DC0
        static Il2CppString* fh();  // RVA: 0x6E2E60
        static Il2CppString* fi();  // RVA: 0x6E2F00
        static Il2CppString* fj();  // RVA: 0x6E2FA0
        static Il2CppString* fk();  // RVA: 0x6E3040
        static Il2CppString* fl();  // RVA: 0x6E30E0
        static Il2CppString* fm();  // RVA: 0x6E3180
        static Il2CppString* fn();  // RVA: 0x6E3220
        static Il2CppString* fo();  // RVA: 0x6E32C0
        static Il2CppString* fp();  // RVA: 0x6E3360
        static Il2CppString* fq();  // RVA: 0x6E3400
        static Il2CppString* fr();  // RVA: 0x6E34A0
        static Il2CppString* fs();  // RVA: 0x6E3540
        static Il2CppString* ft();  // RVA: 0x6E35E0
        static Il2CppString* fu();  // RVA: 0x6E3680
        static Il2CppString* fv();  // RVA: 0x6E3720
        static Il2CppString* fw();  // RVA: 0x6E37C0
        static Il2CppString* fx();  // RVA: 0x6E3860
        static Il2CppString* fy();  // RVA: 0x6E3900
        static Il2CppString* fz();  // RVA: 0x6E39A0
        static Il2CppString* ga();  // RVA: 0x6E3AE0
        static Il2CppString* gb();  // RVA: 0x6E3B80
        static Il2CppString* gc();  // RVA: 0x6E3C20
        static Il2CppString* gd();  // RVA: 0x6E3CC0
        static Il2CppString* ge();  // RVA: 0x6E3D60
        static Il2CppString* gf();  // RVA: 0x6E3E00
        static Il2CppString* gg();  // RVA: 0x6E3EA0
        static Il2CppString* gh();  // RVA: 0x6E3F40
        static Il2CppString* gi();  // RVA: 0x6E3FE0
        static Il2CppString* gj();  // RVA: 0x6E4080
        static Il2CppString* gk();  // RVA: 0x6E4120
        static Il2CppString* gl();  // RVA: 0x6E41C0
        static Il2CppString* gm();  // RVA: 0x6E4260
        static Il2CppString* gn();  // RVA: 0x6E4300
        static Il2CppString* go();  // RVA: 0x6E43A0
        static Il2CppString* gp();  // RVA: 0x6E4440
        static Il2CppString* gq();  // RVA: 0x6E44E0
        static Il2CppString* gr();  // RVA: 0x6E4580
        static Il2CppString* gs();  // RVA: 0x6E4620
        static Il2CppString* gt();  // RVA: 0x6E46C0
        static Il2CppString* gu();  // RVA: 0x6E4760
        static Il2CppString* gv();  // RVA: 0x6E4800
        static Il2CppString* gw();  // RVA: 0x6E48A0
        static Il2CppString* gx();  // RVA: 0x6E4940
        static Il2CppString* gy();  // RVA: 0x6E49E0
        static Il2CppString* gz();  // RVA: 0x6E4A80
        static Il2CppString* ha();  // RVA: 0x6E4BC0
        static Il2CppString* hb();  // RVA: 0x6E4C60
        static Il2CppString* hc();  // RVA: 0x6E4D00
        static Il2CppString* hd();  // RVA: 0x6E4DA0
        static Il2CppString* he();  // RVA: 0x6E4E40
        static Il2CppString* hf();  // RVA: 0x6E4EE0
        static Il2CppString* hg();  // RVA: 0x6E4F80
        static Il2CppString* hh();  // RVA: 0x6E5020
        static Il2CppString* hi();  // RVA: 0x6E50C0
        static Il2CppString* hj();  // RVA: 0x6E5160
        static Il2CppString* hk();  // RVA: 0x6E5200
        static Il2CppString* hl();  // RVA: 0x6E52A0
        static Il2CppString* hm();  // RVA: 0x6E5340
        static Il2CppString* hn();  // RVA: 0x6E53E0
        static Il2CppString* ho();  // RVA: 0x6E5480
        static Il2CppString* hp();  // RVA: 0x6E5520
        static Il2CppString* hq();  // RVA: 0x6E55C0
        static Il2CppString* hr();  // RVA: 0x6E5660
        static Il2CppString* hs();  // RVA: 0x6E5700
        static Il2CppString* ht();  // RVA: 0x6E57A0
        static Il2CppString* hu();  // RVA: 0x6E5840
        static Il2CppString* hv();  // RVA: 0x6E58E0
        static Il2CppString* hw();  // RVA: 0x6E5980
        static Il2CppString* hx();  // RVA: 0x6E5A20
        static Il2CppString* hy();  // RVA: 0x6E5AC0
        static Il2CppString* hz();  // RVA: 0x6E5B60
        static Il2CppString* ia();  // RVA: 0x6E5CA0
        static Il2CppString* ib();  // RVA: 0x6E5D40
        static Il2CppString* ic();  // RVA: 0x6E5DE0
        static Il2CppString* id();  // RVA: 0x6E5E80
        static Il2CppString* ie();  // RVA: 0x6E5F20
        static Il2CppString* if();  // RVA: 0x6E5FC0
        static Il2CppString* ig();  // RVA: 0x6E6060
        static Il2CppString* ih();  // RVA: 0x6E6100
        static Il2CppString* ii();  // RVA: 0x6E61A0
        static Il2CppString* ij();  // RVA: 0x6E6240
        static Il2CppString* ik();  // RVA: 0x6E62E0
        static Il2CppString* il();  // RVA: 0x6E6380
        static Il2CppString* im();  // RVA: 0x6E6420
        static Il2CppString* in();  // RVA: 0x6E64C0
        static Il2CppString* io();  // RVA: 0x6E6560
        static Il2CppString* ip();  // RVA: 0x6E6600
        static Il2CppString* iq();  // RVA: 0x6E66A0
        static Il2CppString* ir();  // RVA: 0x6E6740
        static Il2CppString* is();  // RVA: 0x6E67E0
        static Il2CppString* it();  // RVA: 0x6E6880
        static Il2CppString* iu();  // RVA: 0x6E6920
        static Il2CppString* iv();  // RVA: 0x6E69C0
        static Il2CppString* iw();  // RVA: 0x6E6A60
        static Il2CppString* ix();  // RVA: 0x6E6B00
        static Il2CppString* iy();  // RVA: 0x6E6BA0
        static Il2CppString* iz();  // RVA: 0x6E6C40
        static Il2CppString* ja();  // RVA: 0x6E6D80
        static Il2CppString* jb();  // RVA: 0x6E6E20
        static Il2CppString* jc();  // RVA: 0x6E6EC0
        static Il2CppString* jd();  // RVA: 0x6E6F60
        static Il2CppString* je();  // RVA: 0x6E7000
        static Il2CppString* jf();  // RVA: 0x6E70A0
        static Il2CppString* jg();  // RVA: 0x6E7140
        static Il2CppString* jh();  // RVA: 0x6E71E0
        static Il2CppString* ji();  // RVA: 0x6E7280
        static Il2CppString* jj();  // RVA: 0x6E7320
        static Il2CppString* jk();  // RVA: 0x6E73C0
        static Il2CppString* jl();  // RVA: 0x6E7460
        static Il2CppString* jm();  // RVA: 0x6E7500
        static Il2CppString* jn();  // RVA: 0x6E75A0
        static Il2CppString* jo();  // RVA: 0x6E7640
        static Il2CppString* jp();  // RVA: 0x6E76E0
        static Il2CppString* jq();  // RVA: 0x6E7780
        static Il2CppString* jr();  // RVA: 0x6E7820
        static Il2CppString* js();  // RVA: 0x6E78C0
        static Il2CppString* jt();  // RVA: 0x6E7960
        static Il2CppString* ju();  // RVA: 0x6E7A00
        static Il2CppString* jv();  // RVA: 0x6E7AA0
        static Il2CppString* jw();  // RVA: 0x6E7B40
        static Il2CppString* jx();  // RVA: 0x6E7BE0
        static Il2CppString* jy();  // RVA: 0x6E7C80
        static Il2CppString* jz();  // RVA: 0x6E7D20
        static Il2CppString* ka();  // RVA: 0x6E7E60
        static Il2CppString* kb();  // RVA: 0x6E7F00
        static Il2CppString* kc();  // RVA: 0x6E7FA0
        static Il2CppString* kd();  // RVA: 0x6E8040
        static Il2CppString* ke();  // RVA: 0x6E80E0
        static Il2CppString* kf();  // RVA: 0x6E8180
        static Il2CppString* kg();  // RVA: 0x6E8220
        static Il2CppString* kh();  // RVA: 0x6E82C0
        static Il2CppString* ki();  // RVA: 0x6E8360
        static Il2CppString* kj();  // RVA: 0x6E8400
        static Il2CppString* kk();  // RVA: 0x6E84A0
        static Il2CppString* kl();  // RVA: 0x6E8540
        static Il2CppString* km();  // RVA: 0x6E85E0
        static Il2CppString* kn();  // RVA: 0x6E8680
        static Il2CppString* ko();  // RVA: 0x6E8720
        static Il2CppString* kp();  // RVA: 0x6E87C0
        static Il2CppString* kq();  // RVA: 0x6E8860
        static Il2CppString* kr();  // RVA: 0x6E8900
        static Il2CppString* ks();  // RVA: 0x6E89A0
        static Il2CppString* kt();  // RVA: 0x6E8A40
        static Il2CppString* ku();  // RVA: 0x6E8AE0
        static Il2CppString* kv();  // RVA: 0x6E8B80
        static Il2CppString* kw();  // RVA: 0x6E8C20
        static Il2CppString* kx();  // RVA: 0x6E8CC0
        static Il2CppString* ky();  // RVA: 0x6E8D60
        static Il2CppString* kz();  // RVA: 0x6E8E00
        static Il2CppString* la();  // RVA: 0x6E8F40
        static Il2CppString* lb();  // RVA: 0x6E8FE0
        static Il2CppString* lc();  // RVA: 0x6E9080
        static Il2CppString* ld();  // RVA: 0x6E9120
        static Il2CppString* le();  // RVA: 0x6E91C0
        static Il2CppString* lf();  // RVA: 0x6E9260
        static Il2CppString* lg();  // RVA: 0x6E9300
        static Il2CppString* lh();  // RVA: 0x6E93A0
        static Il2CppString* li();  // RVA: 0x6E9440
        static Il2CppString* lj();  // RVA: 0x6E94E0
        static Il2CppString* lk();  // RVA: 0x6E9580
        static Il2CppString* ll();  // RVA: 0x6E9620
        static Il2CppString* lm();  // RVA: 0x6E96C0
        static Il2CppString* ln();  // RVA: 0x6E9760
        static Il2CppString* lo();  // RVA: 0x6E9800
        static Il2CppString* lp();  // RVA: 0x6E98A0
        static Il2CppString* lq();  // RVA: 0x6E9940
        static Il2CppString* lr();  // RVA: 0x6E99E0
        static Il2CppString* ls();  // RVA: 0x6E9A80
        static Il2CppString* lt();  // RVA: 0x6E9B20
        static Il2CppString* lu();  // RVA: 0x6E9BC0
        static Il2CppString* lv();  // RVA: 0x6E9C60
        static Il2CppString* lw();  // RVA: 0x6E9D00
        static Il2CppString* lx();  // RVA: 0x6E9DA0
        static Il2CppString* ly();  // RVA: 0x6E9E40
        static Il2CppString* lz();  // RVA: 0x6E9EE0
        static Il2CppString* ma();  // RVA: 0x6EA020
        static Il2CppString* mb();  // RVA: 0x6EA0C0
        static Il2CppString* mc();  // RVA: 0x6EA160
        static Il2CppString* md();  // RVA: 0x6EA200
        static Il2CppString* me();  // RVA: 0x6EA2A0
        static Il2CppString* mf();  // RVA: 0x6EA340
        static Il2CppString* mg();  // RVA: 0x6EA3E0
        static Il2CppString* mh();  // RVA: 0x6EA480
        static Il2CppString* mi();  // RVA: 0x6EA520
        static Il2CppString* mj();  // RVA: 0x6EA5C0
        static Il2CppString* mk();  // RVA: 0x6EA660
        static Il2CppString* ml();  // RVA: 0x6EA700
        static Il2CppString* mm();  // RVA: 0x6EA7A0
        static Il2CppString* mn();  // RVA: 0x6EA840
        static Il2CppString* mo();  // RVA: 0x6EA8E0
        static Il2CppString* mp();  // RVA: 0x6EA980
        static Il2CppString* mq();  // RVA: 0x6EAA20
        static Il2CppString* mr();  // RVA: 0x6EAAC0
        static Il2CppString* ms();  // RVA: 0x6EAB60
        static Il2CppString* mt();  // RVA: 0x6EAC00
        static Il2CppString* mu();  // RVA: 0x6EACA0
        static Il2CppString* mv();  // RVA: 0x6EAD40
        static Il2CppString* mw();  // RVA: 0x6EADE0
        static Il2CppString* mx();  // RVA: 0x6EAE80
        static Il2CppString* my();  // RVA: 0x6EAF20
        static Il2CppString* mz();  // RVA: 0x6EAFC0
        static Il2CppString* na();  // RVA: 0x6EB100
        static Il2CppString* nb();  // RVA: 0x6EB1A0
        static Il2CppString* nc();  // RVA: 0x6EB240
        static Il2CppString* nd();  // RVA: 0x6EB2E0
        static Il2CppString* ne();  // RVA: 0x6EB380
        static Il2CppString* nf();  // RVA: 0x6EB420
        static Il2CppString* ng();  // RVA: 0x6EB4C0
        static Il2CppString* nh();  // RVA: 0x6EB560
        static Il2CppString* ni();  // RVA: 0x6EB600
        static Il2CppString* nj();  // RVA: 0x6EB6A0
        static Il2CppString* nk();  // RVA: 0x6EB740
        static Il2CppString* nl();  // RVA: 0x6EB7E0
        static Il2CppString* nm();  // RVA: 0x6EB880
        static Il2CppString* nn();  // RVA: 0x6EB920
        static Il2CppString* no();  // RVA: 0x6EB9C0
        static Il2CppString* np();  // RVA: 0x6EBA60
        static Il2CppString* nq();  // RVA: 0x6EBB00
        static Il2CppString* nr();  // RVA: 0x6EBBA0
        static Il2CppString* ns();  // RVA: 0x6EBC40
        static Il2CppString* nt();  // RVA: 0x6EBCE0
        static Il2CppString* nu();  // RVA: 0x6EBD80
        static Il2CppString* nv();  // RVA: 0x6EBE20
        static Il2CppString* nw();  // RVA: 0x6EBEC0
        static Il2CppString* nx();  // RVA: 0x6EBF60
        static Il2CppString* ny();  // RVA: 0x6EC000
        static Il2CppString* nz();  // RVA: 0x6EC0A0
        static Il2CppString* oa();  // RVA: 0x6EC1E0
        static Il2CppString* ob();  // RVA: 0x6EC280
        static Il2CppString* oc();  // RVA: 0x6EC320
        static Il2CppString* od();  // RVA: 0x6EC3C0
        static Il2CppString* oe();  // RVA: 0x6EC460
        static Il2CppString* of();  // RVA: 0x6EC500
        static Il2CppString* og();  // RVA: 0x6EC5A0
        static Il2CppString* oh();  // RVA: 0x6EC640
        static Il2CppString* oi();  // RVA: 0x6EC6E0
        static Il2CppString* oj();  // RVA: 0x6EC780
        static Il2CppString* ok();  // RVA: 0x6EC820
        static Il2CppString* ol();  // RVA: 0x6EC8C0
        static Il2CppString* om();  // RVA: 0x6EC960
        static Il2CppString* on();  // RVA: 0x6ECA00
        static Il2CppString* oo();  // RVA: 0x6ECAA0
        static Il2CppString* op();  // RVA: 0x6ECB40
        static Il2CppString* oq();  // RVA: 0x6ECBE0
        static Il2CppString* or();  // RVA: 0x6ECC80
        static Il2CppString* os();  // RVA: 0x6ECD20
        static Il2CppString* ot();  // RVA: 0x6ECDC0
        static Il2CppString* ou();  // RVA: 0x6ECE60
        static Il2CppString* ov();  // RVA: 0x6ECF00
        static Il2CppString* ow();  // RVA: 0x6ECFA0
        static Il2CppString* ox();  // RVA: 0x6ED040
        static Il2CppString* oy();  // RVA: 0x6ED0E0
        static Il2CppString* oz();  // RVA: 0x6ED180
        static Il2CppString* pa();  // RVA: 0x6ED2C0
        static Il2CppString* pb();  // RVA: 0x6ED360
        static Il2CppString* pc();  // RVA: 0x6ED400
        static Il2CppString* pd();  // RVA: 0x6ED4A0
        static Il2CppString* pe();  // RVA: 0x6ED540
        static Il2CppString* pf();  // RVA: 0x6ED5E0
        static Il2CppString* pg();  // RVA: 0x6ED680
        static Il2CppString* ph();  // RVA: 0x6ED720
        static Il2CppString* pi();  // RVA: 0x6ED7C0
        static Il2CppString* pj();  // RVA: 0x6ED860
        static Il2CppString* pk();  // RVA: 0x6ED900
        static Il2CppString* pl();  // RVA: 0x6ED9A0
        static Il2CppString* pm();  // RVA: 0x6EDA40
        static Il2CppString* pn();  // RVA: 0x6EDAE0
        static Il2CppString* po();  // RVA: 0x6EDB80
        static Il2CppString* pp();  // RVA: 0x6EDC20
        static Il2CppString* pq();  // RVA: 0x6EDCC0
        static Il2CppString* pr();  // RVA: 0x6EDD60
        static Il2CppString* ps();  // RVA: 0x6EDE00
        static Il2CppString* pt();  // RVA: 0x6EDEA0
        static Il2CppString* pu();  // RVA: 0x6EDF40
        static Il2CppString* pv();  // RVA: 0x6EDFE0
        static Il2CppString* pw();  // RVA: 0x6EE080
        static Il2CppString* px();  // RVA: 0x6EE120
        static Il2CppString* py();  // RVA: 0x6EE1C0
        static Il2CppString* pz();  // RVA: 0x6EE260
        static Il2CppString* qa();  // RVA: 0x6EE3A0
        static Il2CppString* qb();  // RVA: 0x6EE440
        static Il2CppString* qc();  // RVA: 0x6EE4E0
        static Il2CppString* qd();  // RVA: 0x6EE580
        static Il2CppString* qe();  // RVA: 0x6EE620
        static Il2CppString* qf();  // RVA: 0x6EE6C0
        static Il2CppString* qg();  // RVA: 0x6EE760
        static Il2CppString* qh();  // RVA: 0x6EE800
        static Il2CppString* qi();  // RVA: 0x6EE8A0
        static Il2CppString* qj();  // RVA: 0x6EE940
        static Il2CppString* qk();  // RVA: 0x6EE9E0
        static Il2CppString* ql();  // RVA: 0x6EEA80
        static Il2CppString* qm();  // RVA: 0x6EEB20
        static Il2CppString* qn();  // RVA: 0x6EEBC0
        static Il2CppString* qo();  // RVA: 0x6EEC60
        static Il2CppString* qp();  // RVA: 0x6EED00
        static Il2CppString* qq();  // RVA: 0x6EEDA0
        static Il2CppString* qr();  // RVA: 0x6EEE40
        static Il2CppString* qs();  // RVA: 0x6EEEE0
        static Il2CppString* qt();  // RVA: 0x6EEF80
        static Il2CppString* qu();  // RVA: 0x6EF020
        static Il2CppString* qv();  // RVA: 0x6EF0C0
        static Il2CppString* qw();  // RVA: 0x6EF160
        static Il2CppString* qx();  // RVA: 0x6EF200
        static Il2CppString* qy();  // RVA: 0x6EF2A0
        static Il2CppString* qz();  // RVA: 0x6EF340
        static Il2CppString* ra();  // RVA: 0x6EF480
        static Il2CppString* rb();  // RVA: 0x6EF520
        static Il2CppString* rc();  // RVA: 0x6EF5C0
        static Il2CppString* rd();  // RVA: 0x6EF660
        static Il2CppString* re();  // RVA: 0x6EF700
        static Il2CppString* rf();  // RVA: 0x6EF7A0
        static Il2CppString* rg();  // RVA: 0x6EF840
        static Il2CppString* rh();  // RVA: 0x6EF8E0
        static Il2CppString* ri();  // RVA: 0x6EF980
        static void .cctor();  // RVA: 0x6DE2F0
    };

} // namespace <PrivateImplementationDetails>{6CDD5085-30BD-40AD-81A6-F8C9391CA445}
