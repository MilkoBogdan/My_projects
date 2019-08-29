#include "player.h"

void Player::draw()
{
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::SOLID);
    printItem(ItemType::EMPTY_SPACE);
    gotoXY(column * SPACESHIP_WIDTH, (line * SPACESHIP_HEIGHT) + 1);
    printItem(ItemType::SOLID);
    printItem(ItemType::SOLID);
    printItem(ItemType::SOLID);
}
