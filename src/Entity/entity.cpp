#include "entity.h"

void Player::updatePos(float dt)
{
    pos += vel * dt;
}

void Player::screenCollision(const glm::vec2 &screenSize)
{
    if(pos.y + hitbox.size.y >= screenSize.y)
    {
        pos.y = screenSize.y - hitbox.size.y;
        vel.y = 0;
    }
    if(pos.y - hitbox.size.y < 0)
    {
        pos.y = hitbox.size.y;
        vel.y = 0;
    }
    if(pos.x + hitbox.size.x >= screenSize.x)
    {
        pos.x = screenSize.x - hitbox.size.x;
        vel.x = 0;
    }
    if(pos.x - hitbox.size.x < 0)
    {
        pos.x = hitbox.size.x;
        vel.x = 0;
    }
}
