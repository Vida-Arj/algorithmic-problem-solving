# Project Euler - Problem 15

## Problem

Starting at one corner of a grid and moving only right or down, there are exactly 6 distinct paths to reach the opposite corner of a 2×2 grid. Determine how many such paths exist across a 20×20 grid.

## Approach

Used dynamic programming to count the number of ways to reach each point in the grid. The number of paths to any point `(i, j)` equals the sum of the paths to the point directly above it and the point directly to its left, since those are the only two points a path could have come from. The top-left corner is initialized as having exactly one path (the starting point itself), and the boundary conditions (`i == 0` or `j == 0`) are handled by only adding from a neighboring cell when that neighbor actually exists within the grid. The final answer is the number of paths accumulated at the bottom-right corner.

- **Time complexity:** `O(n^2)`, where `n = 20` — every cell in the grid is visited once, with constant work per cell.
- **Space complexity:** `O(n^2)`, for the 2D array storing the path count at every grid point.