using System.Drawing.Drawing2D;
using System.IO;

#pragma warning disable CA1416

namespace TBH_Trainer;

internal sealed class MainForm : Form
{
    private sealed class GameInstance
    {
        public readonly int Index;
        public string Name => $"Game {Index + 1}";

        public readonly GameMemory Mem = new();
        public AntiCheatPatcher? Patcher;
        public HeroStats? Hero;
        public readonly TrainerBridge Bridge = new();
        public int Pid = -1;
        public bool Injected;

        // Patches
        public HighExpPatcher? Exp;
        public HighGoldPatcher? Gold;

        // Lock states
        public float? LockedHp;
        public float? LockedAtk;
        public float? LockedAtkSpeed;
        public float? LockedMoveSpeed;

        // Presets
        public bool InstakillActive;
        public float? SavedAtkBeforeInstakill;
        public bool InvincibleActive;
        public float? SavedHpBeforeInvincible;

        public bool AtkSpeed10kActive;
        public bool AtkSpeed5kActive;
        public float? SavedAtkSpeedBeforePreset;

        public bool MoveSpeed10kActive;
        public bool MoveSpeed5kActive;
        public float? SavedMoveSpeedBeforePreset;

        // Controls
        public Label LblStatus = null!;
        public Button BtnAttach = null!;
        public Button BtnPop = null!;
        public Button BtnBypass = null!;
        public Label LblBypassStatus = null!;

        public CheckBox ChkSpeed = null!;
        public Panel PnlSpeed = null!;
        public TrackBar TrkSpeed = null!;
        public Label LblSpeedValue = null!;
        public TextBox TxtSpeed = null!;
        public Label LblSpeedStatus = null!;
        public bool SuppressSlider;

        public TextBox TxtHp = null!;
        public Button BtnApplyHp = null!;
        public CheckBox ChkLockHp = null!;

        public TextBox TxtAtk = null!;
        public Button BtnApplyAtk = null!;
        public CheckBox ChkLockAtk = null!;

        public TextBox TxtAtkSpeed = null!;
        public Button BtnApplyAtkSpeed = null!;
        public CheckBox ChkLockAtkSpeed = null!;

        public TextBox TxtMoveSpeed = null!;
        public Button BtnApplyMoveSpeed = null!;
        public CheckBox ChkLockMoveSpeed = null!;

        public Button BtnResetStats = null!;

        public TextBox TxtExp = null!;
        public Button BtnApplyExp = null!;
        public Button BtnDisableExp = null!;
        public Label LblExpStatus = null!;

        public TextBox TxtGold = null!;
        public Button BtnApplyGold = null!;
        public Button BtnDisableGold = null!;
        public Label LblGoldStatus = null!;

        public CheckBox ChkInstakill = null!;
        public Label LblInstakillStatus = null!;
        public CheckBox ChkInvincible = null!;
        public Label LblInvincibleStatus = null!;

        public CheckBox ChkAtkSpeed10k = null!;
        public CheckBox ChkAtkSpeed5k = null!;
        public CheckBox ChkMoveSpeed10k = null!;
        public CheckBox ChkMoveSpeed5k = null!;

        // Stash Spawner Controls
        public TextBox TxtStashKey = null!;
        public ComboBox CboStashGrade = null!;
        public TextBox TxtStashCount = null!;
        public Button BtnStashSpawn = null!;
        public Button BtnStashScan = null!;
        public Button BtnStashExport = null!;
        public Label LblStashStatus = null!;

        public GameInstance(int index)
        {
            Index = index;
        }
    }

    private readonly GameInstance[] _instances = new GameInstance[5];

    // Shared UI
    private TextBox _txtLog = null!;
    private Panel _header = null!;
    private TabControl _tabs = null!;

    // Static-patch tab state
    private StaticPatcher? _static;
    private readonly List<StaticPatcher.Feature> _features = StaticPatcher.BuildFeatures();
    private readonly Dictionary<StaticPatcher.Feature, (Label status, Button toggle)> _featRows = new();
    private TextBox _txtDllPath = null!;

    private System.Windows.Forms.Timer? _lockTimer;

    // === Dark Modern Premium Theme Palette ===
    private static readonly Color BgForm     = Color.FromArgb(12, 12, 18);
    private static readonly Color BgInput    = Color.FromArgb(20, 20, 30);
    private static readonly Color BgInputHover = Color.FromArgb(25, 25, 40);
    private static readonly Color BtnBg      = Color.FromArgb(18, 18, 28);
    private static readonly Color BtnBgHover = Color.FromArgb(25, 25, 40);
    private static readonly Color BtnBgPressed = Color.FromArgb(15, 15, 25);
    private static readonly Color AccentBlue = Color.FromArgb(0, 180, 255);
    private static readonly Color AccentCyan = Color.FromArgb(0, 220, 255);
    private static readonly Color AccentPurple = Color.FromArgb(138, 43, 226);
    private static readonly Color AccentGreen  = Color.FromArgb(0, 255, 130);
    private static readonly Color AccentRed    = Color.FromArgb(255, 80, 80);
    private static readonly Color TextPrimary  = Color.FromArgb(230, 230, 250);
    private static readonly Color TextSecondary= Color.FromArgb(160, 165, 180);
    private static readonly Color TextDisabled = Color.FromArgb(90, 95, 110);
    private static readonly Color TextMain     = TextPrimary;
    private static readonly Color TextDim      = TextSecondary;
    private static readonly Color AccentDim    = Color.FromArgb(20, 40, 60);

    private static T? LoadEmbedded<T>(string endsWith) where T : class
    {
        var asm = typeof(MainForm).Assembly;
        var name = asm.GetManifestResourceNames()
            .FirstOrDefault(n => n.EndsWith(endsWith, StringComparison.OrdinalIgnoreCase));
        if (name == null) return null;
        using var s = asm.GetManifestResourceStream(name);
        if (s == null) return null;
        if (typeof(T) == typeof(Bitmap)) return new Bitmap(s) as T;
        if (typeof(T) == typeof(Icon)) return new Icon(s) as T;
        return null;
    }

    private static string DllPath => Path.Combine(AppContext.BaseDirectory, "TBHHook.dll");

    public MainForm()
    {
        for (int i = 0; i < 5; i++)
        {
            _instances[i] = new GameInstance(i);
        }
        InitializeComponent();
    }

    private void InitializeComponent()
    {
        Text = "TBH Trainer v1.3.0 (1.00.09) - Multi-Instance Support";
        ClientSize = new Size(640, 810);
        FormBorderStyle = FormBorderStyle.FixedSingle;
        MaximizeBox = false;
        StartPosition = FormStartPosition.CenterScreen;
        BackColor = BgForm;
        ForeColor = TextMain;
        Font = new Font("Segoe UI", 9);
        try { Icon = LoadEmbedded<Icon>("icon.ico"); } catch { }

        _header = new Panel { Location = new Point(0, 0), Size = new Size(640, 52), BackColor = BgForm };
        _header.Paint += PaintHeader;
        Controls.Add(_header);

        // === Navigation Bar ===
        var navBar = new Panel
        {
            Location = new Point(8, 56), Size = new Size(624, 34),
            BackColor = Color.FromArgb(18, 19, 26)
        };
        navBar.Paint += (s, e) =>
        {
            var g = e.Graphics;
            g.SmoothingMode = SmoothingMode.AntiAlias;
            var r = new Rectangle(0, 0, navBar.Width - 1, navBar.Height - 1);
            using (var path = GetRoundedRectPath(r, 5))
            {
                using (var bg = new SolidBrush(Color.FromArgb(18, 19, 26)))
                    g.FillPath(bg, path);
                using (var pen = new Pen(Color.FromArgb(30, 45, 65), 1f))
                    g.DrawPath(pen, path);
            }
        };

        int navW = 200;
        var btnNavRuntime = new ThemedButton
        {
            Text = "Runtime Cheats", Location = new Point(4, 2), Size = new Size(navW, 30),
            CornerRadius = 4
        };
        var btnNavStatic = new ThemedButton
        {
            Text = "Static DLL Patches", Location = new Point(navW + 8, 2), Size = new Size(navW, 30),
            CornerRadius = 4
        };
        var btnNavCredits = new ThemedButton
        {
            Text = "Credits", Location = new Point(navW * 2 + 12, 2), Size = new Size(navW, 30),
            CornerRadius = 4
        };

        navBar.Controls.AddRange(new Control[] { btnNavRuntime, btnNavStatic, btnNavCredits });
        Controls.Add(navBar);

        // === Hidden TabControl ===
        _tabs = new TabControl
        {
            Location = new Point(8, 94), Size = new Size(624, 604),
            Appearance = TabAppearance.FlatButtons,
            ItemSize = new Size(0, 1),
            SizeMode = TabSizeMode.Fixed
        };
        var tabRuntime = new TabPage("Runtime") { BackColor = BgForm, AutoScroll = false };
        var tabStatic  = new TabPage("Static") { BackColor = BgForm, AutoScroll = false };
        var tabCredits = new TabPage("Credits") { BackColor = BgForm, AutoScroll = false };
        _tabs.TabPages.AddRange(new TabPage[] { tabRuntime, tabStatic, tabCredits });
        Controls.Add(_tabs);

        btnNavRuntime.Click += (s, e) =>
        {
            _tabs.SelectedIndex = 0;
            btnNavRuntime.FlatAppearance.BorderColor = AccentCyan;
            btnNavStatic.FlatAppearance.BorderColor = Color.FromArgb(40, 45, 55);
            btnNavCredits.FlatAppearance.BorderColor = Color.FromArgb(40, 45, 55);
        };
        btnNavStatic.Click += (s, e) =>
        {
            _tabs.SelectedIndex = 1;
            btnNavStatic.FlatAppearance.BorderColor = AccentCyan;
            btnNavRuntime.FlatAppearance.BorderColor = Color.FromArgb(40, 45, 55);
            btnNavCredits.FlatAppearance.BorderColor = Color.FromArgb(40, 45, 55);
        };
        btnNavCredits.Click += (s, e) =>
        {
            _tabs.SelectedIndex = 2;
            btnNavCredits.FlatAppearance.BorderColor = AccentCyan;
            btnNavRuntime.FlatAppearance.BorderColor = Color.FromArgb(40, 45, 55);
            btnNavStatic.FlatAppearance.BorderColor = Color.FromArgb(40, 45, 55);
        };

        BuildRuntimeTab(tabRuntime);
        BuildStaticTab(tabStatic);
        BuildCreditsTab(tabCredits);

        // === Shared Log ===
        var grpLog = new GroupBox
        {
            Text = "Activity Log", Location = new Point(8, 702), Size = new Size(624, 100),
            ForeColor = AccentCyan, Font = new Font("Segoe UI", 9, FontStyle.Bold), BackColor = BgForm
        };
        grpLog.Paint += PaintCardGroup;

        _txtLog = new TextBox
        {
            Location = new Point(12, 24), Size = new Size(600, 64),
            Multiline = true, ScrollBars = ScrollBars.Vertical, ReadOnly = true,
            BackColor = Color.FromArgb(12, 13, 18), ForeColor = Color.FromArgb(120, 220, 200),
            Font = new Font("Consolas", 8.5f), BorderStyle = BorderStyle.FixedSingle
        };
        grpLog.Controls.Add(_txtLog);
        Controls.Add(grpLog);

        _lockTimer = new System.Windows.Forms.Timer { Interval = 100 };
        _lockTimer.Tick += OnLockTimerTick;
        _lockTimer.Start();

        btnNavRuntime.PerformClick();
        Log("Trainer initialized with Multi-Instance support (Max 5 instances).");
        Log("Runtime features work on game version 1.00.09.");
    }

    private void BuildRuntimeTab(TabPage page)
    {
        // Secondary sub-tab control for Game 1 - Game 5
        var gameSubTabs = new TabControl
        {
            Location = new Point(4, 4), Size = new Size(616, 596),
            BackColor = BgForm, ForeColor = TextMain
        };
        
        for (int i = 0; i < 5; i++)
        {
            var inst = _instances[i];
            var subPage = new TabPage(inst.Name) { BackColor = BgForm, AutoScroll = false };
            BuildInstanceTab(subPage, inst);
            gameSubTabs.TabPages.Add(subPage);
        }

        page.Controls.Add(gameSubTabs);
    }

    private void BuildInstanceTab(TabPage page, GameInstance inst)
    {
        int y = 6;
        int fullW = 604;

        // === 1. Connect + Bypass ===
        var grp1 = MakeGroup(page, "1. Connect & Bypass", ref y, 60);
        inst.BtnAttach = MakeBtn("Connect", 12, 22, 85);
        inst.BtnAttach.Click += (s, e) => OnAttach(inst);

        inst.BtnPop = MakeBtn("Pop It!", 102, 22, 70);
        inst.BtnPop.Enabled = false;
        inst.BtnPop.Click += (s, e) => inst.Mem.BringToFront();

        inst.BtnBypass = MakeBtn("Bypass ACTk", 178, 22, 100);
        inst.BtnBypass.Click += (s, e) => OnBypass(inst);
        inst.BtnBypass.Enabled = false;

        inst.LblBypassStatus = new Label { Text = "ACTk: Active", ForeColor = Color.FromArgb(255, 200, 50), Location = new Point(285, 28), AutoSize = true };
        inst.LblStatus = new Label { Text = "Disconnected", ForeColor = AccentRed, Location = new Point(390, 28), AutoSize = true };
        
        grp1.Controls.AddRange(new Control[] { inst.BtnAttach, inst.BtnPop, inst.BtnBypass, inst.LblBypassStatus, inst.LblStatus });

        // === 2. Game Speed ===
        var grp2 = MakeGroup(page, "2. Game Speed", ref y, 110);
        inst.ChkSpeed = new CheckBox
        {
            Text = "Enable Speedhack", Location = new Point(15, 18), AutoSize = true,
            ForeColor = TextMain
        };
        inst.ChkSpeed.CheckedChanged += (s, e) => OnSpeedToggle(inst);
        grp2.Controls.Add(inst.ChkSpeed);

        inst.PnlSpeed = new Panel
        {
            Location = new Point(3, 40), Size = new Size(fullW - 16, 62),
            BackColor = Color.FromArgb(18, 19, 26), Visible = false
        };

        inst.TrkSpeed = new TrackBar
        {
            Location = new Point(6, 2), Size = new Size(fullW - 30, 30),
            Minimum = 0, Maximum = 100, Value = 10, TickFrequency = 10
        };
        inst.TrkSpeed.ValueChanged += (s, e) => OnSpeedSlider(inst);

        inst.PnlSpeed.Controls.Add(new Label { Text = "Speed:", Location = new Point(12, 36), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtSpeed = MakeTxt(60, 33, 60);
        inst.TxtSpeed.Text = "1.00";
        inst.TxtSpeed.KeyDown += (s, e) => OnSpeedKeyDown(inst, e);
        inst.TxtSpeed.Leave += (s, e) => CommitTypedSpeed(inst);
        inst.LblSpeedValue = new Label { Text = "Speed: 1.00x", Location = new Point(130, 36), AutoSize = true, ForeColor = AccentCyan, Font = new Font("Segoe UI", 9, FontStyle.Bold) };
        inst.LblSpeedStatus = new Label { Text = "(0.0 - 10.0x)", Location = new Point(260, 36), AutoSize = true, ForeColor = Color.FromArgb(150, 150, 150) };

        inst.PnlSpeed.Controls.AddRange(new Control[] { inst.TrkSpeed, inst.TxtSpeed, inst.LblSpeedValue, inst.LblSpeedStatus });
        grp2.Controls.Add(inst.PnlSpeed);

        // === 3. Hero Stats ===
        var grp3 = MakeGroup(page, "3. Hero Stats", ref y, 130);
        grp3.Controls.Add(new Label
        {
            Text = "Enter a run/battle first. Locks auto-apply every 100ms.",
            Font = new Font("Segoe UI", 8), ForeColor = Color.FromArgb(150, 150, 150),
            Location = new Point(15, 18), AutoSize = true
        });

        int col1X = 15, col2X = 300;
        int r1Y = 42, r2Y = 72;

        // HP
        grp3.Controls.Add(new Label { Text = "HP:", Location = new Point(col1X, r1Y + 4), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtHp = MakeTxt(col1X + 55, r1Y, 70); inst.TxtHp.Enabled = false;
        inst.BtnApplyHp = MakeBtn("Set", col1X + 135, r1Y - 2, 50); inst.BtnApplyHp.Enabled = false;
        inst.BtnApplyHp.Click += (s, e) => OnApplyHp(inst);
        inst.ChkLockHp = new CheckBox { Text = "Lock", Location = new Point(col1X + 195, r1Y + 2), AutoSize = true, ForeColor = TextSecondary, Enabled = false };
        inst.ChkLockHp.CheckedChanged += (s, e) => OnLockHpChanged(inst);
        grp3.Controls.AddRange(new Control[] { inst.TxtHp, inst.BtnApplyHp, inst.ChkLockHp });

        // ATK
        grp3.Controls.Add(new Label { Text = "ATK:", Location = new Point(col1X, r2Y + 4), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtAtk = MakeTxt(col1X + 55, r2Y, 70); inst.TxtAtk.Enabled = false;
        inst.BtnApplyAtk = MakeBtn("Set", col1X + 135, r2Y - 2, 50); inst.BtnApplyAtk.Enabled = false;
        inst.BtnApplyAtk.Click += (s, e) => OnApplyAtk(inst);
        inst.ChkLockAtk = new CheckBox { Text = "Lock", Location = new Point(col1X + 195, r2Y + 2), AutoSize = true, ForeColor = TextSecondary, Enabled = false };
        inst.ChkLockAtk.CheckedChanged += (s, e) => OnLockAtkChanged(inst);
        grp3.Controls.AddRange(new Control[] { inst.TxtAtk, inst.BtnApplyAtk, inst.ChkLockAtk });

        // ATK Spd
        grp3.Controls.Add(new Label { Text = "ATK Spd:", Location = new Point(col2X, r1Y + 4), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtAtkSpeed = MakeTxt(col2X + 65, r1Y, 70); inst.TxtAtkSpeed.Enabled = false;
        inst.BtnApplyAtkSpeed = MakeBtn("Set", col2X + 145, r1Y - 2, 50); inst.BtnApplyAtkSpeed.Enabled = false;
        inst.BtnApplyAtkSpeed.Click += (s, e) => OnApplyAtkSpeed(inst);
        inst.ChkLockAtkSpeed = new CheckBox { Text = "Lock", Location = new Point(col2X + 205, r1Y + 2), AutoSize = true, ForeColor = TextSecondary, Enabled = false };
        inst.ChkLockAtkSpeed.CheckedChanged += (s, e) => OnLockAtkSpeedChanged(inst);
        grp3.Controls.AddRange(new Control[] { inst.TxtAtkSpeed, inst.BtnApplyAtkSpeed, inst.ChkLockAtkSpeed });

        // Move Spd
        grp3.Controls.Add(new Label { Text = "Move Spd:", Location = new Point(col2X, r2Y + 4), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtMoveSpeed = MakeTxt(col2X + 65, r2Y, 70); inst.TxtMoveSpeed.Enabled = false;
        inst.BtnApplyMoveSpeed = MakeBtn("Set", col2X + 145, r2Y - 2, 50); inst.BtnApplyMoveSpeed.Enabled = false;
        inst.BtnApplyMoveSpeed.Click += (s, e) => OnApplyMoveSpeed(inst);
        inst.ChkLockMoveSpeed = new CheckBox { Text = "Lock", Location = new Point(col2X + 205, r2Y + 2), AutoSize = true, ForeColor = TextSecondary, Enabled = false };
        inst.ChkLockMoveSpeed.CheckedChanged += (s, e) => OnLockMoveSpeedChanged(inst);
        grp3.Controls.AddRange(new Control[] { inst.TxtMoveSpeed, inst.BtnApplyMoveSpeed, inst.ChkLockMoveSpeed });

        // Reset
        inst.BtnResetStats = MakeBtn("Reset All Stats", col1X, 100, 120);
        inst.BtnResetStats.Enabled = false;
        inst.BtnResetStats.Click += (s, e) => OnResetStats(inst);
        grp3.Controls.Add(inst.BtnResetStats);

        // === 4. EXP on Kill ===
        var grp4 = MakeGroup(page, "4. EXP on Kill", ref y, 54);
        grp4.Controls.Add(new Label { Text = "EXP/kill:", Location = new Point(15, 24), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtExp = MakeTxt(80, 20, 100); inst.TxtExp.Text = "999999999"; inst.TxtExp.Enabled = false;
        inst.BtnApplyExp = MakeBtn("Enable", 195, 20, 65); inst.BtnApplyExp.Enabled = false;
        inst.BtnApplyExp.Click += (s, e) => OnApplyExp(inst);
        inst.BtnDisableExp = MakeBtn("Disable", 270, 20, 65); inst.BtnDisableExp.Enabled = false;
        inst.BtnDisableExp.Click += (s, e) => OnDisableExp(inst);
        inst.LblExpStatus = new Label { Text = "OFF", Location = new Point(350, 24), AutoSize = true, ForeColor = TextDim, Font = new Font("Segoe UI", 9, FontStyle.Bold) };
        grp4.Controls.AddRange(new Control[] { inst.TxtExp, inst.BtnApplyExp, inst.BtnDisableExp, inst.LblExpStatus });

        // === 4b. Gold on Kill ===
        var grp4b = MakeGroup(page, "4b. Gold on Kill", ref y, 54);
        grp4b.Controls.Add(new Label { Text = "Gold/kill:", Location = new Point(15, 24), AutoSize = true, ForeColor = TextSecondary });
        inst.TxtGold = MakeTxt(80, 20, 100); inst.TxtGold.Text = "1000000"; inst.TxtGold.Enabled = false;
        inst.BtnApplyGold = MakeBtn("Enable", 195, 20, 65); inst.BtnApplyGold.Enabled = false;
        inst.BtnApplyGold.Click += (s, e) => OnApplyGold(inst);
        inst.BtnDisableGold = MakeBtn("Disable", 270, 20, 65); inst.BtnDisableGold.Enabled = false;
        inst.BtnDisableGold.Click += (s, e) => OnDisableGold(inst);
        inst.LblGoldStatus = new Label { Text = "OFF", Location = new Point(350, 24), AutoSize = true, ForeColor = TextDim, Font = new Font("Segoe UI", 9, FontStyle.Bold) };
        grp4b.Controls.AddRange(new Control[] { inst.TxtGold, inst.BtnApplyGold, inst.BtnDisableGold, inst.LblGoldStatus });

        // === 5. Quick Presets ===
        var grp5 = MakeGroup(page, "5. Quick Presets", ref y, 108);
        grp5.Controls.Add(new Label
        {
            Text = "One-click (locks stats, restores originals on uncheck/reset).",
            Font = new Font("Segoe UI", 8), ForeColor = Color.FromArgb(150, 150, 150),
            Location = new Point(15, 18), AutoSize = true
        });

        inst.ChkInstakill = new CheckBox
        {
            Text = "\u26A1 One-Hit Kill", Location = new Point(15, 38), AutoSize = true,
            ForeColor = Color.FromArgb(255, 100, 100), Font = new Font("Segoe UI", 9, FontStyle.Bold), Enabled = false
        };
        inst.ChkInstakill.CheckedChanged += (s, e) => OnInstakillToggle(inst);
        inst.LblInstakillStatus = new Label { Text = "OFF", Location = new Point(135, 40), AutoSize = true, ForeColor = TextDim, Font = new Font("Segoe UI", 8, FontStyle.Bold) };

        inst.ChkInvincible = new CheckBox
        {
            Text = "\U0001F6E1 Invincible", Location = new Point(230, 38), AutoSize = true,
            ForeColor = Color.FromArgb(100, 200, 255), Font = new Font("Segoe UI", 9, FontStyle.Bold), Enabled = false
        };
        inst.ChkInvincible.CheckedChanged += (s, e) => OnInvincibleToggle(inst);
        inst.LblInvincibleStatus = new Label { Text = "OFF", Location = new Point(345, 40), AutoSize = true, ForeColor = TextDim, Font = new Font("Segoe UI", 8, FontStyle.Bold) };

        // ATK Speed presets (10k / 5k)
        inst.ChkAtkSpeed10k = new CheckBox
        {
            Text = "\u26A0\ufe0f ATK Spd 10k", Location = new Point(15, 62), AutoSize = true,
            ForeColor = AccentCyan, Font = new Font("Segoe UI", 8.5f, FontStyle.Bold), Enabled = false
        };
        inst.ChkAtkSpeed10k.CheckedChanged += (s, e) => OnAtkSpeed10kToggle(inst);

        inst.ChkAtkSpeed5k = new CheckBox
        {
            Text = "\u26A0\ufe0f ATK Spd 5k", Location = new Point(150, 62), AutoSize = true,
            ForeColor = AccentCyan, Font = new Font("Segoe UI", 8.5f, FontStyle.Bold), Enabled = false
        };
        inst.ChkAtkSpeed5k.CheckedChanged += (s, e) => OnAtkSpeed5kToggle(inst);

        // Move Speed presets (10k / 5k)
        inst.ChkMoveSpeed10k = new CheckBox
        {
            Text = "\U0001f40e Move Spd 10k", Location = new Point(285, 62), AutoSize = true,
            ForeColor = AccentGreen, Font = new Font("Segoe UI", 8.5f, FontStyle.Bold), Enabled = false
        };
        inst.ChkMoveSpeed10k.CheckedChanged += (s, e) => OnMoveSpeed10kToggle(inst);

        inst.ChkMoveSpeed5k = new CheckBox
        {
            Text = "\U0001f40e Move Spd 5k", Location = new Point(435, 62), AutoSize = true,
            ForeColor = AccentGreen, Font = new Font("Segoe UI", 8.5f, FontStyle.Bold), Enabled = false
        };
        inst.ChkMoveSpeed5k.CheckedChanged += (s, e) => OnMoveSpeed5kToggle(inst);

        grp5.Controls.AddRange(new Control[] {
            inst.ChkInstakill, inst.LblInstakillStatus,
            inst.ChkInvincible, inst.LblInvincibleStatus,
            inst.ChkAtkSpeed10k, inst.ChkAtkSpeed5k,
            inst.ChkMoveSpeed10k, inst.ChkMoveSpeed5k
        });
    }

    private void BuildStaticTab(TabPage page)
    {
        int y = 8;
        page.Controls.Add(new Label
        {
            Text = "Edits GameAssembly.dll on disk \u2014 CLOSE THE GAME before applying.\n" +
                   "Each patch is byte-verified; wrong version is refused safely.\n" +
                   "Backup created automatically (.denoiser.bak).",
            Location = new Point(12, y), AutoSize = true, ForeColor = Color.FromArgb(148, 153, 170),
            Font = new Font("Segoe UI", 8)
        });
        y += 40;

        page.Controls.Add(new Label { Text = "DLL Path:", Location = new Point(12, y + 4), AutoSize = true, ForeColor = TextMain });
        _txtDllPath = new TextBox
        {
            Location = new Point(80, y), Width = 420, ReadOnly = true,
            BackColor = BgInput, ForeColor = TextMain, BorderStyle = BorderStyle.FixedSingle,
            Font = new Font("Consolas", 8.5f)
        };
        page.Controls.Add(_txtDllPath);
        var btnBrowse = MakeBtn("Browse", 510, y - 2, 96);
        btnBrowse.Click += OnBrowseDll;
        page.Controls.Add(btnBrowse);

        y += 32;

        foreach (var f in _features)
        {
            var pnlRow = new Panel
            {
                Location = new Point(8, y),
                Size = new Size(600, 48),
                BackColor = BgForm
            };
            pnlRow.Paint += PaintFeatureRow;

            var name = new Label
            {
                Text = f.Name, Location = new Point(12, 6), AutoSize = true,
                ForeColor = TextPrimary, Font = new Font("Segoe UI", 9.5f, FontStyle.Bold)
            };
            var desc = new Label
            {
                Text = f.Description, Location = new Point(12, 26), AutoSize = true,
                ForeColor = Color.FromArgb(148, 163, 184), Font = new Font("Segoe UI", 8),
                MaximumSize = new Size(400, 18)
            };
            var status = new Label
            {
                Text = "OFF", Location = new Point(430, 14), AutoSize = true,
                ForeColor = Color.FromArgb(150, 150, 150), Font = new Font("Segoe UI", 9.5f, FontStyle.Bold)
            };
            var toggle = MakeBtn("Apply", 510, 10, 84);
            toggle.Height = 28;
            toggle.Enabled = false;

            var captured = f;
            toggle.Click += (_, _) => OnToggleFeature(captured);

            pnlRow.Controls.AddRange(new Control[] { name, desc, status, toggle });
            page.Controls.Add(pnlRow);

            _featRows[f] = (status, toggle);
            y += 50;
        }

        y += 2;
        var btnRefresh   = MakeBtn("Refresh", 8, y, 90);
        var btnApplyAll  = MakeBtn("Apply All", 106, y, 90);
        var btnRevertAll = MakeBtn("Revert All", 204, y, 90);
        var btnRestore   = MakeBtn("Restore Backup", 302, y, 146);

        btnRefresh.Click += (_, _) => RefreshStatic(log: true);
        btnApplyAll.Click += (_, _) => { foreach (var f in _features) if (f.State == StaticPatcher.FeatureState.Original) OnToggleFeature(f); };
        btnRevertAll.Click += (_, _) => { foreach (var f in _features) if (f.State == StaticPatcher.FeatureState.Patched) OnToggleFeature(f); };
        btnRestore.Click += OnRestoreBackup;

        page.Controls.AddRange(new Control[] { btnRefresh, btnApplyAll, btnRevertAll, btnRestore });

        var auto = StaticPatcher.AutoDetectDll();
        if (auto != null)
        {
            _static = new StaticPatcher(auto);
            _txtDllPath.Text = auto;
            RefreshStatic(log: false);
        }
        else
        {
            _txtDllPath.Text = "GameAssembly.dll not found";
        }
    }

    private void BuildCreditsTab(TabPage page)
    {
        int y = 12;
        var grpCredits = MakeGroup(page, "Credits & Acknowledgements", ref y, 320);

        var lblIntro = new Label
        {
            Text = "Special thanks to the talented members of the community who contributed dumps, offsets, and code logic that made this version possible:",
            Location = new Point(15, 24),
            Size = new Size(580, 50),
            ForeColor = TextSecondary,
            Font = new Font("Segoe UI", 9)
        };

        int rowY = 85;

        var lblJamalTitle = new Label
        {
            Text = "JamalGames", Location = new Point(20, rowY), AutoSize = true,
            ForeColor = AccentCyan, Font = new Font("Segoe UI", 11, FontStyle.Bold)
        };
        var lblJamalDesc = new Label
        {
            Text = "Provided updated class dumps for version [1.00.09]",
            Location = new Point(20, rowY + 22), AutoSize = true,
            ForeColor = TextPrimary, Font = new Font("Segoe UI", 9)
        };

        rowY += 65;

        var lblDenoiserTitle = new Label
        {
            Text = "denoiser", Location = new Point(20, rowY), AutoSize = true,
            ForeColor = AccentPurple, Font = new Font("Segoe UI", 11, FontStyle.Bold)
        };
        var lblDenoiserDesc = new Label
        {
            Text = "Developer of the original Denoiser Trainer for version [1.00.08]",
            Location = new Point(20, rowY + 22), AutoSize = true,
            ForeColor = TextPrimary, Font = new Font("Segoe UI", 9)
        };

        rowY += 65;

        var lblSaydeTitle = new Label
        {
            Text = "sayde90", Location = new Point(20, rowY), AutoSize = true,
            ForeColor = AccentGreen, Font = new Font("Segoe UI", 11, FontStyle.Bold)
        };
        var lblSaydeDesc = new Label
        {
            Text = "Contributed static assembly and runtime patches for version [1.00.09]",
            Location = new Point(20, rowY + 22), AutoSize = true,
            ForeColor = TextPrimary, Font = new Font("Segoe UI", 9)
        };

        grpCredits.Controls.AddRange(new Control[]
        {
            lblIntro,
            lblJamalTitle, lblJamalDesc,
            lblDenoiserTitle, lblDenoiserDesc,
            lblSaydeTitle, lblSaydeDesc
        });

        var lblFooter = new Label
        {
            Text = "Thank you for using TBH Trainer. Play responsibly!",
            Location = new Point(12, y + 15), Size = new Size(600, 25),
            TextAlign = ContentAlignment.MiddleCenter, ForeColor = TextDisabled,
            Font = new Font("Segoe UI", 8.5f, FontStyle.Italic)
        };
        page.Controls.Add(lblFooter);
    }

    // ========================================================================
    //  PAINTING & HELPERS
    // ========================================================================
    private void PaintCardGroup(object? sender, PaintEventArgs e)
    {
        if (sender is not GroupBox g) return;
        var rect = g.ClientRectangle;
        var graphics = e.Graphics;
        graphics.SmoothingMode = SmoothingMode.AntiAlias;

        graphics.Clear(BgForm);

        var bounds = new Rectangle(0, 10, rect.Width - 1, rect.Height - 11);
        using (var path = GetRoundedRectPath(bounds, 6))
        {
            using (var bgBrush = new SolidBrush(Color.FromArgb(18, 19, 26)))
                graphics.FillPath(bgBrush, path);
            using (var borderPen = new Pen(Color.FromArgb(30, 45, 65), 1f))
                graphics.DrawPath(borderPen, path);
        }

        var titleFont = new Font("Segoe UI", 9.5f, FontStyle.Bold);
        var size = graphics.MeasureString(g.Text, titleFont);

        var textBounds = new Rectangle(10, 0, (int)size.Width + 10, 20);
        using (var pillPath = GetRoundedRectPath(textBounds, 4))
        {
            using (var pillBrush = new SolidBrush(Color.FromArgb(24, 27, 36)))
                graphics.FillPath(pillBrush, pillPath);
            using (var pillPen = new Pen(Color.FromArgb(40, AccentBlue), 1f))
                graphics.DrawPath(pillPen, pillPath);
        }

        using (var textBrush = new SolidBrush(AccentCyan))
            graphics.DrawString(g.Text, titleFont, textBrush, 15, 2);
    }

    private void PaintFeatureRow(object? sender, PaintEventArgs e)
    {
        if (sender is not Panel p) return;
        var rect = p.ClientRectangle;
        var graphics = e.Graphics;
        graphics.SmoothingMode = SmoothingMode.AntiAlias;
        graphics.Clear(BgForm);

        var bounds = new Rectangle(0, 0, rect.Width - 1, rect.Height - 1);
        using (var path = GetRoundedRectPath(bounds, 5))
        {
            using (var bgBrush = new SolidBrush(Color.FromArgb(18, 19, 26)))
                graphics.FillPath(bgBrush, path);
            using (var borderPen = new Pen(Color.FromArgb(30, 45, 65), 1f))
                graphics.DrawPath(borderPen, path);
        }
    }

    private GroupBox MakeGroup(Control parent, string text, ref int y, int height)
    {
        var g = new GroupBox
        {
            Text = text, Location = new Point(4, y), Size = new Size(592, height),
            ForeColor = AccentBlue, Font = new Font("Segoe UI", 9, FontStyle.Bold),
            BackColor = BgForm
        };
        g.Paint += PaintCardGroup;
        parent.Controls.Add(g);
        y += height + 6;
        return g;
    }

    private Button MakeBtn(string text, int x, int y, int w)
    {
        var b = new ThemedButton
        {
            Text = text, Location = new Point(x, y), Size = new Size(w, 28),
            FlatStyle = FlatStyle.Flat, BackColor = BtnBg,
            ForeColor = TextPrimary, Font = new Font("Segoe UI", 9, FontStyle.Bold),
            Cursor = Cursors.Hand, CornerRadius = 4
        };
        b.FlatAppearance.BorderColor = AccentBlue;
        b.FlatAppearance.BorderSize = 1;
        b.FlatAppearance.MouseOverBackColor = BtnBgHover;
        b.FlatAppearance.MouseDownBackColor = BtnBgPressed;
        return b;
    }

    private TextBox MakeTxt(int x, int y, int w) => new()
    {
        Location = new Point(x, y), Width = w,
        BackColor = BgInput, ForeColor = TextPrimary,
        BorderStyle = BorderStyle.FixedSingle, Font = new Font("Consolas", 9)
    };

    private void PaintHeader(object? sender, PaintEventArgs e)
    {
        var g = e.Graphics;
        g.SmoothingMode = SmoothingMode.AntiAlias;
        g.InterpolationMode = InterpolationMode.HighQualityBicubic;
        g.TextRenderingHint = System.Drawing.Text.TextRenderingHint.ClearTypeGridFit;
        var rect = _header.ClientRectangle;

        using (var bg = new LinearGradientBrush(
            rect, Color.FromArgb(15, 15, 20), Color.FromArgb(25, 25, 35), 90f))
            g.FillRectangle(bg, rect);

        int tx = 20;

        using var titleFont = new Font("Segoe UI", 16, FontStyle.Bold);
        using var titleBrush = new SolidBrush(Color.FromArgb(220, 220, 230));
        g.DrawString("TBH Trainer", titleFont, titleBrush, tx, 6);

        using var subtitleFont = new Font("Segoe UI", 8.5f);
        using var subtitleBrush = new SolidBrush(Color.FromArgb(150, 150, 170));
        g.DrawString("UnKnoWnCheaTs Community", subtitleFont, subtitleBrush, tx, 30);

        using var tagFont = new Font("Segoe UI", 7.5f);
        using var tagBrush = new SolidBrush(Color.FromArgb(100, 180, 255));
        g.DrawString("1.00.09 \u2022 ACTk Bypass \u2022 Speedhack \u2022 Stat Editor \u2022 Instakill \u2022 EXP Mod",
            tagFont, tagBrush, tx + 200, 10);

        using var pen = new Pen(Color.FromArgb(80, AccentBlue), 1);
        g.DrawLine(pen, 0, rect.Height - 1, rect.Width, rect.Height - 1);
    }

    private void Log(string msg)
    {
        string line = $"[{DateTime.Now:HH:mm:ss}] {msg}\r\n";
        if (_txtLog.InvokeRequired) _txtLog.Invoke(() => _txtLog.AppendText(line));
        else _txtLog.AppendText(line);
    }

    // ========================================================================
    //  EVENT HANDLERS
    // ========================================================================
    private void OnAttach(GameInstance inst)
    {
        if (inst.Mem.IsAttached)
        {
            inst.Bridge.SetSpeed(false, 1.0f);
            inst.Bridge.Dispose();
            inst.Mem.Detach();
            inst.Patcher = null;
            inst.Pid = -1;
            inst.Injected = false;
            inst.BtnAttach.Text = "Connect";
            inst.LblStatus.Text = "Disconnected";
            inst.LblStatus.ForeColor = AccentRed;
            inst.BtnBypass.Enabled = false;
            inst.BtnPop.Enabled = false;
            inst.ChkSpeed.Checked = false;
            inst.PnlSpeed.Visible = false;
            inst.Hero = null;

            inst.TxtHp.Enabled = inst.BtnApplyHp.Enabled = inst.ChkLockHp.Enabled = false;
            inst.ChkLockHp.Checked = false;
            inst.LockedHp = null;

            inst.TxtAtk.Enabled = inst.BtnApplyAtk.Enabled = inst.ChkLockAtk.Enabled = false;
            inst.ChkLockAtk.Checked = false;
            inst.LockedAtk = null;

            inst.TxtAtkSpeed.Enabled = inst.BtnApplyAtkSpeed.Enabled = inst.ChkLockAtkSpeed.Enabled = false;
            inst.ChkLockAtkSpeed.Checked = false;
            inst.LockedAtkSpeed = null;

            inst.TxtMoveSpeed.Enabled = inst.BtnApplyMoveSpeed.Enabled = inst.ChkLockMoveSpeed.Enabled = false;
            inst.ChkLockMoveSpeed.Checked = false;
            inst.LockedMoveSpeed = null;

            inst.BtnResetStats.Enabled = false;

            inst.Exp?.ResetWithoutRestore();
            inst.Exp = null;
            inst.TxtExp.Enabled = inst.BtnApplyExp.Enabled = inst.BtnDisableExp.Enabled = false;
            inst.LblExpStatus.Text = "OFF"; inst.LblExpStatus.ForeColor = TextDim;

            inst.Gold?.ResetWithoutRestore();
            inst.Gold = null;
            inst.TxtGold.Enabled = inst.BtnApplyGold.Enabled = inst.BtnDisableGold.Enabled = false;
            inst.LblGoldStatus.Text = "OFF"; inst.LblGoldStatus.ForeColor = TextDim;

            inst.ChkInstakill.Enabled = false;
            inst.ChkInstakill.Checked = false;
            inst.InstakillActive = false;
            inst.SavedAtkBeforeInstakill = null;
            inst.LblInstakillStatus.Text = "OFF"; inst.LblInstakillStatus.ForeColor = TextDim;

            inst.ChkInvincible.Enabled = false;
            inst.ChkInvincible.Checked = false;
            inst.InvincibleActive = false;
            inst.SavedHpBeforeInvincible = null;
            inst.LblInvincibleStatus.Text = "OFF"; inst.LblInvincibleStatus.ForeColor = TextDim;

            inst.ChkAtkSpeed10k.Enabled = false;
            inst.ChkAtkSpeed10k.Checked = false;
            inst.AtkSpeed10kActive = false;
            inst.ChkAtkSpeed5k.Enabled = false;
            inst.ChkAtkSpeed5k.Checked = false;
            inst.AtkSpeed5kActive = false;
            inst.SavedAtkSpeedBeforePreset = null;

            inst.ChkMoveSpeed10k.Enabled = false;
            inst.ChkMoveSpeed10k.Checked = false;
            inst.MoveSpeed10kActive = false;
            inst.ChkMoveSpeed5k.Enabled = false;
            inst.ChkMoveSpeed5k.Checked = false;
            inst.MoveSpeed5kActive = false;
            inst.SavedMoveSpeedBeforePreset = null;

            Log($"[{inst.Name}] Disconnected.");
            return;
        }

        var activePids = new Dictionary<int, string>();
        foreach (var other in _instances)
        {
            if (other != inst && other.Mem.IsAttached && other.Pid > 0)
            {
                activePids[other.Pid] = other.Name;
            }
        }

        using var picker = new ProcessPickerForm(activePids);
        if (picker.ShowDialog(this) != DialogResult.OK || picker.SelectedPid < 0)
        {
            Log($"[{inst.Name}] Process selection cancelled.");
            return;
        }

        // Verify if another instance has this PID connected already
        foreach (var other in _instances)
        {
            if (other != inst && other.Pid == picker.SelectedPid)
            {
                Log($"[{inst.Name}] ERROR: Process ID {picker.SelectedPid} is already controlled by {other.Name}.");
                return;
            }
        }

        if (inst.Mem.AttachToPid(picker.SelectedPid))
        {
            inst.Pid = picker.SelectedPid;
            inst.Patcher = new AntiCheatPatcher(inst.Mem);
            inst.Hero = new HeroStats(inst.Mem);
            inst.BtnAttach.Text = "Disconnect";
            inst.LblStatus.Text = $"Connected (PID {inst.Pid})";
            inst.LblStatus.ForeColor = Color.FromArgb(100, 255, 100);
            inst.BtnBypass.Enabled = true;
            inst.BtnPop.Enabled = true;

            inst.TxtHp.Enabled = inst.BtnApplyHp.Enabled = inst.ChkLockHp.Enabled = true;
            inst.TxtAtk.Enabled = inst.BtnApplyAtk.Enabled = inst.ChkLockAtk.Enabled = true;
            inst.TxtAtkSpeed.Enabled = inst.BtnApplyAtkSpeed.Enabled = inst.ChkLockAtkSpeed.Enabled = true;
            inst.TxtMoveSpeed.Enabled = inst.BtnApplyMoveSpeed.Enabled = inst.ChkLockMoveSpeed.Enabled = true;
            inst.BtnResetStats.Enabled = true;

            inst.Exp = new HighExpPatcher(inst.Mem);
            inst.TxtExp.Enabled = inst.BtnApplyExp.Enabled = true;
            inst.BtnDisableExp.Enabled = false;

            inst.Gold = new HighGoldPatcher(inst.Mem);
            inst.TxtGold.Enabled = inst.BtnApplyGold.Enabled = true;
            inst.BtnDisableGold.Enabled = false;

            inst.ChkInstakill.Enabled = true;
            inst.ChkInvincible.Enabled = true;
            inst.ChkAtkSpeed10k.Enabled = true;
            inst.ChkAtkSpeed5k.Enabled = true;
            inst.ChkMoveSpeed10k.Enabled = true;
            inst.ChkMoveSpeed5k.Enabled = true;

            Log($"[{inst.Name}] Connected to PID {inst.Pid}.");
        }
        else
        {
            Log($"[{inst.Name}] ERROR: could not attach (no GameAssembly.dll?). Run as Admin.");
        }
    }

    private void OnBypass(GameInstance inst)
    {
        if (inst.Patcher == null) return;

        var report = inst.Patcher.PatchDetectors();
        int ok = report.Count(r => r.ok);
        Log($"[{inst.Name}] --- ACTk Bypass: {ok}/{report.Count} detectors neutralized ---");
        foreach (var (name, success, detail) in report)
            Log($"  [{(success ? "OK" : "SKIP")}] {name} - {detail}");

        if (ok == report.Count)
        {
            inst.LblBypassStatus.Text = "ACTk DISABLED";
            inst.LblBypassStatus.ForeColor = Color.FromArgb(100, 255, 100);
        }
        else if (ok > 0)
        {
            inst.LblBypassStatus.Text = $"PARTIAL ({ok}/{report.Count})";
            inst.LblBypassStatus.ForeColor = Color.FromArgb(255, 200, 50);
        }
        else
        {
            inst.LblBypassStatus.Text = "FAILED";
            inst.LblBypassStatus.ForeColor = AccentRed;
        }
    }

    private bool EnsureSpeedReady(GameInstance inst)
    {
        if (inst.Bridge.IsConnected) return true;
        if (inst.Pid < 0) { Log($"[{inst.Name}] Connect to the game first."); return false; }

        if (!inst.Injected)
        {
            Log($"[{inst.Name}] Injecting TBHHook.dll into PID {inst.Pid}...");
            if (!File.Exists(DllPath))
            {
                Log($"[{inst.Name}] ERROR: TBHHook.dll not found at: {DllPath}");
                return false;
            }
            var (ok, msg) = Injector.Inject(inst.Pid, DllPath);
            Log($"[{inst.Name}]   {msg}");
            if (!ok) return false;
            inst.Injected = true;
        }

        if (!inst.Bridge.Connect(inst.Mem, inst.Pid))
        {
            Log($"[{inst.Name}] ERROR: injected DLL did not create the shared channel.");
            Log("  Check TBHHook_debug.log inside the game directory for error details.");
            return false;
        }

        if (!inst.Bridge.WaitHeartbeat())
        {
            Log($"[{inst.Name}] ERROR: DLL loaded but worker thread is not responding.");
            return false;
        }

        Log($"[{inst.Name}] Bridge connected. il2cpp ready={inst.Bridge.Il2CppReady}, Time resolved={inst.Bridge.TimeResolved}.");
        return true;
    }

    private void OnSpeedToggle(GameInstance inst)
    {
        if (inst.ChkSpeed.Checked)
        {
            if (!EnsureSpeedReady(inst))
            {
                inst.ChkSpeed.Checked = false;
                return;
            }
            inst.PnlSpeed.Visible = true;
            float v = ParseSpeed(inst);
            inst.Bridge.SetSpeed(true, v);
            Log($"[{inst.Name}] Speedhack ENABLED at {Fmt(v)}x.");
        }
        else
        {
            inst.PnlSpeed.Visible = false;
            if (inst.Bridge.IsConnected)
            {
                inst.Bridge.SetSpeed(false, 1.0f);
                Log($"[{inst.Name}] Speedhack disabled (speed restored to 1.00x).");
            }
        }
    }

    private void OnSpeedSlider(GameInstance inst)
    {
        float v = inst.TrkSpeed.Value / 10f;
        if (!inst.SuppressSlider)
            inst.TxtSpeed.Text = Fmt(v);
        inst.LblSpeedValue.Text = $"Speed: {Fmt(v)}x";
        if (!inst.SuppressSlider && inst.ChkSpeed.Checked && inst.Bridge.IsConnected)
            inst.Bridge.SetSpeed(true, v);
    }

    private void OnSpeedKeyDown(GameInstance inst, KeyEventArgs e)
    {
        if (e.KeyCode != Keys.Enter) return;
        e.SuppressKeyPress = true;
        CommitTypedSpeed(inst);
    }

    private void CommitTypedSpeed(GameInstance inst)
    {
        float v = ParseSpeed(inst);
        inst.TxtSpeed.Text = Fmt(v);
        inst.LblSpeedValue.Text = $"Speed: {Fmt(v)}x";

        inst.SuppressSlider = true;
        inst.TrkSpeed.Value = (int)Math.Clamp(Math.Round(v * 10f), 0, 100);
        inst.SuppressSlider = false;

        if (inst.ChkSpeed.Checked && inst.Bridge.IsConnected)
        {
            inst.Bridge.SetSpeed(true, v);
            Log($"[{inst.Name}] Applied speed {Fmt(v)}x.");
        }
    }

    private float ParseSpeed(GameInstance inst)
    {
        string s = inst.TxtSpeed.Text.Trim().Replace(',', '.');
        if (!float.TryParse(s, System.Globalization.NumberStyles.Float,
                System.Globalization.CultureInfo.InvariantCulture, out float v))
            v = 1.0f;
        return Math.Clamp(v, 0f, 10f);
    }

    private static string Fmt(float v) =>
        v.ToString("0.00", System.Globalization.CultureInfo.InvariantCulture);

    private static bool TryParseStat(string text, out float value)
    {
        string s = text.Trim().Replace(',', '.');
        return float.TryParse(s, System.Globalization.NumberStyles.Float,
            System.Globalization.CultureInfo.InvariantCulture, out value);
    }

    // === Hero Stats Apply ===
    private void OnApplyHp(GameInstance inst)
    {
        if (inst.Hero == null) return;
        if (!TryParseStat(inst.TxtHp.Text, out float v)) { Log($"[{inst.Name}] Invalid HP value."); return; }

        if (inst.Hero.SetAllHeroesHp(v))
        {
            Log($"[{inst.Name}] HP set to {Fmt(v)} for all heroes.");
            if (inst.ChkLockHp.Checked) { inst.LockedHp = v; }
        }
        else
            Log($"[{inst.Name}] Could not write HP. Enter a run/battle first.");
    }

    private void OnApplyAtk(GameInstance inst)
    {
        if (inst.Hero == null) return;
        if (!TryParseStat(inst.TxtAtk.Text, out float v)) { Log($"[{inst.Name}] Invalid ATK value."); return; }

        if (inst.Hero.SetAllHeroesAtk(v))
        {
            Log($"[{inst.Name}] ATK set to {Fmt(v)} for all heroes.");
            if (inst.ChkLockAtk.Checked) { inst.LockedAtk = v; }
        }
        else
            Log($"[{inst.Name}] Could not write ATK. Enter a run/battle first.");
    }

    private void OnApplyAtkSpeed(GameInstance inst)
    {
        if (inst.Hero == null) return;
        if (!TryParseStat(inst.TxtAtkSpeed.Text, out float v)) { Log($"[{inst.Name}] Invalid ATK Speed value."); return; }

        if (inst.Hero.SetAllHeroesAtkSpeed(v))
        {
            Log($"[{inst.Name}] ATK Speed set to {Fmt(v)} for all heroes.");
            if (inst.ChkLockAtkSpeed.Checked) { inst.LockedAtkSpeed = v; }
        }
        else
            Log($"[{inst.Name}] Could not write ATK Speed. Enter a run/battle first.");
    }

    private void OnApplyMoveSpeed(GameInstance inst)
    {
        if (inst.Hero == null) return;
        if (!TryParseStat(inst.TxtMoveSpeed.Text, out float v)) { Log($"[{inst.Name}] Invalid Move Speed value."); return; }

        if (inst.Hero.SetAllHeroesMoveSpeed(v))
        {
            Log($"[{inst.Name}] Move Speed set to {Fmt(v)} for all heroes.");
            if (inst.ChkLockMoveSpeed.Checked) { inst.LockedMoveSpeed = v; }
        }
        else
            Log($"[{inst.Name}] Could not write Move Speed. Enter a run/battle first.");
    }

    // --- Stat Locks ---
    private void OnLockHpChanged(GameInstance inst)
    {
        if (inst.ChkLockHp.Checked)
        {
            if (TryParseStat(inst.TxtHp.Text, out float v))
            { inst.LockedHp = v; Log($"[{inst.Name}] HP locked at {Fmt(v)}."); }
            else
            {
                inst.ChkLockHp.CheckedChanged -= (s, e) => OnLockHpChanged(inst);
                inst.ChkLockHp.Checked = false;
                inst.ChkLockHp.CheckedChanged += (s, e) => OnLockHpChanged(inst);
                Log($"[{inst.Name}] Enter a valid HP value first.");
            }
        }
        else { inst.LockedHp = null; Log($"[{inst.Name}] HP unlocked."); }
    }

    private void OnLockAtkChanged(GameInstance inst)
    {
        if (inst.ChkLockAtk.Checked)
        {
            if (TryParseStat(inst.TxtAtk.Text, out float v))
            { inst.LockedAtk = v; Log($"[{inst.Name}] ATK locked at {Fmt(v)}."); }
            else
            {
                inst.ChkLockAtk.CheckedChanged -= (s, e) => OnLockAtkChanged(inst);
                inst.ChkLockAtk.Checked = false;
                inst.ChkLockAtk.CheckedChanged += (s, e) => OnLockAtkChanged(inst);
                Log($"[{inst.Name}] Enter a valid ATK value first.");
            }
        }
        else { inst.LockedAtk = null; Log($"[{inst.Name}] ATK unlocked."); }
    }

    private void OnLockAtkSpeedChanged(GameInstance inst)
    {
        if (inst.ChkLockAtkSpeed.Checked)
        {
            if (TryParseStat(inst.TxtAtkSpeed.Text, out float v))
            { inst.LockedAtkSpeed = v; Log($"[{inst.Name}] ATK Speed locked at {Fmt(v)}."); }
            else
            {
                inst.ChkLockAtkSpeed.CheckedChanged -= (s, e) => OnLockAtkSpeedChanged(inst);
                inst.ChkLockAtkSpeed.Checked = false;
                inst.ChkLockAtkSpeed.CheckedChanged += (s, e) => OnLockAtkSpeedChanged(inst);
                Log($"[{inst.Name}] Enter a valid ATK Speed value first.");
            }
        }
        else { inst.LockedAtkSpeed = null; Log($"[{inst.Name}] ATK Speed unlocked."); }
    }

    private void OnLockMoveSpeedChanged(GameInstance inst)
    {
        if (inst.ChkLockMoveSpeed.Checked)
        {
            if (TryParseStat(inst.TxtMoveSpeed.Text, out float v))
            { inst.LockedMoveSpeed = v; Log($"[{inst.Name}] Move Speed locked at {Fmt(v)}."); }
            else
            {
                inst.ChkLockMoveSpeed.CheckedChanged -= (s, e) => OnLockMoveSpeedChanged(inst);
                inst.ChkLockMoveSpeed.Checked = false;
                inst.ChkLockMoveSpeed.CheckedChanged += (s, e) => OnLockMoveSpeedChanged(inst);
                Log($"[{inst.Name}] Enter a valid Move Speed value first.");
            }
        }
        else { inst.LockedMoveSpeed = null; Log($"[{inst.Name}] Move Speed unlocked."); }
    }

    // --- Reset Stats ---
    private void OnResetStats(GameInstance inst)
    {
        if (inst.Hero == null) return;

        // Restore original stats if backups exist
        if (inst.SavedHpBeforeInvincible.HasValue)
        {
            inst.Hero.SetAllHeroesHp(inst.SavedHpBeforeInvincible.Value);
            inst.SavedHpBeforeInvincible = null;
        }
        if (inst.SavedAtkBeforeInstakill.HasValue)
        {
            inst.Hero.SetAllHeroesAtk(inst.SavedAtkBeforeInstakill.Value);
            inst.SavedAtkBeforeInstakill = null;
        }
        if (inst.SavedAtkSpeedBeforePreset.HasValue)
        {
            inst.Hero.SetAllHeroesAtkSpeed(inst.SavedAtkSpeedBeforePreset.Value);
            inst.SavedAtkSpeedBeforePreset = null;
        }
        if (inst.SavedMoveSpeedBeforePreset.HasValue)
        {
            inst.Hero.SetAllHeroesMoveSpeed(inst.SavedMoveSpeedBeforePreset.Value);
            inst.SavedMoveSpeedBeforePreset = null;
        }

        // Uncheck all locks
        inst.ChkLockHp.Checked = false;
        inst.ChkLockAtk.Checked = false;
        inst.ChkLockAtkSpeed.Checked = false;
        inst.ChkLockMoveSpeed.Checked = false;

        // Disable presets
        inst.ChkInstakill.Checked = false;
        inst.ChkInvincible.Checked = false;
        inst.ChkAtkSpeed10k.Checked = false;
        inst.ChkAtkSpeed5k.Checked = false;
        inst.ChkMoveSpeed10k.Checked = false;
        inst.ChkMoveSpeed5k.Checked = false;

        // Clear text fields
        inst.TxtHp.Text = "";
        inst.TxtAtk.Text = "";
        inst.TxtAtkSpeed.Text = "";
        inst.TxtMoveSpeed.Text = "";

        Log($"[{inst.Name}] All stat locks and presets released. Stats restored to their baseline.");
    }

    // --- Lock Timer ---
    private void OnLockTimerTick(object? sender, EventArgs e)
    {
        foreach (var inst in _instances)
        {
            if (inst.Hero == null || !inst.Mem.IsAttached) continue;

            // Automatically read real stats if empty and in run
            if (string.IsNullOrWhiteSpace(inst.TxtHp.Text))
            {
                float? hp = inst.Hero.GetAllHeroesHp();
                if (hp.HasValue && hp.Value > 0) inst.TxtHp.Text = Fmt(hp.Value);
            }
            if (string.IsNullOrWhiteSpace(inst.TxtAtk.Text))
            {
                float? atk = inst.Hero.GetAllHeroesAtk();
                if (atk.HasValue && atk.Value > 0) inst.TxtAtk.Text = Fmt(atk.Value);
            }
            if (string.IsNullOrWhiteSpace(inst.TxtAtkSpeed.Text))
            {
                float? atkSpd = inst.Hero.GetAllHeroesAtkSpeed();
                if (atkSpd.HasValue && atkSpd.Value > 0) inst.TxtAtkSpeed.Text = Fmt(atkSpd.Value);
            }
            if (string.IsNullOrWhiteSpace(inst.TxtMoveSpeed.Text))
            {
                float? moveSpd = inst.Hero.GetAllHeroesMoveSpeed();
                if (moveSpd.HasValue && moveSpd.Value > 0) inst.TxtMoveSpeed.Text = Fmt(moveSpd.Value);
            }

            // Locks
            if (inst.ChkLockHp.Checked && inst.LockedHp.HasValue)
                inst.Hero.SetAllHeroesHp(inst.LockedHp.Value);

            if (inst.ChkLockAtk.Checked && inst.LockedAtk.HasValue)
                inst.Hero.SetAllHeroesAtk(inst.LockedAtk.Value);

            if (inst.ChkLockAtkSpeed.Checked && inst.LockedAtkSpeed.HasValue)
                inst.Hero.SetAllHeroesAtkSpeed(inst.LockedAtkSpeed.Value);

            if (inst.ChkLockMoveSpeed.Checked && inst.LockedMoveSpeed.HasValue)
                inst.Hero.SetAllHeroesMoveSpeed(inst.LockedMoveSpeed.Value);

            // Presets
            if (inst.InstakillActive)
                inst.Hero.SetAllHeroesAtk(1_000_000f);

            if (inst.InvincibleActive)
                inst.Hero.SetAllHeroesHp(1_000_000f);

            if (inst.AtkSpeed10kActive)
                inst.Hero.SetAllHeroesAtkSpeed(10000f);
            else if (inst.AtkSpeed5kActive)
                inst.Hero.SetAllHeroesAtkSpeed(5000f);

            if (inst.MoveSpeed10kActive)
                inst.Hero.SetAllHeroesMoveSpeed(10000f);
            else if (inst.MoveSpeed5kActive)
                inst.Hero.SetAllHeroesMoveSpeed(5000f);
        }
    }

    // --- Quick Presets ---
    private void OnInstakillToggle(GameInstance inst)
    {
        if (inst.ChkInstakill.Checked)
        {
            if (inst.Hero == null) { Log($"[{inst.Name}] Connect to the game first."); inst.ChkInstakill.Checked = false; return; }

            // Save actual current ATK value from the game memory
            float? liveAtk = inst.Hero.GetAllHeroesAtk();
            if (liveAtk.HasValue && liveAtk.Value > 0 && liveAtk.Value != 1_000_000f)
                inst.SavedAtkBeforeInstakill = liveAtk.Value;

            inst.InstakillActive = true;
            inst.Hero.SetAllHeroesAtk(1_000_000f);
            inst.LblInstakillStatus.Text = "ACTIVE";
            inst.LblInstakillStatus.ForeColor = Color.FromArgb(255, 100, 100);
            Log($"[{inst.Name}] \u26A1 One-Hit Kill ENABLED \u2014 ATK locked to 1,000,000.");
        }
        else
        {
            inst.InstakillActive = false;
            inst.LblInstakillStatus.Text = "OFF";
            inst.LblInstakillStatus.ForeColor = TextDim;

            // Restore original ATK if we saved it
            if (inst.SavedAtkBeforeInstakill.HasValue && inst.Hero != null)
            {
                inst.Hero.SetAllHeroesAtk(inst.SavedAtkBeforeInstakill.Value);
                inst.TxtAtk.Text = Fmt(inst.SavedAtkBeforeInstakill.Value);
                Log($"[{inst.Name}] One-Hit Kill disabled. ATK restored to {Fmt(inst.SavedAtkBeforeInstakill.Value)}.");
                inst.SavedAtkBeforeInstakill = null;
            }
            else
            {
                Log($"[{inst.Name}] One-Hit Kill disabled.");
            }
        }
    }

    private void OnInvincibleToggle(GameInstance inst)
    {
        if (inst.ChkInvincible.Checked)
        {
            if (inst.Hero == null) { Log($"[{inst.Name}] Connect to the game first."); inst.ChkInvincible.Checked = false; return; }

            // Save actual current HP value from the game memory
            float? liveHp = inst.Hero.GetAllHeroesHp();
            if (liveHp.HasValue && liveHp.Value > 0 && liveHp.Value != 1_000_000f)
                inst.SavedHpBeforeInvincible = liveHp.Value;

            inst.InvincibleActive = true;
            inst.Hero.SetAllHeroesHp(1_000_000f);
            inst.LblInvincibleStatus.Text = "ACTIVE";
            inst.LblInvincibleStatus.ForeColor = Color.FromArgb(100, 200, 255);
            Log($"[{inst.Name}] \U0001F6E1 Invincible ENABLED \u2014 HP locked to 1,000,000.");
        }
        else
        {
            inst.InvincibleActive = false;
            inst.LblInvincibleStatus.Text = "OFF";
            inst.LblInvincibleStatus.ForeColor = TextDim;

            // Restore original HP if we saved it
            if (inst.SavedHpBeforeInvincible.HasValue && inst.Hero != null)
            {
                inst.Hero.SetAllHeroesHp(inst.SavedHpBeforeInvincible.Value);
                inst.TxtHp.Text = Fmt(inst.SavedHpBeforeInvincible.Value);
                Log($"[{inst.Name}] Invincible disabled. HP restored to {Fmt(inst.SavedHpBeforeInvincible.Value)}.");
                inst.SavedHpBeforeInvincible = null;
            }
            else
            {
                Log($"[{inst.Name}] Invincible disabled.");
            }
        }
    }

    // --- ATK Speed Presets (10k / 5k) ---
    private void OnAtkSpeed10kToggle(GameInstance inst)
    {
        if (inst.ChkAtkSpeed10k.Checked)
        {
            if (inst.Hero == null) { Log($"[{inst.Name}] Connect to the game first."); inst.ChkAtkSpeed10k.Checked = false; return; }
            inst.ChkAtkSpeed5k.Checked = false;

            float? liveAtkSpd = inst.Hero.GetAllHeroesAtkSpeed();
            if (liveAtkSpd.HasValue && liveAtkSpd.Value > 0 && liveAtkSpd.Value != 10000f && liveAtkSpd.Value != 5000f)
                inst.SavedAtkSpeedBeforePreset = liveAtkSpd.Value;

            inst.AtkSpeed10kActive = true;
            inst.Hero.SetAllHeroesAtkSpeed(10000f);
            Log($"[{inst.Name}] ATK Speed 10k preset ENABLED.");
        }
        else
        {
            inst.AtkSpeed10kActive = false;
            RestoreOriginalAtkSpeed(inst);
        }
    }

    private void OnAtkSpeed5kToggle(GameInstance inst)
    {
        if (inst.ChkAtkSpeed5k.Checked)
        {
            if (inst.Hero == null) { Log($"[{inst.Name}] Connect to the game first."); inst.ChkAtkSpeed5k.Checked = false; return; }
            inst.ChkAtkSpeed10k.Checked = false;

            float? liveAtkSpd = inst.Hero.GetAllHeroesAtkSpeed();
            if (liveAtkSpd.HasValue && liveAtkSpd.Value > 0 && liveAtkSpd.Value != 10000f && liveAtkSpd.Value != 5000f)
                inst.SavedAtkSpeedBeforePreset = liveAtkSpd.Value;

            inst.AtkSpeed5kActive = true;
            inst.Hero.SetAllHeroesAtkSpeed(5000f);
            Log($"[{inst.Name}] ATK Speed 5k preset ENABLED.");
        }
        else
        {
            inst.AtkSpeed5kActive = false;
            RestoreOriginalAtkSpeed(inst);
        }
    }

    private void RestoreOriginalAtkSpeed(GameInstance inst)
    {
        if (!inst.ChkAtkSpeed10k.Checked && !inst.ChkAtkSpeed5k.Checked)
        {
            if (inst.SavedAtkSpeedBeforePreset.HasValue && inst.Hero != null)
            {
                inst.Hero.SetAllHeroesAtkSpeed(inst.SavedAtkSpeedBeforePreset.Value);
                inst.TxtAtkSpeed.Text = Fmt(inst.SavedAtkSpeedBeforePreset.Value);
                Log($"[{inst.Name}] ATK Speed preset disabled. Restored to {Fmt(inst.SavedAtkSpeedBeforePreset.Value)}.");
                inst.SavedAtkSpeedBeforePreset = null;
            }
            else
            {
                Log($"[{inst.Name}] ATK Speed preset disabled.");
            }
        }
    }

    // --- Move Speed Presets (10k / 5k) ---
    private void OnMoveSpeed10kToggle(GameInstance inst)
    {
        if (inst.ChkMoveSpeed10k.Checked)
        {
            if (inst.Hero == null) { Log($"[{inst.Name}] Connect to the game first."); inst.ChkMoveSpeed10k.Checked = false; return; }
            inst.ChkMoveSpeed5k.Checked = false;

            float? liveMoveSpd = inst.Hero.GetAllHeroesMoveSpeed();
            if (liveMoveSpd.HasValue && liveMoveSpd.Value > 0 && liveMoveSpd.Value != 10000f && liveMoveSpd.Value != 5000f)
                inst.SavedMoveSpeedBeforePreset = liveMoveSpd.Value;

            inst.MoveSpeed10kActive = true;
            inst.Hero.SetAllHeroesMoveSpeed(10000f);
            Log($"[{inst.Name}] Move Speed 10k preset ENABLED.");
        }
        else
        {
            inst.MoveSpeed10kActive = false;
            RestoreOriginalMoveSpeed(inst);
        }
    }

    private void OnMoveSpeed5kToggle(GameInstance inst)
    {
        if (inst.ChkMoveSpeed5k.Checked)
        {
            if (inst.Hero == null) { Log($"[{inst.Name}] Connect to the game first."); inst.ChkMoveSpeed5k.Checked = false; return; }
            inst.ChkMoveSpeed10k.Checked = false;

            float? liveMoveSpd = inst.Hero.GetAllHeroesMoveSpeed();
            if (liveMoveSpd.HasValue && liveMoveSpd.Value > 0 && liveMoveSpd.Value != 10000f && liveMoveSpd.Value != 5000f)
                inst.SavedMoveSpeedBeforePreset = liveMoveSpd.Value;

            inst.MoveSpeed5kActive = true;
            inst.Hero.SetAllHeroesMoveSpeed(5000f);
            Log($"[{inst.Name}] Move Speed 5k preset ENABLED.");
        }
        else
        {
            inst.MoveSpeed5kActive = false;
            RestoreOriginalMoveSpeed(inst);
        }
    }

    private void RestoreOriginalMoveSpeed(GameInstance inst)
    {
        if (!inst.ChkMoveSpeed10k.Checked && !inst.ChkMoveSpeed5k.Checked)
        {
            if (inst.SavedMoveSpeedBeforePreset.HasValue && inst.Hero != null)
            {
                inst.Hero.SetAllHeroesMoveSpeed(inst.SavedMoveSpeedBeforePreset.Value);
                inst.TxtMoveSpeed.Text = Fmt(inst.SavedMoveSpeedBeforePreset.Value);
                Log($"[{inst.Name}] Move Speed preset disabled. Restored to {Fmt(inst.SavedMoveSpeedBeforePreset.Value)}.");
                inst.SavedMoveSpeedBeforePreset = null;
            }
            else
            {
                Log($"[{inst.Name}] Move Speed preset disabled.");
            }
        }
    }

    // --- EXP on Kill ---
    private void OnApplyExp(GameInstance inst)
    {
        if (inst.Exp == null) { Log($"[{inst.Name}] Connect to the game first."); return; }
        if (!TryParseStat(inst.TxtExp.Text, out float v) || v <= 0)
        {
            Log($"[{inst.Name}] Invalid EXP value.");
            return;
        }

        var (ok, msg) = inst.Exp.Enable(v);
        Log($"[{inst.Name}][High EXP] {msg}");
        if (ok)
        {
            inst.LblExpStatus.Text = $"ON ({v:0})";
            inst.LblExpStatus.ForeColor = Color.FromArgb(120, 255, 160);
            inst.BtnApplyExp.Text = "Update";
            inst.BtnDisableExp.Enabled = true;
        }
    }

    private void OnDisableExp(GameInstance inst)
    {
        if (inst.Exp == null) return;
        var (ok, msg) = inst.Exp.Disable();
        Log($"[{inst.Name}][High EXP] {msg}");
        if (ok)
        {
            inst.LblExpStatus.Text = "OFF";
            inst.LblExpStatus.ForeColor = TextDim;
            inst.BtnApplyExp.Text = "Enable";
            inst.BtnDisableExp.Enabled = false;
        }
    }

    // --- Gold on Kill ---
    private void OnApplyGold(GameInstance inst)
    {
        if (inst.Gold == null) { Log($"[{inst.Name}] Connect to the game first."); return; }
        if (!long.TryParse(inst.TxtGold.Text.Trim(), out long v) || v <= 0)
        {
            Log($"[{inst.Name}] Invalid Gold value.");
            return;
        }

        var (ok, msg) = inst.Gold.Enable(v);
        Log($"[{inst.Name}][High Gold] {msg}");
        if (ok)
        {
            inst.LblGoldStatus.Text = $"ON ({v:N0})";
            inst.LblGoldStatus.ForeColor = Color.FromArgb(120, 255, 160);
            inst.BtnApplyGold.Text = "Update";
            inst.BtnDisableGold.Enabled = true;
        }
    }

    private void OnDisableGold(GameInstance inst)
    {
        if (inst.Gold == null) return;
        var (ok, msg) = inst.Gold.Disable();
        Log($"[{inst.Name}][High Gold] {msg}");
        if (ok)
        {
            inst.LblGoldStatus.Text = "OFF";
            inst.LblGoldStatus.ForeColor = TextDim;
            inst.BtnApplyGold.Text = "Enable";
            inst.BtnDisableGold.Enabled = false;
        }
    }

    // --- Static Tab handlers ---
    private void OnBrowseDll(object? sender, EventArgs e)
    {
        using var ofd = new OpenFileDialog
        {
            Title = "Select GameAssembly.dll",
            Filter = "GameAssembly.dll|GameAssembly.dll|DLL files (*.dll)|*.dll",
            FileName = "GameAssembly.dll"
        };
        if (ofd.ShowDialog(this) != DialogResult.OK) return;
        _static = new StaticPatcher(ofd.FileName);
        _txtDllPath.Text = ofd.FileName;
        RefreshStatic(log: true);
    }

    private void OnToggleFeature(StaticPatcher.Feature f)
    {
        if (_static == null) { Log("Select GameAssembly.dll first (Browse)."); return; }
        var (ok, msg) = f.State == StaticPatcher.FeatureState.Patched
            ? _static.Revert(f)
            : _static.Apply(f);
        Log($"[{f.Name}] {msg}");
        RefreshStatic(log: false);
    }

    private void OnRestoreBackup(object? sender, EventArgs e)
    {
        if (_static == null) { Log("Select GameAssembly.dll first (Browse)."); return; }
        var (ok, msg) = _static.RestoreBackup();
        Log(msg);
        if (ok) RefreshStatic(log: false);
    }

    private void RefreshStatic(bool log)
    {
        if (_static == null) { if (log) Log("No DLL selected."); return; }
        if (!_static.DllExists) { if (log) Log("GameAssembly.dll not found at the selected path."); return; }

        try { _static.Refresh(_features); }
        catch (Exception ex) { if (log) Log($"Could not read DLL: {ex.Message}"); return; }

        foreach (var f in _features)
        {
            var (status, toggle) = _featRows[f];
            switch (f.State)
            {
                case StaticPatcher.FeatureState.Original:
                    status.Text = "OFF"; status.ForeColor = TextDim;
                    toggle.Text = "Apply"; toggle.Enabled = true;
                    break;
                case StaticPatcher.FeatureState.Patched:
                    status.Text = "ON"; status.ForeColor = Color.FromArgb(120, 255, 160);
                    toggle.Text = "Revert"; toggle.Enabled = true;
                    break;
                default:
                    status.Text = "MISMATCH"; status.ForeColor = Color.FromArgb(255, 170, 60);
                    toggle.Text = "Apply"; toggle.Enabled = false;
                    break;
            }
        }

        if (log)
        {
            int on = _features.Count(f => f.State == StaticPatcher.FeatureState.Patched);
            int mis = _features.Count(f => f.State == StaticPatcher.FeatureState.Mismatch);
            Log($"Status refreshed: {on} ON, {mis} mismatch. Backup {(_static.BackupExists ? "present" : "not yet")}.");
            if (mis > 0) Log("MISMATCH = offset doesn't match this game version (safe).");
        }
    }

    protected override void OnFormClosing(FormClosingEventArgs e)
    {
        foreach (var inst in _instances)
        {
            try { if (inst.Bridge.IsConnected) inst.Bridge.SetSpeed(false, 1.0f); } catch { }
            try { if (inst.Exp is { IsEnabled: true }) inst.Exp.Disable(); } catch { }
            try { if (inst.Gold is { IsEnabled: true }) inst.Gold.Disable(); } catch { }
            inst.Bridge.Dispose();
            inst.Mem.Dispose();
        }
        _lockTimer?.Stop();
        _lockTimer?.Dispose();
        base.OnFormClosing(e);
    }

    private static GraphicsPath GetRoundedRectPath(Rectangle bounds, int radius)
    {
        int d = radius * 2;
        var path = new GraphicsPath();
        if (d <= 0)
        {
            path.AddRectangle(bounds);
            return path;
        }
        path.AddArc(bounds.X, bounds.Y, d, d, 180, 90);
        path.AddArc(bounds.Right - d, bounds.Y, d, d, 270, 90);
        path.AddArc(bounds.Right - d, bounds.Bottom - d, d, d, 0, 90);
        path.AddArc(bounds.X, bounds.Bottom - d, d, d, 90, 90);
        path.CloseFigure();
        return path;
    }
}
