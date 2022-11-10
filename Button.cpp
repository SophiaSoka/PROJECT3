#include <iostream>
#include "Button.h"

Button::Button(){ //defalut constructor 
    clicked = false;
    value = 0;
    r = 0;
    c = 0;
}
Button::Button(int row, int coloum){ //constructor
    clicked = false;
    value = 0;
    r = row;
    c = coloum;
}

string Button::revealIcon(int value){ //returns picture based on button value 
    switch (value){
        case 0:
            return "🟦";
        case 1:
            return "🟩";
        case 2:
            return  "🟨";
        case 3:
            return "🟧";
        case 4:
            return "🟥";
        case 5:
            return "🟪";
        case 10: // if pirate
            return "💀";
        case 11: // if trap
            return "📜";
        default:
            return "  ";
    }
}

//getters and setters
void Button::isClicked(){
    clicked = true;
}
bool Button::getClicked(){
    return clicked;
}

void Button::setValue(int v){
    value = v;
}
int Button::getValue(){
    return value;
}

void Button::setR(int row){
    if (row >= 0 || row < 12){
        r = row;
    }
}
int Button::getR(){
    return r;
}

void Button::setC(int col){
    if (col >= 0 || col < 12){
        c = col;
    }
}

int Button::getC(){
    return c;
}
