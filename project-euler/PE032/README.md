# Project Euler - Problem 32

## Problem

A number is called 1-to-9 pandigital if it uses each of the digits 1 through 9 exactly once across its full representation. Find the sum of all distinct products in multiplication equations (multiplicand × multiplier = product) where the multiplicand, multiplier, and product together form a 1-to-9 pandigital set of digits.

## Approach

Generated every possible arrangement of the digits 1 through 9 using `next_permutation`. For each arrangement, tried every valid way to split it into three consecutive chunks — one for the multiplicand, one for the multiplier, and one for the product — such that their digit lengths add up to 9 total. A quick check skips any split where the product's digit length couldn't possibly be large enough to hold the result of multiplying the other two numbers, avoiding unnecessary work. For each remaining valid split, the three chunks were converted into actual numbers, and if the multiplicand times the multiplier equals the product, that product is added to a set (which automatically discards duplicates). Once every permutation and split has been checked, the final answer is the sum of all the unique products found in the set.

- **Time complexity:** `O(9! * d)`, where `9!` is the number of permutations of the digits and `d` is the small, bounded number of digit-length splits checked per permutation — overall still efficient given the fixed, small problem size.
- **Space complexity:** `O(k)`, where `k` is the number of distinct pandigital products found, for the set storing them.