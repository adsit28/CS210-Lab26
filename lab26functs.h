/** lab26functs.h
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 26
* Purpose: More fun with structs
* ===========================================================
*/

// YOUR STRUCTS GO HERE
typedef struct point_struct{
    int x;
    int y;
} Point;

typedef struct bases_struct{
    char baseName[50];
    int bldgsOwned;
    int structsOwned;
    char city[50];
    char state[30];
} USAFBaseData;

// LAB 26-1 FUNCTIONS GO HERE
//void getPoints(Point* points1, Point* points2);
//double getDistance(Point points1, Point points2);

// LAB 26-3 FUNCTIONS GO HERE

int getNumLines(char filename[]);
void readFile(char filename[], USAFBaseData* baseStruct, int lines);
void printData(USAFBaseData* bases, int numBases);
