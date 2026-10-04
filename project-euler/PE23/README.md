# Project Euler - Problem 23

## Problem

A number is called abundant if the sum of its proper divisors is greater than the number itself. It's known that every integer greater than 28123 can be written as the sum of two abundant numbers. Find the sum of all positive integers that cannot be expressed as the sum of two abundant numbers.

## Approach

First, every number up to 28,123 was checked for being abundant (by computing its proper divisor sum using the same square-root factorization technique as earlier problems) and the result was stored in a boolean lookup array. Then, for every number up to 28,123, a check was made for whether it could be written as the sum of two numbers from that abundant list — by trying every possible split and checking if both parts were marked abundant. Any number that couldn't be expressed this way was added to a running total, which is the final answer.

- **Time complexity:** `O(n * sqrt(n))` for the initial abundant-number check across all numbers up to `n = 28,123`, plus `O(n^2)` for checking every number against every possible pair split — the pair-checking step dominates overall.
- **Space complexity:** `O(n)`, for the boolean array tracking which numbers are abundant.