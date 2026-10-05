# Project Euler - Problem 30

## Problem

Some numbers equal the sum of the fifth powers of their own digits — for instance, 4150 is one such number, since 4^5 + 1^5 + 5^5 + 0^5 equals 4150. Find the sum of every number that has this property, excluding the single-digit numbers 1 and 2 (which trivially satisfy it in a degenerate way).

## Approach

Checked every number from 2 up to one million, computing each one's digit sum of fifth powers through recursion: the function strips the last digit at each step, raises it to the fifth power, adds it to a running total, and recurses on the remaining digits until nothing is left. If this computed sum matches the original number, it's added to the final total.

The search is limited to numbers below one million because of a mathematical bound: a 6-digit number's maximum possible digit sum of fifth powers is 6 × 9^5 = 354,294, which is itself only 6 digits — but once a number reaches 7 digits, its maximum possible digit sum of fifth powers (7 × 9^5 = 413,343) can no longer reach that many digits, so no 7-digit or larger number could ever satisfy the condition.

- **Time complexity:** `O(n * log(n))`, where `n = 1,000,000` — each number requires processing a number of digits proportional to `log(n)`.
- **Space complexity:** `O(log(n))`, for the recursion call stack while processing each number's digits.