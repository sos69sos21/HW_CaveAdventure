#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Item.h"

#define File_Line_Size 100

/*
Loads the list of items from a text file with comma-delimited fields. Returns the number of objects loaded from the filename (or -1 if unable to open the file and load the data). Fills the Item array items with the contents of a file entitled "items.txt".
*/
int ItemReadItems(Item items[], int maxItems, char *filename) {
    FILE *fp;
    int itemCount = 0;
    char *token1;
    char *token2;
    char fLine[File_Line_Size];

    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return -1;
    }

    while (itemCount < maxItems && fgets(fLine, sizeof(fLine), fp)) {
        // Remove double quotation marks from the line
        for (int i = 0; i < strlen(fLine); i++) {
            if (fLine[i] == '\"') {
                memmove(&fLine[i], &fLine[i + 1], strlen(fLine) - i);
                i--;
            }
        }

        token1 = strtok(fLine, ",");
        token2 = strtok(NULL, ",");

        if (token1 != NULL && token2 != NULL) {
            token1 = strtok(token1, "\"");
            token2 = strtok(token2, "\"\r");

            strncpy(items[itemCount].name, token1, MAX_ITEM_NAME_STRING);
            strncpy(items[itemCount].description, token2, MAX_ITEM_DESCRIPTION_STRING);
            itemCount++;
        }
    }
    fclose(fp);
    return itemCount;
}

/*
Finds an item by itemName and returns the item number of the item itemName. The function returns -1 if an item with the specified itemName is not present. The item number is index of the item in the items array.
*/
int ItemGetItemNumber(Item items[], int maxItems, char *itemName){
    for(int i = 0; i < maxItems; i++){
        if(strcmp(items[i].name, itemName) == 0){
            return i;
        }
    }
    return -1;
}