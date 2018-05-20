#ifndef LIVE_PLAYER_H
#define LIVE_PLAYER_H

#include "abstract_obj.h"

class Live_player : public Abstract_obj
{
private:
    int _HP;
    int _MAXHP;
    int _hurtable_range;
    int _attack_range;
public:
    Live_player(const QPoint & obj_location,const QPoint & rlocation,const int img_num,const char **dir_set,
           const int hurtable_range,const int attack_range,const int _MAXHP);
    virtual ~Live_player(){}
protected:
    int getHP(void)const {return _HP;}
    int getMAXHP(void)const {return _MAXHP;}
    int getHurtable_range(void)const {return _hurtable_range;}
    int getAttack_range(void)const {return _attack_range;}
    void setMAXHP(int MAXHP) {_MAXHP=MAXHP;}
    void setHurtable_range(int hurtable_range){_hurtable_range=hurtable_range;}
    void setAttack_range(int attack_range){_attack_range=attack_range;}
    void setHP(int HP) {_HP=HP;}
};

#endif // LIVE_PLAYER_H
