# Project Euler - Problem 31

## Problem

Using a set of standard coin denominations — 1p, 2p, 5p, 10p, 20p, 50p, £1, and £2 — determine the number of distinct ways these coins can be combined to total exactly £2 (200 pence), using any quantity of each coin.

## Approach

Used dynamic programming to count the number of ways to make each amount from 0 to 200 using an increasing subset of the available coin denominations. `dp[i][j]` represents the number of ways to make amount `i` using only the first `j` coin denominations. For each amount and each denomination, there are two possibilities: either that denomination isn't used at all (carrying over the count from using one fewer denomination), or at least one coin of that denomination is used (adding the count of ways to make the remaining amount with the same set of denominations available). The base case is that there is always exactly one way to make an amount of 0 — by using no coins at all. The final answer is the number of ways to make exactly 200 pence using all eight denominations.

- **Time complexity:** `O(A * C)`, where `A = 200` is the target amount and `C = 8` is the number of coin denominations — each cell of the DP table is computed once with constant work.
- **Space complexity:** `O(A * C)`, for the 2D table storing the number of ways to make every amount with every subset of denominations.