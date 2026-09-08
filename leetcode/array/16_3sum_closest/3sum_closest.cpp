/*
3SUM CLOSEST

You are given an integer array nums of length n and an integer target.

Find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

e.g.1,

Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

e.g.2,

Input: nums = [0,0,0], target = 1
Output: 0

Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

----------------------------------------

ALGORITHM

2 pointers
- Time:
- Space

THREE-SUM-CLOSEST(nums, target)
    n = nums.length
    closest_sum = NULL
    min_difference = inf

    SORT(nums)

    for i = 0..n-3
        if nums[i] > 0 and nums[i] == nums[i-1]
            continue
        j = i + 1
        k = n - 1

        while j < k
            three_sum = nums[i] + nums[j] + nums[k]
            difference = abs(target - three_sum)

            if difference == 0
                return three_sum
            else if difference > min_difference
                k--
            else
                min_difference = difference
                closest_sum = three_sum
                j++

    return closest_sum
*/

#include <iostream>
#include <vector>
#include <algorithm>

int threeSumClosest(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int closest_sum = nums[n-1] + nums[n-2] + nums[n-3];
    int min_difference = std::abs(target - closest_sum);
    std::cout << "Init sum: " << closest_sum << "\n";
    std::cout << "Init diff: " << min_difference << "\n";

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = n - 1;

        std::cout << "+ i = " << i << "\n";

        while (j < k) {
            int three_sum = nums[i] + nums[j] + nums[k];
            int diff = std::abs(target - three_sum);

            std::cout << "++++ j = " << j << ", k = " << k << ": three_sum = " << three_sum << ", diff = " << diff << "\n";

            if (diff == 0) return three_sum;
            if (diff < min_difference) {
                min_difference = diff;
                closest_sum = three_sum;
            }
            if (three_sum < target) j++;
            else k --;
        }
    }

    return closest_sum;
}

int main() {
    std::vector<int> nums = {-1,2,1,-4};
    std::cout << threeSumClosest(nums, 1) << "\n"; // 2

    nums = {0,0,0};
    std::cout << threeSumClosest(nums, 1) << "\n"; // 0

    nums = {0,1,2};
    std::cout << threeSumClosest(nums, 0) << "\n"; // 3

    nums = {1,1,1,1};
    std::cout << threeSumClosest(nums, 0) << "\n"; // 3

    return 0;
}