/*
REMOVE DIGIT FROM NUMBER TO MAXIMISE RESULT

You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurence of digit from number such that the value of the resulting string in decimal form is maximised. The test cases are generated such that digit occurs at least once in number.

e.g.1,

Input: number = "123", digit = "3"
Output: "12"

Explanation: There is only one '3' in "123". After removing '3', the result is "12".

e.g.2,

Input: number = "1231", digit = "1"
Output: "231"

Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 > 123, we return "231".

e.g.3,

Input: number = "551", digit = "5"
Output: "51"

Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".

----------------------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(n)

REMOVE-DIGIT(number, digit)
    result = ""
    is_removed = false
    i = 0

    while is_removed is false and i < number.length
        c = number[i]
        if c == digit
            if i == number.length - 1 or c < number[i + 1]
                i ++
                is_removed = true
        result += c
    
    if i < number.length - 1
        result += number[i:]
    return result
*/

#include <iostream>
#include <string>

std::string removeDigit(std::string number, char digit) {
    std::string result;
    bool is_removed = false;
    int i = 0;
    int rm_idx = 0;

    while (!is_removed && i < number.size()) {
        char c = number[i];
        if (c == digit) {
            rm_idx = i;
            if (i == number.size() - 1 || c < number[i + 1]) {
                is_removed = true;
                i++;
                break;
            }
        }
        result += c;
        i++;
    }

    if (i < number.size())
        result += number.substr(i);
    if (!is_removed)
        result.erase(rm_idx, 1);
    std::cout << rm_idx << "\n";
    return result;
}

int main() {
    std::cout << removeDigit("123", '3') << "\n"; // 12
    std::cout << removeDigit("1231", '1') << "\n"; // 231
    std::cout << removeDigit("551", '5') << "\n"; // 51
    return 0;
}