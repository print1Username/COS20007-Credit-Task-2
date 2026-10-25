# COS20007 Credit Task 2

[English](README.md) | [简体中文](README.zh-CN.md)

## Overview

This repository contains a C++ console-based tournament management system for COS20007. It demonstrates object-oriented programming through six main classes: `User`, `Member`, `Leader`, `Organizer`, `Team`, and `Tournament`.

The program supports:

- user login and member registration;
- profile viewing and updating;
- tournament creation, updating, listing, and searching;
- team creation and member management;
- tournament join requests and organizer approval;
- separate menus for members, leaders, and the organizer.

The application stores data in memory, so data created during a run is not saved after the program exits.

## Project Structure

```text
.
├── include/                         # C++ header files
├── src/                             # Application source files and main.cpp
├── tests/                           # CppUnit test source and header files
├── nbproject/                       # NetBeans/Make build configuration
├── COS20007CreditTask2.sln          # Visual Studio solution
├── COS20007CreditTask2.vcxproj      # Visual Studio C++ project
└── Makefile                         # Make entry point
```

## Requirements

Choose one of the following development environments:

- Visual Studio 2022 with the **Desktop development with C++** workload;
- Visual Studio Code with the **C/C++** extension and a working `g++` compiler, such as MinGW-w64;
- CLion with a configured MinGW or GCC toolchain.

Git is required only for cloning and version control.

## Git Setup

1. Install [Git](https://git-scm.com/downloads).
2. Configure your identity once:

   ```bash
   git config --global user.name "Your Name"
   git config --global user.email "your-email@example.com"
   ```

3. Clone and enter the repository:

   ```bash
   git clone https://github.com/print1Username/COS20007-Credit-Task-2.git
   cd COS20007-Credit-Task-2
   ```

4. Check the repository state before working:

   ```bash
   git status
   ```

Generated executables, build folders, IDE caches, PDF files, and text files are excluded by the repository's `.gitignore`.

## Run with Visual Studio 2022

1. Install Visual Studio 2022 and select the **Desktop development with C++** workload in Visual Studio Installer.
2. Open `COS20007CreditTask2.sln`.
3. If Visual Studio reports that platform toolset `v145` is unavailable, accept **Retarget solution** and select the installed Visual Studio 2022 toolset (`v143`).
4. In Solution Explorer, right-click `COS20007CreditTask2` and select **Set as Startup Project** if necessary.
5. Select `Debug` and either `x64` or `x86` from the toolbar.
6. Press `Ctrl+F5` to build and run without debugging, or `F5` to run with debugging.

## Run with Visual Studio Code

1. Install Visual Studio Code, the Microsoft **C/C++** extension, and MinGW-w64.
2. Make sure `g++` is available in a new terminal:

   ```bash
   g++ --version
   ```

3. Open the repository folder in Visual Studio Code.
4. Open the integrated terminal at the repository root and run:

   ```powershell
   New-Item -ItemType Directory -Force build | Out-Null
   g++ -std=c++11 -Iinclude src/main.cpp src/User.cpp src/Member.cpp src/Leader.cpp src/Organizer.cpp src/Team.cpp src/Tournament.cpp -o build/credittask2.exe
   .\build\credittask2.exe
   ```

The repository does not include personal `.vscode` task files. The terminal commands above work without creating IDE-specific configuration.

## Run with CLion

1. Install CLion and configure a MinGW or GCC toolchain under **Settings | Build, Execution, Deployment | Toolchains**.
2. Make sure both `make` and `g++` are available in the selected toolchain.
3. Open the repository root as a project. When prompted, load it as a Makefile project.
4. Build the `build` target with the `Debug` configuration. The equivalent terminal command is:

   ```bash
   make CONF=Debug
   ```

5. Run the generated executable:

   ```text
   dist/Debug/MinGW-Windows/credittask2.exe
   ```

If CLion does not automatically create a run configuration, add an **Application** configuration and select that executable.

## Default Accounts

The program creates these accounts every time it starts:

| Role | Username | Email | Password |
|---|---|---|---|
| Organizer | `organizer` | `organizer@gmail.com` | `password` |
| Leader | `leader` | `leader@gmail.com` | `password` |
| Member | `member` | `member@gmail.com` | `password` |

Newly registered users are created as members.
