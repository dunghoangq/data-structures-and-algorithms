/*
MINIMUM SUM OF FOUR DIGIT NUMBER AFTER SPLITTING DIGITS

You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].

Return the minimum possible sum of new1 and new2.

e.g.1,

Input: num = 2932
Output: 52

Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

e.g.2,

Input: num = 4009
Output: 13

Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.

-----------------------

ALGORITHM

Greedy
- Time: O(1)
- Space: O(1)

MINIMUM-SUM(num)
    Make list of each digit in num
    SORT(list)

    sum = 0
    sum <- sum + first two digits * 10
    sum <- sum + last two digits

    return sum

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int minimumSum(int num) {
    std::vector<int> num_list;
    for (int i = 0; i < 4; i++) {
        num_list.push_back(num % 10);
        num /= 10;
    }
    std::sort(num_list.begin(), num_list.end());

    return num_list[0] * 10 + num_list[1] * 10 + num_list[2] + num_list[3];
}

int main() {
    std::cout << minimumSum(2932) << "\n"; // 52
    std::cout << minimumSum(4009) << "\n"; // 13
    return 0;
}