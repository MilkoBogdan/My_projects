#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "console.h"

const int SPACESHIP_WIDTH = 3;
const int SPACESHIP_HEIGHT = 2;

struct Spaceship
{
    enum ShipType
    {
        PLAYER      = 'p',
        BLANK_SPACE = '_',
        ALIEN       = 'a',
        SHIELD      = 's',
        MOTHERSHIP  = 'm',
        BULLET      = 'b'
    };
    virtual ~Spaceship() = default;
    virtual void moveDown();
    virtual void moveUp();
    virtual void draw();
    virtual void moveLeft();
    virtual void moveRight();

    int line;
    int column;
    ShipType type;
};

#endif // SPACESHIP_H
