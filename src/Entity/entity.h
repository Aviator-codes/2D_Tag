#pragma once
#include "../config.h"
#include "../Textures/texture.h"

struct AABB
{
    glm::vec2 halfSize;
};

struct Player
{
    glm::vec2 pos;
    glm::vec2 vel;

    const float jumpHeight = 300.0f;

    AABB hitbox;
    Texture* tex;
    float texSize;

    void updatePos(float dt);
};