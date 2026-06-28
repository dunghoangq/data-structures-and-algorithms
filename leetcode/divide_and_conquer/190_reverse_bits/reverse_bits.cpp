/*
REVERSE BITS

Reverse bits of a given 32-bit signed integer.

e.g.1,

Input: n = 43261596
Output: 964176192

Explanation:
Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000

e.g.2,

Input: n = 2147483644
Output: 1073741822

Explanation:
Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110

----------------------------

ALGORITHM

Divide and Conquer
- Time: O(1)
- Space: .
*/

#include <iostream>
#include <cstdint>
#include <bitset>

int reverse_bits(int n) {
    // 1. Swap adjacent 16-bit blocks
    n = (n >> 16) | (n << 16);
    // 2. Swap adjacent 8-bit blocks (0x00FF00FF selects every alternate byte)
    n = ((n & 0x00FF00FF) << 8) | ((n & 0xFF00FF00) >> 8);
    // 3. Swap adjacent 4-bit blocks (nibbles)
    n = ((n & 0x0F0F0F0F) << 4) | ((n & 0xF0F0F0F0) >> 4);
    // 4. Swap adjacent 2-bit blocks
    n = ((n & 0x33333333) << 2) | ((n & 0xCCCCCCC) >> 2);
    // 5. Swap adjacent single bits
    n = ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA) >> 1);
    
    return n;
}

uint32_t reverse_bits(int n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; ++i) {
        result <<= 1;       // Shift result left to make room for the next bit
        result |= (n & 1);  // Isolate the rightmost bit of n and add it to result
        n >>= 1;            // Move n right to look at the next bit
    }
    return result;
}