@echo off
cd /d "%~dp0"

echo Building Hook DLL...
pushd TBHHook
call build.bat
popd
if errorlevel 1 (
    echo HOOK BUILD FAILED
    exit /b 1
)

echo Building C# WinForms Trainer...
dotnet publish TBH_Trainer -c Release -r win-x64 --self-contained true -p:PublishSingleFile=true -p:IncludeNativeLibrariesForSelfExtract=true -p:EnableCompressionInSingleFile=true -p:DebugType=embedded -o publish
if errorlevel 1 (
    echo C# TRAINER BUILD FAILED
    exit /b 1
)

if not exist "TrainerBuild" mkdir "TrainerBuild"
copy /Y "publish\TBH Trainer.exe" "TrainerBuild\TBH Trainer.exe" >nul

echo ALL BUILD OK
pause