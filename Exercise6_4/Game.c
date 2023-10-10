#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Game.h"
#include "Location.h"
#include "Item.h"
#include "Player.h"

/*
Initializes the game structure and calls the initialize routines for the game's map and the game's items.
The player object is also initialized
*/
int GameInitialize(Game *pGame){
    srand(clock());
    int place; 

    pGame->numLocations = LocationReadMap(pGame->map, MAX_MAP_LOCATIONS, MAP_FILE);
   // LocationReadMap();
    pGame->itemCount = ItemReadItems(pGame->items, MAX_ITEM_COUNT, ITEMS_FILE);
   // ItemReadItems();
    //PlayerInit();
    PlayerInit(&pGame->player, 0);

    for(int i = 0; i < pGame->itemCount; i++){
        place = rand() % pGame->numLocations;
        LocationAddItem(&pGame->map[place], i);
    }

    return 0;
}