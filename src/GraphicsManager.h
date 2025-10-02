#pragma once

class GraphicsManager {
public:
    bool startup(int width, int height, const char* name, bool fullscreen); //
    void shutdown(); //

private:
    struct GLFWwindow* m_window = nullptr; // forward declaration, avoids including glfw
};