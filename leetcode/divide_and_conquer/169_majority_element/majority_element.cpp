/*
MAJORITY ELEMENT

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

e.g.1,

Input: nums = [3,2,3]
Output: 3

e.g.2,

Input: nums = [2,2,1,1,1,2,2]
Output: 2

-----------------------------

ALGORITHM

Divide and Conquer
- Time: O(n log n) for insertion
- Space: O(n) for storing count of each unique element.

MAJORITY ELEMENT(nums)
    n = nums.length

    map = {key: count}

    for i = 0 to n - 1
        if nums[i] in map
            map[nums[i]]++
        else
            map[nums[i]] = 0
    
    return key with max count in map

-------------------------------

Boyer-Moore Voting Algorithm
- Time: O(n)
- Space: O(1)

MAJORITY_ELEMENT_BOYER_MOORE(nums)
    count = 0
    candidate = 0

    for num in nums
        if count == 0
            candidate = num
        
        count += (num == candidate) ? 1 : -1
    
    return candidate
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// int majority_element(std::vector<int>& nums) {
//     std::map<int, int> map;

//     for (int i = 0; i < nums.size(); i++) {
//         if (map.contains(nums[i]))
//             map[nums[i]]++;
//         else map[nums[i]] = 1;
//     }

//     auto max_pair = std::max_element(map.begin(), map.end(), [](const auto& a, const auto& b)
//         {return a.second < b.second;}
//     );

//     return max_pair->first;
// }


// Boyer-Moore Voting

int majority_element(std::vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) candidate = num;

        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}