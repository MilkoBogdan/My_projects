#include "blank_space.h"

void blank_space :: draw()
{
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::EMPTY_SPACE);
    gotoXY(column * SPACESHIP_WIDTH, line * SPACESHIP_HEIGHT + 1);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::EMPTY_SPACE);
    printItem(ItemType::EMPTY_SPACE);
}
