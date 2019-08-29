#include "bullet.h"

void Bullet::draw()
{

    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::SOLID);
}
