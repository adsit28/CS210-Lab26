/** lab26functs.c
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
#include <math.h>

void getPoints(Point* points1, Point* points2){
    printf("First x and y point: ");
    scanf("%d %d", &points1->x, &points1->y);

    printf("Second x and y point: ");
    scanf("%d %d", &points2->x, &points2->y);
}

double getDistance(Point points1, Point points2){
    double distance = sqrt(pow((points2.x - points1.x),2) + pow((points2.y - points1.y),2));

    return distance;
}

int getNumLines(char filename[]){
    char c;  
    int count = 0;  
    // Open the file  
    FILE* fp = fopen(filename, "r");  

    // Check if file exists  
    if (fp == NULL) {  
        fprintf(stderr, "Could not open file %s", filename);  
        fprintf(stderr, " - terminating\n");  
        exit(1); 
    }  

    // Extract characters from file and store in character c  
    for (c = getc(fp); c != EOF; c = getc(fp)) {  
        // count newline chars 
        if (c == '\n') { 
           count++;
        }
    }  

    // Close the file  
    fclose(fp); 

    return count;  
} 
void readFile(char filename[], USAFBaseData* baseStruct, int lines){
    // Open the file  
    FILE* fp = fopen(filename, "r");  

    // Check if file exists  
    if (fp == NULL) {  
        fprintf(stderr, "Could not open file %s", filename);  
        fprintf(stderr, " - terminating\n");  
        exit(1); 
    }

    for(int i = 0; i < lines; i++){
        fscanf(fp, "%[^,],", baseStruct[i].baseName);
        fscanf(fp, "%d,%d,", &baseStruct[i].bldgsOwned, &baseStruct[i].structsOwned);
        fscanf(fp, "%[^,],%[^\n]\n", baseStruct[i].city, baseStruct[i].state);
    }


    fclose(fp);

}
void printData(USAFBaseData* bases, int numBases){
    for(int i = 0; i < numBases; i++){
        printf("%s, %d, %d, %s, %s\n", bases[i].baseName, bases[i].bldgsOwned, bases[i].structsOwned, bases[i].city, bases[i].state);
    }
}