#pragma once
#include <GLFW/glfw3.h>

class GraphicsManager;

class InputManager {
public:
    InputManager(GraphicsManager& gm);

    void Update();
    bool KeyIsPressed(int key);

private:
    GraphicsManager& graphicsManager;
};
