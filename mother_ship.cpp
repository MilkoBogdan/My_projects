#include "mother_ship.h"

void Mother_ship ::draw()
{
gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT);
printItem(ItemType::EMPTY_SPACE);
printItem(ItemType::SOLID);
printItem(ItemType::EMPTY_SPACE);
gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT + 1);
printItem(ItemType::SOLID);
printItem(ItemType::EMPTY_SPACE);
printItem(ItemType::SOLID);
}
