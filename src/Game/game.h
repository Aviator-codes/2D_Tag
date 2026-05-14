#pragma once
#include "../config.h"
#include "../UI/ui.h"
#include "../Renderer/renderer.h"

struct Game
{
    void init();
    void update(float dt);
    void render();
    void renderDebugUI();
    void close();
    void processInput();
    UI ui;
    Shader shader; 
    Texture tex;
    Renderer2D renderer;
    
    uint VAO, VBO, EBO;
}; 