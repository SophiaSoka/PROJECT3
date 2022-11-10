#include "Player.h"

using namespace std;

Player:: Player (){
    strength = 100;
    lives = 1;
    weapon = "";
    num_hints = 0;
}
Player:: Player(int lives, string weapon, int hint){
    strength = 100;
    lives = lives;
    weapon = weapon;
    num_hints = hint;
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

void Player:: setNumHints(int h){
    num_hints = h;
}
int Player:: getNumHints(){
    return num_hints;
}
