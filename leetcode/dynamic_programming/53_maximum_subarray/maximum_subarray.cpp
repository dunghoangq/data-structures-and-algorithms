/*
MAXIMUM SUBARRAY

Given an integer array nums, find the subarray with the largest sum, and return its sum.

e.g.1,

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Explanation: The subarray [4,-1,2,1] has the largest sum 6.

e.g.2,

Input: nums = [1]
Output: 1

Explanation: The subarray [1] has the largest sum 1.

e.g.3,

Input: nums = [5,4,-1,7,8]
Output: 23

Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

------------------------------

ALGORITHM

Dp
- Time: O(n^2)
- Space: O(n^2)

MAX-SUBARRAY(nums)
    dp = [i][j] := sum of subarray from i to j

    max_val = -inf
    
    for i = 0 to nums.length
        dp[i][j] = nums[i]
        if dp[i][j] > max_val
            max_val = dp[i][j]
    
    for i = 0 to nums.length - 1
        for j = i + 1 to nums.length
            dp[i][j] = dp[i][j - 1] + dp[j]
            if dp[i][j] > max_val
                max_val = dp[i][j]

    return max_val


Better Dp - Kadane's DP recurrence
- Time: O(n^2)
- Space: O(n)

dp[i] := maximum sum at position i
*/

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
#include <algorithm>

// int maxSubarray(std::vector<int>& nums) {
//     int n = nums.size();
//     std::vector<std::vector<int>> dp(n, std::vector<int>(n));
//     int max_val = nums[0];

//     for (int i = 0; i < n; i++) {
//         dp[i][i] = nums[i];
//         if (dp[i][i] > max_val) max_val = dp[i][i];
//     }

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             dp[i][j] = dp[i][j-1] + nums[j];

//             if (dp[i][j] > max_val) max_val = dp[i][j];
//         }
//     }
//     return max_val;
// }

int maxSubarray(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-1] + nums[i]);
    }
    auto max_ele = std::max_element(dp.begin(), dp.end());
    int max_val = *max_ele;
    return max_val;
}

// Not even need a dp
int maxSubarray(std::vector<int>& nums) {
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current = std::max(nums[i], current + nums[i]);
        best = std::max(best, current);
    }

    return best;
}
