# Project Euler - Problem 22

## Problem

A text file contains several thousand first names, each wrapped in quotes and separated by commas. After sorting these names alphabetically, a score is calculated for each one: the sum of its letters' positions in the alphabet (A = 1, B = 2, and so on), multiplied by its position in the sorted list. Find the total of every name's score added together.

## Approach

Read the entire contents of the input file as a single string, then scanned through it character by character to extract each name: whenever a run of uppercase letters was found, it was collected as a name and added to a list, skipping over the quote and comma characters that separate entries. Once every name was extracted, the list was sorted alphabetically. Then, for each name, the alphabetical value of its letters was summed, multiplied by its 1-based position in the sorted list (the array index plus one), and added to a running total.

The input file (`names.txt`) is expected to be in the same directory as the compiled program, since it's read directly via a file stream.

- **Time complexity:** `O(n log n + n * l)`, where `n` is the number of names and `l` is the average name length — sorting dominates at `O(n log n)`, and computing each name's letter sum takes time proportional to its length.
- **Space complexity:** `O(n * l)`, for storing every name in memory.