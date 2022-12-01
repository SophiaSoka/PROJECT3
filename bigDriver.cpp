#include "Map.h"
#include "Trap.h"
#include "Person.h"
#include "Button.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Map map;
    
    cout << "Traps #: " << map.getTrapsCount() << endl;
    cout << "Let's add some traps and piartes: " << endl;
    //assert(map.addAllTraps(5));
    assert(map.addAllPirates(10));
    assert(map.readAndAddTraps("riddles.txt") == 5);
    cout << "Traps: " << map.getTrapsCount() << endl;
    cout << "First Trap is... " << endl;
    cout << "Riddle: " << map.getTrapAt(0).getRiddle() << endl;
    cout << "Answer: " << map.getTrapAt(0).getAnswer() << endl;
    cout << "Hint: " << map.getTrapAt(0).getHint() << endl;
    cout << "Second Trap.. "<< map.getTrapAt(1).getRiddle() << endl;
    Person p1 = Person("Matty", 354, 2);
    Person p2 = Person("Sophia", 475, 3);
    Person p3 = Person("Michael", 215, 1);
    Person p4 = Person("Sarah", 875, 2);
    Person p5 = Person("Conlan", 153, 1);
    Person p6 = Person("Roman", 57, 2);
    Person p7 = Person("Sander", 675, 3);
    Person p8 = Person("Amber", 712, 3);
    Person p9 = Person("Laya", 347, 3);
    Person p10 = Person("Logan", 567, 3);

    map.addPerson(p1);
    map.addPerson(p2);
    map.addPerson(p3);
    map.addPerson(p4);
    map.addPerson(p5);
    map.addPerson(p6);
    map.addPerson(p7);
    map.addPerson(p8);
    map.addPerson(p9);
    map.addPerson(p10);

    map.displayMap();
}
