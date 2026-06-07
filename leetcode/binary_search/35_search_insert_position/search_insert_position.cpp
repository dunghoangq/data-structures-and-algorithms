/*
SEARCH INSERT POSITION

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

e.g.1,

Input: nums = [1,3,5,6], target = 5
Output: 2

e.g.2,

Input: nums = [1,3,5,6], target = 2
Output: 1

e.g.3,

Input: nums = [1,3,5,6], target = 7
Output: 4

-----------------------------------------------

ALGO:

Since it requires O(log n) running time -> Sounds like divide and conquer.
Get the mid element > split nums into 2 halves: left and right.

SEARCH_INDEX(nums, target)
    left = 0
    right = nums.length - 1

    while left <= right:
        mid = left + (right - left)/2

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

Once the left crosses the right (left = right + 1), return left always true because that is the index to add the target.

COMPLEXITY

- Time: O(log n)
- Space: O(1) for using two pointers left and right.
*/

#include <iostream>
#include <vector>

int search_insert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int main() {
    std::vector<int> nums = {1,3,5,6};
    int target = 5;

    std::cout << search_insert(nums, target);
}