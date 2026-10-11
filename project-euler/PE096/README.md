# Project Euler - Problem 96

## Problem

A Sudoku puzzle is a 9×9 grid that must be filled in so that every row, every column, and each of the nine 3×3 boxes contains the digits 1 through 9 exactly once. A provided text file holds fifty such puzzles, each with exactly one valid solution, where a 0 marks an empty cell. After solving every puzzle, read the first three digits of each completed grid's top row as a three-digit number, and find the sum of those fifty numbers.

## Approach

Each puzzle is read from the input file in turn: its header line (`Grid NN`) is skipped, and the next nine lines are converted character by character into a 9×9 array of integers.

Each puzzle is then solved with recursive backtracking. The solver moves through the grid cell by cell, left to right and top to bottom. Cells that are already filled are skipped. For an empty cell, it tries each digit from 1 to 9, using a helper function that rejects a digit if it already appears in the same row, the same column, or the same 3×3 box (the box is located by rounding the cell's row and column down to the nearest multiple of 3). When a digit is valid, it is placed and the solver recurses to the next cell. If that recursion eventually fails, the cell is reset to 0 and the next digit is tried. If no digit fits, the function returns failure, which sends the previous cell back to try its next candidate. When the recursion moves past the last cell, the grid is complete, and the three-digit number from its top-left corner is added to the running total.

The reading loop uses the success of reading the next puzzle's header as its condition, rather than checking for end-of-file in advance, so it stops exactly after the last puzzle and never processes leftover data.

The input file (`p096_sudoku.txt`) is read using a relative path, so the program must be run from within the directory where the file is located, otherwise the file won't be found.

- **Time complexity:** Exponential in the worst case, `O(9^m)` per puzzle, where `m` is the number of empty cells, since up to 9 digits may be tried for each. In practice, the row, column, and box checks prune most branches early, so all fifty puzzles are solved quickly. This is plain backtracking, with no constraint propagation or smarter cell ordering.
- **Space complexity:** `O(1)` per puzzle — the grid is a fixed 9×9 size and the recursion depth is bounded by its 81 cells.