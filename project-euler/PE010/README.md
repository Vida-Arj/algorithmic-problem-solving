# Project Euler - Problem 10

## Problem

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. Find the sum of all the primes below two million.

## Approach

Used the Sieve of Eratosthenes to mark all composite numbers up to 2,000,000: for every number found to still be marked as prime, all of its multiples were marked as non-prime. As an optimization, marking starts from `i * i` rather than `2 * i`, since any smaller multiple of `i` would already have been marked by a smaller prime factor. Every number that remains marked as prime is added to a running sum, which is printed once the sieve is complete.

- **Time complexity:** `O(n log log n)`, the standard complexity of the Sieve of Eratosthenes for a range of size `n = 2,000,000`.
- **Space complexity:** `O(n)`, for the boolean array tracking primality of every number up to `n`.