#include "Trap.h"

using namespace std;

Trap::Trap(){
    riddle = "";
    answer = "";
    hint = "";
    hasFound = false;
    solved = false;
}
Trap::Trap(string text, string ans, string h){
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
void Trap::setAnswer(string new_answer){
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
