#ifndef PLAYER_H 
#define PLAYER_H

#include <iostream>
#include <vector>
using namespace std;

class Player{
    private:
        int strength;
        string weapon;
        int lives;
        vector<string> hints;
        int currentRow;
        int currentColoum;
    public:
        Player();
        Player(int lives, string weapon, int hints);

        void reduceStrength(int takeAwayStrength);
        int getStrength();

        void removeWeapon(string nameOfWeapon);
        string getWeapons();

        void setLives(int lives);
        int getLives();

        vector<string> getHints();

        void setCurrentRow(int r); //maybe boolean 
        int getCurrentRow();

        void setCurrentColoum(int c); //maybe boolean 
        int getCurrentRow();

};
#endif