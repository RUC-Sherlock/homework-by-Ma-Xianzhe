#include "abstract_obj.h"
#include <cmath>


void Abstract_obj::setdpoint()
{
    _dx=_destination.x()-_obj_location.x();
    _dy=_destination.y()-_obj_location.y();
}

Abstract_obj::Abstract_obj(const QPoint &obj_location, const QPoint &rlocation,
                           const int img_num, const char **dir_set, const int speed, const QPoint & des):
                           _img_num(img_num),_speed(speed),_obj_location(obj_location),
                           _img_location(obj_location-rlocation),_pimg(new QImage[img_num]),_destination(des)
{
    for(int i=0;i<img_num;i++){
        _pimg[i].load(dir_set[i]);
    }
    setdpoint();
}



void Abstract_obj::setObj_location(const QPoint & obj_location)
{
    _img_location+=(obj_location-_obj_location);
    _obj_location=obj_location;
    setdpoint();
}

void Abstract_obj::draw(QPainter & p, int index)
{
    p.drawImage(_img_location,_pimg[index]);
}

void Abstract_obj::setDestination(const QPoint &des)
{
    _destination=des;
    setdpoint();
}


void Abstract_obj::move(void)
{
    int distance=(int)(sqrt(_dx*_dx+_dy*_dy)+0.01);
    //如果不重合，一定distance>=1
    if(distance<=_speed)
    {
        setObj_location(_destination);
        setdpoint();
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
    setObj_location(_obj_location+QPoint(xfoot,yfoot));
}
