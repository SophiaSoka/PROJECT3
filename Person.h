#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
using namespace std;

class Person(){
    // We had to declare the variables in the private
    private:
        int name;
        int time;
    // We used getters to retrieve the data
    // We used setters to read the data
    public:
        Person();
        Person(int name, int time);

        vector<person> leaderboard;

        void setName(int name);
        int getName();

        void setTime(int time);
        int getTime();
};
#endif
