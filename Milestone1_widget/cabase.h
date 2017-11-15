#ifndef CABASE_H
#define CABASE_H
#include <string>

using namespace std;


class CAbase
{
public:
    CAbase(int x, int y);

    ~CAbase();


public:
    void set_current_cell(int x,int y, bool value);
    bool get_current_cell(int x,int y);

    void set_next_cell(int x,int y, bool value);
    bool get_next_cell(int x,int y);


    void set_width(int x);
    void set_height(int y);

    int get_width();
    int get_height();


    void show();


    void next_generation();


private:
    int Nx, Ny; //Größe des Universums
    bool* current; // aktuelles Universum
    bool* next; // nächster Schritt


    //gibt jeweils für jeden Nachbar aus ob lebendig oder tot
    bool get_top(int x, int y);
    bool get_top_right(int x, int y);
    bool get_right(int x, int y);
    bool get_bottom_right(int x, int y);
    bool get_bottom(int x, int y);
    bool get_bottom_left(int x, int y);
    bool get_left(int x, int y);
    bool get_top_left(int x, int y);
    int count_alive_neighbors(int x, int y); // zählt lebendige Nachbarn des Feldes

};

#endif // CABASE_H
