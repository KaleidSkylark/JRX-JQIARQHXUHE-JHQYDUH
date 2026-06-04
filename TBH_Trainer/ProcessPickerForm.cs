using System.ComponentModel;
using System.Drawing.Drawing2D;

#pragma warning disable CA1416

namespace TBH_Trainer;

internal sealed class ProcessPickerForm : Form
{
    public int SelectedPid { get; private set; } = -1;

    private readonly ListView _list;
    private readonly TextBox _filter;
    private List<GameMemory.ProcessEntry> _all = new();
    private readonly Dictionary<int, string> _connectedPids;

    // Shared theme palette
    private static readonly Color BgForm     = Color.FromArgb(12, 12, 18);
    private static readonly Color BgInput    = Color.FromArgb(20, 20, 30);
    private static readonly Color BtnBg      = Color.FromArgb(18, 18, 28);
    private static readonly Color AccentCyan = Color.FromArgb(0, 220, 255);
    private static readonly Color AccentDim  = Color.FromArgb(20, 40, 60);
    private static readonly Color TextMain   = Color.FromArgb(230, 230, 250);
    private static readonly Color TextDim    = Color.FromArgb(160, 165, 180);

    public ProcessPickerForm(Dictionary<int, string> connectedPids)
    {
        _connectedPids = connectedPids ?? new Dictionary<int, string>();
        Text = "Select Game Process";
        ClientSize = new Size(540, 480);
        StartPosition = FormStartPosition.CenterParent;
        FormBorderStyle = FormBorderStyle.FixedDialog;
        MaximizeBox = false;
        MinimizeBox = false;
        BackColor = BgForm;
        ForeColor = TextMain;
        Font = new Font("Segoe UI", 9.5f);

        Controls.Add(new Label
        {
            Text = "Choose the game process (processes running GameAssembly.dll appear at the top):",
            Location = new Point(12, 10), Size = new Size(516, 20), ForeColor = TextDim
        });

        _filter = new TextBox
        {
            Location = new Point(12, 34), Width = 400,
            BackColor = BgInput, ForeColor = TextMain,
            BorderStyle = BorderStyle.FixedSingle
        };
        _filter.TextChanged += (_, _) => ApplyFilter();
        
        var btnRefresh = MakeBtn("Refresh", 420, 32, 108, 24);
        btnRefresh.Click += (_, _) => Reload();
        Controls.Add(_filter);
        Controls.Add(btnRefresh);

        _list = new ListView
        {
            Location = new Point(12, 66), Size = new Size(516, 350),
            View = View.Details, FullRowSelect = true, MultiSelect = false,
            BackColor = Color.FromArgb(18, 19, 26), ForeColor = TextMain,
            Font = new Font("Consolas", 9), BorderStyle = BorderStyle.FixedSingle, HideSelection = false
        };
        
        // Double buffering list to remove any lag or flickering
        var doubleBufferProp = typeof(Control).GetProperty("DoubleBuffered", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
        doubleBufferProp?.SetValue(_list, true, null);

        _list.Columns.Add("PID", 70);
        _list.Columns.Add("Process", 170);
        _list.Columns.Add("GameAssembly", 100);
        _list.Columns.Add("Window", 150);
        _list.DoubleClick += (_, _) => Accept();
        Controls.Add(_list);

        var btnOk = MakeBtn("Select Game", 314, 432, 108, 32);
        btnOk.FlatAppearance.BorderColor = Color.FromArgb(0, 255, 130); // Success Green outline
        btnOk.DialogResult = DialogResult.None;
        btnOk.Click += (_, _) => Accept();
        
        var btnCancel = MakeBtn("Cancel", 432, 432, 96, 32);
        btnCancel.DialogResult = DialogResult.Cancel;
        
        Controls.Add(btnOk);
        Controls.Add(btnCancel);
        AcceptButton = btnOk;
        CancelButton = btnCancel;

        Reload();
    }

    private static Button MakeBtn(string text, int x, int y, int w, int h)
    {
        var b = new ThemedButton
        {
            Text = text, Location = new Point(x, y), Size = new Size(w, h),
            FlatStyle = FlatStyle.Flat, CornerRadius = 4
        };
        b.FlatAppearance.BorderSize = 0;
        return b;
    }

    private async void Reload()
    {
        _list.Items.Clear();
        _list.Items.Add(new ListViewItem("Scanning active processes...") { ForeColor = TextDim });
        _filter.Enabled = false;

        // Perform the scan asynchronously so it doesn't freeze the window thread
        var results = await Task.Run(() => GameMemory.ListProcesses());

        _all = results;
        _filter.Enabled = true;
        ApplyFilter();
    }

    private void ApplyFilter()
    {
        string f = _filter.Text.Trim();
        _list.BeginUpdate();
        _list.Items.Clear();
        foreach (var e in _all)
        {
            if (f.Length > 0 &&
                !e.Name.Contains(f, StringComparison.OrdinalIgnoreCase) &&
                !e.Title.Contains(f, StringComparison.OrdinalIgnoreCase) &&
                !e.Pid.ToString().Contains(f))
                continue;

            // Check if process has TBHHook.dll injected
            bool alreadyInjected = false;
            try
            {
                foreach (System.Diagnostics.ProcessModule m in System.Diagnostics.Process.GetProcessById(e.Pid).Modules)
                {
                    if (m.ModuleName.Equals("TBHHook.dll", StringComparison.OrdinalIgnoreCase))
                    {
                        alreadyInjected = true;
                        break;
                    }
                }
            }
            catch { }

            // Check if process is connected in this trainer instance
            bool inCurrentTrainer = _connectedPids.TryGetValue(e.Pid, out string? tabName);

            string displayName = e.Name;
            if (inCurrentTrainer)
            {
                displayName += $" [{tabName} Connected]";
            }
            else if (alreadyInjected)
            {
                displayName += " [INJECTED]";
            }

            var item = new ListViewItem(e.Pid.ToString()) { Tag = e.Pid };
            item.SubItems.Add(displayName);
            item.SubItems.Add(e.HasGameAssembly ? "YES" : "");
            item.SubItems.Add(e.Title);
            
            if (inCurrentTrainer)
            {
                item.ForeColor = AccentCyan; // Colored in AccentCyan (0, 220, 255) for active in this trainer
            }
            else if (alreadyInjected)
            {
                item.ForeColor = Color.FromArgb(255, 150, 50); // Highlight in Orange/Red if injected elsewhere
            }
            else if (e.HasGameAssembly) 
            {
                item.ForeColor = Color.FromArgb(0, 255, 130); // Success green for targeted process
            }
            else
            {
                item.ForeColor = TextMain;
            }
                
            _list.Items.Add(item);
        }
        _list.EndUpdate();
    }

    private void Accept()
    {
        if (_list.SelectedItems.Count == 0 || _list.SelectedItems[0].Tag == null) return;
        SelectedPid = (int)_list.SelectedItems[0].Tag!;
        DialogResult = DialogResult.OK;
        Close();
    }
}
