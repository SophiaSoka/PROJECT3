// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - Button.cpp

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Trap.h"
using namespace std;

class Map
{
private:
    //const string UNEXPLORED = "⬜"; // marker for unexplored spaces
    //const string EXPLORED = "🟦";   // marker for explored spaces
    //const string ROOM = "📜";       // marker for room locations
    //const string NPC = "💀";        // marker for NPC locations
    const string PARTY = "🧍";      // marker for party position
    //const string EXIT = "E";       // marker for dungeon exit

    static const int num_rows_ = 12; // number of rows in map
    static const int num_cols_ = 12; // number of columns in map
    static const int max_pirates_ = 10;  // max non-player characters
    static const int max_traps_ = 5; // max number of traps
    
    Trap traps_[max_traps_];

    int player_position_[2];              // player position (row,col)
    int pirates_positions_[max_pirates_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int traps_positions_[max_traps_][2];   // stores the (row,col) positions of rooms present on map
    string map_data_[num_rows_][num_cols_]; // stores the image that will be shown at a given (row,col)
    
    int pirates_count_;  // stores number of misfortunes currently on map
    int traps_count_; // stores number of sites currently on map
public:
    Map();
    void resetMap();
    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getPiratesCount();
    int getTrapsCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isPiratesLocation(int row, int col);
    bool isTrapsLocation(int row, int col);
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);

    // other
    void displayMap();
    bool move(char);
    bool addPirate(int row, int col);
    bool addTrap(int row, int col);
    bool showPirate(int row, int col);
    bool showTrap(int row, int col);
    void exploreSpace(int row, int col);
    //new function that we added
    void trueValue(int row, int col);
    void explode(int row, int col);
    bool addAllPirates(int num);
    bool addAllTraps(int num);
    int readTraps(string filename);

};
#endif
