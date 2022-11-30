// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Button.cpp

#include <iostream>
#include "Button.h"

// We had to set the variables equal to zero and the bool equal to false
Button::Button(){ //defalut constructor 
    clicked = false;
    value = 0;
    r = 0;
    c = 0;
}
// declared the variables in the constructor and used row and column to hold values
Button::Button(int row, int coloum){ //constructor
    clicked = false;
    value = 0;
    r = row;
    c = coloum;
}

// used a switch statement to return pictures based on button value 
// depending on the value, the map will output a specific color or emoji through the switch statement
string Button::revealIcon(int value){ 
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

// We used setters to read the data
// We used getters to retrive the data
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

// we have to use an if statement in this setter to create a boundary between 0 and 12 with the rows
void Button::setR(int row){
    if (row >= 0 || row < 12){
        r = row;
    }
}
int Button::getR(){
    return r;
}

// we had to use an if statement in this setter to create a boundary between 0 and 112 with the columns
void Button::setC(int col){
    if (col >= 0 || col < 12){
        c = col;
    }
}

int Button::getC(){
    return c;
}