#include "princess.h"
#include <QPoint>

static const char *dir_set[]=
    {":/princess/image/princess/lstand1.png",
    ":/princess/image/princess/rstand1.png",
    ":/princess/image/princess/l_longattack1.png",
    ":/princess/image/princess/l_longattack2.png",
    ":/princess/image/princess/l_longattack3.png",
    ":/princess/image/princess/l_longattack4.png",
    ":/princess/image/princess/r_longattack1.png",
    ":/princess/image/princess/r_longattack2.png",
    ":/princess/image/princess/r_longattack3.png",
    ":/princess/image/princess/r_longattack4.png"
    };
static const QPoint rlocation=QPoint(64,136);
static const int hurtable_range=80;
static const int attack_range=200;
static const int MAXHP=400;
static const int img_num=10;

//仅仅为了下面构造函数使用符号常量
//这样修改初始值的时候好修改，不用到下面繁杂的代码里面修改
Princess::Princess(int xpos, int ypos):
    Live_player(QPoint(xpos,ypos),rlocation,img_num,dir_set,hurtable_range,attack_range,MAXHP),
    _condition(lstand1){}

Princess::Princess(const QPoint & obj_location):
    Live_player(obj_location,rlocation,img_num,dir_set,hurtable_range,attack_range,MAXHP),
    _condition(lstand1){}

bool Princess::isLeft()const
{
    bool c1=(_condition==lstand1);
    bool c2=_condition>=l_longattack1&&_condition<=l_longattack4;
    return c1||c2;
}


#include <iostream>
using namespace std;

void Princess::react(Command cmd)
{
    switch (cmd) {
    case Lstand:
        if(!isStanding()) return;
        _condition=lstand1;
        break;
    case Rstand:
        if(!isStanding()) return;
        _condition=rstand1;
        break;
    case Longattack:
        if(_condition>=l_longattack1&&_condition<=r_longattack1) return;
        else if(isLeft())
            _condition=l_longattack1;
        else
            _condition=r_longattack1;
        break;//一定要记得加break!!!
    default:
        break;
    }
}


void Princess::draw(QPainter &p)
{
    Abstract_obj::draw(p,_condition);
    if(isStanding()) return;
    if(_condition>=l_longattack1&&_condition<l_longattack4)
        _condition=Condition(1+_condition);
    else if(_condition==l_longattack4)
        _condition=lstand1;
    else if(_condition>=r_longattack1&&_condition<r_longattack4)
        _condition=Condition(1+_condition);
    else if(_condition==r_longattack4)
        _condition=rstand1;
}
