#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

// default constructor to set the initial values of time and name
Person::Person(){
    moves = 0;
    name = "";
}

// Here we declared the variables using t and n to have them hold values
Person::Person(int m, string n){
    moves = t;
    name = n;
}

// We used getters to retrieve the data
// We used setters to read the data
int Person::getMoves(){
    return moves;
}
void Person::setMoves(int m){
    moves = m;
}
string Person::getName(){
    return name;
}
void Person::setName(string n){
    name = n;
}
