
#include <fstream>
#include <iostream>
#include "spacemap.h"
#include "player.h"
#include "alien.h"
#include "mother_ship.h"
#include "shield.h"
#include "bullet.h"

using namespace std;

SpaceMap::SpaceMap()
{
    ifstream mapFile("S:\\WORK cpp\\SpaceInvadersV9\\map.txt", ifstream::in);
    if (!mapFile.is_open())
    {
        cout << "Failed to open file!!!!" << endl;
        exit(-1);
    }

    for (int row = 0; row < SPACEMAP_HEIGHT; ++row)
    {
        for (int column = 0; column < SPACEMAP_WIDTH; ++column)
        {
            int element = mapFile.get();
            if (element == '\n')
            {
                element = mapFile.get();
            }
            switch (element)
            {
            case Spaceship::PLAYER:
            {
                player = new Player();
                player->line = row;
                player->column = column;
                player->type = Spaceship::PLAYER;


                break;
            }
            case Spaceship::BLANK_SPACE:

                break;
            case Spaceship::ALIEN:
            {
                Alien *alien = new Alien();
                alien->line = row;
                alien->column = column;
                alien->type = Spaceship::ALIEN;
                aliens.push_back(alien);
                break;
            }
            case Spaceship::SHIELD:
            {
                Shield * shield = new Shield();
                shield->line = row;
                shield->column = column;
                shield->type = Spaceship::SHIELD;
                shields.push_back(shield);
                break;
            }
            case Spaceship::MOTHERSHIP:
            {
                mother_ship = new Mother_ship();
                mother_ship->line = row;
                mother_ship->column = column;
                mother_ship->type = Spaceship::MOTHERSHIP;

                break;
            }
            case Spaceship::BULLET:
            {
                Bullet *bullet = new Bullet();
                bullet->line = row;
                bullet->column = column;
                bullet->type = Spaceship::BULLET;
                bulletLine = row;
                bulletColumn = column;
                bullets.push_back(bullet);
                break;
            }
            }
        }
    }
    mapFile.close();
    lastMove = 1;
}


void SpaceMap::draw()
{
    if (mother_ship != nullptr)
    {
        mother_ship->draw();
    }

    for ( size_t i = 0; i < aliens.size(); ++i)
    {
        aliens[i]->draw();
    }

    for (Shield *shield : shields)
    {
        shield->draw();
    }

    if (player != nullptr)
    {
        player->draw();
    }

    for (Bullet *bullet : bullets)
    {
        bullet->draw();
    }

    for(Bullet * bullet : alien_bullets)
    {
        bullet->draw();
    }
    refreshConsole();
}

void SpaceMap::movePlayerLeft()
{
    player->moveLeft();
}

void SpaceMap::movePlayerRight()
{
    player->moveRight();
}


void SpaceMap::moveAliensRight()
{

    for (size_t i = 0; i < aliens.size();++i)
    {
        if(lastMove < 0){
            aliens[i]->moveLeft();
        }
        else{
            aliens[i]->moveRight();
        }
    }

    if (lastMove < 0)
    {
        --lastMove;
    }
    else{
        ++lastMove;
    }

    if(lastMove < -2){
        lastMove = 1;
    }
    else if(lastMove > 2){
        lastMove = -1;
    }


}


void SpaceMap::moveAliensLeft()
{
    for (size_t i = 0; i < aliens.size();++i)
    {
        aliens[i]->moveLeft();
    }

}

void SpaceMap::moveBulletUp()
{
    std:: vector <size_t> bulletsToErase;


    for( size_t i = 0; i< bullets.size(); ++i)
    {
        Bullet * bullet = bullets[i];

        bullet->moveUp();

        if(bullet->line < 0){
            delete bullet;
            bulletsToErase.push_back(i);
        }


        if (mother_ship != nullptr)
        {
            if (bullet->line == mother_ship->line && bullet->column == mother_ship->column)
            {
                delete bullet;
                bulletsToErase.push_back(i);
                delete mother_ship;
                mother_ship = nullptr;
            }
        }

        for(size_t j = 0; j < aliens.size(); ++j){
            Alien * alien = aliens[j];
            if (bullet->line == alien->line && bullet->column == alien->column )
            {
                delete bullet;
                bulletsToErase.push_back(i);
                delete alien;
                aliens.erase(aliens.begin() + static_cast<int>(j));
            }
        }
        for(size_t k = 0; k < shields.size(); ++k){
            Shield * shield = shields[k];
            if (bullet->line == shield->line && bullet->column == shield->column)
            {
                delete bullet;
                bulletsToErase.push_back(i);
                delete shield;
                shields.erase(shields.begin() + static_cast<int>(k));
            }
        }
    }

    for(size_t i = 0; i < bulletsToErase.size();++i)
    {
        bullets.erase(bullets.begin() + static_cast<int>(bulletsToErase[i] - i));
    }
}


void SpaceMap::moveBulletDown()
{
    vector<size_t> alienBulletsToErase;

    for( size_t i = 0; i< alien_bullets.size(); ++i)
    {
        Bullet * bullet = alien_bullets[i];

        bullet->moveDown();

        if(bullet->line >= SPACEMAP_HEIGHT)
        {
            delete bullet;
            alienBulletsToErase.push_back(i);
        }

        for(size_t k = 0; k < shields.size(); ++k){
            Shield * shield = shields[k];
            if (bullet->line == shield->line && bullet->column == shield->column)
            {
                delete bullet;
                alienBulletsToErase.push_back(i);
                delete shield;
                shields.erase(shields.begin() + static_cast<int>(k));
            }
        }
        if(player != nullptr){
            if (bullet->line == player->line && bullet->column == player->column)
            {
                delete bullet;
                alienBulletsToErase.push_back(i);
                delete player;
                player = nullptr;
            }
        }

    }
    for(size_t i = 0;i < alienBulletsToErase.size();++i)
    {
        alien_bullets.erase(alien_bullets.begin() + static_cast<int>(alienBulletsToErase[i]-i));
    }
}

void SpaceMap::alienShoot()
{
    Bullet * bullet = new Bullet();
    size_t i = static_cast <size_t>(rand()) % static_cast <size_t> (aliens.size());
    bullet->line = aliens[i]->line + 1;
    bullet->column = aliens[i]->column;
    bullet->type = Spaceship::BULLET;
    alien_bullets.push_back(bullet);

}

void SpaceMap::PlayerShoot()
{

    Bullet * bullet = new Bullet();
    bullet->line = player->line -1;
    bullet->column = player->column;
    bullet->type = Spaceship::BULLET;
    bullets.push_back(bullet);
}










