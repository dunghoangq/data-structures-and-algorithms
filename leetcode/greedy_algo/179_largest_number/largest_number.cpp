/*
LARGEST NUMBER

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

e.g.1,

Input: nums = [10,2]
Output: "210"

e.g.2,

Input: nums = [3,30,34,5,9]
Output: "9534330"

----------------------

ALGORITHM

Greedy Insertion Sort
- Time: O(n^2k) for O(k) = cost of comparison
- Space: O(1)

IS-GREATER(x, y)
    a = x * 10 ^ string(y).length + y
    b = y * 10 ^ string(x).length + x

    return a > b

LARGEST-NUMBER(nums)
    if nums.length == 1
        return to_string(nums[0])
    i = 1
    j = 0

    while i < nums.length
        anchor = i
        while anchor > 0
            if IS-GREATER(nums[anchor - 1], nums[anchor]) == false
                temp = nums[anchor]
                nums[anchor] = nums[anchor - 1]
                nums[anchor - 1] = temp
                anchor--
            else
                break
        i++
   
    if nums[0] == 0
        return "0"
    result = ""
    for i = 0 ... nums.length - 1
        result += to_string(nums[i])
    return result

-------------------

Greedy Introsort (std::sort)
- Time: O(n log n)
- Space: O(n)

COMPARATOR(x, y)
    return xy > yx

LARGEST-NUMBER(nums)
    convert nums to string
    SORT(nums, COMPARATOR)
    result = concatenate nums
    return result
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string largestNumber(std::vector<int>& nums) {
    std::vector<std::string> strs;

    for (int x : nums) {
        strs.push_back(std::to_string(x));
    }

    std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
        return a + b > b + a;
    });

    if (strs[0] == "0") return "0";

    std::string result;

    for (const std::string& s : strs) result += s;
    return result;
}