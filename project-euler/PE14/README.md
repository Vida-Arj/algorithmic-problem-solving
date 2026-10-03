# Project Euler - Problem 14

## Problem

Starting from any positive integer n, a chain can be built by repeatedly halving n when it's even, or turning it into 3n + 1 when it's odd. It's conjectured (though unproven) that every such chain eventually reaches 1 regardless of the starting number. Among all starting numbers below one million, find the one that produces the longest chain before reaching 1.

## Approach

For every starting number from 1 to 999,999, computed the length of its Collatz chain recursively: each call reduces `n` according to the even/odd rule and adds 1 to the count, until `n` reaches 1. The chain length for each starting number is computed once and compared against the longest chain found so far, updating the answer whenever a longer one is found.

- **Time complexity:** Not rigorously bounded, since the length of a Collatz chain for a given `n` isn't known in closed form (this is tied to the still-unproven Collatz conjecture). In practice, chain lengths for numbers under one million stay well within a few hundred steps, so the total work stays efficient — but no formal upper bound like `O(n log n)` can be proven here.
- **Space complexity:** `O(d)`, where `d` is the maximum recursion depth (the length of the longest chain encountered), due to the recursive call stack.