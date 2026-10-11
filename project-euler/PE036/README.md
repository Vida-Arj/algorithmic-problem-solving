# Project Euler - Problem 36

## Problem

Some numbers read the same forwards and backwards in both base 10 and base 2 — for instance, 585 is 1001001001 in binary, and both representations are palindromic. Find the sum of every number below one million that has this double-palindrome property in both bases (without allowing leading zeros in either representation).

## Approach

For each number, its decimal digits and binary digits were each extracted recursively into separate arrays, one digit (or bit) at a time, by repeatedly taking the remainder and dividing down. A separate recursive helper then checks whether a given array of digits forms a palindrome, by comparing the outermost pair and working inward until the two pointers meet or cross. A number is counted toward the final sum only if both its decimal and binary digit sequences pass this palindrome check.

- **Time complexity:** `O(n * log(n))`, where `n = 1,000,000` — for each number, extracting its digits in either base and checking for a palindrome both take time proportional to the number of digits (or bits).
- **Space complexity:** `O(log(n))`, for the arrays holding a single number's decimal and binary digits at a time, plus the recursion call stack.