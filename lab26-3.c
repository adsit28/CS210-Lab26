/** lab26-3.c
* ===========================================================
* Name: CS210
* Section:
* Project: Lab 26
* Purpose: More fun with structs
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab26functs.h"

int main() {
    int lines = getNumLines("lab26Data.csv");
    
    USAFBaseData* baseData = NULL;

    baseData = (USAFBaseData*)malloc(lines*sizeof(USAFBaseData));

    readFile("lab26Data.csv", baseData, lines);

    printData(baseData, lines);

    return 0;

}