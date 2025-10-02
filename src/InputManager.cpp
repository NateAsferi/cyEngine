#include "InputManager.h"
#include "GraphicsManager.h"

InputManager::InputManager(GraphicsManager& gm)
    : graphicsManager(gm) {
}

void InputManager::Update() {
    glfwPollEvents();
}

bool InputManager::KeyIsPressed(int key) {
    GLFWwindow* window = graphicsManager.GetWindow();
    return glfwGetKey(window, key) == GLFW_PRESS;
}
