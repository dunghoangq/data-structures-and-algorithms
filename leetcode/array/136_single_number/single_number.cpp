/*
SINGLE NUMMBER

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

e.g.1., 

Input: nums = [2,2,1]
Output: 1


e.g.2.,

Input: nums = [4,1,2,1,2]
Output: 4

e.g.3.,

Input: nums = [1]
Output: 1

------------------------------

ALGORITHM

- Time: O(n)
- Space: O(1)

SINGLE-NUMBER(nums)
    if nums.length == 1
        return nums[0]
    
    x = 0

    for i = 0..nums.length - 1
        x = XOR(nums[i], x)

    return x
*/

#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    int x = 0;

    for (int i = 0; i < n; i++) {
        x = x ^ nums[i];
        std::cout << i << ": " << x << "\n";
    }
    
    return x;
}

int main() {
    std::vector<int> nums = {2, 2, 1};
    std::cout << singleNumber(nums) << "\n";
    return 0;
}