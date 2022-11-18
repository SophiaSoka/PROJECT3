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
    postionR = 0;
    postionC = 0;
    beenFound = false;
}
// Here, we had to declare all of my variables as their type
// This was used to organize the information
Pirate::Pirate(int s, int r, int c)
{
    strength = s;
    postionR = r;
    postionC = c;
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
    return postionR;
}
void Pirate::setPR(int r)
{
    postionR = r;
}
int Pirate::getPC()
{
    return postionC;
}
void Pirate::setPC(int c)
{
    postionC = c;
}
bool Pirate::getBeenFound()
{
    return beenFound;
}
void Pirate::wasFound()
{
    beenFound = true;
}