#include "cabase.h"
#include <iostream>

using namespace std;

CAbase::CAbase(int x, int y)
{
    Nx = x;
    Ny = y;

    current = new bool [Nx * Ny];
    next = new bool [Nx * Ny];

    for (int i=0; i< Nx*Ny; i++){
        current[i] = 0;
        next[i] = 0;
    }


}


CAbase::~CAbase(){
    delete [] current;
    delete [] next;
}

void CAbase::set_current_cell(int x,int y, bool value){
    if ((x < Nx) && (y < Ny)){
        int pos = Nx * y + x;
        current[pos] = value;
    }

}

bool CAbase::get_current_cell(int x,int y){
    if ((x < Nx) && (y < Ny)){
        int pos = Nx * y + x;

        bool value = current[pos];
        return value;
    } else {
        return 0;
    }
}


void CAbase::set_next_cell(int x,int y, bool value){
    if ((x < Nx) && (y < Ny)){
        int pos = Nx * y + x;
        next[pos] = value;
    }

}

bool CAbase::get_next_cell(int x,int y){
    if ((x < Nx) && (y < Ny)){
        int pos = Nx * y + x;
        bool value = next[pos];
        return value;
    } else {
        return 0;
    }
}


bool CAbase::get_top(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (y == 0){
            return get_current_cell(x, Ny - 1);
        }
        else {
            return get_current_cell(x, y - 1);
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_right(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (x == (Nx - 1)){
            return get_current_cell(0,y);
        }
        else {
            return get_current_cell(x + 1,y);
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_bottom(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (y == (Ny - 1)){
            return get_current_cell(x,0);
        }
        else {
            return get_current_cell(x,y + 1);
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_left(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (x == 0){
            return get_current_cell(Nx - 1,y);
        }
        else {
            return get_current_cell(x - 1,y);
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_top_right(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (y == 0){
            if (x == Nx-1){
                return get_current_cell(0,Ny-1);
            } else {
                return get_current_cell(x+1, Ny-1);
            }
        } else {
            if (x == Nx-1){
                return get_current_cell(0,y-1);
            } else {
                return get_current_cell(x+1,y-1);
            }
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_bottom_right(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (y == Ny-1){
            if (x == Nx-1){
                return get_current_cell(0,0);
            } else {
                return get_current_cell(x + 1,0);
            }
        } else {
            if (x == Nx-1){
                return get_current_cell(0, y+1);
            } else {
                return get_current_cell(x+1, y+1);
            }
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_top_left(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (y == 0){
            if (x == 0){
                return get_current_cell(Nx-1,Ny-1);
            } else {
                return get_current_cell(x-1, Ny-1);
            }
        } else {
            if (x == 0){
                return get_current_cell(Nx-1,y-1);
            } else {
                return get_current_cell(x-1,y-1);
            }
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}

bool CAbase::get_bottom_left(int x, int y){
    if ((x < Nx) && (y < Ny)){

        if (y == Ny -1){
            if (x == 0){
                return get_current_cell(Nx-1,0);
            } else {
                return get_current_cell(x-1, 0);
            }
        } else {
            if (x == 0){
                return get_current_cell(Nx-1,y+1);
            } else {
                return get_current_cell(x-1,y+1);
            }
        }

    } else { // falls Fehler bei Eingabe der Koordinaten
        return 0;
    }

}



void CAbase::next_generation(){


    for (int y = 0; y < Ny; y++){
        for (int x = 0; x < Nx; x++){
            int alive = get_current_cell(x,y);
            int neighbors = count_alive_neighbors(x,y);

            set_next_cell(x,y,0);

            if (((alive == 1) && (neighbors == 2)) || ((alive == 1) && (neighbors == 3))){
                set_next_cell(x,y,1);
            }

            if ((alive == 0) && (neighbors == 3)){
                set_next_cell(x,y,1);
            }
        }
    }


    for (int y = 0; y< Ny; y++){
        for (int x = 0; x < Nx; x++){
            set_current_cell(x,y, (get_next_cell(x,y)));
        }
    }



}



int CAbase::count_alive_neighbors(int x, int y){

    int count = 0;

    count += get_top(x,y);
    count += get_right(x,y);
    count += get_bottom(x,y);
    count += get_left(x,y);
    count += get_top_left(x,y);
    count += get_top_right(x,y);
    count += get_bottom_left(x,y);
    count += get_bottom_right(x,y);

    return count;
}


void CAbase::show(){
    for (int i = 0; i< Nx+2; i++){
        cout << "° " ; // RAND
    }

    cout << endl;

    for (int y= 0; y < Ny; y++){
        cout << "° ";
        for (int x = 0; x< Nx; x++){
            if (get_current_cell(x,y)){
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "° " << endl;
    }

    for (int i = 0; i< Nx+2; i++){
        cout << "° " ; // RAND
    }
    cout << endl;
}


void CAbase::set_height(int y){
    Ny = y;
    delete [] current;
    delete [] next;
    current = new bool [Nx * Ny];
    next = new bool [Nx * Ny];

    for (int i=0; i< Nx*Ny; i++){
        current[i] = 0;
        next[i] = 0;
    }

}

void CAbase::set_width(int x){
    Nx = x;
    delete [] current;
    delete [] next;


    current = new bool [Nx * Ny];
    next = new bool [Nx * Ny];


    for (int i=0; i< Nx*Ny; i++){
        current[i] = 0;
        next[i] = 0;
    }
}

int CAbase::get_height(){
    return Ny;
}

int CAbase::get_width(){
    return Nx;
}

