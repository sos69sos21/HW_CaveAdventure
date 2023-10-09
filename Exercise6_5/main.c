#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"

void Describe(int location);
int GetUserInput(char *line, int maxLine);
void ParseUserInput(char *aline);

Game game;

int main(void){

    GameInitialize();
    while(1){
        Describe();
        GetUserInput();
        ParseUserInput();
    }

    return 0;
}

//Describe the location (including items located at the user's current location)
void Describe(int location){

}
// Read user input
int GetUserInput(char *aline, int maxLine){
    fgets(aline, maxLine, stdin);
    aline[maxLine - 1] = '\0';
    return strlen(aline);
}

//Parse and perform the appropriate operation or report an error message
void ParseUserInput(char *aline){
    char *verb;
    char *noun;
    int loc;

    verb = strtok(aline, " "); // get the first token
    noun = strtok(NULL, " "); // get the second token

    swtich(verb[0]){
        case 'n':
        case 'N':
            if(game.map[game.player.location].north == -1){
                printf("You cannot go that way\n");
            }
            else{
                game.player.location = game.map[game.player.location].north;
            }
            break;
        case 'e':
        case 'E':
            if(game.map[game.player.location].east == -1){
                printf("You cannot go that way\n");
            }
            else{
                game.player.location = game.map[game.player.location].east;
            }
            break;
        case 's':
        case 'S':
            if(game.map[game.player.location].south == -1){
                printf("You cannot go that way\n");
            }
            else{
                game.player.location = game.map[game.player.location].south;
            }
            break;
        case 'w':
        case 'W':
            if(game.map[game.player.location].west == -1){
                printf("You cannot go that way\n");
            }
            else{
                game.player.location = game.map[game.player.location].west;
            }
            break;
    }
}