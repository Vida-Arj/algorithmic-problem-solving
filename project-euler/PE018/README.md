# Project Euler - Problem 18

## Problem

Given a triangle of numbers with 15 rows, a path runs from the single number at the top down to the bottom row, where each step can move to either of the two numbers directly beneath the current one. Find the highest possible sum obtainable along any such path.

## Approach

Represented the triangle as a 2D array and used recursion to explore every possible path from the top down: at each position `(i, j)`, the maximum achievable total is the current value plus whichever of the two possible next steps (straight down or down-right) leads to a higher total. The recursion bottoms out once it moves past the last row, returning 0 at that point.

This is a straightforward recursive exploration without memoization, so the number of recursive calls grows exponentially with the number of rows. For a 15-row triangle this is small enough to run quickly, but the same approach would not scale to a much larger triangle without adding memoization (turning it into a proper dynamic programming solution).

- **Time complexity:** `O(2^n)`, where `n = 15` is the number of rows — each position branches into two recursive calls.
- **Space complexity:** `O(n)`, for the recursion call stack, plus `O(n^2)` for storing the triangle itself.