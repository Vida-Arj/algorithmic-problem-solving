# Project Euler - Problem 25

## Problem

Each term in the Fibonacci sequence is built by adding the two terms that came before it, with the sequence beginning at 1 and 1. Determine the position, within this sequence, of the first term that reaches 1,000 digits in length.

## Approach

Since Fibonacci numbers of this size are far too large for any standard numeric type, each term is represented as an array of digits (least significant digit first), and new terms are generated through digit-by-digit addition with carry propagation — the same big-number addition technique used in earlier problems. Starting from the first two terms, the sequence is advanced one step at a time: the next term is computed as the sum of the previous two, the index counter is incremented, and the two tracked terms are shifted forward. This continues until the newly computed term's most significant digit position (index 999 in the array) is no longer zero, meaning the term has reached 1,000 digits — at which point the current index is the answer.

- **Time complexity:** `O(n * d)`, where `n` is the index of the answer and `d = 1000` is the fixed digit array size — each step requires a full digit-by-digit addition.
- **Space complexity:** `O(d)`, for the fixed-size digit arrays tracking the two most recent terms and their sum.