#include "world.h"
#include <QDebug>
#include <iostream>
using namespace std;

World::World():_background(QImage(":/image/image/map.jpg")),
  _player()
{
    if(_background.isNull())
        cerr<<"can't load the background image."<<endl;
    QObject::startTimer(1);
}

void World::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(),_background);
    _player.draw(painter);
}

void World::keyReleaseEvent(QKeyEvent *event)
{
    int d=1;
    switch (event->key()) {
    case Qt::Key_A:
        _player.translate(-d,0);
        break;
    case Qt::Key_D:
        _player.translate(d,0);
        break;
    case Qt::Key_W:
        _player.translate(0,-d);
        break;
    case Qt::Key_S:
        _player.translate(0,d);
        break;
    default:
        break;
    }
}
