/*
JUMP GAME II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum lenght of a forward jump from index i-th. In other words, if you are at index i, you can jum to any index (i + j) where:

- 0 <= j <= nums[i] and
- i + j < n

Return the minimum number of jumps to reach index n - 1. The test cases are genereated such that you can reach index n - 1.

e.g.1,

Input: nums = [2,3,1,1,4]
Output: 2

Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

e.g.2,

Input: nums = [2,3,0,1,4]
Output: 2

------------------------

ALGORITHM

--DP Approach: Slow

JUMP(nums)
    n = nums.length
    min_jump

    dp = [] size n
    dp[0] = 0

    for i = 1 to n - 1
        min_jump = 99999
        for j = 0 to i - 1
            if j + nums[j] >= i and dp[j] + 1 < min_jump
                min_jump = dp[j] + 1
        dp[i] = min_jump
    
    return nums[n-1]

--Greedy Approach

JUMP(nums)
    n = nums.length
    target = n - 1
    steps = 0

    while target >= 0
        for i = 0 to target
            if i + nums[i] >= target
                target = i
                steps++

    return steps

--BFS

JUMP(nums)
    current_end = 0
    farthest = 0
    steps = 0

    for i = 0 to nums.length - 2
        farthest = max(farthest, i + nums[i])

        if (i == curr_end)
            steps++
            curr_end = farthest

    return steps

COMPLEXITY

DP
- Time: O(n^2)
- Space: O(n)

Greedy
- Time: O(n^2)
- Space: O(1)

Greedy - BFS style
- Time: O(n)
- Space: O(1)
*/

#include <iostream>
#include <vector>
#include <utility>

// DP: Super Slow

// int jump(std::vector<int>& nums) {
//     int n = nums.size();
//     int min_jump;

//     std::vector<int> dp(n);
//     dp[0] = 0;

//     for (int i = 1; i < n; i++) {
//         min_jump = 99999;

//         for (int j = 0; j < i; j++) {
//             if (j + nums[j] >= i && dp[j] + 1 < min_jump)
//                 min_jump = dp[j] + 1;
//         }
//         dp[i] = min_jump;
//     }

//     return dp[n-1];
// }

// Greedy: This is still O(n^2) -> Fucking slow!!!

// int jump(std::vector<int>& nums) {
//     int n = nums.size();
//     int target = n - 1;
//     int steps = 0;

//     while (target > 0) {
//         for (int i = 0; i < target; i++) {
//             if (i + nums[i] >= target) {
//                 target = i;
//                 steps++;
//                 break;
//             }
//         }
//     }

//     return steps;
// }


// BFS - O(n)
int jump(std::vector<int>& nums) {
    int curr_end = 0;
    int farthest = 0;
    int steps = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = std::max(farthest, i + nums[i]);

        if (i == curr_end) {
            steps++;
            curr_end = farthest;
        }
    }

    return steps;
}

int main() {
    std::vector<int> nums = {2,3,1,1,4};
    std::cout << "--nums = [";
    for (int i = 0; i < nums.size(); i++) {
        if (i != nums.size() - 1)
            std::cout << nums[i] << ", ";
        else std::cout << nums[i];
    }
    std::cout << "]\n";
    std::cout << jump(nums) << "\n";
}