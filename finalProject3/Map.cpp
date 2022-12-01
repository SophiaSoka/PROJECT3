// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Map.cpp

#include "Map.h"
#include "Button.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// default constructor to reset the map
Map::Map() 
{
    resetMap();
}

/*
 * Algorithm: Resets positions of player, pirates, and clears map_data_
 * Set Player position coordinates to 0
 * loop i from 0 to max_pirates_
 *      Set row and col of location to -1
 * loop i from 0 to max_traps_
 *      Set row and col of room location to -1
 * loop i from 0 to num_rows_
 *      loop j from 0 to num_cols_
 *          Set (i,j) location on map_data_ to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap()
{
    // resets player position, count values, and initializes values in position arrays to -1
    player_position_[0] = 0;
    player_position_[1] = 0;

    for (int i = 0; i < max_pirates_; i++)
    {
        pirates_positions_[i][0] = -1;
        pirates_positions_[i][1] = -1;
    }
    pirates_count_ = 0;

    for (int i = 0; i < max_traps_; i++)
    {
        traps_positions_[i][0] = -1;
        traps_positions_[i][1] = -1;
    }
    traps_count_ = 0;

    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            map_data_[i][j].setValue(0);
        }
    }
}

// return player's row position
int Map::getPlayerRow()
{
    return player_position_[0];
}

// return player's column position
int Map::getPlayerCol()
{
    return player_position_[1];
}

// return current room count
int Map::getTrapsCount()
{
    return traps_count_;
}


// set player position, if in range, two parameters
void Map::setPlayerPosition(int row, int col)
{
    if (isOnMap(row, col))
    {
        player_position_[0] = row;
        player_position_[1] = col;
    }
}

// returns member variable num_rows_
int Map::getNumRows()
{
    return num_rows_;
}

// returns member variable num_cols_
int Map::getNumCols()
{
    return num_cols_;
}

/*
 * @brief Checks if the given (row, col) position is on the map
 *
 * Algorithm:
 *  if 0 <= row < num_rows_ and 0 <= col < num_cols_:
 *      return true
 *  else:
 *      return false
 *
 * Parameters: row (int), col (int)
 * Returns: bool
 */
bool Map::isOnMap(int row, int col)
{
    if (0 <= row && row < num_rows_ && 0 <= col && col < num_cols_)
    {
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is a pirate location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to pirate_count_
 *      if (row,col) is a pirate location
 *          return true
 * return true
 * Parameters: row (int), col (int)
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isPiratesLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < pirates_count_; i++)
    {
        if (row == pirates_positions_[i][0] && col == pirates_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the location is a trap location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to traps_count_
 *      if (row,col) is a trap location
 *          return true
 * return true
 * Parameters: row (int), col (int)
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isTrapsLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < traps_count_; i++)
    {
        if (row == traps_positions_[i][0] && col == traps_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column is an explored space
 * if (row, col) is not on the map:
 *     return false
 * if map_data_[row][col] is ' ':
 *     return true
 * if (row, col) is a pirate's position and has been found:
 *     return true
 * else:
 *     return false
 */
bool Map::isExplored(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (!map_data_[row][col].getClicked())
    {
        return true;
    }
    for (int i = 0; i < pirates_count_; i++)
    {
        if (pirates_positions_[i][0] == row && pirates_positions_[i][1] == col)
        {
            if (pirates_positions_[i][2] == true)
            {
                return true;
            }
            break;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column on map is a free space
 * if row and column is not within the map boundaries
 *      return false
 * if row and column is a pirate location
 *      return false
 * if row and column is a trap location
 *      return false
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::isFreeSpace(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (isPiratesLocation(row, col))
    {
        return false;
    }
    if (isTrapsLocation(row, col))
    {
        return false;
    }
    return true;
}

/*
 * Algorithm: Create a pirate on the map
 * if the pirate is greater than max_pirates_ on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in pirate positions array
 * mark pirate as hidden
 * set (row,col) value in map_data_ to '10'
 * increment pirates_count_
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::addPirate(int row, int col)
{
    if (pirates_count_ >= max_pirates_)
    {
        return false;
    }
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    pirates_positions_[pirates_count_][0] = row;
    pirates_positions_[pirates_count_][1] = col;
    pirates_positions_[pirates_count_][2] = false;
    map_data_[row][col].setValue(10);
    trueValue(row, col);
    pirates_count_++;
    return true;
}

/*
 * Algorithm: Create a trap on the map
 * if traps_count is more than or equal to max_traps_
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in traps_positions is 0, 1
 *      store row, col and type values in the current row of traps_positions
 *      increment traps_count
 *      Set (row,col) value in map_data_ to '11'
 *      return true
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::addTrap(int row, int col)
{

    if (traps_count_ >= max_traps_)
    {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    traps_positions_[traps_count_][0] = row;
    traps_positions_[traps_count_][1] = col;
    traps_count_++;
    map_data_[row][col].setValue(11);
    return true;
}

/*
 * Algorithm: Mark (row, col) as explored, either revealing pirate or empty space
 * if (row, col) is pirate location
 *      mark pirate at traps_position as found
 * else if (row, col) is a free space
 *      mark space as explored in map data
 * 
 * * if (row, col) is trap location
 *      mark trap at player_position_ as found
 * else if (row, col) is a free space
 *      mark space as explored in map data
 * else if taps do not get solved
 *      return 4
 * 
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
int Map::exploreSpace(int row, int col)
{
    map_data_[player_position_[0]][player_position_[1]].isClicked();
    //if(map_data_[player_position_[0]][player_position_[1]].getValue() == 0){
    //    explode(player_position_[0], player_position_[1]);
    //}
    for (int i = 0; i < pirates_count_; i++)
    {
        if (row == pirates_positions_[i][0] && col == pirates_positions_[i][1])
        {
            if(!pirates_[i].getBeenFound()){
                pirates_positions_[i][2] = 1;
                pirates_[i].wasFound();
                return 1;
            }
            else{
                return 2;
            }
        }
    }
    for(int j = 0; j < traps_count_; j++){
        if(row == traps_positions_[j][0] && col == traps_positions_[j][1])
        {
            if(!traps_[j].getFound()){
                traps_[j].wasFound();
                return 3;
            }
            else if(!traps_[j].getSolved()){
                return 4;
            }
            else{
                return 5;
            }
        }
    }
    return 0;
}

/*
 * Algorithm: Make the player move based on the given command
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 * if player moved
 *      if new location is an pirate location
 *          mark new location as explored
 *      return true
 * if the map gets a specific value, then explode the position
 * else
 *      return false
 *
 * Parameters: direction (char)
 * Return: boolean (bool)
 */
int Map::move(char direction) //need to find a way to make first postion blue 
{
    // check input char and move accordingly
    switch (tolower(direction))
    {
    case 'w': // if user inputs w, move up if it is an allowed move
        if (player_position_[0] > 0)
        {
            player_position_[0] -= 1;
        }
        else
        {
            return 0;
        }
        break;
    case 's': // if user inputs s, move down if it is an allowed move
        if (player_position_[0] < num_rows_ - 1)
        {
            player_position_[0] += 1;
        }
        else
        {
            return 0;
        }
        break;
    case 'a': // if user inputs a, move left if it is an allowed move
        if (player_position_[1] > 0)
        {
            player_position_[1] -= 1;
        }
        else
        {
            return 0;
        }
        break;
    case 'd': // if user inputs d, move right if it is an allowed move
        if (player_position_[1] < num_cols_ - 1)
        {
            player_position_[1] += 1;
        }
        else
        {
            return 0;
        }
        break;
    default:
        return 0;
    }
    // if the user moves to specific value explode the map
    if(map_data_[player_position_[0]][player_position_[1]].getValue() == 0){
        explode(player_position_[0],player_position_[1]);
    }
            
    return exploreSpace(player_position_[0], player_position_[1]);
     
}

/*
 * Algorithm: This function prints a 2D map in the terminal based on what the user clicks.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print 'PARTY'
 *          else if pirate is at (i,j)
 *              if pirate has been found:
 *                  print mad_data_ revealed icon
 *              else
 *                  print '⬜'
 *          else
 *              print the value of (i,j) in map_data_
 *
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap()
{
    map_data_[0][0].isClicked();
    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            if (player_position_[0] == i && player_position_[1] == j)
            {
                cout << PARTY;
            }
            else if (map_data_[i][j].getClicked()){
                cout << map_data_[i][j].revealIcon(map_data_[i][j].getValue());
            }
            else{
                cout << "⬜";
            }
        }
        cout << endl;
    }
}

/*
Algorithm: This function determines if the value in the row and column holds true
parameters: (int) row, (int) col
returns: void, just updates the value of buttons around the input corrdinates
    (input value will be corrdinates of a pirate)
    gets all buttons touching the input value by having two rested for loops 
    checks the index is on map 
    if the button isn't a pirate or trap it increments the value by one
*/ 

void Map::trueValue(int row, int col){
    
    for (int x = row-1; x <= row+1; x++){
        for(int y = col-1; y<= col+1; y++){
            // checks that the input coordniates are in bounds
            if(x>=0 && y < 12){
                if(y >= 0 && y < 12){
                    // makes the inputs change colors
                    if(map_data_[x][y].getValue() != 10 && map_data_[x][y].getValue() != 11){
                        map_data_[x][y].setValue(map_data_[x][y].getValue()+1);
                    }
                }
            }
        }
    }
}
/*
Algorithm: This function explodes the row and columns for the map
parameters: (int) row, (int) col
returns: void, just updates the buttons around the input corrdinates
    gets all buttons touching the input value by using two rested for loops 
    checks the index is on map 
    if the button isn't a pirate or trap and it hasn't been clicked yet 
        it "clicks" the button (which will have correct image show up on map)
        if the button is ocean (has value of zero) it will explode again
*/
void Map::explode(int row, int col){
    for (int x = row-1; x <= row+1; x++){
        for(int y = col-1; y<= col+1; y++){
            // checks that the surrounding buttons are in bounds
            if(x>=0 && y < 12){
                if(y >= 0 && y < 12){
                    // checks if the surrounding buttons aren't a riddle or map and whether or not they've been clicked
                    if((map_data_[x][y].getValue() != 10 && map_data_[x][y].getValue() != 11) && !(map_data_[x][y].getClicked())){
                        map_data_[x][y].isClicked();
                        // if button isn't touching a pirate or trap it will explode that button, making it recursive
                        if(map_data_[x][y].getValue() == 0){
                            explode(x,y);
                        }
                    }
                }
            }
        }
    }
}
/*
Algorithm: This function adds all pirates to the map with one parameter
* Uses srand to randomize the pirates locations
* Uses a while loop to randomize the pirate in different rows and columns, and will increment the count
* else if
    count >= max_pirates_
        return false
* if num == count
    return true
Paramters: num
Return: boolean (bool)
*/
bool Map::addAllPirates(int num){
    //seed value 
    srand((unsigned) time(NULL));
    int count = 0;
    int row;
    int col;
    while(count < num){
        row = (rand() % 12);
        col = (rand() % 12);
        if(row != 0 || col != 0){
            if (addPirate(row, col)){
                pirates_[count] = Pirate(((rand()%10)*10), row, col);
                count++;
            }
            else if(count >= max_pirates_){
                return false;
            }
        }
    }
    if(num == count){
        return true;
    }
    return true;
}
/*
Algorithm: This function adds all the traps to the map with one parameter
* Uses srand to randomize the trap locations
* Uses a while loop to randomize the traps in different rows and columns, and will increment the count
* else if
    count >= max_traps_
        return false
* if num == count
    return true
Paramters: num
Return: boolean (bool)
*/

bool Map::addAllTraps(int num){
    //seed value 
    srand((unsigned) time(NULL));
    int count = 0;
    int row;
    int col;
    while(count < num){
        row = (rand() % 12);
        col = (rand() % 12);
        if (addTrap(row, col)){
            count++;
        }
        else if(count >= max_traps_){
            return false;
        }
    }
    if(num == count){
        return true;
    }
    return false;
}

Trap Map:: getTrapAt(int index){ // returns the trap index
    return traps_[index];
}
Pirate Map::getPirateAt(int index){ // returns the pirate index
    return pirates_[index];
}

//helper function for readTraps, taken from project two
int split(string input_string, char separator, string arr[], int arr_size){
    //returns 0 if the string is empty 
    if(input_string.length() <= 0){
        return 0;
    }
    int count = 0;
    string word = "";
    //loops through string one char at a time 
    for(int i = 0; i < input_string.length(); i++){
        //if the array is full it returns -1 with as many possible index's filled 
        if (arr_size <= count){
            return -1;
        }
        //if char is the separator the previous characters(word) is added to array and reset 
        if(input_string[i] == separator){
            arr[count] = word;
            word = "";
            count++;
        }
        //if char is not seperator its added to the temp string word 
        else{
            word += input_string[i];
        }
    }
    //once gone through whole string, adds the last "word" and returns the total number of strings added 
    arr[count] = word;
    count++;
    return count;
}

/*
parameters: (string) filename
returns: int, -2, -1 or the number of traps in traps_ array 
    creates helper variables 
    checks if there is room in the array (if not return -2)
    opens file (if not returns -1)
    splits every line of file into an array 
    puts elements of that array into Trap constructor 
    puts the trap created into array of traps_ 
    returns the total number of posts in array 
*/
//reads in a file and stores each line as a trap object in the traps 
//a lot like the readPosts or readLikes function in project 2
/*int Map::readAndAddTraps(string filename){
    srand((unsigned) time(NULL));
    string temp_arr[4];
    Trap temp_trap;
    ifstream fin;
    string line;
    int return_split;
    // returns -2 if traps_count == max_traps
    if(traps_count_ == max_traps_){
        return -2;
    }
    // opens file (if not returns -1)
    fin.open(filename);
    if(fin.fail()){
        return -1;
    }
    int count = 0;
    int row;
    int col;
    // while loop to retrieve data
    while(getline(fin, line)){
        // if statement if the line length is greater than zero
        if(line.length() > 0){
            //splits every line of file into an array 
            return_split = split(line, ',', temp_arr, 3);
            if(return_split == 3){
                //puts elements of that array into Post constructor 
                Trap temp_trap(temp_arr[0], stoi(temp_arr[1]), temp_arr[2]);
                //puts the post created into array of posts 
                row = (rand() % 12);
                col = (rand() % 12);
                // if statement to addtrap to rows and columns, temparary variable
                if(row != 0 || col != 0){
                    if (addTrap(row, col)){
                        traps_[traps_count_] = temp_trap;
                    }
                }
            }
        }// if array is full it returns size and ends loop 
        if(traps_count_ >= max_traps_){
            return traps_count_;
        }
    }
    // returns the total number of posts in array 
    return traps_count_; 
}*/

void Map:: printLeaderboard(string filename){
    vector<Person> leaderboard;
    string line;
    string temp_arr[3];
    ifstream fin;
    int count = 0;
    fin.open(filename);
    while(getline(fin, line)){
        if(line.length() > 0){
            split(line, ',', temp_arr, 3);
            Person temp_person = Person(temp_arr[0], stoi(temp_arr[1]), stoi(temp_arr[2]));
            cout << (count+1) << ": " ;
            cout << temp_person.getName() << " - " << temp_person.getMoves() <<  " - level: " << temp_person.getLevel() << endl;
            count++;
        }
    }
}
int Map::updateLeaderboardFile(string filename, Person new_person){
    vector<Person> leaderboard;
    Person temp_person;
    string temp_arr[3];
    ifstream fin;
    string line;
    bool added = false;;
    int r = 0;
    fin.open(filename);
    if(fin.fail()){
        return -1;
    }
    while(getline(fin, line)){
        if(line.length() > 0){
            split(line, ',', temp_arr, 3);
            Person temp_person = Person(temp_arr[0], stoi(temp_arr[1]), stoi(temp_arr[2]));
            leaderboard.push_back(temp_person);
        }
    }
    int new_moves = new_person.getMoves();
    int temp_moves = 0;
    for(int i = 0; i < leaderboard.size(); i++){
        temp_moves = leaderboard.at(i).getMoves();
        if(temp_moves > new_moves && !added){
            leaderboard.insert(leaderboard.begin() + i, new_person);
            added = true;
        }
    }
    if(!added){
        leaderboard.push_back(new_person);
        added =true;
    }
    ofstream fout;
    fout.open(filename);
    for(int i = 0; i < leaderboard.size(); i++){
        fout << leaderboard.at(i).getName() << ","<< leaderboard.at(i).getMoves() << "," << leaderboard.at(i).getLevel() << endl;
        r++;
    }
    fout.close();
    return r;
}
/*
bool Map::addPerson(Person new_person, vector<Person> leaderboard){
    int new_moves = new_person.getMoves();
    int temp_moves = 0;
    for(int i = 0; i < leaderboard.size(); i++){
        temp_moves = leaderboard.at(i).getMoves();
        if(temp_moves > new_moves){
            leaderboard.insert(leaderboard.begin() + i, new_person);
            return true;
        }
    }
    leaderboard.push_back(new_person);
    return true;
}
*/