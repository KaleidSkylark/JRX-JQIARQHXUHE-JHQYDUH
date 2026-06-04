@echo off
REM Build TBHHook.dll (x64) and copy it next to the trainer exe.
setlocal

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if not exist "%VSWHERE%" (
    echo ERROR: vswhere.exe not found
    exit /b 1
)

for /f "usebackq delims=" %%i in (`
    "%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -find VC\Auxiliary\Build\vcvars64.bat
`) do (
    set "VCVARS=%%i"
)

if not defined VCVARS (
    echo ERROR: vcvars64.bat not found
    exit /b 1
)

call "%VCVARS%"

cd /d "%~dp0"

dotnet publish -c Release -r win-x64 --self-contained true -p:PublishSingleFile=true -p:IncludeNativeLibrariesForSelfExtract=true -p:EnableCompressionInSingleFile=true -p:DebugType=embedded -o ..\publish
if errorlevel 1 (
    echo BUILD FAILED
    exit /b 1
)

if not exist "..\TrainerBuild" mkdir "..\TrainerBuild"
copy /Y "..\publish\TBH Trainer.exe" "..\TrainerBuild\TBH Trainer.exe" >nul

echo BUILD OK - TBHHook.dll copied to TrainerBuild
endlocal
