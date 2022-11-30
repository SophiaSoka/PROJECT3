// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Pirate.h

#ifndef PIRATE_H 
#define PIRATE_H

#include <iostream>
using namespace std;

class Pirate{
    // We had to declare the variables we declared prior as a public so they could be manipulated
    // We set some variables as getters to retrieve a variable's value
    // We set the other variables as setters to set the variables as void, so they will not return
    private:
        int strength;
        int positionR;
        int positionC;
        bool beenFound;
    public:
        // We used getters to retrieve the data
        // We used setters to read the data
        // Declared the variables inside the parameter
        Pirate(); // default constructor
        Pirate(int strength, int positionR, int positionC); // constructor with parameters

        int getStrength();
        
        void setPR(int r);
        int getPR();

        void setPC(int c);
        int getPC();

        void wasFound();
        bool getBeenFound();

};
#endif
