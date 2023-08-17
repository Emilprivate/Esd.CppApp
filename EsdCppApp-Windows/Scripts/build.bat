@echo off

:: Get the location of this script
SET SCRIPT_DIR=%~dp0

:: Navigate to the project root (assumes the script is in a directory under the project root)
cd %SCRIPT_DIR%..

:: Create a new 'build' directory, or navigate to it if it already exists
IF NOT EXIST build ( mkdir build )
cd build

:: Generate Visual Studio solution files
cmake -G "Visual Studio 17 2022" ..

echo To build the project, open the generated Visual Studio solution in the 'build' directory.
pause
