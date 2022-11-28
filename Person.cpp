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
Person::Person(int t, int n){
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
int Person::getName(){
    return name;
}
void Person::setName(){
    name = n;
}
