#include "live_player.h"


Live_player::Live_player(const QPoint &obj_location, const QPoint &rlocation, const int img_num, const char **dir_set,
       const int hurtable_range, const int attack_range, const int MAXHP):
    Abstract_obj(obj_location,rlocation,img_num,dir_set),
    _HP(MAXHP),_MAXHP(MAXHP),_hurtable_range(hurtable_range),_attack_range(attack_range){}

