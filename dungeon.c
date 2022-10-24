/** dungeon.c
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 26
* Purpose: More fun with structs
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dungeon.h"

bool grabbedKey = false;
bool grabbedSword = false;
bool defeatedDragon = false;

Room *room0_1;
Room *room0_2;
Room *room1_1;
Room *room1_2;
Room *room1_3;
Room *room1_4;
Room *room1_5;
Room *room1_6;
Room *room2_1;
Room *room2_2;
Room *room2_3;
Room *room2_4;
Room *room2_5;
Room *room3_1;
Room *room3_2;
Room *room4_1;
Room *room4_2;
Room *room4_3;
Room *room4_4;

Room *createRoom(char *description, bool hasKey, bool hasSword, bool hasDoor, bool hasDragon)
{
    Room *newRoom = (Room *)malloc(sizeof(Room));

    strcpy(newRoom->description, description);
    newRoom->key = hasKey;
    newRoom->sword = hasSword;
    newRoom->door = hasDoor;
    newRoom->dragon = hasDragon;

    return newRoom;
}

void connectRooms(Room* r1, Room* r2, enum Direction d) {
    if (d == North) {
        r1->goNorth = r2;
        r2->goSouth = r1;
    }
    else if  (d == South) {
        r1->goSouth = r2;
        r2->goNorth = r1;
    }
    else if (d == East) {
        r1->goEast = r2;
        r2->goWest = r1;
    }
    else if (d == West) {
        r1->goWest = r2;
        r2->goEast = r1;
    }
}

// This function creates the Dungeon
Room *createDungeon()
{
    Room *startingRoom = createRoom("The entrance to the dungeon.", false, false, false, false);
    room0_1 = createRoom("A wizard's laboratory, full of old tomes and scrolls.", false, false, false, false);
    room0_2 = createRoom("The wizard's chambers. Where could they be?", false, false, false, false);
    room1_1 = createRoom("A musty hallway.", false, false, false, false);
    room1_2 = createRoom("Chambers.", false, false, false, false);
    room1_3 = createRoom("Another hallway.", false, false, false, false);
    room1_4 = createRoom("A damp wall. You see two paths.", false, false, false, false);
    room1_5 = createRoom("A former latrine.", false, false, false, false);
    room1_6 = createRoom("A dead end.", true, false, false, false);
    room2_1 = createRoom("A narrow passageway.", false, false, false, false);
    room2_2 = createRoom("An opening. You see rooms in all directions", false, false, false, false);
    room2_3 = createRoom("Steps. You wonder where they lead . . .", false, false, false, false);
    room2_4 = createRoom("An old broken bridge.  You'll never be able to cross it", false, false, false, false);
    room2_5 = createRoom("A nondescript room. A solid oak door stands before you", false, false, true, false);
    room3_1 = createRoom("A festering rats nest", false, false, false, false);
    room3_2 = createRoom("An old armoury. You see something sharp in the corner.", false, true, false, false);
    room4_1 = createRoom("Another hallway. You're getting sick of these.", false, false, false, false);
    room4_2 = createRoom("An unlocked door stands before you.  It's getting really warm.", false, false, false, false);
    room4_3 = createRoom("The dragon's lair. I hope you are prepared!", false, false, false, true);
    room4_4 = createRoom("Another latrine? Control yourselves . . .", false, false, false, false);

    // Add Bidirectional Travel
    connectRooms(startingRoom, room1_1, North);
    connectRooms(startingRoom, room0_1, South);
    connectRooms(room0_1, room0_2, East);
    connectRooms(room1_1, room1_2, North);
    connectRooms(room2_2, room2_3, North);
    connectRooms(room2_3, room2_4, North);
    connectRooms(room2_2, room3_1, East);
    connectRooms(room4_2, room4_3, North);
    connectRooms(room4_2, room4_4, South);
    connectRooms(room1_2, room1_3, West);
    connectRooms(room1_3, room1_4, West);
    connectRooms(room1_4, room1_6, North);
    connectRooms(room3_1, room3_2, South);
    connectRooms(room2_2, room2_5, West);
    connectRooms(room4_1, room4_2, West);
    connectRooms(room1_4, room1_5, South);
    connectRooms(room1_2, room2_1, North);
    connectRooms(room2_1, room2_2, North);
    
    return startingRoom;
}

// This function gets the key from the room if it is present
void getKey(Room *room)
{
    if (room != NULL)
    {
        printf("Ye find yeself in: %s\n", room->description);
        if (room->key)
        {
            printf("You successfully grab the key.  You wonder what it unlocks.\n\n");
            grabbedKey = true;
            room->key = false;
        }
        else
        {
            printf("You do not see a key here to grab.\n\n");
        }
    }
    else
    {
        printf("You run into a wall.  There is no room in that direction.\n\n");
    }
}

// This function gets the sword if it is present
void getSword(Room *room)
{
if (room != NULL)
    {
        printf("Ye find yeself in: %s\n", room->description);
        if (room->sword)
        {
            printf("You successfully grab the sword.  Evil beware . . . you have something sharp.\n\n");
            grabbedSword = true;
            room->sword = false;
        }
        else
        {
            printf("You do not see a sword here to grab.\n\n");
        }
    }
    else
    {
        printf("You run into a wall.  There is no room in that direction.\n\n");
    }
}

// This function opens the locked door if it is there
void openDoor(Room *room)
{
    if (room != NULL)
    {
        printf("Ye find yeself in: %s\n", room->description);
        if (room->door && grabbedKey)
        {
            printf("You successfully opened the door.\n\n");
            connectRooms(room2_5, room4_1, West);
        }
        else
        {
            printf("The Door is Locked. You need a key to open it.\n\n");
        }
    }
    else
    {
        printf("You run into a wall.  There is no room in that direction.\n\n");
    }
}

// This function attempts to kill the dragon
void attackDragon(Room *room)
{
    if (room != NULL)
    {
        printf("Ye find yeself in: %s\n", room->description);
        if (room->dragon && grabbedSword)
        {
            printf("You lunge your sword at the dragon and catch it offguard.  The dragon wasn't expecting you to know how to use pointers . . . \n");
            printf("As you search the corpse, you discover lab points!  Turn them in to zyBooks and get your credit!\n");
            room->dragon = false;
        }
        else if (room->dragon)
        {
            printf("You accidentally walked into the dragon's lair without a weapon.  Unfortunately, you have no weapon.  The dragon flicks a fireball at you, and you erupt into flames.\n\n");
        }
        else
        {
            printf("There is no dragon here.\n\n");
        }
    }
    else
    {
        printf("You run into a wall.  There is no room in that direction.\n\n");
    }
}
