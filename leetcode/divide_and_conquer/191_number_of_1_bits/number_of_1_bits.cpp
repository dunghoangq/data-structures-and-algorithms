/*
NUMBER OF 1 BITS

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

e.g.1,

Input: n = 11
Output: 3

Explanation:
The input binary string 1011 has a total of three set bits.

e.g.2,

Input: n = 128
Output: 1

Explanation:
The input binary string 10000000 has a total of one set bit.

e.g.3,

Input: n = 2147483645
Output: 30

Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

--------------------------------------

ALGORITHM

Divide and Conquer
- Time: O(N)
- Space: O(1)

HAMMING-WEIGHT(n)
    count = 0

    for i = 0 to number of bits of n
        count += (n & 1) ? 1 : 0
        n = n >> 1

    return count
*/

#include <iostream>
#include <climits>

int hamming_weight(int n) {
    int count = 0;
    size_t total_bits = sizeof(n) * CHAR_BIT;

    for (int i = 0; i < total_bits - 1; i++) {
        count += (n & 1) ? 1 : 0;
        n = n >> 1;
    }

    return count;
}