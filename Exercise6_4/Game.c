#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"
#include "Location.h"
#include "Item.h"
#include "Player.h"

int GameInitialize(Game *pGame){
    srand(clock());
    int place; 

    LocationReadMap();
    ItemReadItems();
    PlayerInit();

    for(int i = 0; i < pGame->itemCount; i++){
        place = rand() % pGame->numLocations;
        LocationAddItem(&pGame->map[place], i);
    }

    return 0;
}