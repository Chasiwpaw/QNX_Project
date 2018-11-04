#ifndef POSITION_H
#define POSITION_H
#include <iostream>

class Position {
    public:
        int x, y, z;

        Position(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

#endif
