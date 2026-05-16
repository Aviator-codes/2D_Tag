#pragma once
#include "../config.h"

struct UI
{
    GLFWwindow* window = NULL;

    static constexpr int WIN_WIDTH = 800;
    static constexpr int WIN_HEIGHT = 600;
    static const char* WIN_NAME;

    void init();
    void UIsetup();
    void renderUI();
    void cleanup();
};

extern glm::vec2 windowSize;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  
