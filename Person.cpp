// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Person.cpp

#include <fstream>
#include <iostream>
#include "Person.h"
using namespace std;

// default constructor to set the initial values of time and name
Person::Person(){
    moves = 0;
    name = "";
}

// Here we declared the variables using t and n to have them hold values
Person::Person(string n, int m){
    moves = m;
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
