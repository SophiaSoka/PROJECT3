#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
using namespace std;

class Person(){
    // We had to declare the variables in the private
    private:
        string name;
        int time;
    // We used getters to retrieve the data
    // We used setters to read the data
    // We declared a vector in the public to hold the players for the leaderboard
    public:
        Person(); // default constructor
        Person(string name, int time); // constructor with parameters

        vector<person> leaderboard;

        void setName(string name);
        string getName();

        void setTime(int time);
        int getTime();
};
#endif