#include <iostream>
#include <fstream>

#include "console.h"

#include "spaceship.h"
#include "spacemap.h"

#include "application_loop.h"
#include "timer.h"

using namespace std;

static SpaceMap map;


void refreshScreenAlienMove()
{

        map.moveAliensRight();

}

void refreshScreen()
{
    //    map.alienShoot();
    map.moveBulletUp();
    map.moveBulletDown();
    clearScreen();
    map.draw();
}

void refreshScreenAlien(){
    map.alienShoot();
}

void onKeyPressed(KeyType *key)
{
    if (*key == KeyType::ARROW_LEFT)
    {
        map.movePlayerLeft();
    }
    else if (*key == KeyType::ARROW_RIGHT)
    {
        map.movePlayerRight();
    }
    //        else if(*key == KeyType::ARROW_DOWN)
    //        {
    //            map.moveAliensRight();
    //        }
    else if (*key == KeyType::SPACE_BAR)
    {
        map.PlayerShoot();
    }
    else if (*key == KeyType::QUIT)
    {
        exit(EXIT_SUCCESS);
    }

    clearScreen();
    map.draw();

    delete key;
}

int main()
{
    application_loop app;

    setCursorVisible(false);
    map.draw();

    timer updateTimer;
    updateTimer.setTimeout(100);
    updateTimer.onTimeout(refreshScreen);
    updateTimer.start();

    timer updateTimerAlien;
    updateTimerAlien.setTimeout(600);
    updateTimerAlien.onTimeout(refreshScreenAlien);
    updateTimerAlien.start();

    timer AlienMove;
    AlienMove.setTimeout(500);
    AlienMove.onTimeout(refreshScreenAlienMove);
    AlienMove.start();



    app.run(onKeyPressed);

    return 0;
}
