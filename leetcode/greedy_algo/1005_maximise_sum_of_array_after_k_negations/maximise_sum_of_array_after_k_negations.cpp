/*
MAXIMISE SUM OF ARRAY AFTER K NEGATIONS

Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].

You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.

e.g.1,

Input: nums = [4,2,3], k = 1
Output: 5

Explanation: Choose index 1 and nums becomes [4,-2,3].

e.g.2,

Input: nums = [3,-1,0,2], k = 3
Output: 6

Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].

e.g.3,

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13

Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].

------------------------------------------

ALGORITHM

LARGEST_SUM_AFTER_NEGATIONS(nums, k)
    SORT(nums)
    sum = sum(nums)
    i = 0
    j = 0

    while i <= k and j < nums.length
        if sum > sum - nums[j] * 2
            i++    
            j++
            sum -= nums[j] * 2
        else if sum == sum - nums[j] * 2
            break
        else
            i++
            sum -= nums[j] * 2

    return sum

COMPLEXITY

- Time: O(n log n)
- Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>


int largest_sum_after_negations(std::vector<int>& nums, int k) {
    // Sort nums
    std::sort(nums.begin(), nums.end());
    std::cout << "Sorted nums = [";
    for (int i = 0; i < nums.size(); i ++) {
        if (i != nums.size() - 1)
            std::cout << nums[i] << ", ";
        else std::cout << nums[i];
    }
    std::cout << "]" << "\n";

    int i = 0;
    int j = 0;
    int min = nums[0];

    while (i < k && j <= nums.size()) {
        if (j == nums.size()) j--;
        if (nums[j] == 0) break;
        else if (nums[j] <= min) {
            nums[j] = -nums[j];
            min = nums[j];
            i++;
            j++;
        }
        else {
            j--;
            nums[j] = -nums[j];
            min = nums[j];
            i++;
        }
    }

    std::cout << "Result nums = [";
    for (int i = 0; i < nums.size(); i ++) {
        if (i != nums.size() - 1)
            std::cout << nums[i] << ", ";
        else std::cout << nums[i];
    }
    std::cout << "]" << "\n";
    return std::accumulate(nums.begin(), nums.end(), 0);
}

int main() {
    std::vector<std::pair<std::vector<int>, int>> numss = {
        {{4,2,3}, 1},           // 5
        {{3,-1,0,2}, 3},        // 6
        {{2,-3,-1,5,-4}, 2},    // 13
        {{-100,-100,-100}, 4},  // 100
        {{1,3,2,6,7,9}, 3},     // 26
        {{-8,3,-5,-3,-5,-2}, 6},// 22
        {{-4,-2,-3}, 4}         //
    };

    for (auto [nums, k] : numss) {
        std::cout << "nums = [";
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1)
                std::cout << nums[i] << ", ";
            else
                std::cout << nums[i];
        }
        std::cout << "]" << ", k = " << k << "\n";
        std::cout << largest_sum_after_negations(nums, k) << "\n";
    }
}