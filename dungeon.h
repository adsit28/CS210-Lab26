/** lab26-2.c
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 26
* Purpose: More fun with structs
* ===========================================================
*/

#include <stdbool.h>

#ifndef LAB26_DUNGEON_H
#define LAB26_DUNGEON_H

// A struct to describe a room in the dungeon
typedef struct room_ {
    char description[255];
    bool key;
    bool sword;
    bool door;
    bool dragon;
    struct room_* goNorth;
    struct room_* goEast;
    struct room_* goSouth;
    struct room_* goWest;
} Room;

// Enumerated Types to Describe Directions
enum Direction {North, South, East, West};

// This function creates the Dungeon
Room* createDungeon();

// Player Actions
void getKey(Room* room);
void getSword(Room* room);
void openDoor(Room* room);
void attackDragon(Room* room);

#endif