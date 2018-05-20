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
     ":/princess/image/princess/r_longattack4.png",
     ":/princess/image/princess/lmove1.png",
     ":/princess/image/princess/rmove1.png"
    };
static const QPoint rlocation=QPoint(64,136);
static const QPoint rheart=QPoint(64,110);
//以上两个点均为相对于图片左上角的坐标
//Live_player提供了getHeart()函数，返回heart的绝对坐标
//放心，在使用setObj_location()改变人的坐标的时候
//内部已把图片坐标和心的坐标相应地修改了 所以可放心使用
static const int hurtable_range=30;
static const int attack_range=200;
static const int MAXHP=400;
static const int img_num=12;
static const int speed=10;
//注意：每增加一次图片，对应在头文件Condition对应位置要写上状态
//并且更新img_num
//照片顺序最好符合逻辑

//以上定义了这么多的符号常量
//仅仅为了下面构造函数使用符号常量不适用裸露的数字，方便修改
//代码中尽量不出现裸露的数字是一个很好的习惯
//这样修改初始值的时候好修改，不用到下面繁杂的代码里面修改
//照片顺序最好先左后右，同一个运动状态的照片放一起
//照片名称最好和condition对应状态一致
Princess::Princess(int xpos, int ypos):
    Live_player(QPoint(xpos,ypos),rlocation,rheart,img_num,dir_set,hurtable_range,attack_range,MAXHP,speed),
    _condition(lstand1){}

Princess::Princess(const QPoint & obj_location):
    Live_player(obj_location,rlocation,rheart,img_num,dir_set,hurtable_range,attack_range,MAXHP,speed),
    _condition(lstand1){}

bool Princess::isLeft()const
{
    bool c1=(_condition==lstand1);
    bool c2=_condition>=l_longattack1&&_condition<=l_longattack4;
    bool c3=_condition==lmove1;
    return c1||c2||c3;
}



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
        if(!isStanding()) return;
        //只有静止状态才能发动攻击
        //移动过程中也不行
        else if(isLeft())
            _condition=l_longattack1;
        else
            _condition=r_longattack1;
        break;//一定要记得加break!!!
    case Move:
        if(_condition>=l_longattack1&&_condition<=r_longattack4) return;
        else if(isLeft())
            _condition=lmove1;
        else
            _condition=rmove1;
        break;
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
    else if(isMoving())
        {
        int dx=getDx();
        int dy=getDy();
        if(dx==0&&dy==0)
        {
            //此时已到达终点
            if(isLeft())
                _condition=lstand1;
            else _condition=rstand1;
            return;
        }
        else if(dx>0)
        {
            //这里在中间再改一次状态是为了
            //一次Move指令没有做完，用户就下达了下一个Move指令
            //此时人脸的方向仍然是上一个move状态的方向
            _condition=rmove1;
            move();
//在Live_player类提供move()函数
//效果是按照给人物的speed（即每次移动的步长）和人物与目标点的距离差
//取较小者移动该人物的坐标
        }
        else
        {
            _condition=lmove1;
            move();
        }
    }
}
