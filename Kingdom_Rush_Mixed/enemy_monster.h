#ifndef ENERMY_MONSTER_H
#define ENERMY_MONSTER_H

#include "constant.h"
#include "live_player.h"
#include <QPoint>

class Enemy_monster : public Live_player
{
public:
    Enemy_monster(int xpos, int ypos);
    Enemy_monster(const QPoint & obj_location);
    void react(Command cmd);
    void draw(QPainter &p);
    bool isWalking(void)const
    {
        if(_condition>=l_walk1_1&&_condition<=l_walk12_2)
            return true;
        else
            return false;
    }
    ~Enemy_monster(){}
private:
    enum Condition{l_walk1_1,l_walk1_2,l_walk2_1,l_walk2_2,l_walk3_1,l_walk3_2,l_walk4_1,l_walk4_2,l_walk5_1,l_walk5_2,l_walk6_1,l_walk6_2,l_walk7_1,l_walk7_2,l_walk8_1,l_walk8_2,l_walk9_1,l_walk9_2,l_walk10_1,l_walk10_2,l_walk11_1,l_walk11_2,l_walk12_1,l_walk12_2,
                   l_attack1_1,l_attack1_2,l_attack1_3,l_attack2_1,l_attack2_2,l_attack2_3,l_attack3_l,_attack3_2,l_attack3_3,l_attack4_1,l_attack4_2,l_attack4_3,l_attack5_1,l_attack5_2,l_attack5_3,l_attack6_1,l_attack6_2,l_attack6_3};
    Condition _condition;
    int point_destination;//标记下一个要去的点是第几个。针对destination数组中的列数，0-3
    int _sleep;
};

#endif // ENERMY_FAR_H
