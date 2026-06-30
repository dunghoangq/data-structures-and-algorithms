/*
MINIMUM OPERATIONS TO MAKE THE ARRAY INCREASING

You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.

- For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].

Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.

e.g.1,

Input: nums = [1,1,1]
Output: 3

Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].

e.g.2,

Input: nums = [1,5,2,4,1]
Output: 14

e.g.3,

Input: nums = [8]
Output: 0

----------------------------------------------

ALGORITHM

Greedy
- Time: 
- Space: 

MIN-OPERATIONS(nums)
    if nums.length == 1 or 0
        return 0

    ops = 0

    for i = 1 to nums.length - 1
        if nums[i] <= nums[i-1]
            ops += nums[i-1] - nums[i] + 1
            nums[i] += nums[i-1] - nums[i] + 1
    
    return ops
*/

#include <iostream>
#include <vector>

int minOperations(std::vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1)
        return 0;

    int ops = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i-1]) {
            ops += nums[i-1] - nums[i] + 1;
            nums[i] += nums[i-1] - nums[i] + 1;
        }
    }

    return ops;
}