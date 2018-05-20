#include "window.h"
#include "ui_window.h"
#include <QPainter>
#include <QTimer>

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window),player(500,500),
    _background(":/background/image/map/1.png")
{
    ui->setupUi(this);
    setMouseTracking(true);
    QObject::startTimer(20);
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x()<player.getX())
        player.react(Princess::Lstand);
    else
        player.react(Princess::Rstand);
}


void Window::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        player.setDestination(event->pos());
        player.react(Princess::Move);
    }
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(),_background);
    player.draw(painter);
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        player.react(Princess::Longattack);
}
Window::~Window()
{
    delete ui;
}
