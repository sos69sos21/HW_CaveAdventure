#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemList.h"

/*
Define a function named ItemListInit that takes a pointer to an ItemList structure parameter
Set the conunt to 0
*/
void ItemListInit(ItemList *pItemList){
    pItemList->count = 0;

}

/*
Used to add an item to list.  Uses two parameters:
If the list is not at its max capacity, returns the
new count of items in the list after adding
the item.  If already at max capacity, it returns -1
*/
int ItemListAddItem(ItemList *pItemList, int itemNumber){
    if(pItemList->count < MAX_ITEM_LIST){
        pItemList->items[pItemList->count] = itemNumber;
        pItemList->count++;
        return pItemList->count;
    }
    else{
        return -1;
    }
}

/*
Search for a specific item int he list and removes it.  If the item is successsfully removed
, return the updated count of items in the list.  If not found, returns -1
*/
int ItemListRemoveItem(ItemList *pItemList, int itemNumber){
    for(int i = 0; i < pItemList->count; i++){
        if(pItemList->items[i] == itemNumber){
            for(int j = i; j < pItemList->count - 1; j++){
                pItemList->items[j] = pItemList->items[j + 1];
            }
            pItemList->count--;
            return pItemList->count;
        }
    }
    return -1;
}

/*
Searches for specific item in the list and returns "True".  If item
found then it exist in the list.  If not found on the list, then return is "False"
*/
bool ItemListHasItem(ItemList *pItemList, int itemNumber){
    for(int i =0; i < pItemList->count; i++){
        if(pItemList->items[i] == itemNumber){
            return true;
        }
    }
    return false;
}