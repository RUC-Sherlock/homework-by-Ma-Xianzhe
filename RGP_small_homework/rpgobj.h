#ifndef RPGOBJ_H
#define RPGOBJ_H

#include <QRect>
#include <QImage>
#include <QPainter>

class RPGobj:public QRect
{

public:
    enum Type{player};
    RPGobj(Type tp,int xpos=0,int ypos=0);
    bool is_eatable()const {return _eatable;}
    bool is_coverable()const {return _coverable;}
    Type get_type()const {return _type;}
    void draw(QPainter &p);
private:
    const static int num_of_types=1;
    const struct
    {
        int xpos;
        int ypos;
        int width;
        int height;
    }Rect[num_of_types]={{1,13,1,2}};
    const static QImage all;
    const static int GRID_SIZE=32;
    QImage _image;
    Type _type;
    bool _eatable;
    bool _coverable;
};

#endif // RPGOBJ_H
