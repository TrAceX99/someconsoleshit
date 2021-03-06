#include "objectClasses.h"
#include <windows.h>

void Player::Update(double& deltaTime) {
    Object::Update(deltaTime);
    // Get WASD input
    int deltaX = GetAsyncKeyState('D') ? 1 : 0 +
    GetAsyncKeyState('A') ? -1 : 0;
    int deltaY = GetAsyncKeyState('S') ? 1 : 0 +
    GetAsyncKeyState('W') ? -1 : 0;

    // Update precise player position
    position.x += deltaX * SPEED * deltaTime;
    position.y += deltaY * SPEED * deltaTime;

    // Animation testing
    if (deltaX > 0) direction = 1;
    if (deltaX < 0) direction = -1;
    sprite->imageIndex = (direction == 1 ? 2 : 0) + (GetAsyncKeyState(VK_SPACE) ? 1 : 0);
    return;
}

void UIObject::Update(double& deltaTime) {
    relativePosition = position;
}