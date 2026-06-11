/*
FIBONACCI NUMBER

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).

e.g.1,

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

e.g.2,

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

e.g.3,

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

----------------------------------------------------------

ALGORITHM

FIB(n)
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    f0 = 0
    f1 = 1

    for i = 2 to n:
        temp = f1
        f1 += f0
        f0 = temp
    
    return f1


COMPLEXITY

- Time: O(n)
- Space: O(1)

*/

#include <iostream>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int f0 = 0;
    int f1 = 1;

    for (int i = 2; i <= n; i++) {
        int temp = f1;
        f1 += f0;
        f0 = temp;
    }
    return f1;
}