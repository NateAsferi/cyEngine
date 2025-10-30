#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "spdlog/spdlog.h"
#include "GraphicsManager.h"

/**
* @brief Creates the window for the game engine.
* @param width Width of the window.
* @param height Height of the window.
* @param name Name of the program.
* @param fullscreen Whether or not the window should be fullscreened.
* @return True, if the window is created sucessfully. False, if an error has occurred.
*/
bool GraphicsManager::startup(int width, int height, const char* name, bool fullscreen) {
    if (!glfwInit()) {
        spdlog::error("Failed to initialize GLFW.");
        return false;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_window = glfwCreateWindow(
        width, height, name,
        fullscreen ? glfwGetPrimaryMonitor() : nullptr,
        nullptr
    );

    if (!m_window) {
        spdlog::error("Failed to create a window.");
        glfwTerminate();
        return false;
    }

    glfwSetWindowAspectRatio(m_window, width, height);

    spdlog::info("Window created successfully.");
    return true;
}

/**
* @brief 
* 
* 
*/
bool GraphicsManager::ShouldQuit() const {
    return glfwWindowShouldClose(m_window);
}

/**
* 
* 
* 
*/
void GraphicsManager::SetShouldQuit(bool value) {
    glfwSetWindowShouldClose(m_window, value);
}

/**
* @brief Terminates all windows and graphics.
*/
void GraphicsManager::shutdown() {
    glfwTerminate();
    spdlog::info("GLFW terminated.");
}
