#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Cell.h"

class Board{
public:
    Board(int length_=4, int height_=4);
    Board(const Board&);
    Board& operator=(const Board&);
    ~Board();

    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();

    void addCell();
    int getScore() const;

    friend class Engine;

private:
    int length;
    int height;
    int score;
    Cell** table;

    void free_(Cell**);
    void copy();
    void printBoard() const;
    bool availableMoves() const;

    Cell* getRandomCell();
};

#endif // BOARD_H_INCLUDED
