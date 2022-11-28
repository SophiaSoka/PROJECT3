#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

// default constructor to set the initial values of time and name
Person::Person(){
    time = 0;
    name = "";
}

// Here I declared the variables as different names to store them
Person::Person(string n, int t){
    time = t;
    name = n;
}

// We used getters to retrieve the data
// We used setters to read the data
int Person::getTime(){
    return time;
}
void Person::setTime(int t){
    time = t;
}
string Person::getName(){
    return name;
}
void Person::setName(string n){
    name = n;
}
