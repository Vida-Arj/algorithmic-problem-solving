# Project Euler - Problem 20

## Problem

A factorial, written as n!, is the product of every integer from n down to 1. For example, 10! works out to 3628800, and adding up its digits (3, 6, 2, 8, 8, 0, and 0) gives 27. Using that same idea, determine the digit sum of 100!.

## Approach

Since 100! is far too large for any standard numeric type, it was represented as an array of digits (least significant digit first) and built up through repeated multiplication: starting from 1, the array is multiplied by each integer from 1 to 100 in turn, with carries propagated digit by digit exactly as in manual multiplication. Once the full value of 100! is built, its digits are summed to produce the final answer.

- **Time complexity:** `O(k * d)`, where `k = 100` is the number of multiplications and `d = 200` is the fixed digit array size — each multiplication step touches every digit once.
- **Space complexity:** `O(d)`, for the fixed-size array holding the digits of the number.