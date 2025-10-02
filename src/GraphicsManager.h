#pragma once
#include "GLFW/glfw3.h"

class GraphicsManager {

public:
    bool startup(int width, int height, const char* name, bool fullscreen); 
    void shutdown(); 
    GLFWwindow* GetWindow() const { return m_window; }
    bool ShouldQuit() const;
    void SetShouldQuit(bool value);

private:
    struct GLFWwindow* m_window = nullptr; 
};