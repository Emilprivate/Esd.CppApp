@echo off

REM Navigate to the EsdCppApp directory, where CMakeLists.txt is located
cd EsdCppApp-Src

REM Create a new directory for the build artifacts
if not exist "build" (
    mkdir build
)

REM Navigate to the build directory
cd build

REM Run CMake to configure the project
cmake -DSDL2_DIR=C:\SDL2\cmake ..

REM Run MSBuild to build the project
MSBuild EsdCppApp.vcxproj

REM Return to the original directory
cd ..\..

REM Print a success message
echo Build completed
