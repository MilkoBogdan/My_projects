#include "alien.h"


void Alien::draw()
{
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT);
    printItem(ItemType::SOLID);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::SOLID);
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT + 1);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::SOLID);
    printItem(ItemType::EMPTY_SPACE);
}
