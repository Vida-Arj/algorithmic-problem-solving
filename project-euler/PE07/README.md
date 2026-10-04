# Project Euler - Problem 7

## Problem

By listing the first six prime numbers (2, 3, 5, 7, 11, and 13), it can be seen that the 6th prime is 13. Find the 10,001st prime number.

## Approach

Iterated through integers starting from 2, checking each one for primality using a helper function that tests divisibility only up to the square root of the number. Every time a prime was found, a counter was incremented; once the counter reached 10,001, the most recently found prime was the answer.

- **Time complexity:** `O(n * sqrt(m))`, where `n` is the number of candidates checked and `m` is the current candidate value — each primality check takes `O(sqrt(m))`.
- **Space complexity:** `O(1)` — only a few integer variables are used regardless of input size.