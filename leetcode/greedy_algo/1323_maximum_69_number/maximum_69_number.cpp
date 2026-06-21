/*
MAXIMUM 69 NUMBER

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

e.g.1,

Input: num = 9669
Output: 9969

Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

e.g.2,

Input: num = 9996
Output: 9999

Explanation: Changing the last digit 6 to 9 results in the maximum number.

e.g.3,

Input: num = 9999
Output: 9999

Explanation: It is better not to apply any change.

---------------------

ALGORITHM

- Time: O(n)

*/

#include <iostream>
#include <string> // Left to Right
#include <cmath> // Right to Left

// Left to Right

int maximum_69_number(int num) {
    std::string digits = std::to_string(num);

    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] == '6') {
            digits[i] = '9';
            break;
        }
    }

    return std::stoi(digits);
}

// Right to Left

int maximum_69_number_r2l(int num) {
    unsigned int n = num;

    while (n > 0) {
        int digit = n % 10;

        n /= 10;
    }
}