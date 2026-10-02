# Project Euler - Problem 8

## Problem

Given a 1000-digit number, find the thirteen adjacent digits whose product is the greatest, and determine what that product is.

## Approach

Read the full 1000-digit number as a single string. Then used a sliding window of 13 consecutive digits across the string: for each window, computed the product of its digits and kept track of the largest product found. Each digit character was converted to its numeric value by subtracting the ASCII code for `'0'`.

Since the product of 13 digits (up to `9^13`, roughly 2.5 trillion) can exceed the range of a 32-bit `int`, the product is accumulated using `long long` to avoid overflow.

- **Time complexity:** `O(n * w)`, where `n` is the length of the digit string (1000) and `w = 13` is the fixed window size — each of the `n - w` windows requires computing a product over `w` digits.
- **Space complexity:** `O(n)`, for storing the full digit string.