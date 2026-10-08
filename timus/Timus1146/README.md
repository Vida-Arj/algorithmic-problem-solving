# Timus - Problem 1146

## Problem

An N × N grid of integers is given, containing both positive and negative values. Any block made of consecutive rows and consecutive columns (at least one cell) forms a sub-rectangle, and its sum is the total of the values inside it. Find the largest sum that any sub-rectangle can have. N is at most 100, and every value lies between -127 and 127. The program reads N followed by the N² values (row by row) from standard input and prints the maximum sum. For the 4 × 4 sample grid, the answer is 15.

## Approach

Used a 2D prefix sum table so that the sum of any sub-rectangle can be read off in constant time.

**Building the table.** `dp[i][j]` holds the sum of every value in the rectangle from the top-left corner of the grid down to cell `(i, j)`. It is built from its neighbours using inclusion–exclusion: add the table entry above and the entry to the left, subtract the overlap that both of them include (the entry diagonally above-left), and add the current cell's own value:

`dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + a[i][j]`

**Evaluating a rectangle.** Any sub-rectangle is fixed by its top-left corner `(x, y)` and bottom-right corner `(i, j)`. Its sum is obtained from the table with the same inclusion–exclusion idea, subtracting the parts above and to the left of it and adding back the overlap that was subtracted twice:

`dp[i][j] - dp[x-1][j] - dp[i][y-1] + dp[x-1][y-1]`

**Searching.** Every pair of corners is tried, with `(i, j)` ranging over the whole grid and `(x, y)` ranging over every cell above and to the left of it (including itself), and the largest sum seen is kept.

**Starting value.** A sub-rectangle must contain at least one cell, so the answer can be negative — for a grid of only negative values it is the largest single cell. For this reason the running maximum starts from a very low value (-1,290,000) rather than 0. This is below any sum the constraints allow, since the lowest possible rectangle sum is -127 × 100 × 100 = -1,270,000, so the first rectangle checked always replaces it.

A faster `O(n^3)` approach exists (fix a pair of rows, then apply Kadane's maximum-subarray algorithm to the column sums between them). The `O(n^4)` method used here is simpler to reason about and runs well under a second even for the largest allowed grid.

- **Time complexity:** `O(n^4)`, where `n` is the grid size — about `(n(n+1)/2)^2` pairs of corners are checked (roughly 25.5 million for `n = 100`), each in constant time thanks to the prefix sums. Without prefix sums, summing each rectangle cell by cell would make this `O(n^6)`.
- **Space complexity:** `O(n^2)`, for the grid and the prefix sum table.