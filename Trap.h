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
