#ifndef PIRATE_H 
#define PIRATE_H

#include <iostream>
using namespace std;

class Pirate{
    // We had to declare the variables we declared prior as a public so they could be manipulated by anyone 
    // We set some variables as getters to retrieve a variable's value
    // We set the other variables as setters to set the variables value in my function and these are voided, so they will not return
    private:
        int strength;
        int positionR;
        int positionC;
        bool beenFound;
    public:
        // We used getters and setters in our h file
        // Declared the variables inside the parameter
        Pirate(); // default constructor
        Pirate(int strength, int positionR, int positionC);

        int getStrength();
        
        void setPR(int r);
        int getPR();

        void setPC(int c);
        int getPC();

        void wasFound();
        bool getBeenFound();

};
#endif
