/*
GUESS NUMBER HIGHER OR LOWER

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns thress possible results:
- -1: Your guess is higher than the number I picked (i.e. num > pick).
- 1: Your guess is lower than the number I picked (i.e. num < pick).
- 0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

e.g.1,

Input: n = 10, pick = 6
Output: 6

e.g.2,

Input: n = 1, pick = 1
Output: 1

e.g.3,

Input: n = 2, pick = 1
Output: 1

--------------------------------------------

ALGORITHM

GUESS_NUMBER(n)
    i = 1
    j = n

    while (i <= j):
        mid = i + (j - 1)//2

        if guess(mid) == 0:
            return mid
        eles if guess(mid) == -1:
            j = mid - 1
        else:
            i = mid + 1

COMPLEXITY

- Time: O(log n)
- Space: O(1)
*/

#include <iostream>

int guess(int num) {
    return 0;
}

int guess_number(int n) {
    int i = 1;
    int j = n;

    while (i <= j) {
        int mid = i + (j - i)/2;

        if (guess(mid) == 0) return mid;
        else if (guess(mid) == -1) j = mid - 1;
        else i = mid + 1;
    }
    return i;
}