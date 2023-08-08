// header file "Board.h" where I declare Board class and all its methods

#ifndef SUDOKU_V2_BOARD_H
#define SUDOKU_V2_BOARD_H

#include "Tile.h"
#include <vector>
#include <tuple>


using ROW = int;
using ROW1 = int;
using ROW2 = int;
using COL = int;
using COL1 = int;
using COL2 = int;
using VAL = int;
using VALS = std::vector<int>;

class Board {
private:
    Tile grid[9][9];

public:
    // setter to set value of tile at index (row, col) [named slightly differently]
    void set_value_b(int row, int col, int newValue);

    // overloading function set_value_b to accept Tiles as an input to use Tile() in the default constructor
    void set_value_b(int row, int col, Tile& tile);

    // boolean function to check if board is solved or not
    bool is_solved();

    // service function
    void print_board();

    // function to check what values you can set for the tile
    std::vector<int> all_possible_values(int row, int col);

    /* function to check if any tile in a 3x3 grid is the only tile with a certain value e.g. only tile that can take a
     * 1, and it returns the index of the tile as well as the value it holds
     */
    std::vector<std::tuple<ROW, COL, VAL>> only_comes_once(int row, int col);
    
    // Board's default constructor
    Board();
};

#endif //SUDOKU_V2_BOARD_H
