#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
    // We had to declare the variables in the private
    private:
        string name;
        int time;
    // We used getters to retrieve the data
    // We used setters to read the data
    public:
        Person();
        Person(string name, int time);

        vector<Person> leaderboard;

        void setName(int name);
        int getName();

        void setTime(int time);
        int getTime();
};
#endif
