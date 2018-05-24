#ifndef OTHERS_H
#define OTHERS_H

#include "abstract_obj.h"

class Others : public Abstract_obj
{
public:
    Others(const QPoint obj_location,const QPoint & rlocation,const int img_num,const char **dir_set);
    virtual ~Others();
protected:
    virtual void move(){}
};

#endif // OTHERS_H
