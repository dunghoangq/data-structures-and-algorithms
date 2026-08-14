/*
Given integer arrays: nums1, nums2, sorted in non-decreasing order.
Integer m, n are lengths of nums1, nums2.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

Do not return the new array, sort inplace nums1. so the actual nums1.length = m + n.

e.g.1,

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

e.g.2,

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

e.g.3,

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]

Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

--------------------------------

ALGORITHM

- Time: O(m + n)
- Space: O(1)

MERGE(nums1, m, nums2, n)
    i = m - 1
    j = n - 1

    for k = m + n - 1 .. 0
        if nums1[i] <= nums2[j]
            nums1[k] = nums1[i]
            i--
        else
            nums1[k] = nums2[j]
            j--
*/

#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;

    for (int k = m + n - 1; k >= 0; k--) {
        if (i < 0) {
            nums1[k] = nums2[j];
            j--;
        }
        else if (j < 0) {
            nums1[k] = nums1[i];
            i--;
        }
        else if (nums1[i] <= nums2[j]) {
            nums1[k] = nums2[j];
            j--;
        }
        else {
            nums1[k] = nums1[i];
            i--;
        }
        std::cout << nums1[k] << "\n";
    }
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3; int n = 3;
    merge(nums1, m, nums2, n);

    return 0;
}