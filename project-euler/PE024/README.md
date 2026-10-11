# Project Euler - Problem 24

## Problem

A permutation is simply a rearrangement of a set of items. If every possible arrangement of the digits 0 through 9 is listed in numerical order, find the one-millionth arrangement in that ordered list.

## Approach

Used the standard library's `next_permutation` function, which rearranges a sequence into its next lexicographically greater permutation. Starting from the digits 0 through 9 in ascending order (the very first permutation in lexicographic order), the function was called repeatedly in a loop, counting each arrangement as it was generated. Once the counter reached one million, the digits at that point represented the answer and were printed.

- **Time complexity:** `O(k * d)`, where `k = 1,000,000` is the number of permutations generated and `d = 10` is the number of digits — each call to `next_permutation` takes linear time in the number of elements.
- **Space complexity:** `O(d)`, for the fixed-size array holding the current permutation of digits.