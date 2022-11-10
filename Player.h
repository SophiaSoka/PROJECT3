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
