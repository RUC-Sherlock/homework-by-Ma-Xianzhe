#ifndef ABSTRACT_OBJ_H
#define ABSTRACT_OBJ_H

#include <QImage>
#include <QPainter>
#include <QPoint>

class Abstract_obj
{
private:
    int _img_num;
    int _dx;
    int _dy;
    int _speed;
    QPoint _obj_location;
    QPoint _img_location;
    QImage * _pimg;
    QPoint _destination;
    void setdpoint(void);
public:
    Abstract_obj(const QPoint & obj_location, const QPoint & rlocation, const int img_num, const char **dir_set,
                 const int speed=0,const QPoint & des=QPoint());
    virtual void draw(QPainter &p,int index);
    int getX()const {return _obj_location.x();}
    int getY()const {return _obj_location.y();}
    const QPoint& getObj_location()const {return _obj_location;}
    int getObj_locationX(void)const {return _obj_location.x();}
    int getObj_locationY(void)const {return _obj_location.y();}
    int getDestinationX(void)const {return _destination.x();}
    int getDestinationY(void)const {return _destination.y();}
    int getDx(void)const {return _dx;}
    int getDy(void) {return _dy;}
    int getSpeed(void) {return _speed;}
    void setDestination(const QPoint & des);
    virtual ~Abstract_obj(){delete []_pimg;}
protected:
    virtual void setSpeed(int speed) {_speed=speed;}
    virtual void setObj_location(const QPoint & obj_location);
    virtual void move(void);
};

#endif // ABSTRACT_OBJ_H
