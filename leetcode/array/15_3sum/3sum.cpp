/*
3SUM

Given an integer array nums, return all triplets [nums[i], nums[j], nums[k]] such that i != j, j != k, k != i, and nums[i] + nums[j] + nums[k] = 0.

Notice that the solution set must not contain duplicate triplets.

e.g.1,

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

e.g.2,

Input: nums = [0,1,1]
Output: []

Explanation: The only possible triplet does not sum up to 0.

e.g.3,

Input: nums = [0,0,0]
Output: [[0,0,0]]

Explanation: The only possible triplet sums up to 0.

---------------------------

ALGORITHM

2 pointer
- Time: O(n^2)
- Space: O(1)

THREE-SUM(nums)
    if nums.length < 3
        return []

    SORT(nums)

    n = nums.length
    result = []

    for i = 0..n-3
        if i > 0 and nums[i] == nums[i-1]
            continue
        target = -nums[i]
        j = i + 1
        k = n - 1

        while j < k
            if nums[j] + nums[k] > target
                k--
            else if nums[j] + nums[k] < target
                j++
            else
                result.append([nums[i], nums[j], nums[k]])
                while nums[j] == nums[j+1]
                    j++
                while nums[k] == nums[k-1]
                    k--
                j++
                k--
    
    return result
        
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> result;
    if (n < 3) return result;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        int target = -nums[i];
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            if (nums[j] + nums[k] < target) j++;
            else if (nums[j] + nums[k] > target) k--;
            else {
                result.push_back({nums[i], nums[j], nums[k]});
                std::cout << i << ", " << j << ", " << k << "\n";
                while (j < k && nums[j] == nums[j+1])
                    j++;
                while (j < k && nums[k] == nums[k-1])
                    k--;
                j++;
                k--;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1,2,0,1,0,0,0,0};
    std::vector<std::vector<int>> result = threeSum(nums);
    return 0;
}