# Cài đặt môi trường

## Windows — dùng WSL (khuyến nghị)
```bash
wsl --install
```
Trong Ubuntu:
```bash
sudo apt update
sudo apt install -y build-essential git gdb
```

## macOS
```bash
xcode-select --install
brew install gcc make git
```

## Kiểm tra
```bash
gcc --version
make --version
git --version
```

## VS Code
Cài extension: **C/C++**, **Makefile Tools**, **GitLens**.
