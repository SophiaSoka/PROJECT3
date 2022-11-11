// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Map.cpp

#include "Map.h"
#include "Button.h"
#include <iostream>
#include <fstream>

using namespace std;

Map::Map()
{
    resetMap();
}

/*
 * Algorithm: Resets positions of player, NPCs, and rooms and clears map_data_
 * Set Player position coordinates to 0
 * Set npc_count_ to false
 * Set room_count_ to 0
 * loop i from 0 to max_npcs_
 *      Set row and col of location to -1
 * loop i from 0 to max_rooms
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


// set player position, if in range
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
 * Algorithm: Checks if the location is an NPC location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to npc_count_
 *      if (row,col) is a npc location
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
 * Algorithm: Checks if the location is an room location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to room_count_
 *      if (row,col) is a room location
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
 * if (row, col) is npc location and has been found:
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
 * if row and column is a npc location
 *      return false
 * if row and column is a room location
 *      return false
 * if row and column is the dungeon exit
 *      return false
 * return true
 *
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
 * Algorithm: Create an NPC on the map
 * if npc is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in npcPosition array
 * mark NPC as hidden
 * set (row,col) value in map_data_ to 'N'
 * increment npc_count_
 * return true
 *
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
 * Algorithm: Create a room on the map
 * if room_count_ is more than or equal to number of rooms
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in room_positions_ matrix is -1 -1
 *      store row, col and type values in the current row of room_positions_ matrix
 *      increment room_count_
 *      Set (row,col) value in map_data_ to 'R'
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
 * Algorithm: Removes the NPC at (row, col) from the map
 * loop i from 0 to npc_count_
 *      if npc_position[i] is (row, col)
 *          swap npc_position[npc_count_-1] with npc_position[i]
 *          reset npc_position[npc_count_-1][0] and npc_position[npc_count_-1][1] to -1
 *          reset npc_position[npc_count_-1][2] to 0
 *          decrement npc_count_
 *          set map data at (row, col) to explored
 *          return true
 * return false
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 
bool Map::showPirate(int row, int col)
{
    for (int i = 0; i < npc_count_; i++)
    {
        if (npc_positions_[i][0] == row && npc_positions_[i][1] == col)
        {
            // swap i'th npc with last npc
            npc_positions_[i][0] = npc_positions_[npc_count_ - 1][0];
            npc_positions_[i][1] = npc_positions_[npc_count_ - 1][1];
            npc_positions_[i][2] = npc_positions_[npc_count_ - 1][2];
            // reset last npc
            npc_positions_[npc_count_ - 1][0] = -1;
            npc_positions_[npc_count_ - 1][1] = -1;
            npc_positions_[npc_count_ - 1][2] = false;
            // decrement npc_count_
            npc_count_--;
            // set map data to explored
            map_data_[row][col] = EXPLORED;
            return true;
        }
    }
    return false;
}
*/
/*
 * Algorithm: Removes the room at (row, col) from the map
 * loop i from 0 to room_count_
 *      if room_position[i] is (row, col)
 *          swap room_position[room_count_-1] with room_position[i]
 *          reset room_position[room_count_-1][0] and room_position[room_count_-1][1] to -1
 *          decrement room_count_
 *          set map data at (row, col) to explored
 *          return true
 * return false
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 
bool Map::removeRoom(int row, int col)
{
    for (int i = 0; i < room_count_; i++)
    {
        if (room_positions_[i][0] == row && room_positions_[i][1] == col)
        {
            // swap i'th room with last room
            room_positions_[i][0] = room_positions_[room_count_ - 1][0];
            room_positions_[i][1] = room_positions_[room_count_ - 1][1];
            // reset last room
            room_positions_[room_count_ - 1][0] = -1;
            room_positions_[room_count_ - 1][1] = -1;
            // decrement room_count_
            room_count_--;
            // set map data to explored
            map_data_[row][col] = EXPLORED;
            return true;
        }
    }
    return false;
}
*/
/*
 * Algorithm: Mark (row, col) as explored, either revealing NPC or empty space
 * if (row, col) is NPC location
 *      mark npc at player_position_ as found
 * else if (row, col) is a free space
 *      mark space as explored in map data
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
void Map::exploreSpace(int row, int col)
{
    map_data_[player_position_[0]][player_position_[1]].isClicked();
    if(map_data_[player_position_[0]][player_position_[1]].getValue() ==0){
        explode(player_position_[0], player_position_[1]);
    }
    for (int i = 0; i < pirates_count_; i++)
    {
        if (row == pirates_positions_[i][0] && col == pirates_positions_[i][1])
        {
            // mark NPC as found
            pirates_positions_[i][2] = 1;
            return;
        }
    }
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
 *      if new location is an NPC location
 *          mark new location as explored
 *      return true
 * else
 *      return false
 *
 * Parameters: direction (char)
 * Return: boolean (bool)
 */
bool Map::move(char direction) //need to find a way to make first postion blue 
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
            return false;
        }
        break;
    case 's': // if user inputs s, move down if it is an allowed move
        if (player_position_[0] < num_rows_ - 1)
        {
            player_position_[0] += 1;
        }
        else
        {
            return false;
        }
        break;
    case 'a': // if user inputs a, move left if it is an allowed move
        if (player_position_[1] > 0)
        {
            player_position_[1] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 'd': // if user inputs d, move right if it is an allowed move
        if (player_position_[1] < num_cols_ - 1)
        {
            player_position_[1] += 1;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
    }
    // if new location is an NPC location, mark as explored
    if (isPiratesLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    else{
        map_data_[player_position_[0]][player_position_[1]].isClicked();
    }
    if(map_data_[player_position_[0]][player_position_[1]].getValue() == 0){
        explode(player_position_[0],player_position_[1]);
    }
    return true;
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print 'X'
 *          else if npc is at (i,j)
 *              if npc has been found:
 *                  print 'N'
 *              else
 *                  print '-'
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
            if(x>=0 && y < 12){
                if(y >= 0 && y < 12){
                    if(map_data_[x][y].getValue() != 10 && map_data_[x][y].getValue() != 11){
                        map_data_[x][y].setValue(map_data_[x][y].getValue()+1);
                    }
                }
            }
        }
    }
}
/*
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
            if(x>=0 && y < 12){
                if(y >= 0 && y < 12){
                    if((map_data_[x][y].getValue() != 10 && map_data_[x][y].getValue() != 11) && !(map_data_[x][y].getClicked())){
                        map_data_[x][y].isClicked();
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
//helper function for readTraps
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
    //once gone through whole string, adds the lest "word" and returns the total number of strings added 
    arr[count] = word;
    count++;
    return count;
}
*/
/*parameters: (string) filename
returns: int,-2, -1 or the number of traps in traps_ array 
    creates helper variables 
    checks if there is room in the array (if not return -2)
    opens file (if not returns -1)
    splits every line of file into an array 
    puts elements of that array into Trap constructor 
    puts the trap created into array of traps_ 
    returns the total number of posts in array 
*/
//reads in a file and stores each line as a trap object in the traps 
//alot like the readPosts or readLikes function in project 2
/*int Map::readTraps(string filename){
    string temp_arr[4];
    Trap temp_trap;
    ifstream fin;
    string line;
    int return_split;
    if(traps_count_ == max_traps_){
        return -2;
    }
    //opens file (if not returns -1)
    fin.open(filename);
    if(fin.fail()){
        return -1;
    }
    while(getline(fin, line)){
        if(line.length() > 0){
            //splits every line of file into an array 
            return_split = split(line, ',', temp_arr, 3);
            if(return_split == 3){
                //puts elements of that array into Post constructor 
                Trap temp_trap(temp_arr[0], temp_arr[1], temp_arr[2]);
                //puts the post created into array of posts 
                traps_[traps_count_] = temp_trap;
                traps_count_++;
            }
        }//if array is full it returns size and ends loop 
        if(traps_count_ >= max_traps_){
            return traps_count_;
        }
    }
    //returns the total number of posts in array 
    return traps_count_; 
    
}
*/
