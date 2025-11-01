#include <iostream>
#include <GLFW/glfw3.h>

int main() {
    std::cout << "Starting Society Simulator..." << std::endl;

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Society Simulator - Hello World", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make context current
    glfwMakeContextCurrent(window);

    std::cout << "Window created successfully!" << std::endl;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear screen with dark blue color
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);
        
        // Poll events
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    std::cout << "Goodbye!" << std::endl;
    return 0;
}