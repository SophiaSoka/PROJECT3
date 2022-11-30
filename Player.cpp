// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Player.cpp

#include "Player.h"
#include "Pirate.h"

using namespace std;

// We declared the values for the variables in the default constructor
Player::Player (){ //defalut constructor 
    strength = 100;
    lives = 1;
    weapon = "";
    num_hints = 0;
    num_keys = 0;
}
// We declared the data type of our values in the constructors parameter, along with using different variable names to store values
Player::Player(int num_lives, string weapon_name, int hint){ //constructor
    strength = 100;
    lives = num_lives;
    weapon = weapon_name;
    num_hints = hint;
    num_keys = 0;
}

//We used getters to retrieve our data
// We used setters to read our data
void Player::reduceStrength(int takeAwayStrength){ 
    strength = strength - takeAwayStrength;
}
int Player::getStrength(){ 
    return strength;
}

void Player::removeWeapon(){
    weapon = "";
}
string Player::getWeapons(){
    return weapon;
}

void Player::setLives(int l){
    lives = l;
}
int Player::getLives(){
    return lives;
}

void Player::setNumHints(int h){
    num_hints = h;
}
int Player::getNumHints(){
    return num_hints;
}

void Player::addKey(){
    num_keys++;
}
int Player::getNumKeys(){
    return num_keys;
}

// We used a void statement to display the user their inventory throughout the game with cout statements
void Player::printInventory(){
    cout << "----Player Info----" << endl;
    cout << "Strength:   | " << strength << endl;
    cout << "Lives:      | " << lives <<endl;
    cout << "Weapon:     | " << weapon << endl;
    cout << "Hints:      | " << num_hints << endl;
    cout << "-------------------" << endl;
    return;
}

// We used another void statement to interact with the user when they run into a pirate
// this code will prompt the user their chances of beating the pirate on whether or not they use a weapon, and tell the user the pirate's strength
// The user will be able to display their inventory to see what they may want to do in this scenario
// Based on the result of the fight, the user may die and lose the game, or win the fight which will show the user their strength and continue the game
// We used different cout statements to interact with the user based on their choices, asking the user what they want to do
void Player::fightPirate(Pirate pirate){
    char display;
    char useWeapon;
    bool lostWeapon = false;;
    int proablilty = 6;
    cout << "ARGHHHH! You've run into a Pirate and must fight it" << endl;
    cout << "You have a 60% chance of losing to a Pirate without using a weapon "<< endl;
    cout << "and a 30% chance of losing to a Pirate while using a weapon. "<< endl;
    cout << "But if you chosse to use your weapon you have a 10% chance of losing that weapon and not being able to use it again" << endl;
    cout << "If you lose against a pirate, the strength of the pirate will be subtracted from your strength." << endl;
    cout << "This pirate has a strength of " << pirate.getStrength() << "!" << endl;
    cout << endl;
    cout << "Would you like to display your Inventory? (y/n)"<< endl;
    cin >> display;
    if(display == 'y'){
        printInventory();
    }
    else if(display == 'n'){
        cout << "Ok. ";
    }
    else{
        cout << "This was not a valid input, so we understand that as no" << endl;
    }

    if(weapon != ""){
        cout << "Would you like to use your " << weapon << "? (y/n)" << endl;
        cin >> useWeapon;
        if(useWeapon == 'y'){
            proablilty = 3;
            if((rand()%10) == 9){
                lostWeapon = true;
                weapon = "";
            }
        }
        else if(useWeapon == 'n'){
            cout << "Ok. ";
        }
        else{
            cout << "This was not a valid input, so we understand that as no" << endl;
        }
    }
    else{
        cout << "It doesn't look like you have a weapon to fight with. Good Luck!" << endl;
    }

    cout << "Currently flighting pirate..." << endl;
    int rand_result = (rand() % 9);
    if(rand_result >= proablilty){
        cout << "You won the fight!! You still have a strength of " << strength << endl;
    }
    else {
        strength -= pirate.getStrength();
        if(strength > 0){
            cout << "You lost the fight:( You now have a strength of " << strength << endl;
        }
        else{
            lives--;
            char useLife;
            if(lives > 0){
                cout << "You lost the fight and have no strength, do you want to use another life?(y/n)" << endl;
                cin >> useLife;
                if(useLife == 'y'){
                    strength = 100;
                    cout << "Your strength is back to 100, good luck!" << endl;
                }
                else{
                    cout << "Are you sure you don't want to use an extra life you bought?(y/n)" << endl;
                    cin >> useLife;
                    if(useLife == 'n'){
                        strength = 100;
                        cout << "Great choice! Your strength is back to 100, good luck!" << endl;
                    }else{
                        endGame('l');
                    }                 
                }
            }else{
                endGame('l');
            }
        }
    }
    
    return;
}
// this bool statement is used for whether or not a user solves a riddle
// The user will be prompted with the riddle, if they want to use their hints, and whether or not they solved the riddle
bool Player:: solveTrap(Trap trap){
    string user_answer;
    char useHint;
    cout << "You've found a riddle!! Once you solve the riddle you will get a key, getting you closer to treasure!!" << endl;
    cout << "If you have a hint you may use it, but once you run out of hints theres no way to get more!!"<< endl;
    cout << "The riddle is: " << trap.getRiddle()<< endl;
    // used if statements to prompt the user if they want to use their hints, and an else statement if they have no hints
    if (num_hints > 0){
        cout << "Would you like to use one of your hints? (y/n)" << endl;
        cin >> useHint;
        if(useHint == 'y'){
            cout << "Your hint is: " << trap.getHint() << endl;
            num_hints--;
        }
    }else{
        cout << "It doesn't look like you have any hints, good luck!!" << endl;
    }
    cout << "Please enter your guess: " << endl;
    cin >> user_answer;
    // used an if statement if the riddle was solved correctly, and an else statement if solved incorrectly
    if(user_answer == trap.getAnswer()){
        cout << "Horray!! You solved it" << endl;
        cout << endl;
        num_keys++;
        return true;
    }else{
        cout << "You got it wrong :(" << endl;
        return false;
    }
    
    return false;
}
//independent function 
/*parameter: takes in a char, representing the results of teh game
returns: void, prints out differnt information based on what the user decided 
    prints out the results of the game and asks if they want to play again
    if the dont't want to play again it asks them if they would like to see the leader board
    if they say yes it is printed out 
*/
void Player::endGame(char result){
    if(result == 'w'){
        cout << "You have collected three keys and won the game!!" << endl;
    }
    else if(result == 'l'){
        cout << "You have lost the game here. Better luck next time!!" << endl;
    }
    
    char view;
    cout << "Would you like to see the leader board? (y/n)" << endl;
    cin >> view;
    if(view == 'y'){
        // print leader board 
    }
    else if(view == 'n'){
        cout << "Ok, see you again soon" << endl;
    }
    else{
        cout << "Invalid input." << endl;
    }
    return;
}