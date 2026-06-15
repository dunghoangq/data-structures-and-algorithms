/*
ARRAY PARTITION

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1),... (an, bn) such that the sum of min(ai, bi) for all i is maximised.
Retrun the maximised sum.

e.g.1,

Input: nums = [1,4,3,2]
Output: 4

Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.

e.g.2,

Input: nums = [6,2,6,5,1,2]
Output: 9

Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.

-----------------------------------------

ALGORITHM

ARRAY_PAIR_SUM(nums)
    n = nums.length / 2
    SORT(nums)

    sum = 0

    for i = 0 to k - 1:
        sum += nums[2*i]
    return sum

COMPLEXITY

- Time: O(n log n)
- Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>

// Greedy Approach

// int array_pair_sum(std::vector<int> nums) {
//     int n = nums.size() / 2;
//     std::sort(nums.begin(), nums.end());

//     int sum = 0;
//     for (int i = 0; i < n; i++) sum += nums[2*i];

//     return sum;
// }

// Counting-sort approach, much faster O(n + k) with k = 20001

int array_pair_sum(std::vector<int> nums) {
    std::vector<int> count(20001, 0);

    for (int x : nums)
        count[x + 10000]++;

    bool take = true;
    int sum = 0;

    for (int i = 0; i < 20001; i++) {
        while (count[i]--) {
            if (take) sum += i - 10000;
            take = !take;
        }
    }
    return sum;
}

int main() {
    std::cout << array_pair_sum({1, 4, 3, 2}) << "\n"; // 4
    std::cout << array_pair_sum({6,2,6,5,1,2}) << "\n"; // 9
    return 0;
}