// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Pirate.cpp

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
// Here, we had to declare all of the variables as their type with the new name to hold a value
// This was used to organize our data
Pirate::Pirate(int s, int r, int c)
{
    strength = s;
    positionR = r;
    positionC = c;
    beenFound = false;
}
// We used getters to retrieve our data
// We used setters here to read the data from files
// We also used a separate declaration to state whether or not beenfound held true
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