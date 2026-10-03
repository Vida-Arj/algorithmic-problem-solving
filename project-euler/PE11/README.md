# Project Euler - Problem 11

## Problem

In a 20×20 grid of numbers, find the greatest product of four adjacent numbers in the same direction — horizontally, vertically, diagonally, or counter-diagonally (up, down, left, right, or along a diagonal).

## Approach

Read the full 20×20 grid into a 2D array, then checked every possible group of four adjacent cells in each of the four directions:

- **Vertical**: four consecutive cells moving down a column.
- **Horizontal**: four consecutive cells moving across a row.
- **Diagonal (↘)**: four consecutive cells moving down and to the right.
- **Diagonal (↗)**: four consecutive cells moving up and to the right.

For each group, the product of its four values was computed and compared against the largest product found so far, which was updated whenever a bigger product was found.

- **Time complexity:** `O(n^2)`, where `n = 20` is the grid size — each direction requires a single pass over the grid, with a constant amount of work (multiplying four numbers) per cell.
- **Space complexity:** `O(n^2)`, for storing the full grid in memory.