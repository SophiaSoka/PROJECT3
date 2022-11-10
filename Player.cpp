// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Button.cpp

#include "Player.h"

using namespace std;

Player::Player (){     //defalut constructor 
    strength = 100;
    lives = 1;
    weapon = "";
    num_hints = 0;
}
Player::Player(int lives, string weapon, int hint){  //constructor
    strength = 100;
    lives = lives;
    weapon = weapon;
    num_hints = hint;
}

//getters and setters 
void Player::reduceStrength(int takeAwayStrength){
    strength = strength - takeAwayStrength;
}
int Player::getStrength(){
    return strength;
}

void Player::removeWeapon(){
    weapon = "";
}
string Player::getWeapons(){
    return weapon;
}

void Player::setLives(int l){
    lives = l;
}
int Player::getLives(){
    return lives;
}

void Player::setNumHints(int h){
    num_hints = h;
}
int Player::getNumHints(){
    return num_hints;
}
