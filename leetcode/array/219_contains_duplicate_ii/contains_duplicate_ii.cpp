/*
CONTAINS DUPLICATE II

Given an integer array nums, and an integer k, return true if there're indices i, j : nums[i] == nums[j], and abs(i - j) <= k.

e.g.1,

Input: nums = [1,2,3,1], k = 3
Output: true

e.g.2,

Input: nums = [1,0,1,1], k = 1
Output: true

e.g.3,

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

-----------------------

ALGORITHM

- Time: O(n)
- Space: O(k)

CONTAINS-NEARBY-DUPLICATE(nums, k)
    n = nums.length
    window = UNORDERED-SET()

    for i = 0..n-1
        if nums[i] in window
            return true
        window.add(nums[i])
        if window.length > k
            window.pop(nums[i - k])
    
    return false
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
//     int n = nums.size();
//     if (k == 0 || n < 2) return false;

//     std::unordered_set<int> window;

//     for (int i = 0; i < n; i++) {
//         if (window.contains(nums[i]))
//             return true;
//         window.insert(nums[i]);
        
//         if (window.size() > k)
//             window.erase(nums[i-k]);
//     }

//     return false;
// }


// Faster approach

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (k == 0 || n < 2) return false;

    std::unordered_map<int, int> window;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (window.contains(num) && i - window[num] <= k)
            return true;

        window[num] = i;
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << containsNearbyDuplicate(nums, 3) << "\n"; // true

    nums = {1, 0, 1, 1};
    std::cout << containsNearbyDuplicate(nums, 1) << "\n"; // true

    nums = {1,2,3,1,2,3};
    std::cout << containsNearbyDuplicate(nums, 2) << "\n"; // false

    nums = {2, 2};
    std::cout << containsNearbyDuplicate(nums, 3) << "\n"; // true

    nums = {1,4,2,3,1,2};
    std::cout << containsNearbyDuplicate(nums, 3) << "\n"; // true

    return 0;
}