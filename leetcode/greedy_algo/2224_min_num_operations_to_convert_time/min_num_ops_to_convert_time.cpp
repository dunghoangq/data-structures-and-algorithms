/*
MINIMUM NUMBER OF OPERATIONS TO CONVERT TIME

You are given two strings current and correct representing 24-hour times.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.

Return the minimum number of operations needed to convert current to correct.

e.g.1,

Input: current = "02:30", correct = "04:35"
Output: 3

Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.


e.g.2,

Input: current = "11:00", correct = "11:01"
Output: 1

Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.

----------------------------------

ALGORITHM

Greedy
- Time: O(1)
- Space: O(1)

CONVERT-TIME(current, correct)
    Extract corr_h, corr_m from correct
    Extract curr_h, curr_m from current

    count = 0

    if corr_h == curr_h and curr_m <= corr_m
        diff = corr_m - curr_m
    else 
        count += 24*(corr_h <= curr_h) + corr_h - curr_h - 1*(corr_m < curr_m)
        diff = 60*(corr_m < curr_m) + corr_m - curr_m

    if diff >= 15
        curr_count = diff // 15
        count += curr_count
        diff -= curr_count * 15
    if diff >= 5
        curr_count = diff // 5
        count += curr_count
        diff -= curr_count * 5
    if diff >= 0
        count += diff

    return count
*/

#include <iostream>
#include <string>

int convertTime(std::string current, std::string correct) {
    int curr_h = std::stoi(current.substr(0, 2));
    int curr_m = std::stoi(current.substr(3, 2));
    int corr_h = std::stoi(correct.substr(0, 2));
    int corr_m = std::stoi(correct.substr(3, 2));

    int count = 0;
    int diff;

    if (corr_h == curr_h && curr_m <= corr_m)
        diff = corr_m - curr_m;
    else {
        count += 24*(corr_h <= curr_h) + corr_h - curr_h - 1*(corr_m < curr_m);
        diff = 60*(corr_m < curr_m) + corr_m - curr_m;
    }

    if (diff >= 15) {
        int curr_count = diff / 15;
        count += curr_count;
        diff -= curr_count * 15;
    }
    if (diff >= 5) {
        int curr_count = diff / 5;
        count += curr_count;
        diff -= curr_count * 5;
    }
    if (diff > 0) {
        count += diff;
    }

    return count;
}