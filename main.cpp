#include "Board.h"
#include <vector>

int main()
{
    Board sudokuGrid; // calls default constructor
    std::vector<std::tuple<int, int ,int>> singleOccurrences;

    sudokuGrid.set_value_b(0, 3, 9);
    sudokuGrid.set_value_b(0, 4, 1);
    sudokuGrid.set_value_b(0, 6, 4);
    sudokuGrid.set_value_b(0, 8, 7);
    sudokuGrid.set_value_b(1, 0, 3);
    sudokuGrid.set_value_b(1, 2, 4);
    sudokuGrid.set_value_b(1, 3, 6);
    sudokuGrid.set_value_b(1, 4, 8);
    sudokuGrid.set_value_b(1, 7, 1);
    sudokuGrid.set_value_b(2, 1, 7);
    sudokuGrid.set_value_b(2, 2, 9);
    sudokuGrid.set_value_b(2, 4, 5);
    sudokuGrid.set_value_b(2, 6, 6);
    sudokuGrid.set_value_b(2, 8, 3);
    sudokuGrid.set_value_b(3, 0, 9);
    sudokuGrid.set_value_b(3, 2, 2);
    sudokuGrid.set_value_b(3, 6, 8);
    sudokuGrid.set_value_b(3, 8, 1);
    sudokuGrid.set_value_b(4, 1, 1);
    sudokuGrid.set_value_b(4, 2, 5);
    sudokuGrid.set_value_b(4, 5, 6);
    sudokuGrid.set_value_b(4, 6, 3);
    sudokuGrid.set_value_b(4, 7, 4);
    sudokuGrid.set_value_b(5, 1, 3);
    sudokuGrid.set_value_b(5, 4, 9);
    sudokuGrid.set_value_b(5, 7, 5);
    sudokuGrid.set_value_b(6, 0, 2);
    sudokuGrid.set_value_b(6, 3, 5);
    sudokuGrid.set_value_b(6, 4, 3);
    sudokuGrid.set_value_b(6, 6, 7);
    sudokuGrid.set_value_b(7, 2, 3);
    sudokuGrid.set_value_b(7, 3, 1);
    sudokuGrid.set_value_b(7, 7, 9);
    sudokuGrid.set_value_b(8, 0, 6);
    sudokuGrid.set_value_b(8, 3, 4);
    sudokuGrid.set_value_b(8, 4, 7);
    sudokuGrid.set_value_b(8, 6, 1);
    sudokuGrid.set_value_b(8, 7, 3);


    while (!(sudokuGrid.is_solved())) {
        for (int row = 2; row < 9; row += 3) {
            for (int col = 2; col < 9; col += 3) {
                singleOccurrences = sudokuGrid.only_comes_once(row, col);

                if (singleOccurrences.size() > 0) {
                    for (auto tupleIt = singleOccurrences.begin(); tupleIt != singleOccurrences.end(); tupleIt++) {
                        const auto& tuple = *tupleIt;

                        const auto& rowToUse = std::get<0>(tuple);
                        const auto& colToUse = std::get<1>(tuple);
                        const auto& valToUse = std::get<2>(tuple);

                        sudokuGrid.set_value_b(rowToUse, colToUse, valToUse);
                    }
                }
            }
        }
    }

    sudokuGrid.print_board();
    return 0;
}
