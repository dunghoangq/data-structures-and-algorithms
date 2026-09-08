/*
SEARCH IN ROTATED SORTED ARRAY

Integer array nums sorted in ascending order (distinct values only).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

e.g.1,

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

e.g.2,

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

e.g.3,

Input: nums = [1], target = 0
Output: -1

----------------------------------

ALGORITHM

Binary search
- Time: O(log n)
- Space: O(1)

BINARY-SEARCH(nums, target, start, end)
    if start > end
        return -1
    mid = start + (end - start) / 2

    if nums[mid] == target
        return mid
    BINARY-SEARCH(nums, target, start, mid - 1)
    BINARY-SEARCH(nums, target, mid + 1, end)

SEARCH(nums, target)
    n = nums.length
    return BINARY-SEARCH(nums, target, 0, n-1)
*/

#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int target, int start, int end) {
    if (start > end) return -1;
    
    int mid = start + (end - start)/2;

    if (nums[mid] == target) return mid;
    if (nums[start] <= nums[mid]) {
        if (nums[start] <= target && target < nums[mid])
            return binarySearch(nums, target, start, mid - 1);
        else
            return binarySearch(nums, target, mid + 1, end);
    }
    else {
        if (nums[mid] < target && target <= nums[end])
            return binarySearch(nums, target, mid + 1, end);
        else
            return binarySearch(nums, target, start, mid - 1);
    }
}

int search(std::vector<int>& nums, int target) {
    int n = nums.size();
    return binarySearch(nums, target, 0, n - 1);
}

int main() {
    std::vector<int> nums = {4,5,6,7,0,1,2};
    std::cout << search(nums, 0) << "\n"; // 4
    std::cout << search(nums, 3) << "\n"; // -1

    nums = {4,5,6,7,8,1,2,3};
    std::cout << search(nums, 8) << "\n"; // 4

    nums = {5,1,2,3,4};
    std::cout << search(nums, 1) << "\n"; // 1

    nums = {4,5,6,7,0,1,2};
    std::cout << search(nums, 0) << "\n"; // 4

    nums = {4,5,6,7,0,1,2};
    std::cout << search(nums, 0) << "\n"; // 4

    return 0;
}