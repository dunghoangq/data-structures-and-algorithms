/*
Given integer aray nums. Return true if there's any integer appears more than once. Else return false.

e.g.1,

Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.

e.g.2,

Input: nums = [1,2,3,4]
Output: false

Explanation:
All elements are distinct

e.g.3,

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

--------------------------

ALGO

- Time: O(n)
- Space: O(1)

CONTAINS-DUPLICATE(nums)
    n = nums.length
    if n == 1
        return false
    
    x = 0

    for i = 0..n - 1
        x = XOR(x, nums[i])
        if x == 0
            return true
    
    return false
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool containsDuplicate(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return false;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 1}; // true
    std::vector<int> nums2 = {1, 2, 3, 4}; // false
    std::vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2}; // true
    std::cout << containsDuplicate(nums1) << "\n";
    std::cout << containsDuplicate(nums2) << "\n";
    std::cout << containsDuplicate(nums3) << "\n";
    return 0;
}