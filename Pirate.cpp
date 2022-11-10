#include <iostream>
#include <fstream>
#include "Pirate.h"

using namespace std;

// default constructor to set the initial values equal to 50, 0, and false
Pirate::Pirate()
{
    strength = 50;
    positionR = 0;
    positionC = 0;
    beenFound = false;
}
// Here, we had to declare all of my variables as their type
// This was used to organize the information
Pirate::Pirate(int s, int r, int c)
{
    strength = s;
    positionR = r;
    positionC = c;
    beenFound = false;
}
// We used getters and setters to retrieve the data from the h files we made
// We had to return the variables in the getters, and set them equal to a value in the setters
int Pirate::getStrength()
{
    return strength;
}
int Pirate::getPR()
{
    return positionR;
}
void Pirate::setPR(int r)
{
    positionR = r;
}
int Pirate::getPC()
{
    return positionC;
}
void Pirate::setPC(int c)
{
    positionC = c;
}
bool Pirate::getBeenFound()
{
    return beenFound;
}
void Pirate::wasFound()
{
    beenFound = true;
}
