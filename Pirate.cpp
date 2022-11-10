#include <iostream>
#include <fstream>
#include "Pirate.h"

using namespace std;

Pirate::Pirate()
{
    strength = 50;
    positionR = 0;
    positionC = 0;
    beenFound = false;
}

Pirate::Pirate(int s, int r, int c)
{
    strength = s;
    positionR = r;
    positionC = c;
    beenFound = false;
}

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
