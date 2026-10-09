# Timus - Problem 1119

## Problem

The streets of a city form a grid of square quarters, each with sides of 100 meters. A walker starts at the south-west corner of the grid and wants to reach the north-east corner of the quarter at position (N, M), where N and M (each at most 1000) are the west–east and south–north sizes of the grid. The walker only ever moves north or east along the streets, but K of the quarters (K ≤ 100) can also be crossed along their diagonal, from the quarter's south-west corner to its north-east corner. Find the length of the shortest route in meters, rounded to the nearest whole number. For the sample with a 3 × 2 grid and diagonal quarters at (1, 1), (3, 2), and (1, 2), the answer is 383.

## Approach

Used dynamic programming over the street crossings of the grid. Let `dp[i][j]` be the length of the shortest route from the start to the crossing that is `i` blocks east and `j` blocks north of it. Because the walker only moves north or east, a crossing can be reached in at most three ways:

- From the crossing to its west, walking one block: `dp[i-1][j] + 100`
- From the crossing to its south, walking one block: `dp[i][j-1] + 100`
- From the crossing diagonally to its south-west, if the quarter between them is one of the diagonal ones: `dp[i-1][j-1] + 100 * sqrt(2)`

`dp[i][j]` is the smallest of the available options. The crossings along the west and south edges of the grid have no choice but to be reached by walking straight along the edge, so they are initialised to `100 * i` and `100 * j`. The diagonal quarters are recorded in a boolean grid as they are read, and the answer is `dp[N][M]`, rounded to the nearest integer.

Distances are stored as floating-point numbers because of the `sqrt(2)`. This is safe for the final rounding: a route can use at most 100 diagonals, and for any number of diagonals up to 100 the fractional part of the total length never comes within about 0.0007 of a rounding boundary, which is several orders of magnitude larger than any floating-point error that accumulates here.

The program reads N, M, K, and then K pairs of quarter coordinates (west–east position first, then south–north position) from standard input.

- **Time complexity:** `O(N * M)` — each crossing is computed once with constant work, and reading the K diagonal quarters adds `O(K)`.
- **Space complexity:** `O(N * M)`, for the table of distances and the grid marking the diagonal quarters (the table could be reduced to a single row by keeping only the previous row).