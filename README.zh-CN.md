# COS20007 Credit Task 2

[English](README.md) | [简体中文](README.zh-CN.md)

## 程序简介

本仓库是为 COS20007 开发的 C++ 控制台锦标赛管理系统。项目通过 `User`、`Member`、`Leader`、`Organizer`、`Team` 和 `Tournament` 六个主要类演示面向对象程序设计。

程序支持以下功能：

- 用户登录和普通成员注册；
- 查看及更新个人资料；
- 创建、更新、查看和搜索锦标赛；
- 创建队伍和管理队员；
- 申请加入锦标赛并由组织者审批；
- 为普通成员、队长和组织者提供不同的操作菜单。

程序只在内存中保存数据，因此程序关闭后，本次运行期间创建的数据不会被保留。

## 项目结构

```text
.
├── include/                         # C++ 头文件
├── src/                             # 应用程序源文件及 main.cpp
├── tests/                           # CppUnit 测试源文件和头文件
├── nbproject/                       # NetBeans/Make 构建配置
├── COS20007CreditTask2.sln          # Visual Studio 解决方案
├── COS20007CreditTask2.vcxproj      # Visual Studio C++ 项目
└── Makefile                         # Make 构建入口
```

## 环境要求

选择以下任意一种开发环境：

- Visual Studio 2022，并安装 **Desktop development with C++（使用 C++ 的桌面开发）** 工作负载；
- Visual Studio Code，并安装 **C/C++** 扩展及可用的 `g++` 编译器，例如 MinGW-w64；
- CLion，并配置 MinGW 或 GCC 工具链。

Git 只用于克隆项目和版本控制。

## 配置 Git 环境

1. 安装 [Git](https://git-scm.com/downloads)。
2. 首次使用时配置个人信息：

   ```bash
   git config --global user.name "Your Name"
   git config --global user.email "your-email@example.com"
   ```

3. 克隆仓库并进入项目目录：

   ```bash
   git clone https://github.com/print1Username/COS20007-Credit-Task-2.git
   cd COS20007-Credit-Task-2
   ```

4. 开始工作前检查仓库状态：

   ```bash
   git status
   ```

仓库中的 `.gitignore` 已排除生成的可执行文件、构建目录、IDE 缓存、PDF 文件和文本文件。

## 使用 Visual Studio 2022 运行

1. 安装 Visual Studio 2022，并在 Visual Studio Installer 中选择 **Desktop development with C++（使用 C++ 的桌面开发）**。
2. 打开 `COS20007CreditTask2.sln`。
3. 如果 Visual Studio 提示平台工具集 `v145` 不可用，请接受 **Retarget solution（重定向解决方案）**，并选择 Visual Studio 2022 已安装的工具集 `v143`。
4. 如有需要，在解决方案资源管理器中右键单击 `COS20007CreditTask2`，选择 **Set as Startup Project（设为启动项目）**。
5. 在工具栏选择 `Debug`，并选择 `x64` 或 `x86`。
6. 按 `Ctrl+F5` 构建并运行，或按 `F5` 以调试方式运行。

## 使用 Visual Studio Code 运行

1. 安装 Visual Studio Code、Microsoft **C/C++** 扩展和 MinGW-w64。
2. 在新终端中确认 `g++` 可以使用：

   ```bash
   g++ --version
   ```

3. 使用 Visual Studio Code 打开本仓库文件夹。
4. 在仓库根目录打开集成终端并运行：

   ```powershell
   New-Item -ItemType Directory -Force build | Out-Null
   g++ -std=c++11 -Iinclude src/main.cpp src/User.cpp src/Member.cpp src/Leader.cpp src/Organizer.cpp src/Team.cpp src/Tournament.cpp -o build/credittask2.exe
   .\build\credittask2.exe
   ```

仓库没有提交个人使用的 `.vscode` 任务配置。以上终端命令不需要创建 IDE 专用配置即可运行。

## 使用 CLion 运行

1. 安装 CLion，然后在 **Settings | Build, Execution, Deployment | Toolchains** 中配置 MinGW 或 GCC 工具链。
2. 确认所选工具链可以使用 `make` 和 `g++`。
3. 在 CLion 中打开仓库根目录，并在出现提示时将其作为 Makefile 项目加载。
4. 使用 `Debug` 配置构建 `build` 目标。对应的终端命令为：

   ```bash
   make CONF=Debug
   ```

5. 运行生成的程序：

   ```text
   dist/Debug/MinGW-Windows/credittask2.exe
   ```

如果 CLion 没有自动创建运行配置，请添加一个 **Application** 配置，并选择上述可执行文件。

## 默认账户

程序每次启动时都会创建以下账户：

| 身份 | 用户名 | 邮箱 | 密码 |
|---|---|---|---|
| 组织者 | `organizer` | `organizer@gmail.com` | `password` |
| 队长 | `leader` | `leader@gmail.com` | `password` |
| 普通成员 | `member` | `member@gmail.com` | `password` |

通过注册功能创建的新用户身份为普通成员。
