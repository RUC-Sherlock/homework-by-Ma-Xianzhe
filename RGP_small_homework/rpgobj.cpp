#include "rpgobj.h"
#include <QImage>
#include <QRect>
#include <iostream>

using namespace std;

const QImage RPGobj::all=QImage(":/image/image/TileB.png");


RPGobj::RPGobj(Type tp, int xpos, int ypos):QRect(xpos,ypos,Rect[tp].width*GRID_SIZE,Rect[tp].height*GRID_SIZE),_type(tp)
{
    if(all.isNull()) cerr<<"can't load all!"<<endl;
    _image=all.copy(Rect[tp].xpos*GRID_SIZE,Rect[tp].ypos*GRID_SIZE,Rect[tp].width*GRID_SIZE,Rect[tp].height*GRID_SIZE);
    switch (tp) {
    case player:
        _coverable=false;
        _eatable=false;
        break;
    default:
        break;
    }
}

void RPGobj::draw(QPainter &p)
{
    //p.drawImage(*this,_image);can this be done?
    p.drawImage(*this,_image);
}



