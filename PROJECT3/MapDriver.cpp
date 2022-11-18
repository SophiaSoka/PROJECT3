// CSCI 1300 Fall 2022
// Author: Sophia Soka and Matthew Keane
// Sophia Soka's Rec: Recitation:306 - Zachary Atkins, Matthew Keane's Rec: Recitation 102 - Ojasvi Bhalerao
// Project 3 - MapDriver.cpp

#include "Map.h"
#include "Button.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Map map;
    cout << "Initial map: " << endl;
    map.displayMap(); // starting point
    cout << "Default constructor: " << endl; 
    cout << "Room #: " << map.getTrapsCount() << endl;
    cout << "Let's add some traps: " << endl;
    assert(map.addAllTraps(5));
    assert(map.addAllPirates(10));
    map.displayMap();
    /*
    assert(map.addTrap(2, 3));
    assert(map.addTrap(8, 11));
    assert(map.addTrap(2, 7));
    assert(map.addTrap(8, 2));
    assert(!map.addTrap(15, 15)); // should not show on map nor error out, out of bounds
    assert(!map.addTrap(2, 3));   // will not do anything since space is occupied
    assert(map.addTrap(5, 7));
    assert(!map.addTrap(3, 7)); // will fail due to exceeding max_rooms_
    map.displayMap();
    
    cout << "Spawning some NPCs: " << endl;
    assert(map.addPirate(4, 4));
    assert(map.addPirate(1, 2));
    assert(map.addPirate(7, 2));
    assert(map.addPirate(10, 4));
    assert(!map.addPirate(2, 7)); // should fail due to space being occupied
    assert(map.addPirate(9, 0));
    assert(map.addPirate(10, 0)); // should fail due to max number of NPCs == 5
    map.displayMap();
    
    cout << "Let's move a little. First, down:" << endl;
    map.move('s'); // go down
    map.displayMap();
    cout << "Now, right:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On an NPC space? ..." << map.isPiratesLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Moving onto an NPC space that was previously hidden:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On NPC space now?..." << map.isPiratesLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Let's move off it, should be updated as visible:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On room right now?..." << map.isTrapsLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Okay, let's move onto the room:" << endl;
    map.move('s');
    map.displayMap();
    cout << "On room right now? " << map.isTrapsLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "... and move left off" << endl;
    map.move('a');
    map.displayMap();
    */
    char dir;
    for(int i = 0; i < 150; i++){
        cout << "enter which way you want to move (w,a,s,d)" << endl;
        cin >> dir;
        map.move(dir);
        map.displayMap();
    }

    return 0;
}