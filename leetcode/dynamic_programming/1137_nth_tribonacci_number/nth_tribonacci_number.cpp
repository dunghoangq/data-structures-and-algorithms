/*
N-TH TRIBONACCI NUMBER

The Tribonacci sequence Tn is defined as follow:

T0 = 0, T1 = 1, T2 = 1, and
Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

e.g.1,

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

e.g.2,

Input: n = 25
Output: 1389537

--------------------------------------------

ALGORITHM

TRIBONACCI(n)
    if n < 3:
        return 0
    
    t0 = 0
    t1 = 1
    t2 = 1

    for i = 3 to n:
        j = t2
        t2 += t0 + t1
        t0 = t1
        t1 = j
    
    return t2

COMPLEXITY

- Time: O(n)
- Space: O(1)

*/

#include <iostream>
#include <vector>

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int t0 = 0;
    int t1 = 1;
    int t2 = 1;

    for (int i = 3; i <= n; i++) {
        int j = t2;
        t2 += t0 + t1;
        t0 = t1;
        t1 = j;
    }
    return t2;
}

int main() {
    std::vector<int> ns = {4, 25};

    for (const auto& n: ns)
        std::cout << tribonacci(n) << "\n";
}