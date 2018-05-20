#ifndef ABSTRACT_OBJ_H
#define ABSTRACT_OBJ_H

#include <QImage>
#include <QPainter>
#include <QPoint>

class Abstract_obj
{
private:
    int _img_num;
    QPoint _obj_location;
    QPoint _img_location;
    QImage * _pimg;
public:
    Abstract_obj(const QPoint & obj_location,const QPoint & rlocation,const int img_num,const char **dir_set);
    int getX()const {return _obj_location.x();}
    int getY()const {return _obj_location.y();}
    virtual void draw(QPainter &p,int index);
    const QPoint& getObj_location()const {return _obj_location;}
    virtual ~Abstract_obj(){delete []_pimg;}
protected:
    void setObj_location(const QPoint & obj_location);
};

#endif // ABSTRACT_OBJ_H
