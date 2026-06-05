# 🛡️ TBH: TaskBarHero Trainer

A unknowncheats community trainer for **TaskBarHero** with full Multi-Instance Support.

---

## 📂 Project Structure

This repository is optimized to include only the essential binaries required to run and hook the trainer:

* 📂 **DontTouchIT/**
    * ⚙️ `TBH Trainer.exe` — The main standalone trainer application (v1.3.5).
    * 🔗 `TBHHook.dll` — Helper dynamic-link library for system speedhack and process hooking.

---

## 🆕 Version 1.3.5 Change Log

This version includes manual backup management and robust DLL recovery:

### ⚙️ Static DLL Patches & Backup Management
* **Create Backup Button**: Added a new **Create Backup** button in the static DLL patcher tab, allowing users to manually copy the active `GameAssembly.dll` to `GameAssembly.dll.unknowncheats.bak` (overwriting any previous backup if desired).
* **Robust Restore Backup**: Clicking the **Restore Backup** button now deletes the active `GameAssembly.dll` and renames/moves the backup file (`GameAssembly.dll.unknowncheats.bak`) back to its original name.
---

## 🆕 Version 1.3.4 Change Log

This version replaces the dynamic preset with a robust static DLL patch for the Cube:

### 🎒 Stash Spawner Removal
* **Removed Stash Spawner**: Completely removed the non-functional stash spawner UI controls, scanning, item database spawning, and export catalog handlers from the interface and code. The main panel is now much cleaner and less cramped.

### ⚙️ Static DLL Patches
* **Cube XP (Synthesis)**: Added a new static patch under the "Static DLL Patches" tab: `Cube XP (Synthesis)`. When applied to `GameAssembly.dll` (with the game closed), performing a synthesis returns **100,000,000,000 EXP** for the Cube, leveling it up instantly.

---

## 🆕 Version 1.3.1 & 1.3.2 Change Log

This version includes key improvements, new features, and settings separation fixes:

### 🛡️ Setting Isolation & Stats Isolation
* **Multi-Instance Sandboxing**: Multi-instance preset hooks (like One-Hit Kill, Invincible, and speed presets) are fully isolated per game instance. Settings will no longer bleed, interconnect, or affect other running game processes.
* **Momentary Preset Backups**: Presets capture and save your original stats only when the preset is toggled. When unchecked, stats revert cleanly to their captured baseline. If toggled outside a run, they default safely back to standard game parameters (10 ATK, 100 HP, 1.0 ATK Speed, 5.0 Move Speed) instead of leaving them locked to cheat values.

### 🧪 UI Polish & manual Stats Input
* **Blank Textboxes**: Hero stats textboxes (HP, ATK, ATK Speed, Move Speed) are blank by default and do not continuously read memory or overwrite your inputs.
* **Removed "Reset All Stats"**: The redundant "Reset All Stats" button and its click handlers have been removed to prevent state conflicts and provide a cleaner, more focused UI.

---

## 🚀 Getting Started

1. Download the repository/release. The `DontTouchIT` folder already automatically contains the current version of the trainer (`TBH Trainer.exe`) and the hook library (`TBHHook.dll`).
2. Run `TBH Trainer.exe` from inside the `DontTouchIT` folder as **Administrator**.
3. Select your process instance (active processes running `GameAssembly.dll` will automatically float to the top of the picker).
4. Play responsibly!

---
<p align="center">Made with 💻AI and a prayer.</p>