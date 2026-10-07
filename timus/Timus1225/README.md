# Timus - Problem 1225

## Problem

A row of N vertical stripes is to be coloured using white, blue, and red, subject to two rules: no two neighbouring stripes may share a colour, and every blue stripe must sit directly between a white stripe and a red stripe (in either order). Given N between 1 and 45, determine how many different colourings are possible. For example, N = 3 allows 4: white-red-white, red-white-red, white-blue-red, and red-blue-white.

## Approach

Used dynamic programming over the number of stripes. Let `dp[i]` be the number of valid colourings of `i` stripes.

A blue stripe needs a neighbour on both sides, so it can never be the first or last stripe. This means every valid colouring starts and ends with white or red. Any valid colouring of `i` stripes then falls into exactly one of two cases:

- The last stripe is directly preceded by the opposite non-blue colour. Removing the last stripe leaves a valid colouring of `i - 1` stripes, and any valid colouring of `i - 1` stripes can be extended this way by appending the colour opposite to its final stripe.
- The last stripe is preceded by a blue stripe, which in turn is preceded by the opposite colour. Removing the last two stripes leaves a valid colouring of `i - 2` stripes, and any such colouring can be extended by appending a blue stripe followed by the colour opposite to its final stripe.

These two cases never overlap and together cover every valid colouring, so `dp[i] = dp[i - 1] + dp[i - 2]`.

The base cases are `dp[1] = 2` (a single white or red stripe, since blue cannot stand alone) and `dp[2] = 2` (white-red and red-white, since blue cannot be at an end). This is the Fibonacci recurrence, with `dp[n]` equal to twice the n-th Fibonacci number.

For N = 45 the answer is 2,269,806,340, which exceeds the range of a signed 32-bit integer, so 64-bit integers are used.

The program reads N from standard input and prints the number of valid colourings.

- **Time complexity:** `O(n)`, where `n = N` is the number of stripes — each value is computed once from the two before it.
- **Space complexity:** `O(n)`, for the table of counts (this could be reduced to `O(1)` by keeping only the last two values).