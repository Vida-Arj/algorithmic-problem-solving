# Project Euler - Problem 67

## Problem

This is the same challenge as Problem 18 — finding the highest possible sum along a path from the top of a triangle to the bottom, moving to an adjacent number on the row below at each step — but for a much larger 100-row triangle, read from an input file rather than hardcoded.

## Approach

Unlike the brute-force recursive approach used for the smaller 15-row triangle in Problem 18, this solution uses proper dynamic programming with memoization, since a 100-row triangle has far too many possible paths to explore exhaustively. Working from the bottom row upward, each position's best achievable total is computed as its own value plus whichever of the two positions directly below it (straight down or down-right) leads to a higher cumulative sum. Since every position is computed exactly once and reused by the row above it, the final answer at the top of the triangle reflects the optimal path without ever re-exploring the same position twice.

The input file (`0067_triangle.txt`) is read using a relative path, so the program must be run from within the same directory where the file is located (rather than just having the compiled executable sit alongside it) — otherwise the file won't be found.

- **Time complexity:** `O(n^2)`, where `n = 100` is the number of rows — every position in the triangle is computed exactly once.
- **Space complexity:** `O(n^2)`, for the arrays storing the triangle's values and the computed path sums.