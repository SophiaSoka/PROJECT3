// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person{
    // We had to declare the variables in the private
    private:
        string name;
        int moves;
    // We used getters to retrieve the data
    // We used setters to read the data
    // We declared a vector in the public to hold the players for the leaderboard
    public:
        Person(); // default constructor
        Person(string name, int moves); // constructor with parameters

        void setName(string name);
        string getName();

        void setMoves(int moves);
        int getMoves();
};
#endif
