/** lab26-2.c
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 26
* Purpose: More fun with structs
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "dungeon.h"

int main() {

    Room* dungeon = createDungeon();
    printf("%s\n", dungeon->description);

    // When You Know Where the Key Is, Call This Function and Give It the Path
    //getKey(dungeon->);

    // When You Know Where the Sword Is, Call This Function and Give It the Path
    //getSword(dungeon->);

    // When You Know Where the Door Is, Call This Function and Give It the Path
    //openDoor(dungeon->);

    // When You Know Where the Dragon Is, Call This Function and Give It the Path
    // Note: You must have done the first 3 tasks above to find the dragon
    //attackDragon(dungeon->);

    return 0;
}
