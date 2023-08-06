# Sudoku-Solver
I made a C++ code that is able to solve sudoku puzzles of "easy" difficulty from the website "https://sudoku.com/"

The way the project works is that it goes grid by grid and it does the equivalent of the "Notes" feature on the website - it makes a note of all the numbers that can go inside of free tiles (indicated by a value of 0). After making this note for eery tile in a grid, it checks to see if:
    a) a tile can only store 1 value (it can only be a 1 or a 2 or a 3 or a 4, etc.)
    b) a number only occurs in 1 tile (only 1 tile in the grid has a 1 or a 2 or a 3, etc.)

After doing this, it will make a vector of tuples, the tuples containing the value that the tile needs to hold as well as the row and column indexes of the tiles (the tile at (2, 0) in the code I have provided can only contain a 1, so the tuple would look like (2, 0, 1). It will do this for all tiles in a grid before moving onto the next grid and, after finishing all 9 of them, it will check if the grid has been solved. If it hasn't, the program will loop and start from the beginning. This will keep going on until the board has been solved
