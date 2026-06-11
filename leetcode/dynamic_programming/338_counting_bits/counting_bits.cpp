/*
COUNTING BITS

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is te number of 1's in the binary representation of i.

e.g.1,

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

e.g.2,

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

------------------------------------------

ALGORITHM

COUNT_BITS(n)
    result = [0] * (n + 1)

    for i = 1 to n:
        result[i] = result[i >> 1] + i & 1
    
    return result

COMPLEXITY

- Time: O(n)
- Space: O(n)


*/

#include <iostream>
#include <vector>

std::vector<int> count_bits(int n) {
    std::vector<int> result(n + 1);

    for (int i=1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}