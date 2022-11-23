#include "Player.h"
#include "Map.h"
#include "Button.h"
#include <iostream>
using namespace std;

int main(){
    char level;
    cout << "Welcome to Matty and Sophia's Final Project for CSCI1300!" << endl;
    Map map;
    bool inLoop = true;
    while(inLoop){
        cout << "Please choose your difficulty level (1,2,3)" << endl;
        cin >> level;
        if(level == '1'){
            map.addAllTraps(5);
            map.addAllPirates(10);
            inLoop = false;
        }
        else if(level == '2'){
            map.addAllTraps(5);
            map.addAllPirates(15);
            inLoop = false;
        }
        else if(level == '3'){
            map.addAllTraps(5);
            map.addAllPirates(20);
            inLoop = false;
        }
        else{
            cout << "Invalid Input." << endl;
        }
    }

    //PRINTS INSTRUCTIONS FOR THE GAME 

    //MR.MERCHANT DO YOUR THING HERE 
   
    int input;
    int weapon;
    int hint;
    int extra_life;
    cout << "Mr. Jones, it is good to see you again. Have you come back for more supplies?" << endl;
    cout << "Choose one of the following:" << endl;
    cout << "1.) Weapons: You will need a weapon to fight the pirates along your journey" << endl;
    cout << "2.) Hints: In your journey, there will be riddles you will need to solve in order to not get killed from a boobytrap." << endl;
    cout << "3.) Extra-life: You may need an extra-life if you are unable to solve a riddle or fight a pirate." << endl;
    cin >> input;
    cout << endl;
    if(input == 1)
    {
        cout << "There are a couple of different weapon options, each has the same damage level though." << endl;

        cout << "Choose one of the following:" << endl;
        cout << "1.) Sword (50 damage) (20 coins)" << endl;
        cout << "2.) Hatchet (50 damage) (20 coins)" << endl;
        cout << "3.) Machete (50 damage) (20 coins)" << endl;
        cout << "4.) Input 4 if you want to cancel" << endl;
        cin >> weapon;
        if(weapon == 1)
        {
            cout << "Acquired sword (50 damage)." << endl;
        }
        if(weapon == 2)
        {
            cout << "Acquired hatchet (50 damage)." << endl;
        }
        if(weapon == 3)
        {
            cout << "Acquired Machete (50 damage)." << endl;
        }
        if(weapon == 4)
        {
            cout << "Cancel." << endl;
        }
    }
    if(input == 2)
    {
        cout << "There are five different hints for the riddles in the game which if answered correctly will give you the keys." << endl;
        cout << "1.) Input 1 if you want to receive hints." << endl;
        cout << "2.) Input 2 if you want to cancel." << endl;
        cin >> hint;
        if(hint == 1)
        {
            cout << "Hints:" << endl;
            cout << "1.) Think about the high sea during a storm..." << endl;
            cout << "2.) Most pirates say aarrr matey" << endl;
            cout << "3.) Where do you put a ship when you are done using it" << endl;
            cout << "4.) Pirates tend to get lost here" << endl;
            cout << "5.) A pirate is known for saying this when frustrated" << endl;
        }
        if(hint == 2)
        {
            cout << "Cancel." << endl;
        }

    }
    if(input == 3)
    {
        cout << "You have the option of receiving an extra-life in case you run into a pirate without a weapon or fail to answer a riddle correctly." << endl;
        cout << "1.) One extra-life." << endl;
        cout << "2.) Input 2 if you want to cancel." << endl;
        cin >> extra_life;
        if(extra_life == 1)
        {
            cout << "Acquired extra life." << endl;
        }
        if(extra_life == 2)
        {
            cout << "Cancel." << endl;
        }
    }

    //player will have parameters onec merchant is written 
    //Player player(lives, weapon, hints);
    Player player; 
    bool playing = true;
    int command;
    while (playing){
        cout << "======Main Menu=====" << endl;
        cout << "1. Move Player" << endl;
        cout << "2. Show Inventory" << endl;
        cout << "3. Display Board" << endl;
        cout << "4. Display Leaderboard" << endl;
        cout << "5. Quit" << endl;
        cin >> command;
        switch (command){
            case 1:
                int moves;
                bool flag;
                flag = true;
                cout << "How many times would you like to move before seeing this menu again?" << endl;
                cin >> moves;
                while (flag){
                    if(moves < 1 || moves > 100){
                        cout << "Invalid Input. Please enter a number between 1 and 100" << endl;
                        cin >> moves;
                    }
                    else{
                        flag = false;
                    }
                }
                char dir;
                for(int i = 0; i < moves; i++){
                    cout << "Enter which way you want to move (w,a,s,d)" << endl;
                    cin >> dir;
                    map.move(dir);     //There is an infinite loop if you enter more letters than int moves at once 
                    map.displayMap();
                }
                break;
            case 2:
                player.printInventory(); 
                break;
            case 3:
                map.displayMap();
                break;
            case 4:
                //print leader board
                break;
            case 5:
                cout << "Thanks for playing, see you again soon!" << endl;
                return 0;
            default:
                cout << "Invalid Input. Please enter a number 1 through 5" << endl; 
                break;
        }
    }
    /*
    char dir;
    for(int i = 0; i < 100; i++){
        cout << "enter which way you want to move (w,a,s,d)" << endl;
        cin >> dir;
        map.move(dir);
        map.displayMap();
    }
    */
    return 0;

}
