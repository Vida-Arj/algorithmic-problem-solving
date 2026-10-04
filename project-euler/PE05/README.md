# Project Euler - Problem 5

## Problem

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. Find the smallest positive number that is evenly divisible by all of the numbers from 1 to 20.

## Approach

Started checking from 2520 — the smallest number divisible by all of 1 through 10 — and incremented upward, testing each candidate against divisibility by every number from 11 to 20. Starting from 2520 instead of 1 is a valid optimization: any number divisible by all of 11–20 is also divisible by all of 1–10, since every factor needed for 1–10 is already covered within the 11–20 range. A helper function checks divisibility against the full 11–20 range for a given candidate, and the main loop stops as soon as the first one that passes is found.

- **Time complexity:** `O(n * k)`, where `n` is the number of candidates checked before finding the answer and `k = 10` is the fixed range (11 to 20) checked for each candidate.
- **Space complexity:** `O(1)` — only a few integer variables are used regardless of input size.