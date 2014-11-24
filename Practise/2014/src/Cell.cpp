#include "Cell.h"
#include <time.h>
#include <stdlib.h>


Cell::Cell(int size, int color): size(size), color(color){}

Cell Cell::operator+(const Cell& cell) const{
    Cell result;
    result.color = this->color + cell.color;
    result.size = this->size + cell.size;


}

Cell& Cell::operator=(const Cell& cell){
    if(this != &cell){
        this->color = cell.color;
        this->size = cell.size;
    }
    return *this;
}

Cell& Cell::operator+=(const Cell& cell){
    *this = *this + cell;
    return *this;
}

bool Cell::operator==(const Cell& cell) const{
    return this->size == cell.size;
}

bool Cell::isEmpty(){
    return size == 0;
}

int Cell::getSize(){
    return size;
}

void Cell::resetCell(){
    size = 0;
    color = 0;
}
