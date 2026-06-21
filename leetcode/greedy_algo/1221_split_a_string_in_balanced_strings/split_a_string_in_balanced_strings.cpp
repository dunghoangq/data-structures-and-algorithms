/*
SPLIT A STRING IN BALANCED STRINGS

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number os substrings such that:

- Each substring is balanced.

Return the maximum number of balanced strings you can obtain.

e.g.1,

Input: s = "RLRRLLRLRL"
Output: 4

Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

e.g.2,

Input: s = "RLRRRLLRLL"
Output: 2

Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.


e.g.3,

Input: s = "LLLLRRRR"
Output: 1

Explanation: s can be split into "LLLLRRRR".

------------------------------

ALGORITHM

------------------------------

Greedy
- Time: O(n)
- Space: O(1)

BALANCED_STRING_SPLIT(s)
    count = 0
    ls = 0
    rs = 0

    for i = 0 to s.length - 1
        if s[i] == 'L'
            ls++
        else
            rs++
        if ls == rs
            count++
            ls = rs = 0
    return count

*/

#include <iostream>
#include <string>

int balanced_string_split(std::string s) {
    int count = 0;
    int ls = 0;
    int rs = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 1) == "L") ls++;
        else rs++;

        if (ls == rs) {
            count++;
            ls = 0;
            rs = 0;
        }
    }

    return count;
}

int main() {
    std::cout << balanced_string_split("RLRRLLRLRL") << "\n"; // 4
    std::cout << balanced_string_split("RLRRRLLRLL") << "\n"; // 2
    std::cout << balanced_string_split("LLLLRRRR") << "\n"; // 2
    return 0;
}