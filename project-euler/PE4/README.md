# Project Euler - Problem 4

## Problem

A palindromic number reads the same both ways. Find the largest palindrome made from the product of two 3-digit numbers.

## Approach

Checked every product of two 3-digit numbers (from 100 to 999) and tested whether it reads the same forwards and backwards, keeping track of the largest palindrome found. To avoid redundant work, the inner loop starts from the current value of the outer loop instead of 100, since `i * j` and `j * i` produce the same product.

A helper function converts each product to a string and compares it with its reverse to determine whether it's a palindrome.

- **Time complexity:** `O(n^2)`, where `n = 900` is the range of 3-digit numbers — every pair of factors is checked once.
- **Space complexity:** `O(1)`, aside from the small string used temporarily to check each candidate for being a palindrome.