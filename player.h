#ifndef PLAYER_H
#define PLAYER_H

#include "spaceship.h"

struct Player : public Spaceship
{
    void draw();
};

#endif // PLAYER_H
