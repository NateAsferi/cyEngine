#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "spdlog/spdlog.h"
#include "GraphicsManager.h"

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

void GraphicsManager::shutdown() {
    glfwTerminate();
    spdlog::info("GLFW terminated.");
}
