#include "enemy_monster.h"
#include <QPoint>

enum Route{map1_1,map1_2,map1_3,map2_1,map2_2,map3_1,map3_2,map3_3,map3_4};

static const QPoint destination[9][4]=
{{QPoint(1152,228),QPoint(950,430),QPoint(293,427),QPoint(0,562)},
 {QPoint(1020,497),QPoint(760,497),QPoint(380,497),QPoint(0,497)},
 {QPoint(985,625),QPoint(776,625),QPoint(385,625),QPoint(0,582)},
 {QPoint(918,322),QPoint(696,382),QPoint(172,327),QPoint(0,397)},
 {QPoint(995,716),QPoint(644,812),QPoint(301,728),QPoint(0,741)},
 {QPoint(445,190),QPoint(426,411),QPoint(205,545),QPoint(0,520)},
 {QPoint(882,266),QPoint(834,441),QPoint(432,412),QPoint(0,515)},
 {QPoint(911,624),QPoint(847,468),QPoint(442,422),QPoint(0,533)},
 {QPoint(900,844),QPoint(630,683),QPoint(605,378),QPoint(0,522)}
};
static const char *dir_set[]=
    {":/enemy_monster/image/enemy_monster/l_walk (1).png",
     ":/enemy_monster/image/enemy_monster/l_walk (1).png",
     ":/enemy_monster/image/enemy_monster/l_walk (2).png",
     ":/enemy_monster/image/enemy_monster/l_walk (2).png",
     ":/enemy_monster/image/enemy_monster/l_walk (3).png",
     ":/enemy_monster/image/enemy_monster/l_walk (3).png",
     ":/enemy_monster/image/enemy_monster/l_walk (4).png",
     ":/enemy_monster/image/enemy_monster/l_walk (4).png",
     ":/enemy_monster/image/enemy_monster/l_walk (5).png",
     ":/enemy_monster/image/enemy_monster/l_walk (5).png",
     ":/enemy_monster/image/enemy_monster/l_walk (6).png",
     ":/enemy_monster/image/enemy_monster/l_walk (6).png",
     ":/enemy_monster/image/enemy_monster/l_walk (7).png",
     ":/enemy_monster/image/enemy_monster/l_walk (7).png",
     ":/enemy_monster/image/enemy_monster/l_walk (8).png",
     ":/enemy_monster/image/enemy_monster/l_walk (8).png",
     ":/enemy_monster/image/enemy_monster/l_walk (9).png",
     ":/enemy_monster/image/enemy_monster/l_walk (9).png",
     ":/enemy_monster/image/enemy_monster/l_walk (10).png",
     ":/enemy_monster/image/enemy_monster/l_walk (10).png",
     ":/enemy_monster/image/enemy_monster/l_walk (11).png",
     ":/enemy_monster/image/enemy_monster/l_walk (11).png",
     ":/enemy_monster/image/enemy_monster/l_walk (12).png",
     ":/enemy_monster/image/enemy_monster/l_walk (12).png",
     ":/enemy_monster/image/enemy_monster/l_attack (1).png",
     ":/enemy_monster/image/enemy_monster/l_attack (1).png",
     ":/enemy_monster/image/enemy_monster/l_attack (1).png",
     ":/enemy_monster/image/enemy_monster/l_attack (2).png",
     ":/enemy_monster/image/enemy_monster/l_attack (2).png",
     ":/enemy_monster/image/enemy_monster/l_attack (2).png",
     ":/enemy_monster/image/enemy_monster/l_attack (3).png",
     ":/enemy_monster/image/enemy_monster/l_attack (3).png",
     ":/enemy_monster/image/enemy_monster/l_attack (3).png",
     ":/enemy_monster/image/enemy_monster/l_attack (4).png",
     ":/enemy_monster/image/enemy_monster/l_attack (4).png",
     ":/enemy_monster/image/enemy_monster/l_attack (4).png",
     ":/enemy_monster/image/enemy_monster/l_attack (5).png",
     ":/enemy_monster/image/enemy_monster/l_attack (5).png",
     ":/enemy_monster/image/enemy_monster/l_attack (5).png",
     ":/enemy_monster/image/enemy_monster/l_attack (6).png",
     ":/enemy_monster/image/enemy_monster/l_attack (6).png",
     ":/enemy_monster/image/enemy_monster/l_attack (6).png"
    };
static const QPoint rlocation=QPoint(72,106);
static const QPoint rheart=QPoint(72,68);
//图片大小为146*120
static const int hurtable_range=50;
static const int attack_range=250;//？瞎写的，再调
static const int MAXHP=20;//同瞎写
static const int img_num=42;
static const int speed=3;
static const QPoint des=destination[map1_1][0];

Enemy_monster::Enemy_monster(int xpos, int ypos):
    Live_player(QPoint(xpos,ypos),rlocation,rheart,img_num,dir_set,hurtable_range,attack_range,MAXHP,speed,des),
    _condition(l_walk1_1),point_destination(0),_sleep(0){}

Enemy_monster::Enemy_monster(const QPoint & obj_location):
    Live_player(obj_location,rlocation,rheart,img_num,dir_set,hurtable_range,attack_range,MAXHP,speed,des),
    _condition(l_walk1_1),point_destination(0),_sleep(0){}

void Enemy_monster::react(Command cmd)
{
    if(_sleep%2) return;
    switch(cmd){
        case Command::Lwalk:
            if(_condition<=l_walk12_1) _condition=Condition(1+_condition);
            else _condition=l_walk1_1;
            break;
        case Command::Lattack:
            //if(!isStanding()) return;
            //冰女进入攻击范围后小兵先停下再进攻
            //移动中无法进攻
            if(_condition<l_attack1_1)
                _condition=l_attack1_1;
            else
            {
                if(_condition>=l_attack1_1&&_condition<l_attack6_3)
                    _condition=Condition(1+_condition);
                else
                    _condition=l_attack1_1;
            }
            break;
        default:
            break;
    }
}

void Enemy_monster::draw(QPainter &p)
{
    Abstract_obj::draw(p,_condition);
    _sleep=(_sleep+1)%20;
    if(isWalking())
    {
        int dx=getDx();
        int dy=getDy();
        if(dx==0&&dy==0)
        {
            //到达目的地
            if(point_destination<=2)
            {
                point_destination++;
                setDestination(destination[map1_1][point_destination]);
            }
            /*if(_condition==l_walk1)_condition=l_walk2;
            else _condition=l_walk1;*/

        }
        if(_sleep) return;
        move();
    }
}

