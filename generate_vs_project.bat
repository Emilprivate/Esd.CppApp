@echo off

REM Create a new directory for the build artifacts
if not exist "build" (
    mkdir build
)

REM Navigate to the build directory
cd build

REM Set the path to the SDL2 cmake config files
set SDL2_DIR=C:\SDL2\cmake\

REM Run CMake to configure the project
cmake -G "Visual Studio 17 2022" -A x64 .. --debug-output

REM Print a success message
echo Build configuration completed
