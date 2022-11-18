// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Piarte.h

#ifndef PIRATE_H 
#define PIRATE_H

#include <iostream>
using namespace std;

class Pirate{
    private:
        int strength;
        int postionR;
        int postionC;
        bool beenFound;
    public:
        Pirate();
        Pirate(int strength, int postionR, int postionC);

        int getStrength();
        
        void setPR(int r);
        int getPR();

        void setPC(int c);
        int getPC();

        void wasFound();
        bool getBeenFound();

};
#endif