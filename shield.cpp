#include "shield.h"

void Shield::draw()
{
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT);
    printItem(ItemType::SOLID);
    printItem(ItemType::SOLID);
    printItem(ItemType::SOLID);
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT + 1);
    printItem(ItemType::SOLID);
    printItem(ItemType::SOLID);
    printItem(ItemType::SOLID);
}
