# Timus - Problem 2018

## Problem

An album consists of n tracks, and each track is a remix of one of two songs, written as 1 or 2. The album is only acceptable if it never has more than `a` remixes of song 1 in a row, and never has more than `b` remixes of song 2 in a row. Count the number of different acceptable albums, where an album is a sequence of 1s and 2s of length n, and print the result modulo 1,000,000,007. The inputs satisfy 1 ≤ a, b ≤ 300 and max(a, b) + 1 ≤ n ≤ 50,000. For n = 3, a = 2, and b = 1, the acceptable albums are 112, 121, 211, and 212, so the answer is 4.

## Approach

Used dynamic programming over the length of the album, keeping track of which song the album currently ends with. Let `dpa[i]` be the number of acceptable sequences of length `i` that end with a run of 1s, and `dpb[i]` the number that end with a run of 2s.

A sequence of length `i` ending in a run of 1s of length `L` (where `1 <= L <= a`) is made of an acceptable sequence of length `i - L` that ends in a run of 2s, followed by `L` ones. The prefix must end in a 2, since otherwise its last run of 1s would merge with the new one and could exceed the limit. If the whole sequence is one run of 1s, the prefix is empty. Summing over every allowed run length gives:

`dpa[i] = dpb[i - 1] + dpb[i - 2] + ... + dpb[i - a]`

and symmetrically:

`dpb[i] = dpa[i - 1] + dpa[i - 2] + ... + dpa[i - b]`

where terms with a negative index are left out. The empty prefix is represented by `dpa[0] = dpb[0] = 1`, and the single-track cases are `dpa[1] = dpb[1] = 1`. The answer is `dpa[n] + dpb[n]`, and every addition is reduced modulo 1,000,000,007, since the number of sequences grows exponentially.

For the sample, `dpa = [1, 1, 2, 2]` and `dpb = [1, 1, 1, 2]`, so the answer is `2 + 2 = 4`, matching the expected output.

- **Time complexity:** `O(n * (a + b))` — each of the `n` lengths sums at most `a` terms for `dpa` and `b` terms for `dpb`. At the largest allowed input (n = 50,000 and a = b = 300) that is about 30 million additions, which runs in a fraction of a second. It could be reduced to `O(n)` by keeping prefix sums of the two tables, but the direct sums are fast enough for these limits.
- **Space complexity:** `O(n)`, for the two tables of counts.