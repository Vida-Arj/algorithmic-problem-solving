# Project Euler - Problem 28

## Problem

Numbers can be arranged in a square spiral, starting from 1 at the center and winding outward. For a 5×5 spiral built this way, the sum of the numbers that fall on either diagonal is 101. Find the equivalent diagonal sum for a 1001×1001 spiral.

## Approach

Walked the spiral recursively starting from the center cell, moving outward one step at a time. At each position, the direction to move next (right, down, left, or up) is determined by comparing the current row and column against the two diagonals of the grid — this mirrors how the four straight edges of a square spiral connect to each other at the corners. Whenever the current position lands on either diagonal, its value is added to a running total. The recursion naturally stops once it steps outside the bounds of the grid.

Because this walks every cell of the spiral through recursive calls, the recursion depth grows with the total number of cells (`n^2`). For a 1001×1001 grid, that's roughly one million recursive calls, which exceeds the default stack size most compilers allocate and causes a stack overflow. To run this solution for large `n`, the program must be compiled with an increased stack size, for example:

```bash
g++ solution.cpp -o solution "-Wl,--stack,67108864"
```

- **Time complexity:** `O(n^2)`, where `n = 1001` — every cell in the spiral is visited exactly once.
- **Space complexity:** `O(n^2)`, for the grid array that tracks each cell's value, plus `O(n^2)` for the recursive call stack in the worst case.