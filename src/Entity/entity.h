#pragma once
#include "../config.h"
#include "../Textures/texture.h"

struct Player
{
    glm::vec2 pos;
    glm::vec2 vel;

    float speed;

    Texture* tex;

    void updatePos(float dt);
};
