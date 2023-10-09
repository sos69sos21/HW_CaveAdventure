#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Item.h"
//#include "ItemList.h"
#include "Location.h"

#define MAX_LINE 400

/*
Used to support LocationReadMap().
Takes in an empty Location pointer and a line of text from map.txt
Counts/locates all the double quotes and commas from the line
If line has correct number of double quotes and commas, process it
Processing = parse the line and add fields to location data type
Return 1 if success, 0 if fail
*/
int ParseLocation(Location *pLocation, char *aline){
    // Using
    pLocation->north = atoi(strtok(aline, ","));
    pLocation->east = atoi(strtok(NULL, ","));
    pLocation->south = atoi(strtok(NULL, ","));
    pLocation->west = atoi(strtok(NULL, ","));

    // Handle location name string
    char *token = strtok(NULL, ",");
    // Remove leading whitespace and double quotes
    while(isspace((unsigned char)*token) || *token == '"'){
        token++;
    }
    // Remove trailing double quotes and new line character
    char * end = token + strlen(token) - 1;
    while(isspace((unsigned char)*end) || *end == '"'){
        *end = '\0';
        end--;
    }
    strncpy(pLocation->name, token, MAX_LOC_NAME_STRING);

    // Handle location description string
    token = strtok(NULL, ",");
    // Remove leading whitespace and double quotes
    while(isspace((unsigned char)*token) || *token == '"'){
        token++;
    }
    // Remove trailing double quotes
    end = token + strlen(token) - 1;
    while(isspace((unsigned char)*end) || *end == '"'){
        *end = '\0';
        end--;
    }
    strncpy(pLocation->description, token, MAX_LOC_DESCRIPTION_STRING);

    return 1;
}
/* Returns the number of map locations loaded into the map array or returns -1
if there's an error loading the locations. If an error is returned, the program should terminate.
*/
int LocationReadMap(Location map[], int maxLocations, char *filename){
    char aline[MAX_LINE];
    int numLocations = 0;
   //int result = 0;
    FILE *fp;
    Location aLocation;

    // Load the location from the file
    if((fp = fopen(filename, "r")) != NULL){
        while(!feof(fp)){
            // Reset the location structure
            memset(&aLocation, 0, sizeof(Location));
            if(fgets(aline, MAX_LINE, fp) != NULL){
                if(ParseLocation(&aLocation, aline)){
                    map[numLocations++] = aLocation;
                }
                else{
                    printf("ERROR: %s is malformed at line %d\n", filename, numLocations);
                    exit(1);
                }
            }
        }
        fclose(fp);
    }
    else{
       // result = -1;
        printf("ERROR: failed to read file: %s \n", filename);
        exit(1);
    }

    // if(numLocations > 0){

    // }
    return numLocations;
}

/* Adds the item specified by itemNumber to the item list for the location
specified by pLocation.
*/
void LocationAddItem(Location *pLocation, int itemNumber){
    if(pLocation->items.count > MAX_ITEMS){
        printf("ERROR: Unable to add item, item limit reached.\n");
        return;
    }

    pLocation->items.items[pLocation->items.count] = itemNumber;
    pLocation->items.count++;
    return;


    // //Check if there is room to add more items
    // if(pLocation->items.itemCount < MAX_ITEMS){
    //     // Add the item to the item list
    //     pLocation->items.items[pLocation->items.itemCount] = itemNumber;
    //     pLocation->items.itemCount++;
    // }
    // else{
    //     printf("ERROR: You cannot do this.\n");
}

/* Removes the item specified by itemNumber from the item list for the location
specified by pLocation.
*/
void LocationRemoveItem(Location *pLocation, int itemNumber){
    // Search for the item in the item list
    for(int i = 0; i < pLocation->items.count; i++){
        if(pLocation->items.items[i] == itemNumber){
            // Found the item, remove it by shifting elements
            for(int j = i; j < pLocation->items.count - 1; j++){
                pLocation->items.items[j] = pLocation->items.items[j + 1];
            }
            pLocation->items.count--;
            return;
        }
    }
}

/* Returns true if the itemNumber is contained within the item list
for the location specified by pLocation and returns false if it is not.
*/
bool LocationHasItem(Location *pLocation, int itemNumber){
    // Search for the item in the item list
    for(int i = 0; i < pLocation->items.count; i++){
        if(pLocation->items.items[i] == itemNumber){
            // Item found
            return true;
        }
    }
    // Item not found
    return false; 
}