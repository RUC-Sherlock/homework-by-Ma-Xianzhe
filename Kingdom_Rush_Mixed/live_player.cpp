#include "live_player.h"
#include <cmath>


void Live_player::setdpoint()
{
    _dx=_destination.x()-getObj_locationX();
    _dy=_destination.y()-getObj_locationY();
}

Live_player::Live_player(const QPoint &obj_location, const QPoint &rlocation, const QPoint &rheart, const int img_num, const char **dir_set,
       const int hurtable_range, const int attack_range, const int MAXHP, int speed, const QPoint &des):
    Abstract_obj(obj_location,rlocation,img_num,dir_set),
    _HP(MAXHP),_MAXHP(MAXHP),_hurtable_range(hurtable_range),_attack_range(attack_range),_speed(speed),_heart(obj_location-rlocation+rheart),
    _obj_rheart(rheart-rlocation),_destination(des)
{
    setdpoint();
}

void Live_player::setDestination(const QPoint &des)
{
    _destination=des;
    setdpoint();
}

void Live_player::setObj_location(const QPoint &obj_location)
{
    Abstract_obj::setObj_location(obj_location);
    _heart+=_obj_rheart+getObj_location();
    setdpoint();
}

int Live_player::HeartDistanceWith(const Abstract_obj & obj)const
{
    int dx=this->_heart.x()-obj.getObj_locationX();
    int dy=this->_heart.y()-obj.getObj_locationY();
    return sqrt(dx*dx+dy*dy);
}

bool Live_player::inAttack_range(const Live_player &obj) const
{
    return _attack_range>=ObjDistanceWith(obj);
}

bool Live_player::inHurtable_range(const Abstract_obj &obj) const
{
    return _hurtable_range>=HeartDistanceWith(obj);
}

void Live_player::move(void)
{
    int distance=(int)(sqrt(_dx*_dx+_dy*_dy)+0.01);
    //如果不重合，一定distance>=1
    if(distance<=_speed)
    {
        setObj_location(_destination);
        return;
    }
    //此时distance<_speed
    int xfoot,yfoot;
    if(_dx==0) xfoot=0;
    else {
        xfoot=(_speed*_dx)/distance;
    }
    if(_dy==0) yfoot=0;
    else {
        yfoot=(_speed*_dy)/distance;
    }
    setObj_location(getObj_location()+QPoint(xfoot,yfoot));
}
