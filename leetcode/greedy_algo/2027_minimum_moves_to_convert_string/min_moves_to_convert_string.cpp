/*
MINIMUM MOVES TO CONVERT STRING

You are given a string s consisting of n characters which are either 'X' or 'O'.

A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.

Return the minimum number of moves required so that all the characters of s are converted to 'O'.

e.g.1,

Input: s = "XXX"
Output: 1

Explanation: XXX -> OOO
We select all the 3 characters and convert them in one move.

e.g.2,

Input: s = "XXOX"
Output: 2

Explanation: XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.

e.g.3,

Input: s = "OOOO"
Output: 0

Explanation: There are no 'X's in s to convert.

----------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(1)

MINIMUM-MOVES(s)
    moves = 0
    current_chunk = -1
    n = s.length

    for i = 0 ... n - 3
        if s[i] == 'X'
            if current_chunk == -1
                moves++
                current_chunk = i
            else if i >=  current_chunk + 3
                moves++
                current_chunk = i
            else
                continue
*/

#include <iostream>
#include <string>

int minimumMoves(std::string s) {
    int moves = 0;
    int current_chunk = -3;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == 'X') {
            if (i >= current_chunk + 3) {
                moves++;
                current_chunk = i;
            }
        }
    }

    return moves;
}

int main() {
    std::cout << minimumMoves("XXX") << "\n"; // 1
    std::cout << minimumMoves("XXOX") << "\n"; // 2
    std::cout << minimumMoves("OOOO") << "\n"; // 0
    return 0;
}