// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Trap.h
#ifndef TRAP_H
#define TRAP_H

#include <iostream>
#include <vector>
using namespace std;

class Trap{
    private:
        string riddle;
        string answer;
        string hint;
        bool hasFound;
        bool solved;
    public:
        Trap();
        Trap(string text, string answer, string hint);
        
        string getRiddle();
        void setRiddle(string new_riddle);

        string getAnswer();
        void setAnswer(string new_answer);

        string getHint();
        void setHint(string new_hint);

        bool getFound();
        void wasFound();

        bool getSolved();
        void wasSolved();

};
#endif