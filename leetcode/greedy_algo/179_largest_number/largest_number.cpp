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

Greedy
- Time: 
- Space: 

COMBINE(x, y)
    return x * 10 * string(y).length + y

GET-MAX(nums) // O(n)
    return max number in nums

LARGEST-NUMBER(nums)
    result = ""
    

*/