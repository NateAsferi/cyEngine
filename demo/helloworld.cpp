#include "GraphicsManager.h"

int main() {
    GraphicsManager gfx;

    if (!gfx.startup(800, 600, "Hello Engine", false)) {
        return -1; // failed to start
    }

    // Main loop
    while (true) {
        // In the future: poll input, update game logic, draw frame
        if (false) break; // stub exit condition
    }

    gfx.shutdown();
    return 0;
}
