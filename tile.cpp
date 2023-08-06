// source file "tile.cpp" that contains implementation of methods of the Tile class

#include "Tile.h"

// implementing setter to change value of tile
void Tile::set_value(int newVal) {
    value = newVal;
}

// implementing getter to get value of tile
int Tile::get_value() {
    return value;
}

// implementing operator overloading
Tile& Tile::operator=(const Tile &other) {
    if (this == &other) {
        return *this;
    }

    value = other.value;
}

// implementing the copy constructor
Tile::Tile(const Tile &otherTile) {
    value = otherTile.value;
}

// implementation of default constructor
Tile::Tile() {
    value = 0;
}
