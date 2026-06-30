/*
LATEST TIME BY REPLACING HIDDEN DIGITS

You are given a string time in the form of hh:mm, where some of the digits in the string are hidden (represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.

e.g.1,

Input: time = "2?:?0"
Output: "23:50"

Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.

e.g.2,

Input: time = "0?:3?"
Output: "09:39"

e.g.3,

Input: time = "1?:22"
Output: "19:22"

----------------------------------

ALGORITHM

Greedy
- Time: O(1)
- Space: (1)

MAXIMUM-TIME(time)

    // Hour update
    if time[0] == "?"
        if time[1] in {"?", "0", "1", "2", "3"}
            time[0] = "2"
        else
            time[0] = "1"
    if time[1] == "?"
        if time[0] == "1" or "0"
            time[1] = "9"
        else
            time[1] = "3"
    
    // Min updates
    if time[3] == "?"
        time[3] = "5"
    if time[4] == "?"
        time[4] = "9"
    
    return time
*/

#include <iostream>
#include <string>

std::string maximum_time(std::string time) {
    // Hour updates
    std::string allowed_hours = "?0123";

    if (time[0] == '?') {
        if (allowed_hours.find(time[1]) != std::string::npos)
            time[0] = '2';
        else time[0] = '1';
    }
    if (time[1] == '?') {
        if (time[0] == '1' || time[0] == '0') time[1] = '9';
        else time[1] = '3';
    }

    // Min updates
    if (time[3] == '?') time[3] = '5';
    if (time[4] == '?') time[4] = '9';

    return time;
}

int main() {
    std::cout << maximum_time("2?:?0") << "\n"; // "23:50"
    std::cout << maximum_time("0?:3?") << "\n"; // "09:39"
    std::cout << maximum_time("1?:22") << "\n"; // "19:22"
}