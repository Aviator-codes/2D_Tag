#pragma once
#include "../config.h"
#include "../shaders/shader.h"
#include "../Textures/texture.h"
#include "../UI/ui.h"

struct Renderer2D
{
    void init(UI* ui_);
    void begin();
    void draw(Texture& tex,
              float x,
              float y,
              float w,
              float h);
    void end();

    Shader shader;

    uint VAO;
    uint VBO;
    uint EBO;

    glm::mat4 projection;
    UI* ui;
};