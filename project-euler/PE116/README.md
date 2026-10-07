# Project Euler - Problem 116

## Problem

A row of black unit-square tiles can have some of its tiles covered by longer coloured tiles: red tiles are 2 units long, green tiles are 3 units long, and blue tiles are 4 units long. A single row may only use one colour, and at least one coloured tile must be placed. For a row that is 5 units long, this gives 7 arrangements with red, 3 with green, and 2 with blue, for a total of 12. Find the total number of valid arrangements for a row that is 50 units long.

## Approach

Used dynamic programming, solving the problem separately for each tile colour and then adding the three results together.

For a fixed coloured tile length `x`, let `dp[i]` be the number of ways to fill a row of length `i` using black unit tiles and coloured tiles of length `x`. Looking at the last position in the row, there are only two possibilities: it is a black tile, which leaves `dp[i - 1]` ways to fill the rest, or it is the end of a coloured tile, which leaves `dp[i - x]` ways to fill the rest (only possible when `i >= x`). So `dp[i] = dp[i - 1] + dp[i - x]`, with `dp[0] = 1` for the empty row.

`dp[50]` also counts the single arrangement with no coloured tile at all, which the problem doesn't allow, so 1 is subtracted. Since colours can't be mixed, every valid arrangement uses exactly one colour, so the counts for red, green, and blue never overlap and can simply be summed.

The counts grow quickly (the red tiles alone already exceed 20 billion), so 64-bit integers are required to avoid overflow.

- **Time complexity:** `O(n)`, where `n = 50` is the row length — each of the three colours requires a single linear pass over the row.
- **Space complexity:** `O(n)`, for the table of counts.