/*
MINIMUM SUBSEQUENCE IN NON-INCREASING ORDER

Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence.

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

e.g.1,

Input: nums = [4,3,10,9,8]
Output: [10,9]

Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included. However, the subsequence [10,9] has the maximum total sum of its elements.

e.g.2,

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 

Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to be returned in non-increasing order.

-----------------------------

ALGORITHM

Greedy
- Time: O(n log n)
- Space: O(n)

MIN_SUBSEQUENCE(nums)
    SORT(nums) decreasing
    sum = SUM(nums)
    curr_sum = 0
    result = []

    for i = 0 to nums.length - 1
        curr_sum += nums[i]
        result.append(nums[i])
        if curr_sum > sum / 2
            break
    
    return result
*/

#include <iostream>
#include <vector>
#include <algorithm> // for rances::sort
#include <functional> // for ranges::greater
#include <numeric> // for accumulate

std::vector<int> min_subsequence(std::vector<int>& nums) {
    std::ranges::sort(nums, std::ranges::greater());
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int curr_sum = 0;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        result.push_back(nums[i]);
        curr_sum += nums[i];
        if (curr_sum > sum / 2) break;
    }

    return result;
}