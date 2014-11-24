#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "Engine.h"

using namespace std;


int main()
{
    srand(time(NULL));

    Engine Game;
    char command[20];

    cout << "To see all commands type \"help\"" << endl << endl;

    while(true){
        cout << "Your score is: ";
        Game.printScore();
        cout << endl;

        Game.printBoard();
        if(Game.isGameOver()){
            cout << endl << "Game Over!" << endl
            << "Your score is: " << endl;
            Game.printScore();
            Game.saveHighScore();
        }
        cout << "Input command: ";
        cin.getline(command,20);
        system("cls");
        Game.getCommand(command);
    }
    return 0;
}
