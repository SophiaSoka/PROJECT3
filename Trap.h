#ifndef TRAP_H
#define TRAP_H

#include <iostream>
#include <vector>
using namespace std;

class Trap{
    // We had to declare the variables we declared prior as a public so they could be manipulated by anyone 
    // We set the other variables as setters to set the variables value in my function and these are voided, so they will not return
    private:
        string riddle;
        string answer;
        string hint;
        bool hasFound;
        bool solved;
    public:
        // We used getters and setters in our h file
        // Declared the variables inside the parameter
        Trap(); // default constructor
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
