# Project Euler - Problem 1

## Problem

Find the sum of all natural numbers below 1000 that are multiples of 3 or 5.

## Approach

Iterated through every integer from 1 up to (but not including) 1000, checking whether it was divisible by 3 or 5. Numbers satisfying either condition were added to a running total, which was printed once the loop finished.

- **Time complexity:** `O(n)`, where n = 1000 — a single pass through the range.
- **Space complexity:** `O(1)` — only a running sum is kept, no extra data structures.