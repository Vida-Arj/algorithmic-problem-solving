# Project Euler - Problem 29

## Problem

Computing a^b for every combination of a and b within a given range produces a set of values, some of which repeat. For example, using 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5 produces 15 distinct values once duplicates are removed. Using 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100 instead, find how many distinct values are produced.

## Approach

Since values like 100^100 are far too large for any standard numeric type, each power is represented as a digit array (least significant digit first), built up through repeated big-number multiplication — for a fixed base `a`, each successive power is obtained by multiplying the previous result by `a` again, carrying over digit by digit as in manual multiplication. Every computed value is inserted into a `set`, which automatically discards duplicates since it only keeps unique entries. Once every combination of `a` and `b` in the given range has been processed, the final count of distinct values is simply the size of the set.

- **Time complexity:** `O(A * B * d)`, where `A = 99` and `B = 99` are the ranges for the base and exponent and `d = 201` is the fixed digit array size — each power requires a full digit-by-digit multiplication, and each set insertion involves comparing against existing entries of similar size.
- **Space complexity:** `O(A * B * d)` in the worst case, for storing every distinct value computed.