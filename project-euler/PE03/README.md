# Project Euler - Problem 3

## Problem

The prime factors of 13195 are 5, 7, 13, and 29. Find the largest prime factor of the number 600,851,475,143.

## Approach

Used trial division to factor the number: starting from 2, repeatedly divided out every factor `i` while `i * i` stays less than or equal to the remaining value of `x`. Each time a factor was fully divided out, it was recorded as the current largest factor found so far. Once the loop ends, if the remaining value of `x` is still greater than 1, it means `x` itself is a prime number larger than the square root of the original input — in that case, `x` is the answer. Otherwise, the largest recorded factor during the loop is the answer.

This avoids checking every number up to `x` directly, since any composite factor larger than `sqrt(x)` must pair with a smaller factor that would already have been found.

- **Time complexity:** `O(sqrt(n))`, where `n` is the input number — the loop only needs to check potential factors up to the square root of the (shrinking) remaining value.
- **Space complexity:** `O(1)` — only a few variables are used regardless of input size.