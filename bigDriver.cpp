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
    Person p1 = Person("Matty", );
    Person p2 = Person();
    Person p3 = Person();

    map.addPerson(p1);
    map.addPerson(p2);
    map.addPerson(p3);

    map.displayMap();
}
