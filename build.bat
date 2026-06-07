
@echo off
cls
echo ===================================================
echo             Building OpenGL Application            
echo ===================================================

:: 1. Define Compiler and Flags
set CXX=g++
set CXXFLAGS=-Wall -std=c++17 -Iinclude

:: 2. Define Directories and Target
set LIB_DIR=-Llib
set LIBS=-lglfw3 -lopengl32 -lgdi32 -luser32
set OUTPUT=main.exe

:: 3. Clear out old build artifacts safely
if exist %OUTPUT% del /q %OUTPUT%

echo Compiling source files...
:: 4. Run the compilation command string
%CXX% %CXXFLAGS% src/main.cpp src/glad.c -o %OUTPUT% %LIB_DIR% %LIBS%

:: 5. Check if compilation succeeded or failed
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Build failed! Check compiler output above.
    echo ===================================================
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo [SUCCESS] Build completed: %OUTPUT%
echo ===================================================
echo Running application...
echo.

:: 6. Auto-execute the window app immediately after building
%OUTPUT%
