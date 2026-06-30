/*
LARGEST ODD NUMBER IN STRING

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if odd integer exists.

A substring is a contiguous sequence of characters within a string.

e.g.1,

Input: num = "52"
Output: "5"

Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

e.g.2,

Input: num = "4206"
Output: ""

Explanation: There are no odd numbers in "4206".

e.g.3,

Input: num = "35427"
Output: "35427"

Explanation: "35427" is already an odd number.

----------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(1)

LARGEST-ODD-NUMBER(num)
    i = num.length - 1

    while i >= 0
        int digit = num[i]
        if digit % 2 == 1
            return num[:i]
        else
            i--
    return ""
*/

#include <iostream>
#include <string>

std::string largestOddNumber(std::string num) {
    int n = num.size();
    int i = n - 1;

    while (i >= 0) {
        int digit = num[i];
        if (digit % 2 == 1)
            return num.substr(0, i + 1);
        else i--;
    }

    return "";
}