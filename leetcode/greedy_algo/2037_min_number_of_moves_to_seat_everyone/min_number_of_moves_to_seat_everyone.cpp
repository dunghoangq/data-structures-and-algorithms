/*
MINIMUM NUMBER OF MOVES TO SEAT EVERYONE

There are n available seats and n students standing in a room. You are given an array seats of length n, where seats[i] is the position of the i-th seat. You are also given the array students of length n, where students[j] is the position of the j-th student.

You may perform the following move any of the times:

- Increase or decrease the position of the i-th student by 1 (i.e., moving the i-th student from position x to x + 1 or x - 1)

Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

e.g.1,

Input: seats = [3,1,5], students = [2,7,4]
Output: 4

Explanation: The students are moved as follows:
- The first student is moved from position 2 to position 1 using 1 move.
- The second student is moved from position 7 to position 5 using 2 moves.
- The third student is moved from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.

e.g.2,

Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7

Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from position 3 to position 4 using 1 move.
- The third student is moved from position 2 to position 5 using 3 moves.
- The fourth student is moved from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.

e.g.3,

Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4

Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from position 1 to position 2 using 1 move.
- The second student is moved from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.

--------------------------------

ALGORITHM

Greedy
- Time: O(n log n)
- Space: O(1)

MIN-MOVES-TO-SEAT(seats, students)
    SORT(seats)
    SORT(students)

    moves = 0
    for i = 0 ... n - 1
        moves += abs(seats[i] + students[i])

    return moves
*/

#include <iostream>
#include <vector>
#include <cmath>    // for abs
#include <numeric>  // for accumulate
#include <algorithm>

int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());

    int moves = 0;
    for (int i = 0; i < seats.size(); i++) {
        moves += std::abs(seats[i] - students[i]);
    }

    return moves;
}