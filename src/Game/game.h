#pragma once
#include "../config.h"
#include "../UI/ui.h"
#include "../Entity/entity.h"
#include "../Renderer/renderer.h"

struct Game
{
    void init();
    void update(float dt);
    void render();
    void renderDebugUI();
    void close();
    void processInput(float dt);

    glm::vec3 backgroundColor = {0.2f, 0.4f, 0.7f};

    UI ui;
    Shader shader; 
    std::vector<Texture> textures;
    Renderer2D renderer;
    
    uint VAO, VBO, EBO;

    Player player;

    const float g = 400.0f;
    bool viewHitboxes = false;
    bool viewCenter = false;
    float groundY = 600.0f;
}; 