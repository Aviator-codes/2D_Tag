#include "entity.h"

void Player::updatePos(float dt)
{
    pos += vel * dt;
}