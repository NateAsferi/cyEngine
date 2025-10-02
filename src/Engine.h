#pragma once
#include <functional>
#include "GraphicsManager.h"
#include "InputManager.h"

class Engine {
public:
    Engine() : inputManager(graphicsManager) {}

    typedef std::function<void()> UpdateCallback;
    void RunGameLoop(const UpdateCallback& callback) {
        while (!graphicsManager.ShouldQuit()) {
            inputManager.Update();
            callback();
        }
    }

    GraphicsManager& GetGraphicsManager() { return graphicsManager; }
    InputManager& GetInputManager() { return inputManager; }

private:
    GraphicsManager graphicsManager;
    InputManager inputManager;
};
