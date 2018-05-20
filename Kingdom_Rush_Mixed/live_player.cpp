#include "live_player.h"


Live_player::Live_player(const QPoint &obj_location, const QPoint &rlocation, const QPoint &rheart, const int img_num, const char **dir_set,
       const int hurtable_range, const int attack_range, const int MAXHP, int speed, const QPoint &des):
    Abstract_obj(obj_location,rlocation,img_num,dir_set,speed,des),
    _HP(MAXHP),_MAXHP(MAXHP),_hurtable_range(hurtable_range),_attack_range(attack_range),_heart(obj_location-rlocation+rheart),
    _obj_rheart(rheart-rlocation){}


void Live_player::setObj_location(const QPoint &obj_location)
{
    Abstract_obj::setObj_location(obj_location);
    _heart+=_obj_rheart+getObj_location();
}

void Live_player::move(void)
{
    Abstract_obj::move();
    _heart+=_obj_rheart+getObj_location();
}
