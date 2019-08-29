#include "spaceship.h"
#include "bullet.h"
#include "spacemap.h"

void Spaceship::draw()
{

}
void Spaceship::moveLeft()
{
    if (column > 0){
     --column;

    }
}

void Spaceship::moveRight()
{
    if(column < 20){
    ++column;

    }
}
 void Spaceship::moveUp()
{
     --line;
}
 void Spaceship::moveDown(){

    ++line;
 }

