# OpenGL 3.3 Core Project Template

A lightweight, minimal starter template for modern OpenGL (3.3 Core Profile) using **GLFW** and **GLAD**. This setup is completely independent and compiles directly from the command line using **GCC/g++**—no CMake or Visual Studio required. Perfect for following along with tutorials like [LearnOpenGL.com](https://learnopengl.com).

## 📁 Project Structure

```text
my_opengl_project/
├── build.bat         # Automated build & run script
├── README.md         # Project documentation
├── .gitignore        # Keeps build binaries out of version control
├── include/          # Header dependencies
│   ├── glad/         # GLAD OpenGL loader headers
│   ├── KHR/          # Khronos cross-platform type mapping
│   └── GLFW/         # GLFW window configuration headers
├── lib/              # Pre-compiled static libraries
│   └── libglfw3.a    # GLFW static binary (MinGW-w64 format)
└── src/              # Engine source code
    ├── glad.c        # GLAD source mapping
    └── main.cpp      # Application entry point & render loop
```

## 🛠️ Prerequisites

Before compiling, ensure you have the following toolchain installed on your Windows machine:
*   **MinGW-w64 (GCC/g++)**: Ensure `g++` is installed and added to your system's environment `PATH` variable.
*   **Updated GPU Drivers**: Ensure your integrated graphics drivers (e.g., Intel UHD 620) are up to date to support native OpenGL 3.3 Core pipelines.

## 🚀 How to Build and Run

You do not need an IDE or complex build software. To compile and launch the template in one click:

1. Open your standard terminal or **Command Prompt** (`cmd`).
2. Navigate to the project root directory:
   ```bash
   cd path/to/this/project
   ```
3. Execute the automated batch file:
   ```bash
   build.bat
   ```

The script will automatically wipe any old executables, compile `main.cpp` and `glad.c`, link your native system graphics drivers (`opengl32`, `gdi32`, `user32`), and immediately launch a dark-teal test window to confirm everything works flawlessly.

## ⚠️ Notes for Development

*   **Shader & Asset Loading**: When loading external `.glsl` or image files later, keep your file paths relative to the project root directory where `build.bat` is executed (e.g., use `"shaders/vertex.glsl"` instead of `"vertex.glsl"`).
*   **Version Control**: The included `.gitignore` file automatically blocks tracking for generated `.exe`, `.obj`, and `.o` binary assets, keeping your Git history completely clean.
