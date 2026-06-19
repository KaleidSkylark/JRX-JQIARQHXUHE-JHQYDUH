# 🛡️ TBH: TaskBarHero Barforge Trainer 
[NO LONGER CONTINUE TO UPDATE, CHECK UNKNOWNCHEATS SOURCE IS THERE. THE DEVS ARE SHIT NO MARKET NOT PLAYING SINCE LAST WEEK AHAHAHA]

A Barforge trainer for **TaskBarHero** with full Multi-Instance Support.

---

## 📂 Project Structure

This repository is optimized to include only the essential binaries required to run and hook the trainer:

* 📂 **DontTouchIT/**
    * ⚙️ `TBHBarforge.exe` — The main standalone trainer application (v1.4.0).
    * 🔗 `TBHBarforge.dll` — Helper dynamic-link library for system speedhack and process hooking.

---
## 🆕 Cheat Table V1.00.11 by jonxpin (jonxpin added new features UPDATED)
---
## 🆕 Version 1.4.0 Change Log (Denoiser V4 Integration) OUTDATED

This version integrates the upgrades from Denoiser V4, fully supporting game version 1.00.08 and 1.00.09 hotfix, while maintaining premium dark styling and multi-instance isolated IPC channels:

### ⚙️ Native IL2CPP Stash Item Spawner
* **Scan Stash**: Reads the contents of all 49 stash slots and inventory items, automatically parsing obfuscated item class structures and extracting keys + rarity grades.
* **Export Catalog**: Exports the entire game item catalog from `yq` data manager directly to a text file for easy item ID browsing.
* **Gear Spawn**: Spawns arbitrary item keys at chosen rarity grades (Common up to Cosmic) directly into empty stash slots using fast-path native IL2CPP call bridges.

### 📊 Hero Diagnostics & Stats Lock
* **Diagnostics Report**: Scans and reads active party heroes, listing decrypted Attack Damage, Attack Speed, Max HP, and current health controller parameters.
* **Persistent Locks**: Pushes HP and Attack Speed locks down to the C++ hook level, which checks and reapplies locked stats periodically on the injected thread.

### 🛡️ Multi-Instance MMF Isolation
* **Collision Prevention**: Dynamically appends process ID (`pid`) to all Memory Mapped File IPC names (`TBHTrainerShared_<PID>`, `TBHTrainerScan_<PID>`, and `TBHTrainerHeroes_<PID>`). Allows up to 5 game instances running in parallel with completely independent speed, spawn, scan, and stats-locking profiles.

### ⚙️ Static DLL Patches & Backup Management
* **Cube XP (Synthesis)**: Replaced V4's 1B XP patch with our custom 22-byte 100B XP patch (`Offset = 0x948FB0` in 1.00.09) in the static build profile.
* **Manual Backup Manager**: Maintained the custom `.denoiser.bak` file name and manual backup/restore rename-back mechanism.

---

## 🚀 Getting Started

1. Download the repository/release. The `DontTouchIT` folder contains the current version of the trainer (`TBHBarforge.exe`) and the hook library (`TBHBarforge.dll`).
2. Run `TBHBarforge.exe` as **Administrator**.
3. Select your process instance (active processes running `GameAssembly.dll` will automatically float to the top of the picker).
4. Play responsibly!

---
<p align="center">Made with 💻AI and a prayer.</p>
