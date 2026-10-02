# Project Euler - Problem 6

## Problem

The sum of the squares of the first ten natural numbers is 385. The square of the sum of the first ten natural numbers is 3025. The difference between these two values is 2640. Find the difference between the sum of the squares and the square of the sum of the first one hundred natural numbers.

## Approach

Split the problem into two small helper functions: one that computes the sum of squares (`sumsq`) by adding `i * i` for each number from 1 to `n`, and another that computes the square of the sum (`sqsum`) by first summing the numbers from 1 to `n` and then squaring the result. The final answer is simply the difference between these two values for `n = 100`.

- **Time complexity:** `O(n)`, where `n = 100` — each helper function makes a single pass over the range.
- **Space complexity:** `O(1)` — only a running total is kept in each function, no extra data structures.