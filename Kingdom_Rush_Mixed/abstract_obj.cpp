#include "abstract_obj.h"
#include <cmath>


Abstract_obj::Abstract_obj(const QPoint &obj_location, const QPoint &rlocation,
                           const int img_num, const char **dir_set):
                           _img_num(img_num),_obj_location(obj_location),
                           _img_location(obj_location-rlocation),_pimg(new QImage[img_num])
{
    for(int i=0;i<img_num;i++){
        _pimg[i].load(dir_set[i]);
    }
}



void Abstract_obj::setObj_location(const QPoint & obj_location)
{
    _img_location+=(obj_location-_obj_location);
    _obj_location=obj_location;
}

void Abstract_obj::draw(QPainter & p, int index)
{
    p.drawImage(_img_location,_pimg[index]);
}


int Abstract_obj::ObjDistanceWith(const Abstract_obj &obj) const
{
    int dx=obj._obj_location.x()-this->_obj_location.x();
    int dy=obj._obj_location.y()-this->_obj_location.y();
    return sqrt(dx*dx+dy+dy);
}

