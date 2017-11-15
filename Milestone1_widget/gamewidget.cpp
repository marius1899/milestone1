#include "gamewidget.h"
#include "qpainter.h"
#include "iostream"
#include "QMouseEvent"
#include "stdlib.h"
#include "math.h"

using namespace std;



Gamewidget::Gamewidget(QWidget *parent) : QWidget(parent)
{
    test = new CAbase(50,50);
    test->show();

    anz_x = test->get_width(); // anzahl der Kästchen nach rechts
    anz_y = test->get_height(); // anzahl der Kästchen nach links

    //width1 = width();
    //height1 = height();
    cout << "höhe widget " <<height() << endl;
    cout << "weite widget " <<width() << endl;

}

void Gamewidget::paintEvent(QPaintEvent *event){

    width1 = width();
height1 = height();
    breite =(double) width()/(anz_x); // breite der Kästchen
    hoehe = (double) height()/(anz_y); // höhe der Kästchen


    QPainter p(this);

    QRect borders(0, 0,width()-1, height()-1);
    p.drawRect(borders);

    QRect *rect;

    cout << "höhe paint " <<height() << endl;
    cout << "weite paint " <<width() << endl;
cout << "höhe rechne" << anz_y*hoehe << endl;
cout << "breite rechne" << anz_x *breite << endl;

cout << "anzahl x " << anz_x <<endl;
cout << "anzahl y " << anz_y<<endl;

cout <<"breite "<< breite <<endl;
cout << "höhe "<<hoehe << endl;

    for (int i =0; i<anz_x-1; i++){
        for (int j=0; j<anz_y-1; j++){
            if (test->get_current_cell(i,j)){

                rect = new QRect(i*breite,j*hoehe, breite, hoehe);
                p.fillRect(*rect, QBrush(Qt::black));
            }

        }
    }
//    for (int i =0; i<anz_y; i+=2){
//        rect = new QRect(0,i*hoehe, breite, hoehe);
//        p.fillRect(*rect, QBrush(Qt::black));
//    }
      QColor gridColor = "gray";
      gridColor.setAlpha(30);
    p.setPen(gridColor);


    for(double i = breite; i <= (double) width1; i += breite){
        p.drawLine(i, 0, i, height1);
    }

    for(double i = hoehe; i <= height1; i += hoehe){
        p.drawLine(0, i, width1, i);

    }

}

void Gamewidget::mousePressEvent(QMouseEvent *e){
    //emit environmentChanged(true);
    breite = (double) floor((width1)/(anz_x)); // breite der Kästchen
    hoehe = (double) floor((height1)/(anz_y)); // höhe der Kästchen


    cout << "höhe mouse " <<height() << endl;
    cout << "weite mouse " <<width() << endl;


    e->Paint;

    int k = (double) floor(e->y()/hoehe);
    int j = (double) floor(e->x()/breite);
    QPainter p(this);
    QRect *rect;
cout << "(x,y) = " << "(" <<  k << ", "<< j << ") "<< endl;

if (test->get_current_cell(j,k)){
    test->set_current_cell(j,k,0);
} else {
    test->set_current_cell(j,k,1);

}


   // rect = new QRect(j*breite,k*hoehe, breite, hoehe);

    //p.fillRect(*rect, QBrush(Qt::black));

    update();




    //universe[k*universeSize + j] = !universe[k*universeSize + j];
    //update();
}
