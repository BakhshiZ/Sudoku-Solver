// header file "Tile.h" where I declare the Tile class and all its methods

#ifndef SUDOKU_V2_TILE_H
#define SUDOKU_V2_TILE_H

// a class to represent each individual tile of the 9x9 sudoku grid
class Tile {
private:
    // the number that the tile has (default is 0)
    int value;

public:
    // setter to alter value of tile
    void set_value(int newVal);

    // getter to retrieve value of tile
    int get_value();

    // overloading the '=' operator
    Tile& operator=(const Tile& other);

    // copy constructor
    Tile(const Tile& otherTile);

    // default constructor that sets value to 0 and isFixed to false;
    Tile();
};

#endif // SUDOKU_V2_TILE_H
