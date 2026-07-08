/*
UNIQUE PATHS

There is a robot on an m x n grid. The robot is initially located at the top-left corner (grid[0][0]). The robot tries to move to the bottom-right corner (grid[m-1][n-1]). The robot can only either move down or right at any point in time.

Given two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

e.g.1,

Input: m = 3, n = 7
Output: 28

e.g.2,

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

---------------------------

ALGORITHM

Dp
- Time: O(m*n)
- Space: O(m*n)

UNIQUE-PATHS(m, n)
    dp[i][j] := # unique paths to reach to grid[i][j], init 0

    for i = 0 ... m - 1
        for j = 0 ... n - 1
            up = i - 1
            left = j - 1

            if 0 <= up < m
                dp[i][j] += dp[up][j]
            if 0 <= left < n:
                dp[i][j] += dp[i][left]
    return dp[m-1][n-1]
*/

#include <iostream>
#include <vector>

// int uniquePaths(int m, int n) {
//     std::vector<std::vector<int>> dp(m, std::vector<int> (n, 1));

//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             dp[i][j] = dp[i-1][j] + dp[i][j-1];
//         }
//     }

//     return dp[m-1][n-1];
// }


int uniquePaths(int m, int n) {
    std::vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j-1];
        }
    }

    return dp[n-1];
}

int main() {
    std::cout << uniquePaths(3, 7) << "\n"; // 28
    std::cout << uniquePaths(3, 2) << "\n"; // 3
    return 0;
}