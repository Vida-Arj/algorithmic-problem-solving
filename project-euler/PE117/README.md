# Project Euler - Problem 117

## Problem

A row can be covered using grey unit-square tiles together with longer coloured tiles: red tiles are 2 units long, green tiles are 3 units long, and blue tiles are 4 units long. Unlike Problem 116, colours may be freely mixed within the same row. A row that is 5 units long can be covered in 15 distinct ways. Find the number of ways to cover a row that is 50 units long.

## Approach

Used dynamic programming over the length of the row. Let `dp[i]` be the number of ways to cover a row of length `i`. Looking at the last tile in the row, it can only be one of four things: a grey tile of length 1, or a red, green, or blue tile of length 2, 3, or 4. In each case, the rest of the row is a shorter row that can be covered in `dp[i - length]` ways, so:

`dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4]`

The base case is `dp[0] = 1`, since an empty row can be covered in exactly one way (using no tiles). Because every tile length corresponds to exactly one tile type, each different sequence of tile lengths is a different covering, so mixed colours are counted automatically. Unlike Problem 116, there is no requirement to use a coloured tile, so the all-grey arrangement is a valid covering and is included in the count.

The result for a 50-unit row is on the order of 10^14, far beyond the range of a 32-bit integer, so 64-bit integers are used.

- **Time complexity:** `O(n * k)`, where `n = 50` is the row length and `k = 4` is the number of tile lengths — each position is computed once from the four positions before it. Since `k` is a constant, this is effectively `O(n)`.
- **Space complexity:** `O(n)`, for the table of counts.