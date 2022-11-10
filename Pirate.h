#ifndef PIRATE_H 
#define PIRATE_H

#include <iostream>
#include "Player.h"
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
