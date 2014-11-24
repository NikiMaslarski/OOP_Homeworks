#include <iostream>
#include "Board.h"
#include <stdlib.h>
#include <iomanip>

void Board::free_(Cell** table_){
    for(int i = 0; i < length; i++)
        delete []table_[i];
    delete []table_;
}

Board::Board(int length_, int height_):
    length(length_),
    height(height_),
    score(0)
    {
        table = new Cell*[length];
        for(int i = 0; i < length; i++)
            table[i] = new Cell[height];
        addCell();
        addCell();
    }

Board::~Board(){
    free_(table);
}

Board::Board(const Board& board){
    this->length = board.length;
    this->height = board.height;
    for(int i = 0; i < length; i++)
        for(int j = 0; j < height; j++)
            this->table[i][j] = board.table[i][j];
}

Board& Board::operator=(const Board& board){
    if(this != &board){
        free_(table);
        this->length = board.length;
    this->height = board.height;
    for(int i = 0; i < length; i++)
        for(int j = 0; j < height; j++)
            this->table[i][j] = board.table[i][j];
    }
    return *this;
}

Cell* Board::getRandomCell(){
    int x = rand() % length;
    int y = rand() % height;

    return &table[x][y];
}

void Board::addCell(){
    Cell* randCell;
    do{
        randCell = getRandomCell();
    }while(!randCell->isEmpty());

    if((rand()%10 + 1) % 7 == 0)
        *randCell += Cell(4,2);
    else
        *randCell += Cell(2,1);
}


void Board::printBoard() const{
    for(int i = 0; i < length; i++){
        for(int j = 0; j < height; j++){
            std::cout << std::setw(5) << table[j][i].getSize();
        }
        std::cout << std::endl << std::endl << std::endl;
    }
}

bool Board::moveDown(){
    bool flag = false;
    for(int i = 0; i < length; i++){
        int j1 = height - 1;
        for(int j2 = j1-1; j2 >= 0; --j2){
            if(table[i][j2].isEmpty())
                continue;

            if(!table[i][j1].isEmpty()){
                if(table[i][j2] == table[i][j1]){
                    table[i][j1] += table[i][j2];
                    table[i][j2].resetCell();
                    score += table[i][j1].getSize();
                    flag = true;
                }
                else if(j1-1 != j2){
                    table[i][j1-1] = table[i][j2];
                    table[i][j2].resetCell();
                    flag = true;
                }
                --j1;
            }
            else{
                table[i][j1] = table[i][j2];
                table[i][j2].resetCell();
                flag = true;
            }
        }
    }
    return flag;
}

bool Board::moveUp(){
    bool flag = false;
    for(int i = 0; i < length; i++){
        int j1 = 0;
        for(int j2 = j1+1; j2 < height; ++j2){
            if(table[i][j2].isEmpty())
                continue;

            if(!table[i][j1].isEmpty()){
                if(table[i][j2] == table[i][j1]){
                    table[i][j1] += table[i][j2];
                    table[i][j2].resetCell();
                    score += table[i][j1].getSize();
                    flag = true;
                }
                else if(j1+1 != j2){
                    table[i][j1+1] = table[i][j2];
                    table[i][j2].resetCell();
                    flag = true;
                }
                ++j1;
            }
            else{
                table[i][j1] = table[i][j2];
                table[i][j2].resetCell();
                flag = true;
            }
        }
    }
    return flag;
}

bool Board::moveRight(){
    bool flag = false;
    for(int i = 0; i < height; i++){
        int j1 = length - 1;
        for(int j2 = j1-1; j2 >= 0; --j2){
            if(table[j2][i].isEmpty())
                    continue;

            if(!table[j1][i].isEmpty()){
                if(table[j2][i] == table[j1][i]){
                    table[j1][i] += table[j1][i];
                    table[j2][i].resetCell();
                    score += table[j1][i].getSize();
                    flag = true;
                }
                else if(j1-1 != j2){
                    table[j1-1][i] = table[j2][i];
                    table[j2][i].resetCell();
                    flag = true;
                }
                --j1;
            }
            else{
                table[j1][i] = table[j2][i];
                table[j2][i].resetCell();
                flag = true;
            }
        }
    }
    return flag;
}

bool Board::moveLeft(){
    bool flag = false;
    for(int i = 0; i < height; i++){
        int j1 = 0;
        for(int j2 = j1+1; j2 < length; ++j2){
            if(table[j2][i].isEmpty())
                continue;

            if(!table[j1][i].isEmpty()){
                if(table[j2][i] == table[j1][i]){
                    table[j1][i] += table[j2][i];
                    table[j2][i].resetCell();
                    score += table[j1][i].getSize();
                    flag = true;
                }
                else if(j1+1 != j2){
                    table[j1+1][i] = table[j2][i];
                    table[j2][i].resetCell();
                    flag = true;
                }
                ++j1;
            }
            else{
                table[j1][i] = table[j2][i];
                table[j2][i].resetCell();
                flag = true;
            }
        }
    }
    return flag;
}

bool Board::availableMoves() const{
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < height-1; ++j){
            if(table[i][j].isEmpty() || table[i][j+1].isEmpty()
               || table[i][j] == table[i][j+1])
            {
                return true;
            }
        }
    }

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < length-1; ++j){
            if(table[j][i].isEmpty() || table[j+1][i].isEmpty()
               || table[j][i] == table[j+1][i])
            {
                return true;
            }
        }
    }
    return false;
}

int Board::getScore() const{
    return score;
}
