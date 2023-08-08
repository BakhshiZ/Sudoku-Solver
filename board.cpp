// source file "board.cpp" that contains implementation of methods of the Board class

#include "Board.h"
#include "Tile.h"
#include <iostream>
#include <vector>
#include <algorithm>

using ROW = int;
using COL = int;
using VAL = int;

// implementation of setter from class Board with 3 ints as parameter
void Board::set_value_b(int row, int col, int newValue) {
    grid[row][col].set_value(newValue);
}


// implementation of setter from class Board
void Board::set_value_b(int row, int col, Tile &tile) {
    grid[row][col] = tile;
}


/* function that iterates through the whole board tile by tile and if there is a 0, it means the board is not solved and
 * returns false. If there is no 0 in the file, it returns true
 */
bool Board::is_solved() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col].get_value() == 0) {
                return false;
            }
        }
    }

    return true;
}


// function to print the board. The if statements included are just for purposes of pretty printing
void Board::print_board() {
    for (int row = 0; row < 9; row++) {

        // if statement that adds the divider between grids
        if ((row % 3 == 0) && (row > 0)) {
            std::cout << "_______________________" << std::endl;
        }

        for (int col = 0; col < 9; col++) {
            std::cout << grid[row][col].get_value() << " ";

            // if statement that adds the divider between grids
            if (((col + 1) % 3 == 0) && (col > 0)) {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
    }
}


std::vector<int> Board::all_possible_values(int row, int col) {
    if (grid[row][col].get_value() != 0) {
        return {};
    }

    std::vector<int> all_values_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // rounding the parameters row and col down to their nearest multiples of 3
    int rowStart = 3 * (row / 3);
    int colStart = 3 * (col / 3);

    // iterating through all the tiles in a grid and removing their values from all_values_vector
    for (int rowCounter = rowStart; rowCounter < rowStart + 3; rowCounter++) {
        for (int colCounter = colStart; colCounter < colStart + 3; colCounter++) {
            if (grid[rowCounter][colCounter].get_value() != 0) {
                auto it = std::find(all_values_vector.begin(), all_values_vector.end(),
                                    grid[rowCounter][colCounter].get_value());
                all_values_vector.erase(it);
            }
        }
    }

    // repeated logic inside loop, but this time it checks every value in the column and removes it
    for (int rowCounter = 0; rowCounter < 9; rowCounter++) {
        if (grid[rowCounter][col].get_value() != 0) {
            auto it = std::find(all_values_vector.begin(), all_values_vector.end(),
                                grid[rowCounter][col].get_value());

            /* checks if the element is present in all_values_vector as the element may not be there if it was present
             * somewhere in the row and in the grid or in the row and column simultaneously
             */
            if (it != all_values_vector.end()) {
                all_values_vector.erase(it);
            }
        }
    }

    // repeated logic inside loop, but this time it checks every value in the column and removes it
    for (int colCounter = 0; colCounter < 9; colCounter++) {
        if (grid[row][colCounter].get_value() != 0) {
            auto it = std::find(all_values_vector.begin(), all_values_vector.end(),
                                grid[row][colCounter].get_value());

            /* checks if the element is present in all_values_vector as the element may not be present if it was
             * present somewhere in the row and in the grid or in the row and column simultaneously
             */
            if (it != all_values_vector.end()) {
                all_values_vector.erase(it);
            }
        }
    }

    return all_values_vector;
}


/* function that checks all values that all tiles in a grid can hold and checks if any value only occurs once in the
 * grid. If it does, returns index position of that tile along with the value. It also checks if a tile can only have 1
 * value and, if it can, it also returns that
 */
std::vector<std::tuple<ROW, COL, VAL>> Board::only_comes_once(int row, int col) {
    // tuple that will contain row index, column index and value for any tiles we need to return
    std::tuple<int, int, int> returningTuple;

    // tuple that stores all the values a tile can hold as well as the row and column index of the tile
    std::tuple<std::vector<int>, int, int> workingTuple;

    // vector that contains tuples that we return
    std::vector<std::tuple<ROW, COL, VAL>> returningVector;

    // vector to store all possible values for any tile
    std::vector<int> allValuesOfTile;

    // vector of vectors that store all possible values for any tile along with its row and column indexes
    std::vector<std::tuple<std::vector<int>, ROW, COL>> allValuesInGrid;

    // vector to keep track of how many times the numbers appear in the grid
    std::vector<int> numberCounter = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // rounding down the row and column entered so that we can iterate through the grid
    int rowStart = 3 * (row / 3);
    int colStart = 3 * (col / 3);

    // iterating through the grid and pushing all values into the vector supposed to store them
    for (int rowCounter = rowStart; rowCounter < rowStart + 3; rowCounter++) {
        for (int colCounter = colStart; colCounter < colStart + 3; colCounter++) {
            allValuesOfTile = this->all_possible_values(rowCounter, colCounter);
            workingTuple = std::make_tuple(allValuesOfTile, rowCounter, colCounter);
            allValuesInGrid.push_back(workingTuple);

            // if there is only 1 value that can be put in the tile, immediately add it to a tuple and put in
            // vector we are meant to return
            if (allValuesOfTile.size() == 1) {
                returningTuple = std::make_tuple(rowCounter, colCounter, allValuesOfTile[0]);
                returningVector.push_back(returningTuple);
            }
        }
    }

    // iterator to go through all the tuples in the vector
    std::vector<std::tuple<std::vector<int>, int, int>>::iterator tupleIt = allValuesInGrid.begin();

    /* iterating through the tuples of values that can be put in the tile and then increasing the count of occurrences of
     * number by 1. e.g. if a 1 is found, increment the element at the first index in numberCounter; if a 2 is detected,
     * do the same for index position 2, etc. etc.
     */
    for (tupleIt; tupleIt != allValuesInGrid.end(); tupleIt++) {
        for (std::vector<int>::iterator vectorIt = std::get<0>(*tupleIt).begin(); vectorIt !=
                                                                                  std::get<0>(*tupleIt).end(); vectorIt++) {
            numberCounter[(*vectorIt - 1)]++;
        }
    }

    // if any number occurs once, we go through tupleIt once more to find where it was and we replace it
    for (int i = 0; i < 9; i++) {
        // if the number only occurs once then we find its row and column index and put them inside the returning vec
        if (numberCounter[i] == 1) {
            for (tupleIt = allValuesInGrid.begin(); tupleIt != allValuesInGrid.end(); tupleIt++) {
                for (std::vector<int>::iterator vectorIt = std::get<0>(*tupleIt).begin();
                     vectorIt != std::get<0>(*tupleIt).end();
                     vectorIt++) {
                    /* if the number inside the vector = 1, index position (i) is 0 inside numberCounter; if number = 2,
                     * index inside numberCounter is 1, so we compare with i + 1
                     */

                    if (*vectorIt == (i + 1)) {
                        returningTuple = std::make_tuple(std::get<1>(*tupleIt),  // the row index of tile
                                                         std::get<2>(*tupleIt),  // the column index of tile
                                                         *vectorIt                  // the actual value of tile
                        );
                        returningVector.push_back(returningTuple);
                    }
                }
            }
        }
    }
    return returningVector;
}


Board::Board() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            Tile tile;
            this->set_value_b(row, col, tile);
        }
    }
}
