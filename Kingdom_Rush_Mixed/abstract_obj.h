#ifndef ABSTRACT_OBJ_H
#define ABSTRACT_OBJ_H

#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QObject>

class Abstract_obj:public QObject
{
private:
    int _img_num;
    QPoint _obj_location;
    QPoint _img_location;
    QImage * _pimg;
public:
    Abstract_obj(const QPoint & obj_location, const QPoint & rlocation, const int img_num, const char **dir_set);
    virtual void draw(QPainter &p,int index);
    const QPoint& getObj_location()const {return _obj_location;}
    int getObj_locationX(void)const {return _obj_location.x();}
    int getObj_locationY(void)const {return _obj_location.y();}
    void setObj_location(const QPoint & obj_location);
    int ObjDistanceWith(const Abstract_obj & obj)const;
    virtual ~Abstract_obj(){delete []_pimg;}
protected:
    virtual void move()=0;
};

#endif // ABSTRACT_OBJ_H
