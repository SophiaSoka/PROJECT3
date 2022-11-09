#ifndef BOARD_H 
#define BOARD_H

#include <iostream>
#include <vector>
#include "Button.h"
#include "Pirate.h"
#include "Trap.h"
using namespace std;

//ICON CODE WEBSITE 

class Board{
    private:
        Trap list_Of_Traps[5];
        Pirate list_Of_Pirates[10];
        int const boardSize;
        Button buttons[12][];
    public:
        Board();
        Board(int size);
        Button[][] getList();

        void addPirates(int numOfPirates);
        void trueValue(int x, int y);
        void explode(int x, int y);

};
#endif