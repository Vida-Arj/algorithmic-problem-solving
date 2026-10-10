# Timus - Problem 1353

## Problem

Given a number S between 1 and 81, count how many integers from 1 up to 1,000,000,000 (inclusive) have digits that add up to exactly S. For S = 1 the answer is 10.

## Approach

Used dynamic programming with memoization over the number of digits and the remaining digit sum.

Every integer from 0 to 999,999,999 corresponds to exactly one string of 9 digits (padding with leading zeros where needed), so the task reduces to counting 9-digit strings whose digits add up to S. Let `VF(d, s)` be the number of ways to choose `d` digits, each from 0 to 9, that add up to `s`. Choosing the first digit `i` leaves `d - 1` digits that must add up to `s - i`, so:

`VF(d, s) = VF(d - 1, s) + VF(d - 1, s - 1) + ... + VF(d - 1, s - 9)`

The base cases are `VF(0, 0) = 1` (no digits left and nothing left to add up) and `VF(0, s) = 0` for any other `s`. A negative remaining sum is impossible, so it returns 0 immediately, which also keeps every table lookup inside the bounds of the array. Each result is stored in a table (initialised to -1 to mean "not computed yet"), so every `(d, s)` pair is only computed once.

The count for 9-digit strings covers the integers 0 to 999,999,999. The number 0 has digit sum 0, so it is never counted, since S is at least 1. The requested range also includes 1,000,000,000 itself, which is not a 9-digit string and has digit sum 1, so the answer is increased by one when S = 1. For S = 1 this gives the 9 numbers 1, 10, 100, ..., 100,000,000, plus 1,000,000,000, which makes 10, matching the sample. The largest answer over all allowed values of S is 45,433,800.

- **Time complexity:** `O(D * S * B)`, where `D = 9` is the number of digits, `S <= 81` is the largest digit sum, and `B = 10` is the number of possible digit values — each state is computed once with 10 additions. Since all three are fixed, this is effectively constant, at only a few thousand operations.
- **Space complexity:** `O(D * S)`, for the memoization table.