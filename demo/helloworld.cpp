#include "Engine.h"
#include <iostream>

int main() {
    Engine engine;

    // Initialize graphics
    if (!engine.GetGraphicsManager().startup(800, 600, "Checkpoint 3", false)) {
        return -1;
    }

    engine.RunGameLoop([&]() {
        if (engine.GetInputManager().KeyIsPressed(GLFW_KEY_A)) {
            std::cout << "A key pressed!\n";
        }
        if (engine.GetInputManager().KeyIsPressed(GLFW_KEY_ESCAPE)) {
            engine.GetGraphicsManager().SetShouldQuit(true);
        }
        });

    engine.GetGraphicsManager().shutdown();
    return 0;
}
