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
        Button();
        Button(int row, int coloum);
        //based on value of the button, it changes the Icon or pisture revelaed when the button is clicked
        string revealIcon(int value);
        //shows message that you've won or lost the game 
        void endGame(string result);

        void isClicked();
        bool getClicked();

        void setValue(int value);
        int getValue();

        void setR(int row);
        int getR();

        void setC(int coloum);
        int getC();

        void setIcon();
        string getIcon(string icon);
};
#endif