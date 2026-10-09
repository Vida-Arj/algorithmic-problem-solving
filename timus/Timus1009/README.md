# Timus - Problem 1009

## Problem

Count how many numbers written in base K have exactly N digits and never contain two zeros in a row. A number written with leading zeros is counted by its real length, so the first digit can't be zero. The inputs satisfy 2 ≤ K ≤ 10, N ≥ 2, and N + K ≤ 18. The program reads N and K (each on its own line) from standard input and prints the count. For example, N = 2 and K = 10 gives 90.

## Approach

Used dynamic programming over the number of digits. Let `f(n)` be the number of valid `n`-digit numbers in base K. Looking at the last digit, there are two cases:

- **The last digit is non-zero** (K − 1 choices). The first `n - 1` digits can be any valid `(n - 1)`-digit number, giving `(K - 1) * f(n - 1)` numbers.
- **The last digit is zero.** The digit before it must then be non-zero, since otherwise there would be two zeros in a row. So the number ends with a non-zero digit followed by a zero, and the first `n - 2` digits can be any valid `(n - 2)`-digit number, giving `(K - 1) * f(n - 2)` numbers.

These cases never overlap and cover every valid number, so:

`f(n) = (K - 1) * (f(n - 1) + f(n - 2))`

The base cases are `f(1) = K - 1` (the digits 1 to K − 1, since the first digit can't be zero) and `f(0) = 1`. The value `f(0) = 1` stands for the empty prefix, and it makes `n = 2` work: the two-digit numbers ending in zero are a non-zero digit followed by 0, which is exactly `K - 1` numbers. For the sample, `f(1) = 9` and `f(2) = 9 * (9 + 1) = 90`, matching the expected answer.

The table has 20 entries, which is enough: since K ≥ 2 and N + K ≤ 18, N is at most 16. The largest answer the constraints allow is 1,434,392,064 (for N = 11 and K = 7), well within the range of a 64-bit integer.

- **Time complexity:** `O(n)`, where `n = N` is the number of digits — each value is computed once from the two before it.
- **Space complexity:** `O(n)`, for the table of counts (this could be reduced to `O(1)` by keeping only the last two values).