#ifndef LIVE_PLAYER_H
#define LIVE_PLAYER_H
#include "abstract_obj.h"
#include "constant.h"
//注意：基类Abstract_obj中的move（）函数和set_Obj_location函数
//都不要使用，只能使用Abstract_obj中重新定义的move和set_Obj_location

class Live_player:public Abstract_obj
{
private:
    int _HP;
    int _MAXHP;
    int _hurtable_range;
    int _attack_range;
    int _dx;
    int _dy;
    int _speed;
    QPoint _heart;
    QPoint _obj_rheart;//心相对于_obj_location的坐标
    QPoint _destination;
    void setdpoint();
public:
    Live_player(const QPoint & obj_location,const QPoint & rlocation,const QPoint & rheart,const int img_num,const char **dir_set,
           const int hurtable_range,const int attack_range,const int MAXHP,int speed=0,const QPoint & des=QPoint());
    const QPoint & getHeart(void)const {return _heart;}
    int getHP(void)const {return _HP;}
    int getMAXHP(void)const {return _MAXHP;}
    int getDx(void)const {return _dx;}
    int getDy(void) {return _dy;}
    int getSpeed(void) {return _speed;}
    int getHurtable_range(void)const {return _hurtable_range;}
    int getAttack_range(void)const {return _attack_range;}
    int getDestinationX(void)const {return _destination.x();}
    int getDestinationY(void)const {return _destination.y();}
    int HeartDistanceWith(const Abstract_obj & obj)const;
    bool inHurtable_range(const Abstract_obj & obj)const;
    bool inAttack_range(const Live_player & obj)const;
    virtual void setDestination(const QPoint & des);
    virtual void react(Command cmd)=0;
    virtual ~Live_player(){}
protected:
    void setMAXHP(int MAXHP) {_MAXHP=MAXHP;}
    void setHurtable_range(int hurtable_range){_hurtable_range=hurtable_range;}
    void setAttack_range(int attack_range){_attack_range=attack_range;}
    void setHP(int HP) {_HP=HP;}
    void setSpeed(int speed) {_speed=speed;}
    virtual void setObj_location(const QPoint & obj_location);
    virtual void move();
};

#endif // LIVE_PLAYER_H
