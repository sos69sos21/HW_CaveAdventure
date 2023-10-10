#ifndef GAME_H
#define GAME_H

#include "Location.h"
#include "Item.h"
#include "Player.h"

#define MAX_MAP_LOCATIONS 20
#define MAX_ITEM_COUNT 20
#define MAP_FILE "map.txt"
#define ITEMS_FILE "items.txt"

/*
Structure that holds needed information to represent and manage the state of the game.
Struct includes data about the game map, location, items, and teh player's character
*/
typedef struct{
    int numLocations;
    Location map[MAX_MAP_LOCATIONS];
    int itemCount;
    Item items[MAX_ITEM_COUNT];
    Player player;
} Game;

int GameInitialize(Game *pGame);

#endif