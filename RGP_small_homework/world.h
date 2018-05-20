#ifndef WORLD_H
#define WORLD_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QImage>
#include <player.h>

class World:public QMainWindow
{
private:
    QImage _background;
    Player _player;
public:
    World();
    void paintEvent(QPaintEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event){update();}
};

#endif // WORLD_H
