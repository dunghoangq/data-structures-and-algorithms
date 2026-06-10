/*
INTERSECTION OF TWO ARRAYS

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

e.g.1,

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

e.g.2,

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

------------------------------------------

ALGORITHM

INTERSECTION(nums1, nums2)
    SORT(nums2)
    result = []

    for i in nums1:
        if i in nums2 - binary search:
            result.append(i)

    deduplicate result
    return result

COMPLEXITY

- Time: O(m log n + n log n)
    - O(n log n) for sorting nums2
    - O(m log n) for loop and binary search
- Space: O(k) to store result

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums2.begin(), nums2.end());
    std::unordered_set<int> result;

    for (const auto& i : nums1) {
        int l = 0;
        int r = nums2.size() - 1;
        bool is_in_nums2 = false;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (nums2[mid] == i) {
                is_in_nums2 = true;
                break;
            }
            if (nums2[mid] < i) l = mid + 1;
            else r = mid - 1;
        }

        if (is_in_nums2 == true) result.insert(i);
    }

    std::vector<int> final_result(result.begin(), result.end());
    return final_result;
}

int main() {
    std::vector<int> nums1 = {4,9,5};
    std::vector<int> nums2 = {9, 4, 9, 4, 8};
    std::vector<int> result = intersection(nums1, nums2);

    std::cout << "[";
    for (const auto& i : result) {
        std::cout << i << " ";
    }
    std::cout << "]";
    return 0;
}