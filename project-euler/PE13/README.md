# Project Euler - Problem 13

## Problem

Work out the first ten digits of the sum of one hundred given 50-digit numbers.

## Approach

Since the numbers are far too large to fit in any standard numeric type, each number was read as a string and processed digit by digit, similar to how addition is done by hand. Two numbers were read per iteration (50 iterations covering all 100 numbers), each converted into an array of digits in reverse order (least significant digit first). The digits of both numbers were added position by position into a running total array, carrying over any overflow (values of 10 or more) to the next position — exactly as in manual long addition. Because the total array persists across iterations, each new pair of numbers is added directly onto the cumulative sum built up so far.

Once all numbers were processed, the most significant non-zero digit position was located, and the digits were printed from there down to the first position, giving the full sum.

- **Time complexity:** `O(n * d)`, where `n = 100` is the number of input numbers and `d = 50` is the number of digits in each — every digit of every number is processed exactly once.
- **Space complexity:** `O(d)`, for the fixed-size digit arrays used to hold each number and the running sum.