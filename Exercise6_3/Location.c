#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Location.h"
#include "ItemList.h"

/* Returns the number of map locations loaded into the map array or returns -1
if there's an error loading the locations. If an error is returned, the program should terminate.
*/
int LocationReadMap(Location map[], int maxLocations, char *filename){

}

/* Adds the item specified by itemNumber to the item list for the location
specified by pLocation.
*/
void LocationAddItem(Location *pLocation, int itemNumber){

}

/* Removes the item specified by itemNumber from the item list for the location
specified by pLocation.
*/
void LocationRemoveItem(Location *pLocation, int itemNumber){

}

/* Returns true if the itemNumber is contained within the item list
for the location specified by pLocation and returns false if it is not.
*/
bool LocationHasItem(Location *pLocation, int itemNumber){
    
}