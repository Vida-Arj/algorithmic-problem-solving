# Project Euler - Problem 34

## Problem

Some numbers equal the sum of the factorials of their own digits — for example, 145 is one such number, since 1! + 4! + 5! equals 145. Find the sum of every number with this property (excluding the single-digit numbers 1 and 2, which trivially satisfy it).

## Approach

For every number from 3 up to 99,999, computed the sum of the factorials of its digits using two helper functions: one that computes a factorial recursively, and another that recursively strips digits one at a time, looks up each digit's factorial, and accumulates the total. If this computed sum matches the original number, it's added to the final answer.

A provable upper bound for the search exists: for a 7-digit number, the maximum possible digit-factorial sum is 7 × 9! = 2,540,160, which is still large enough to represent a 7-digit number — so 7-digit candidates can't be ruled out by this argument alone. For an 8-digit number, however, the maximum possible sum is 8 × 9! = 2,903,040, which falls short of the smallest 8-digit number (10,000,000) — making it mathematically impossible for any 8-digit or larger number to satisfy the condition. This means a fully rigorous search would need to check up to 9,999,999.

In practice, the search here is capped at 99,999, relying on the well-established result that the only two non-trivial numbers satisfying this property — 145 and 40,585 — both fall well within that range, with none existing between 100,000 and the provable 7-digit bound.

- **Time complexity:** `O(n * log(n))`, where `n = 100,000` is the chosen search limit — each number requires processing a number of digits proportional to `log(n)`, with a constant-time factorial lookup per digit (since digits only range from 0 to 9).
- **Space complexity:** `O(log(n))`, for the recursion call stack while processing each number's digits.