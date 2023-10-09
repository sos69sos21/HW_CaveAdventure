#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "ItemList.h"

/* Initializes the Player structure pointed to by pPlayer.
Sets the initial location number to the value specified by locationNumber.
*/
void PlayerInit(Player *pPlayer, int locationNumber){
    // Set the intitial location number to the value specified by locationNumber.


    // Handle ItemList items
    ItemListInit(&pPlayer->items);
}

/* Adds the item specified by itemNumber to the item list for the player specified
by pPlayer.
*/
void PlayerAddItem(Player *pPlayer, int itemNumber){
    ItemListAddItem(pPlayer->items, itemNumber);
}

// Removes the item specified by itemNumber from the item list for the player specified by pPlayer.
void PlayerRemoveItem(Player *pPlayer, int itemNumber){

}

/* Returns true if the itemNumber is contained within the item list for the player
specified by pPlayer and returns false if it is not.
*/
bool PlayerHasItem(Player *pPlayer, int itemNumber){

}