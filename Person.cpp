#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

// default constructor to set the initial values of time and name
Person::Person(){
    time = 0;
    name = "";
}

// Here we declared the variables using t and n to have them hold values
Person::Person(int t, string n){
    time = t;
    name = n;
}

// We used getters to retrieve the data
// We used setters to read the data
int Person::getTime(){
    return time;
}
void Person::setTime(){
    time = t;
}
string Person::getName(){
    return name;
}
void Person::setName(){
    name = n;
}