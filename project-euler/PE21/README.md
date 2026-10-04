# Project Euler - Problem 21

## Problem

For any number, its proper divisors are the numbers smaller than it that divide into it evenly, and summing those gives a related value. Two distinct numbers are considered a matching pair when each one's divisor sum produces the other. Find the total of every number below 10,000 that takes part in such a pair.

## Approach

A helper function computes the sum of proper divisors of a number by checking factors up to its square root: for every factor `i` found, both `i` and its pair `n / i` are added (unless they're equal, in which case it's only counted once), and the number itself is subtracted at the end since only proper divisors should count. For every number below 10,000, this function is applied twice — once to get its divisor sum, and again on that result — to check whether applying it twice returns the original number while the two numbers involved aren't the same. Any number satisfying this condition is added to a running total.

- **Time complexity:** `O(n * sqrt(n))`, where `n = 10,000` — each number requires computing its proper divisor sum in `O(sqrt(n))`, and this is done (at most twice) for every number in the range.
- **Space complexity:** `O(1)` — only a few integer variables are used regardless of input size.