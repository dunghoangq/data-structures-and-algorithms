/*
DIVISOR GAME

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
- Choosing any integer x with 0 < x < n and n % x == 0;
- Replacing the number n on the chalkboard with n - x.

Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

e.g.1,

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

e.g.2,

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

-----------------------------

ALGORITHM

> lemma: if integer n not prime, any divisor of n is <= n/2.

n = ab, if a > n/2 -> b = n/a < 2 then n = 1 because n cannot be 0.
    -> a = n
    -> n prime

DIVISOR_GAME(n)
    if n == 1:
        return false
    dp = [] length n+1
    dp[0] = 0   // 0-based index
    dp[1] = 0   // 1 = true, 0 = false

    // for a step Alice take, the substructure must return false for Alice to win.
    for i = 2 to n:
        for j = 1 to i/2:
            if i % j == 0 and dp[i - j] == 0:
                dp[i] = 1
                break
        dp[i] = 0
    return dp[n]

COMPLEXITY

- Time: O(n^2)
- Space: O(n)

*/

#include <iostream>
#include <vector>

bool divisor_game(int n) {
    if (n == 1) return false;

    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;

    for (int i=2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i/2; j++) {
            if (i % j == 0 && dp[i-j] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    std::vector<int> ns = {2, 3, 4, 5};

    for (const auto& n : ns) {
        std::cout << divisor_game(n) << "\n";
    }
    return 0;
}