// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Button.cpp

#ifndef PLAYER_H 
#define PLAYER_H

#include <iostream>
#include "Trap.h"

using namespace std;

class Player{
    private:
        int strength;
        string weapon;
        int lives;
        int num_hints;
        
    public:
        Player();
        Player(int lives, string weapon, int hints);

        void reduceStrength(int takeAwayStrength);
        int getStrength();

        void removeWeapon();
        string getWeapons();

        void setLives(int lives);
        int getLives();

        void setNumHints(int hints);
        int getNumHints();

};
#endif
