# Project Euler - Problem 16

## Problem

Take 2^15, which works out to 32768 — adding up its digits (3, 2, 7, 6, and 8) gives 26. Using that same idea, determine what the digits of 2^1000 add up to.

## Approach

Since 2^1000 is far too large to fit in any standard numeric type, it was represented as an array of digits (least significant digit first) and built up through repeated doubling, starting from the digit array for 2^1. Doubling the number 999 times produces 2^1000. Each doubling step multiplies every digit by 2, propagating any carry to the next position — the same process used in manual multiplication. Once the full number is built, its digits are simply summed to produce the final answer.

- **Time complexity:** `O(k * d)`, where `k = 999` is the number of doublings and `d = 500` is the fixed digit array size — each doubling step touches every digit once.
- **Space complexity:** `O(d)`, for the fixed-size array holding the digits of the number.