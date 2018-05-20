#include "abstract_obj.h"
#include <iostream>
using namespace std;

Abstract_obj::Abstract_obj(const QPoint &obj_location, const QPoint &rlocation, const int img_num, const char **dir_set):
    _img_num(img_num),_obj_location(obj_location),_img_location(obj_location-rlocation),_pimg(new QImage[img_num])
{
    for(int i=0;i<img_num;i++){
        _pimg[i].load(dir_set[i]);
    }
}


void Abstract_obj::setObj_location(const QPoint & obj_location)
{
    _obj_location=obj_location;
    _img_location+=obj_location-_obj_location;
}

void Abstract_obj::draw(QPainter & p, int index)
{
    p.drawImage(_img_location,_pimg[index]);
}
