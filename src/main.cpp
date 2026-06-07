#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Callback function to resize the viewport when the user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // 1. Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 2. Request an OpenGL 3.3 Core Profile Context from your Intel Driver
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 3. Create the window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "Intel UHD 620 - OpenGL Test", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 4. Initialize GLAD to load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 5. Print out system details to confirm your hardware is working
    std::cout << "GPU Vendor:   " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer:     " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "GL Version:   " << glGetString(GL_VERSION) << std::endl;

    // 6. Main Application Render Loop
    while (!glfwWindowShouldClose(window)) {
        // Process simple Escape key exit input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // Render commands go here: Clear the screen to a custom color (R, G, B, A)
        glClearColor(0.1f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap back-and-front color buffers and poll user input/window events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 7. Clean up all resources properly before exiting
    glfwTerminate();
    return 0;

}
