/*
PARTITION ARRAY INTO THREE PARTS WITH EQUAL SUM

Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i + 1 < j with (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])

e.g.1,

Input: arr = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true

Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

e.g.2,

Input: arr = [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false

e.g.3,

Input: arr = [3,3,6,5,-2,2,5,1,-9,4]
Output: true

Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4

------------------------------------------------

ALGORITHM

CAN_THREE_PARTS_EQUAL_SUM(arr)
    target_sum = sum(arr)/3 // each part = sum / 3
    part_sum = 0
    part_num = 0

    for i = 0 to arr.length - 1
        part_sum += arr[i]

        if part_sum == target_sum
            part_num++
            part_sum = 0
    
    return (part_num == 3)

COMPLEXITY

- Time: O(n)
- Space: O(1)

*/

#include <iostream>
#include <vector>
#include <numeric>

bool can_three_parts_equal_sum(std::vector<int>& arr) {
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    int target_sum;
    if (sum % 3 == 0)
        target_sum =  sum / 3;
    else return false;
    
    int part_sum = 0;
    int part_num = 0;

    for (int i = 0; i < arr.size(); i++) {
        part_sum += arr[i];
        if (part_sum == target_sum) {
            part_num++;
            part_sum = 0;
        }
    }

    return (part_num >= 3);
}
