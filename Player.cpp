#include "Player.h"

using namespace std;

Player:: Player (){
    strength = 100;
    lives = 1;
    weapon = "";
    hints = 0;
}
Player:: Player(int lives, string weapon, int hint){
    strength = 100;
    lives = lives;
    weapon = weapon;
    hints = hint;
}

void Player:: reduceStrength(int takeAwayStrength){
    strength = strength - takeAwayStrength;
}
int Player::getStrength(){
    return strength;
}

void Player:: removeWeapon(){
    weapon = "";
}
string Player:: getWeapons(){
    return weapon;
}

void Player:: setLives(int l){
    lives = l;
}
int Player:: getLives(){
    return lives;
}

void Player:: setHints(int h){
    hints = h;
}
int Player:: getHints(){
    return hints;
}
