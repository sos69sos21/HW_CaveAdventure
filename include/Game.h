#ifndef GAME_H
#define GAME_H

#define MAX_MAP_LOCATIONS 20
#define MAX_ITEM_COUNT 20

typedef struct{
    int numLocations;
    Location map[MAX_MAP_LOCATIONS];
    int itemCount;
    Item items[MAX_ITEM_COUNT];
    Player player;
} Game;

int GameInitialize(Game *pGame);

#endif