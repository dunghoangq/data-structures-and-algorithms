/*
LARGEST PERIMETER TRIANGLE

Given an integer array nums, return the largest perimeter of a trianle with a non-zero area, formed from three of these lengths. If it is impossible to form any trianle of a non-zero area, return 0.

e.g.1,

Input: nums = [2,1,2]
Output: 5

Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

e.g.2,

Input: nums = [1,2,1,10]
Output: 0

Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.

-----------------------------------

ALGORITHM

LARGEST_PERIMETER(nums)
    SORT(nums)

    for i = n - 3 to 0
        if nums[i] + nums[i+1] > nums[i+2]
            return nums[i] + nums[i+1] + nums[i+2]
    
    return 0

COMPLEXITY

- Time: O(n log n) for sort

*/

#include <iostream>
#include <vector>
#include <algorithm>

int largest_perimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    for (int i = nums.size() - 3; i >= 0; i--) {
        if (nums[i] + nums[i+1] > nums[i+2])
            return nums[i] + nums[i+1] + nums[i+2];
    }

    return 0;
}