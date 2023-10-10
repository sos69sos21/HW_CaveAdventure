#ifndef ITEMS_H
#define ITEMS_H

#define MAX_ITEM_NAME_STRING 25
#define MAX_ITEM_DESCRIPTION_STRING 80
#define MAX_ITEMS 15

// Used to store names and descriptoin as charater arrays.
// Size of arrays are determined by the constants in [].
// Limits the length to a specific number of characters.
typedef struct{
    char name[MAX_ITEM_NAME_STRING];
    char description[MAX_ITEM_DESCRIPTION_STRING];
}Item;

/*
Loads the list of items from a text file with comma delimited fields. Returns the number of objects loaded from the filename (or -1 if unable to open the file and load the data). Fills the Item array items with the contents of a file entitled "items.txt".
 */
int ItemReadItems(Item items[], int maxItems, char *filename);

/*
Finds an item by itemName and returns the item number of the item itemName. The function returns -1 if an item with the specified itemName is not present. The item number is index of the item in the items array.
*/
int ItemGetItemNumber(Item items[], int maxItems, char *itemName);


#endif