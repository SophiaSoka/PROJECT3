// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Trap.cpp
#include "Trap.h"

using namespace std;

Trap:: Trap(){
    riddle = "";
    answer = "";
    hint = "";
    hasFound = false;
    solved = false;
}
Trap:: Trap(string text, string ans, string h){
    riddle = text;
    answer = ans;
    hint = h;
    hasFound = false;
    solved = false;
}

string Trap::getRiddle(){
    return riddle;
}
void Trap::setRiddle(string new_riddle){
    riddle = new_riddle;
}

string Trap::getAnswer(){
    return answer;
}
void Trap:: setAnswer(string new_answer){
    answer = new_answer;
}

string Trap::getHint(){
    return hint;
}
void Trap::setHint(string new_hint){
    hint = new_hint;
}

bool Trap::getFound(){
    return hasFound;
}
void Trap::wasFound(){
    hasFound = true;
}

bool Trap::getSolved(){
    return solved;
}
void Trap::wasSolved(){
    solved = true;
}