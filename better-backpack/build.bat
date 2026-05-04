@echo off
setlocal enableextensions

rem Better Backpack mod build (DLL + injector).
rem Requires:
rem   - Visual Studio 2022 Community at the default install path (cl.exe v14.x)
rem   - The Dumper-7 SDK extracted at C:\Tools\work\sdk\
rem
rem Output: dist\BetterBackpack.dll  +  dist\inject.exe
rem
rem Cold build is ~30s. Re-run any time you change dllmain.cpp / basic_impl.cpp
rem / inject.c. Incremental rebuilds are a couple of seconds.

set VCVARS="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
set SDK_ROOT=C:\Tools\work\sdk
set SDK_DIR=%SDK_ROOT%\SDK
set OUTDIR=dist
set OBJDIR=build

if not exist %VCVARS% (
    echo ERROR: vcvars64.bat not found at %VCVARS%
    echo Install Visual Studio 2022 Community ^(C++ workload^) or edit this path.
    exit /b 1
)

if not exist "%SDK_DIR%\Basic.hpp" (
    echo ERROR: Dumper-7 SDK not found at %SDK_DIR%
    echo Expected Basic.hpp, Maine_classes.hpp, Engine_classes.hpp, etc.
    exit /b 2
)

call %VCVARS% >nul
if errorlevel 1 (
    echo ERROR: vcvars64.bat failed
    exit /b 3
)

if not exist %OUTDIR% mkdir %OUTDIR%
if not exist %OBJDIR% mkdir %OBJDIR%

echo Building Better Backpack DLL...
echo SDK: %SDK_DIR%
echo Output: %OUTDIR%\BetterBackpack.dll
echo.

cl.exe /nologo /LD /EHsc /MD /O2 /std:c++latest /W3 ^
    /D"TARGET_PLATFORM=1" /D"NDEBUG" /D"_WINDLL" /D"WIN32_LEAN_AND_MEAN" /D"NOMINMAX" ^
    /I "%SDK_ROOT%" ^
    /I "%SDK_DIR%" ^
    /Fo%OBJDIR%\ /Fd%OBJDIR%\ ^
    dllmain.cpp ^
    basic_impl.cpp ^
    "%SDK_DIR%\CoreUObject_functions.cpp" ^
    /link /OUT:%OUTDIR%\BetterBackpack.dll user32.lib kernel32.lib

if errorlevel 1 goto :dll_failed

echo.
echo Building injector...
cl.exe /nologo /MD /O2 /W3 ^
    /D"NDEBUG" /D"WIN32_LEAN_AND_MEAN" ^
    /Fo%OBJDIR%\ /Fd%OBJDIR%\ ^
    inject.c ^
    /link /OUT:%OUTDIR%\inject.exe user32.lib kernel32.lib advapi32.lib

if errorlevel 1 goto :inject_failed

echo.
echo Built:
dir /b %OUTDIR%\BetterBackpack.dll %OUTDIR%\inject.exe
exit /b 0

:dll_failed
echo.
echo BUILD FAILED -- DLL did not build
exit /b 10

:inject_failed
echo.
echo BUILD FAILED -- injector did not build
exit /b 11
