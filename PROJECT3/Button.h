// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Button.h

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
using namespace std;

class Button{
    private:
        bool clicked;
        int value;
        int r;
        int c;
        
    public:
        Button(); //defalut constructor
        Button(int row, int coloum); //constructor 
        //based on value of the button, it returns the corresponding picture
        string revealIcon(int value);

        //getters and setters 
        void isClicked();
        bool getClicked();

        void setValue(int value);
        int getValue();

        void setR(int row);
        int getR();

        void setC(int coloum);
        int getC();

};
#endif