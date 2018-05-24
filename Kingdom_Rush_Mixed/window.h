#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QImage>
#include "princess.h"
#include "enemy_monster.h"
//#include "constant.h"


namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event){update();}
private:
    Ui::Window *ui;
    Princess player;
    Enemy_monster stone1;//考虑写个数组
    QImage _background;
private slots:
//    void react(Signal);
};

#endif // WINDOW_H
