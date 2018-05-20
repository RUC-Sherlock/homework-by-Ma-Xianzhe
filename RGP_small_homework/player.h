#ifndef PLAYER_H
#define PLAYER_H

#include "rpgobj.h"

class Player : public RPGobj
{
public:
    Player(int xpos=0,int ypos=0):RPGobj(player,xpos,ypos){}
};

#endif // PLAYER_H
