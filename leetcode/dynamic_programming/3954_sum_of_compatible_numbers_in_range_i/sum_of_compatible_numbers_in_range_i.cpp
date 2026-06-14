/*
SUM OF COMPATIBLE NUMBERS IN RANGE I

You are given two integers n and k.

A positive integer x is called compatible if it satisfies both of the following conditions:
- abs(n-x) <= k
- (n & x) == 0

Return the sum of all compatible integers x.

Note:
- Here, & denotes the bitwise AND operator.
- The absolute difference between integers i and j is defined as abs(i - j).

e.g.1,

Input: n = 2, k = 3
Output: 10

Explanation:
The compatible integers are:
- x = 1, since abs(2 - 1) = 1 and 2 & 1 = 0.
- x = 4, since abs(2 - 4) = 2 and 2 & 4 = 0.
- x = 5, since abs(2 - 5) = 3 and 2 & 5 = 0.
Thus, the answer is 1 + 4 + 5 = 10.

e.g.2,

Input: n = 5, k = 1
Output: 0

Explanation:
There are no compatible integers in the range [4, 6]. Thus, the answer is 0.

------------------------------------

ALGORITHM

SUM_OF_GOOD_INTEGERS(n, k)
    sum = 0

    // x must be from max(0, n-k) to n+k
    for i = max(0, n-k) to n + k:
        if i & n == 0:
            sum += i
    return sum

COMPLEXITY

- Time: O(n + k)
- Space: O(1)
*/

#include <iostream>

int sum_of_good_integers(int n, int k) {
    int sum = 0;    // might use long long sum if it's large number.

    for (int i = std::max(0, n - k); i <= n + k; i++) {
        if ((i & n) == 0) sum += i;
    }
    return sum;
}

int main() {
    std::cout << sum_of_good_integers(2, 3) << "\n";    // 10
    std::cout << sum_of_good_integers(5, 1) << "\n";    // 0
    std::cout << sum_of_good_integers(1, 13) << "\n";   // 56
    return 0;
}