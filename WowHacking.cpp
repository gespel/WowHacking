#include <windows.h> 
#include <iostream>
#include <sstream>
#include "Utils.h"
#include "WorldRareVisionHack.h"
#include "MemoryHacks.h"

using namespace std;

int main() {
    //WorldRareVisionHack wrvh;
    //wrvh.startHack();
    MemoryHacks mh;
    cout << mh.getGold();

    return 0;
}
