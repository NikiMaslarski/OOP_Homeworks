#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include "Board.h"

class Engine{
public:
    Engine();
    ~Engine();

    void getCommand(char*);
    void printBoard() const;
    bool isGameOver() const;
    void printScore() const;
    void printHighScore() const;
    void saveHighScore();


private:
    Board* board;
    int topScore[10];
    void getScoreFromFile();
    void saveScoreToFile();
};

#endif // ENGINE_H_INCLUDED
