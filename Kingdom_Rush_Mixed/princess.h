#ifndef PRINCESS_H
#define PRINCESS_H
#include "constant.h"
#include "live_player.h"
#include <QPoint>
//#include "constant.h"

class Princess : public Live_player
{
    Q_OBJECT
//signals:
//    void response(Signal);
public:
    Princess(int xpos, int ypos);
    Princess(const QPoint & obj_location);
    void react(Command cmd);
    void draw(QPainter &p);
    bool isLeft(void)const;
    bool isStanding(void)const {return _condition<l_longattack1;}
    bool isMoving(void)const {return _condition==rmove1||_condition==lmove1;}
    bool isRight(void)const {return !isLeft();}
private:
    enum Condition{lstand1,rstand1,l_longattack1,l_longattack2,
        l_longattack3,l_longattack4,r_longattack1,r_longattack2,
        r_longattack3,r_longattack4,lmove1,rmove1};
    Condition _condition;
};

#endif // PRINCESS_H
