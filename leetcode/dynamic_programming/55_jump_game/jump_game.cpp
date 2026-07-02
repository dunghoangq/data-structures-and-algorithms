/*
JUMP GAME

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or alse otherwise.

e.g.1,

Input: nums = [2,3,1,1,4]
Output: true

Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

e.g.2,

Input: nums = [3,2,1,0,4]
Output: false

Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

-----------------------------

ALGORITHM

Dp
- Time: O(n)
- Space: O(1)

CAN-JUMP(nums)
    n = nums.length
    current_position = 0
    max_step = nums[current_position]
    max_range = 0

    while current_position  < n
        if nums[current_position] == 0
            return false
        for i = 1 ... max_step
            next_position = current_position + i
            next_max_range = next_position + nums[next_position]
            if next_max_range >= max_range
                max_range = next_max_range
                current_position = next_position
        if max_range >= n - 1
            return true
    return false
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool canJump(std::vector<int>& nums) {
    if (nums.size() == 1) return true;

    int curr_end = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = std::max(farthest, i + nums[i]);
        if (farthest >= nums.size() - 1) return true;
        else if (farthest == i) return false;

        if (farthest == curr_end) {
            curr_end = farthest;
        }
    }

    return false;
}

int main() {
    std::vector<int> nums = {2,3,1,1,4};
    std::cout << canJump(nums) << "\n";
    return 0;
}