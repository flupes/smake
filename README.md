# Setup a simple C++ development environment under Windows-10 + WSL

## Install WSL + Ubuntu 18.04

Follow:
https://docs.microsoft.com/en-us/windows/wsl/install-win10
And install Ubuntu 18.04

For better integration, take part of the Windows Insider Program and install WSL-2:
https://docs.microsoft.com/en-us/windows/wsl/wsl2-install


## Install the compilation tools in WSL

```
sudo apt update
sudo apt install build-essential make clang git
```

## Install Visual Studio Code

Get the Windows 64bit version from:
https://code.visualstudio.com/download

Install the extension for WSL:
https://code.visualstudio.com/docs/cpp/config-wsl

Install also the following extensions:
  - clang-formatter for WSL
  - Microsoft C/C++ IntelliSense extension

The `.vscode/tasks.json` defines two build tasks:
  1. The default build all (shift+ctrl+b)
  2. A clean task

However, from the terminal, you can also access the other targets:
```
make help
```

## Using this Makefile

  - Customize the makefile following the instructions in its header
  - type `make` and smile


