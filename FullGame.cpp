// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - FullGame.cpp

#include "Player.h"
#include "Map.h"
#include "Button.h"
#include <iostream>
using namespace std;

/*
 * Algorithm: This is our start menu which will prompt the user and give instructions as the user progresses through the game
 * Prompt the user with the difficulty they want to select by using if statements inside a while loop
 * Included the merchant which will prompt the user on wha they can purchase for their journey
 * Used a while loop to display the user with options throughout the game if they want to move, see inventory, or quit
 * Used a switch statement for the user's movement throughout the map
 * In the switch statement the user is prompted if they run into a pirate, a trap, want to see their inventory, etc. with while loops and if statements
 */
int main(){
    string name;
    int num_moves;
    char level;
    int level_int;
    cout << "Welcome to Matty and Sophia's Final Project for CSCI1300! Our game will start by choosing the difficulty level you want to play on,\nwhich will determine the amount of pirates included. Following this, you will be prompted by a merchant to purchase items with the coins you are given. \nThe items you can purchase are weapons to fight pirates, hints to solve riddles located in traps, and an extra-life if you fail to defeat a pirate or solve a riddle. \nAfter you have selected everything you desire from the merchant, you will be prompted with the main menu, which consists of the options: \nmove player, show inventory, display board, display leaderboard, and quit. The main menu will continue to pop up throughout the game if you run out of moves, \nfight a pirate, or solve a riddle. You will use a, s, w, or d to move left, down, up, or right throughout the game. \nThe map will explode to help you navigate throughout the game depending on if run into open space, a pirate, or a trap. \nTo win the game, you must collect three of the five keys in the game which will come from solving riddles. \nTry to avoid the pirates and answer riddles to the best of your ability. Good luck!" << endl;
    Map map;
    bool inLoop = true;
    cout << endl;
    cout << "Please enter your name: " << endl;
    cin >> name;
    // We used a while loop which will prompt the user with the difficulty they want to select
    while(inLoop){
        cout << name << " please choose your difficulty level (1,2,3)" << endl;
        cin  >> level;
        // if the user selects one, they'll have the same riddles but only ten pirates
        if(level == '1'){
            level_int = 1;
            map.readAndAddTraps("riddles.txt");
            map.addAllPirates(10);
            inLoop = false;
        }
        // if the user selects two, they'll have the same riddles but only 15 pirates
        else if(level == '2'){
            level_int = 2;
            map.readAndAddTraps("riddles.txt");
            map.addAllPirates(15);
            inLoop = false;
        }
        // if the user selects three, they'll have the same riddles but 15 pirates
        else if(level == '3'){
            level_int =3;
            map.readAndAddTraps("riddles.txt");
            map.addAllPirates(20);
            inLoop = false;
        }
        else{
            cout << "Invalid Input." << endl;
        }
    }
    // This is the merchant which prompts the user with the supplies they can purchase for the game
    // We declared variables specified below and set the necessary values
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
    // We used a while loop to prompt the user on what they can purchase if they have more than 20 coins, used cout statements to display this
    while(coins >= 20){
        cout << endl;
        cout << "You have " << coins << " coins in the bank" << endl;
        cout << "Choose one of the following:" << endl;
        cout << "1.) Weapon(20 coins): You will need a weapon to fight the pirates along your journey" << endl;
        cout << "2.) Hints(30 coins): In your journey, there will be riddles you will need to solve in order to not get killed from a boobytrap." << endl;
        cout << "3.) Extra-life(50 coins): You may need an extra-life if you are unable to solve a riddle or fight a pirate." << endl;
        cin >> input;
        cout << endl;
        // We used an if statement if the user selected one from the prompt above, which displays options for weapons
        // We used if statements to specify the weapon chosen by the user which will display the option chosen and the weapon's damage with cout statements
        // Will print not enough coins if the user has not enough coins
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
        // We used an else if statement if the user selected option two
        // In this option the user will have the option to spend thirty coins to receive hints or not to help answer riddles later on
        else if(input == 2)
        {
            if (coins >= 30){
                cout << "There are five different hints for the riddles in the game which if answered correctly will give you the keys." << endl;
                cout << "1.) Input 1 if you want to receive hints." << endl;
                cout << "2.) Input 2 if you want to cancel." << endl;
                cin >> hint;
                // We used an if statement if the option was one, which displays the hints for the user to use later on
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
                // We used an else if statement if the user selected option two which will cancel and return the user to the option menu
                else if(hint == 2)
                {
                    hint = 0;
                    cout << "Cancel." << endl;
                }
            }
            // used an else statement if the user doesn't have enough coins
            else{
                cout << "It doesn't look like you have enough coins for a hint" << endl;
            }

        }
        // We used an else if statement if the user selects option three
        // The user will be prompted if they want to purchase an extra-life for their battles against pirates and traps
        else if(input == 3)
        {
            // We used an if statement if the user has greater than or equal than fifty coins to display the following cout statements
            if (coins >= 50){
                cout << "You have the option of receiving an extra-life in case you run into a pirate without a weapon or fail to answer a riddle correctly." << endl;
                cout << "1.) One extra-life." << endl;
                cout << "2.) Input 2 if you want to cancel." << endl;
                cin >> extra_life;
                // We used an if statement if the user decided to choose to receive an extra-life
                // We used a cout statement to display if the user acquired an extra-life
                if(extra_life == 1)
                {
                    total_lives ++;
                    coins -= 50;
                    cout << "Acquired extra-life." << endl;
                }
                // We used an else if statement if the user selected to cancel and not receive and extra-life
                // We used a cout statement to display cancel
                else if(extra_life == 2)
                {
                    cout << "Cancel." << endl;
                }
            }
            // We used an else statement to display if the user doesn't have enough coins
            else{
                cout << "It doesn't look like you have enough coins to buy an extra-life" << endl;
            }
        }
        // We used an else statement if the user inputs an invalid input
        else{
            cout << "Invalid input. Please enter a number 1, 2 or 3" << endl;
        }
    }
    
    // player will have parameters onec merchant is written 
    // Player p = Player();
    Player p = Player(total_lives, name_of_weapon, total_hints);
    
    // We declared the variables and the values for our variables below
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
    bool show_lb;
    // We used a while loop to display the main menu for the user which will allow them to select an input
    while (p.getStrength() > 0 && p.getLives() > 0){
        cout << "======Main Menu=====" << endl;
        cout << "1. Move Player" << endl;
        cout << "2. Show Inventory" << endl;
        cout << "3. Display Board" << endl;
        cout << "4. Display Leaderboard" << endl;
        cout << "5. Quit" << endl;
        cin >> str_command;
        // Used an if statement to run option one
        if(str_command.length() == 1){
            command = str_command[0];
        }
        // Used an else statement if the input is invalid
        else{
            cout << "Invalid Input." << endl;
        }
        // Here, we used a switch statement for the user to decide what they want to do, number of moves, direction of movement, the trraps, and the pirates
        // Case one is a while loop which will prompt the user with the amount of times they would like to move in a given time
        // IF the user inputs a number not between 1 and 100 then the game will say invalid input
        switch (command){
            case '1':
                int moves;
                bool flag;
                flag = true;
                cout << "How many times would you like to move before seeing this menu again?" << endl;
                cin >> moves;
                while (flag){
                    if(moves < 1 || moves > 100){
                        // infinite loop when you plug in something wrong 
                        cout << "Invalid Input. Please enter a number between 1 and 100" << endl;
                        cin >> moves;
                    }else{
                        flag = false;
                    }   
                }
                char dir;
                // displays the map for the user to navigate through
                map.displayMap();
                // We used a for loop with multiple if and if else statements to prompt the user on where to move, traps, or pirates
                for(int i = 0; i < moves; i++){
                    if(p.getNumKeys() == 3){
                        Person new_winner = Person(name, num_moves, level_int);
                        map.updateLeaderboardFile("leaderboard.txt", new_winner);
                        if(p.endGame('w')){
                            map.printLeaderboard("leaderboard.txt");
                        }
                        return 0;
                    }
                    // This if statement will prompt the user with what direction they want to move and will take in their input
                    else if(p.getStrength() > 0 && p.getLives() > 0){
                        cout << "Enter which way you want to move (w,a,s,d)" << endl;
                        cin >> dir;
                        return_val = map.move(dir); //There is an infinite loop if you enter more letters than int moves at once 
                        // This is an if statement to determine whether or not a pirate has been discovered
                        if(return_val == 1){
                            p.fightPirate(map.getPirateAt(pirates_found));
                            pirates_found++;
                        // Else if statement to tell the user if they found a pirate they already discovered
                        }else if(return_val == 2){
                            cout << "You found a pirate that has already been found. Keep exploring new spaces!" << endl;
                        // Else if statement to figure out whether a trap has been found
                        }else if(return_val == 3){
                            p.solveTrap(map.getTrapAt(traps_found));
                            traps_found++;
                        // Else if statement to tell the user that a trap has already been found, but not solved
                        }else if(return_val == 4){
                            cout << "You found a trap was already found but not solved. Keep exploring new spaces!" << endl;
                        // Else if statement if a trap has been found, but is already solved
                        }else if(return_val == 5){
                            cout << "You found a trap has already been solved. Keep exploring new spaces!" << endl;
                        // Else statement to tell the user they cannot move in a certain direction
                        }else{
                            cout << "You can't move in that direction" << endl;
                        }
                        num_moves++;
                        map.displayMap();
                    }
                    // Else statement to end the game
                    else{
                        if(p.endGame('l')){
                            map.printLeaderboard("leaderboard.txt");
                        }
                        return 0;
                    }
                }
                break;
            // Case 2 will display the user's inventory
            // Case 3 will display the map
            // Case 4 will display the leaderboard
            // Case 5 will prompt the user with the exiting message for the game ending
            // Case 5 will print invalid input if the user does not select a number 1 through 5
            case '2':
                p.printInventory(); 
                break;
            case '3':
                map.displayMap();
                break;
            case '4':
                map.printLeaderboard("leaderboard.txt");
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