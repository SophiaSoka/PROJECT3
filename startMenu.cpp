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
            map.readAndAddTraps("riddle.txt");
            map.addAllPirates(10);
            inLoop = false;
        }
        else if(level == '2'){
            map.readAndAddTraps("riddle.txt");
            map.addAllPirates(15);
            inLoop = false;
        }
        else if(level == '3'){
            map.readAndAddTraps("riddle.txt");
            map.addAllPirates(20);
            inLoop = false;
        }
        else{
            cout << "Invalid Input." << endl;
        }
    }

    //PRINTS INSTRUCTIONS FOR THE GAME 
    
    //MR.MERCHANT DO YOUR THING HERE 
    int coins = 100;
    string str_input;
    int input;
    int weapon;
    string name_of_weapon;
    int hint;
    int total_hints = 0;
    int extra_life;
    int total_lives = 1;
    cout << "Mr. Jones, it is good to see you again. Have you come for more supplies?" << endl;
    while(coins >= 20){
        cout << endl;
        cout << "You have " << coins << " coins in the bank" << endl;
        cout << "Choose one of the following:" << endl;
        cout << "1.) Weapons(20 coins): You will need a weapon to fight the pirates along your journey" << endl;
        cout << "2.) Hints:(30 coins) In your journey, there will be riddles you will need to solve in order to not get killed from a boobytrap." << endl;
        cout << "3.) Extra-life(50 coins): You may need an extra-life if you are unable to solve a riddle or fight a pirate." << endl;
        cin >> input;
        cout << endl;
        
        if(input == 1)
        {
            if(coins >= 20){
                cout << "There are a couple of different weapon options, each has the same damage level though." << endl;
                cout << "Choose one of the following:" << endl;
                cout << "1.) Sword (50 damage) (20 coins)" << endl;
                cout << "2.) Hatchet (50 damage) (20 coins)" << endl;
                cout << "3.) Machete (50 damage) (20 coins)" << endl;
                cout << "4.) Input 4 if you want to cancel" << endl;
                cin >> weapon;
                if(weapon == 1)
                {
                    coins -= 20;
                    name_of_weapon = "sword";
                    cout << "Acquired sword (50 damage)." << endl;
                }
                else if(weapon == 2)
                {
                    coins -= 20;
                    name_of_weapon = "hatchet";
                    cout << "Acquired hatchet (50 damage)." << endl;
                }
                else if(weapon == 3)
                {
                    coins -= 20;
                    name_of_weapon = "machete";
                    cout << "Acquired Machete (50 damage)." << endl;
                }
                else if(weapon == 4)
                {
                    name_of_weapon = "";
                    cout << "Canceled." << endl;
                }
            }else{
                cout << "It doesn't look like you have enough coins to buy a weapon!" << endl;
            }
            
        }
        else if(input == 2)
        {
            if (coins >= 30){
                cout << "There are five different hints for the riddles in the game which if answered correctly will give you the keys." << endl;
                cout << "1.) Input 1 if you want to receive hints." << endl;
                cout << "2.) Input 2 if you want to cancel." << endl;
                cin >> hint;
                if(hint == 1)
                {
                    coins -= 30;
                    total_hints ++;
                    //cout << "Hints:" << endl;
                    //cout << "1.) Think about the high sea during a storm..." << endl;
                    //cout << "2.) Most pirates say aarrr matey" << endl;
                    //cout << "3.) Where do you put a ship when you are done using it" << endl;
                    //cout << "4.) Pirates tend to get lost here" << endl;
                    //cout << "5.) A pirate is known for saying this when frustrated" << endl;
                }
                else if(hint == 2)
                {
                    hint = 0;
                    cout << "Cancel." << endl;
                }
            }
            else{
                cout << "It doesn't look like you have enough coins for a hint" << endl;
            }

        }
        else if(input == 3)
        {
            if (coins >= 50){
                cout << "You have the option of receiving an extra-life in case you run into a pirate without a weapon or fail to answer a riddle correctly." << endl;
                cout << "1.) One extra-life." << endl;
                cout << "2.) Input 2 if you want to cancel." << endl;
                cin >> extra_life;
                if(extra_life == 1)
                {
                    total_lives ++;
                    coins -= 50;
                    cout << "Acquired extra life." << endl;
                }
                else if(extra_life == 2)
                {
                    cout << "Cancel." << endl;
                }
            }
            else{
                cout << "It doesn't look like you have enough coins to buy an extra life" << endl;
            }
        }
        else{
            cout << "Invalid input. Please enter a number 1, 2 or 3" << endl;
        }
    }
    
    //player will have parameters onec merchant is written 
    //Player p = Player();
    Player p = Player(total_lives, name_of_weapon, total_hints); ;
 
    int traps_found = 0;
    int pirates_found = 0;
    //cout << map.getTrapsCount() << endl;
    //cout << map.readTraps("riddle.txt") << endl;
    //cout << "Riddle: " << map.getTrapAt(traps_found).getRiddle() << endl;
    //cout << "Answer: " << map.getTrapAt(traps_found).getAnswer() << endl;
    //cout << "Hint: " << map.getTrapAt(traps_found).getHint() << endl;
    //cout << map.getTrapsCount() << endl;
    int return_val;
    //bool playing = true;
    string str_command;
    char command;
    while (p.getStrength() > 0 && p.getLives() > 0){
        cout << "======Main Menu=====" << endl;
        cout << "1. Move Player" << endl;
        cout << "2. Show Inventory" << endl;
        cout << "3. Display Board" << endl;
        cout << "4. Display Leaderboard" << endl;
        cout << "5. Quit" << endl;
        cin >> str_command;
        if(str_command.length() == 1){
            command = str_command[0];
        }
        else{
            cout << "Invalid Input." << endl;
        }
        switch (command){
            case '1':
                int moves;
                bool flag;
                flag = true;
                cout << "How many times would you like to move before seeing this menu again?" << endl;
                cin >> moves;
                while (flag){
                    if(moves < 1 || moves > 100){
                        //infinite loop when you plug in something wrong 
                        cout << "Invalid Input. Please enter a number between 1 and 100" << endl;
                        cin >> moves;
                    }else{
                        flag = false;
                    }   
                }
                char dir;
                map.displayMap();
                for(int i = 0; i < moves; i++){
                    if(p.getStrength() > 0 && p.getLives() > 0){
                        cout << "Enter which way you want to move (w,a,s,d)" << endl;
                        cin >> dir;
                        return_val = map.move(dir);     //There is an infinite loop if you enter more letters than int moves at once 
                        if(return_val == 1){
                            p.fightPirate(map.getPirateAt(pirates_found));
                            pirates_found++;
                        }else if(return_val == 2){
                            cout << "You found a pirate that has already been found. Keep exploring new spaces!" << endl;
                        }else if(return_val == 3){
                            p.solveTrap(map.getTrapAt(traps_found));
                            traps_found ++;
                        }else if(return_val == 4){
                            cout << "You found a trap was already found but not solved . Keep exploring new spaces!" << endl;
                        }else if(return_val == 5){
                            cout << "You found a trap has already been solved. Keep exploring new spaces!" << endl;
                        }else{
                            cout << "You can't move in that direction" << endl;
                        }
                        map.displayMap();
                    }else{
                        p.endGame('l');
                        return 0;
                    }
                }
                break;
            case '2':
                p.printInventory(); 
                break;
            case '3':
                map.displayMap();
                break;
            case '4':
                //print leader board
                break;
            case '5':
                cout << "Thanks for playing, see you again soon!" << endl;
                return 0;
            default:
                cout << "Invalid Input. Please enter a number 1 through 5" << endl; 
                break;
        }

        
    }
 
    return 0;

}