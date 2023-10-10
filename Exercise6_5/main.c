#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"
#include "Player.h"
#include "Location.h"

void Describe(int location);
int GetUserInput(char *line, int maxLine);
void ParseUserInput(char *aline);
void PrintGameItems();

Game game;

int main(void){

    // Initialized the game
    // Prints a list of game items, includes names
    // and description
    GameInitialize(&game);
    PrintGameItems();
    
    /*
    Runs an infinite loop until 'q' is pressed.  Describe()
    describes player's current location, prints the name and 
    description.  User input(), used to prompt user input
    reads it and stores it. Parse performs game action based 
    on user's input
    */
    while(1){
        Describe(game.player.location);

        char aline[20];
        GetUserInput(aline, 20);
        
        //printf("%s",aline);
        ParseUserInput(aline);
    }

    return 0;
}

/*
Displays a list of game items, names and descriptions
*/
void PrintGameItems(){
    printf("GAME ITEMS\n");
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < game.itemCount; i++){
        printf("%s \t", game.items[i].name);
        printf("%s \n", game.items[i].description);
    }
    printf("--------------------------------------------------------\n");
}


//Describe the location (including items located at the user's current location)
void Describe(int location){

    printf("Player Location: %s\n", game.map[location].name);
    printf("Location Description: %s\n", game.map[location].description);

    if(game.map[location].items.count > 0){
        for(int i = 0; i < game.map[location].items.count; i++){
            int itemNum = game.map[location].items.items[i];
            printf("There is a %s here\n", game.items[itemNum].name);
        }
    }
}
/*
Prompts the user for input
Read a line of text from the console
Store it int he provided Char array
Return the length of the input line
*/
int GetUserInput(char *aline, int maxLine){
    printf(">");
    fgets(aline, maxLine, stdin);
    aline[maxLine - 1] = '\0';
    return strlen(aline);
}

//Parse and perform the appropriate operation or report an error message
void ParseUserInput(char *aline){
    char *verb;
    char *noun;

    verb = strtok(aline, " "); // get the first token
    noun = strtok(NULL, "\r\n"); // get the second token

    switch(verb[0]){
        case 'q':
        case 'Q':
            exit(1);
            break;
        case 'n':
        case 'N':
            if(game.map[game.player.location].north == -1){
                printf("You cannot go that way\n\n");
            }
            else{
                game.player.location = game.map[game.player.location].north;
            }
            break;
        case 'e':
        case 'E':
            if(game.map[game.player.location].east == -1){
                printf("You cannot go that way\n\n");
            }
            else{
                game.player.location = game.map[game.player.location].east;
            }
            break;
        case 's':
        case 'S':
            if(game.map[game.player.location].south == -1){
                printf("You cannot go that way\n\n");
            }
            else{
                game.player.location = game.map[game.player.location].south;
            }
            break;
        case 'w':
        case 'W':
            if(game.map[game.player.location].west == -1){
                printf("You cannot go that way\n\n");
            }
            else{
                game.player.location = game.map[game.player.location].west;
            }
            break;
        case 'g':
        case 'G':
            if(noun == NULL){
                printf("ERROR: Missing item name\n\n");
            }
            for(int i = 0; i < game.map[game.player.location].items.count; i++){
                int itemNum = game.map[game.player.location].items.items[i];
                if(strcmp(noun, game.items[itemNum].name) == 0){
                      PlayerAddItem(&game.player, itemNum);
                      LocationRemoveItem(&game.map[game.player.location], itemNum);
                }
            }
            break;
        case 'd':
        case 'D':
            if(noun == NULL){
                printf("ERROR: Missing item name\n\n");
            }
            for(int i = 0; i < game.player.items.count; i++){
                int itemNum = game.player.items.items[i];
                if(strcmp(noun, game.items[itemNum].name) == 0){
                      PlayerRemoveItem(&game.player, itemNum);
                      LocationAddItem(&game.map[game.player.location], itemNum);
                }
            }
            break;
        case 'i':
        case 'I':
            printf("USER INVENTORY\n");
            printf("--------------------------------------------------------\n");
            for(int i = 0; i < game.player.items.count; i++){
                int itemNum = game.player.items.items[i];
                printf("%s \t", game.items[itemNum].name);
                printf("%s\n", game.items[itemNum].description);
            }
            printf("--------------------------------------------------------\n");
            break;
    }
}