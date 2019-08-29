#ifndef SPACEMAP_H
#define SPACEMAP_H
#include <vector>
#include "spaceship.h"
#include "alien.h"
#include "bullet.h"
#include "player.h"
#include "mother_ship.h"
#include "shield.h"
#include "mother_ship.h"


const int SPACEMAP_WIDTH = 20;
const int SPACEMAP_HEIGHT = 10;

struct SpaceMap
{
    std::vector<Bullet *> alien_bullets;
    std::vector<Bullet *> bullets;
    std::vector<Alien *> aliens;
    std::vector<Shield *> shields;
    Mother_ship* mother_ship;
    Player* player;





    int lastMove;
    int bulletLine = -1;
    int bulletColumn = -1;

    SpaceMap();

    void moveAliensRight();
    void moveAliensLeft();

    void draw();
    void PlayerShoot();
    void movePlayerLeft();
    void movePlayerRight();
    void alienShoot();
    void moveBulletUp();
    void moveBulletDown();
};

#endif // SPACEMAP_H
