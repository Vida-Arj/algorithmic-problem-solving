# Project Euler - Problem 40

## Problem

Imagine writing out the positive integers one after another to form a fractional number: 0.123456789101112... Find the product of the digits at seven specific positions after the decimal point: the 1st, 10th, 100th, 1,000th, 10,000th, 100,000th, and 1,000,000th.

## Approach

Built the fractional digit sequence by converting each integer to a string and appending it to a running result string, starting after `"0."`. Rather than guessing in advance how many integers would need to be concatenated, the loop keeps appending integers only until the string has grown long enough to contain the 1,000,000th digit — stopping as soon as that length is reached, so no unnecessary work is done beyond what's needed. Once the sequence is long enough, the digit at each of the seven required positions is looked up directly by its index in the string (accounting for the two-character `"0."` prefix) and converted back from a character to its numeric value. The final answer is the product of these seven digits.

- **Time complexity:** `O(d)`, where `d = 1,000,001` is the target string length — the loop stops as soon as the sequence reaches this length, so only as many integers as necessary are ever converted and appended.
- **Space complexity:** `O(d)`, for storing the concatenated digit sequence up to the required length.