#include <iostream>
#include <cstring>
#include <fstream>
#include "Engine.h"

using namespace std;

Engine::Engine(){
    board = new Board;
    getScoreFromFile();
}

Engine::~Engine(){
    delete board;
}

void Engine::printBoard() const{
    board->printBoard();
}

void Engine::getCommand(char* command){
    if(!strcmp(command,"New game"))
    {
        int x,y;
        std::cout << "Enter length: ";
        std::cin >> x;
        std::cout << "Enter heigth: ";
        std::cin >> y;
        delete board;
        board = new Board(x, y);
    }

    else if(!strcmp(command, "High score")){
        this->printHighScore();
        std::cout << "Enter key to continue" << std::endl;
        std::cin.get();
    }

    else if(!strcmp(command, "help")){
        cout << "To see the top 10 scores type: \"High score\"" << endl
             << "To start a new game with different size board type: \"New game\"" << endl
             << "Enter a key to continue.";
        cin.get();
    }

    else{
        char command_ = command[0];
        bool flag;
        switch(command_){
        case 'a': flag = board->moveLeft(); break;
        case 's': flag = board->moveDown(); break;
        case 'd': flag = board->moveRight(); break;
        case 'w': flag = board->moveUp(); break;
        }
        if(flag){
            board->addCell();
        }
    }
}


bool Engine::isGameOver() const{
    return !board->availableMoves();
}

void Engine::printScore() const{
    std::cout << board->score << std::endl;
}

void Engine::printHighScore() const{
    for(int i = 0; i < 10; ++i){
        std::cout << i+1 << ". " << topScore[i] << std::endl;
    }
}

void Engine::saveScoreToFile(){
    ofstream file;
    file.open("HighScore.txt");
    if(!file.is_open()){
        cerr << "Failed to save High Score";
        return;
    }
    for(int i = 0; i < 10; i++){
        file << topScore[i];
        file << " ";
    }
    file.close();
}

void Engine::getScoreFromFile(){
    fstream file;
    file.open("HighScore.txt");
    if(!file.is_open()){
        cerr << "Failed to load High Score";
        return;
    }
    for(int i = 0; i < 10; ++i){
        file >> topScore[i];
    }
    file.close();
}

void Engine::saveHighScore(){
    if(board->getScore() > topScore[9]){
        topScore[9] = board->getScore();
    }

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 9; ++j){
            if(topScore[j] < topScore[j+1]){
                int temp = topScore[j];
                topScore[j] = topScore[j+1];
                topScore[j+1] = temp;
            }
        }
    }
    saveScoreToFile();
}
