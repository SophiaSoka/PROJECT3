#include "Trap.h"

using namespace std;

// default constructor to set the initial values equal to empty and false
Trap::Trap(){
    riddle = "";
    answer = "";
    hint = "";
    hasFound = false;
    solved = false;
}
// Here, we had to declare all of my variables as their type
// This was used to organize the information
Trap::Trap(string text, string ans, string h){
    riddle = text;
    answer = ans;
    hint = h;
    hasFound = false;
    solved = false;
}
// We used getters and setters to retrieve the data from the h files we made
// We had to return the variables in the getters, and set them equal to a value in the setters
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
