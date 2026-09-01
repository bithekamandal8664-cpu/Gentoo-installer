# Gentoo Installer

A custom Gentoo Linux installer written entirely in C.

This project is basically **Gentoo's own TV remote, but it's C.** 😭

## What it does

The installer is split into several C programs:

- `linker.c` — clones/builds the installer components
- `Stage.c` — prepares partitions, filesystems, mounts, and installs the Gentoo Stage 3
- `Chroot.c` — prepares and enters the Gentoo chroot
- `Setup.c` — configures the system, kernel, GRUB, firmware, users, and packages
- `eselect.c` — handles `eselect` configuration
- `DE_WM.c` — lets you choose a desktop environment or window manager

## Desktop environments

Currently supported:

1. KDE Plasma
2. GNOME
3. XFCE
4. LXQt

## Window managers

Currently supported:

1. Hyprland
2. Sway
3. Niri
4. Awesome

## Requirements

You need:

- A Gentoo installation environment / LiveGUI
- Root privileges
- Internet connection
- `git`
- `wget`
- `tar`
- Gentoo's `emerge`
- A working x86_64 system

## Usage

Clone the repository:

```bash
wget https://raw.githubusercontent.com/bithekamandal8664-cpu/Gentoo-installer/refs/heads/main/linker.c 
gcc linker.c -o linker
./linker
```

## RULE OF THE THUMB
follow the instructions and be careful of what you choose! enjoy you installation! UwU

