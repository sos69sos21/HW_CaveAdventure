#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemList.h"

void ItemListInit(ItemList *pItemList){
    pItemList->count = 0;

}

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

bool ItemListHasItem(ItemList *pItemList, int itemNumber){
    for(int i =0; i < pItemList->count; i++){
        if(pItemList->items[i] == itemNumber){
            return true;
        }
    }
    return false;
}