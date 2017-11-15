#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "cabase.h"

class Gamewidget : public QWidget
{
    Q_OBJECT
public:
    explicit Gamewidget(QWidget *parent);
    void paintEvent(QPaintEvent *event);
    void  mousePressEvent(QMouseEvent *e);

private:
    double breite;
    double hoehe;
    CAbase *test;

    double width1, height1;

    int anz_x, anz_y;

signals:

public slots:


};

#endif // GAMEWIDGET_H
