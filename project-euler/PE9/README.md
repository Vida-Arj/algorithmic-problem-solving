# Project Euler - Problem 9

## Problem

A Pythagorean triplet is a set of three natural numbers a < b < c for which a² + b² = c². There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product a × b × c.

## Approach

Brute-forced all combinations of three numbers from 1 to 998 using nested loops. For each triplet, a helper function first sorts the three values using a `swp` function (passed by reference) so that `a <= b <= c`, then checks whether the sorted values satisfy both the Pythagorean condition (`a² + b² = c²`) and the sum condition (`a + b + c = 1000`). As soon as a valid triplet is found, its product is printed and the program exits immediately, avoiding unnecessary further iterations.

- **Time complexity:** `O(n^3)`, where `n = 998` — every combination of three numbers in the given range is checked in the worst case.
- **Space complexity:** `O(1)` — only a fixed number of integer variables are used regardless of input size.