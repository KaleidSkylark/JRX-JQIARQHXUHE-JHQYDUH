using System.Drawing.Drawing2D;

#pragma warning disable CA1416

namespace TBH_Trainer;

/// <summary>
/// Modern flat button designed for dark theme with hover/press effects and rounded corners.
/// Owner-draws all states for consistent premium appearance.
/// </summary>
internal sealed class ThemedButton : Button
{
    private static readonly Color DisabledFore = Color.FromArgb(100, 105, 120);
    private static readonly Color DisabledBack = Color.FromArgb(18, 18, 28);
    private static readonly Color DisabledBorder = Color.FromArgb(30, 30, 45);

    [System.ComponentModel.DesignerSerializationVisibility(System.ComponentModel.DesignerSerializationVisibility.Hidden)]
    public int CornerRadius { get; set; } = 5;

    protected override void OnPaint(PaintEventArgs e)
    {
        var g = e.Graphics;
        g.SmoothingMode = SmoothingMode.AntiAlias;

        var rect = new Rectangle(0, 0, Width - 1, Height - 1);
        
        using (var path = GetRoundedRectPath(rect, CornerRadius))
        {
            if (Enabled)
            {
                // Determine button state
                bool mouseDown = (MouseButtons == MouseButtons.Left && ClientRectangle.Contains(PointToClient(MousePosition)));
                bool mouseOver = ClientRectangle.Contains(PointToClient(MousePosition));

                // Background color based on state
                Color bgColor;
                if (mouseDown)
                    bgColor = Color.FromArgb(12, 12, 18); // Darker Pressed
                else if (mouseOver)
                    bgColor = Color.FromArgb(28, 30, 42); // Brighter Hover
                else
                    bgColor = Color.FromArgb(18, 19, 26); // Normal Slate Card

                using (var brush = new SolidBrush(bgColor))
                {
                    g.FillPath(brush, path);
                }

                // Draw gorgeous glow border
                Color borderColor = FlatAppearance.BorderColor;
                if (borderColor == Color.Empty || borderColor == Color.Transparent)
                {
                    borderColor = Color.FromArgb(0, 180, 255);
                }

                if (mouseOver)
                {
                    // Draw a brighter/glowing border when hovered
                    using (var pen = new Pen(borderColor, 1.5f))
                    {
                        g.DrawPath(pen, path);
                    }
                }
                else
                {
                    using (var pen = new Pen(Color.FromArgb(60, borderColor), 1f))
                    {
                        g.DrawPath(pen, path);
                    }
                }
            }
            else
            {
                // Disabled state
                using (var brush = new SolidBrush(DisabledBack))
                {
                    g.FillPath(brush, path);
                }
                using (var pen = new Pen(DisabledBorder, 1f))
                {
                    g.DrawPath(pen, path);
                }
            }
        }

        // Text rendering
        TextRenderer.DrawText(
            g, Text, Font, ClientRectangle,
            Enabled ? Color.FromArgb(230, 230, 250) : DisabledFore,
            TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter |
            TextFormatFlags.EndEllipsis);
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
