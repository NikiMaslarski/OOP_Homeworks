#ifndef CELL_H
#define CELL_H

enum COLORS{Grey, Brown, Yellow, Orange, Pink, Purple, Blue, Green, Red, Black};

class Cell{
public:
    Cell(int size = 0, int color = 0);

    Cell operator+(const Cell&) const;
    Cell& operator+=(const Cell&);
    Cell& operator=(const Cell&);
    bool operator==(const Cell&) const;

    bool isEmpty();
    int getSize();
    void resetCell();

private:
    int size;
    int color;
};

#endif // CELL_H
