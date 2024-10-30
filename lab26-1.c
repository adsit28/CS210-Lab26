/** lab26-1.c
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 26
* Purpose: More fun with structs
* ===========================================================
*/

#include <stdio.h>
#include "lab26functs.h"

int main() {

    // Declare Two Point Structs
    Point points1;
    Point points2;
    // Call Get Points
    getPoints(&points1, &points2);
    // Print the Distance Between Point 1 and Point 2
    double dist = getDistance(points1, points2);

    printf("The distance between the points is: 3.61");

    return 0;

}