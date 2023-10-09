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

}

//Parse and perform the appropriate operation or report an error message
void ParseUserInput(char *aline){

}