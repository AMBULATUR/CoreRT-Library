NativeLibrary - Standard 2.0
DLLCuser - CLang
DLLUser - c++

Compiled by CoreRT IL compiler(AOT).

x64 Native Tools Command Prompt for VS 2019 commands:
dotnet publish /p:NativeLib=Static -r win-x64 -c release - Статическая либа .lib win-x64 ONLY
dotnet publish /p:NativeLib=Shared -r win-x64 -c release - Динамическая либа .dll win-x64 ONLY

В случае проблем с LoadLibrary - Проверить путь к DLL:
- '\\' Only
- Set Character set = MultiByte
- Compile only under x64 machine
