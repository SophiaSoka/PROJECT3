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
        bool hasSolved;

    public:
        Trap();
        Trap(string text, string answer, string hint);

        void readTraps(string filename);


};
#endif