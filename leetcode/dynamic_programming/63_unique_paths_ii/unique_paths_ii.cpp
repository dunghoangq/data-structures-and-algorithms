/*
UNIQUE PATHS II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (grid[0][0]). The robot tries to move to the bottom-right of the grid (grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0, respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possitive unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than equal to 2 * 10^9.

e.g.1,

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2

Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

e.g.2,

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

-----------------------------

ALGORITHM

Dp
- Time:
- Space:

UNIQUE-PATHS-WITH-OBSTACLES(grid)
    m = grid.length
    n = grid[0].length

    dp = [i][j] := # paths to reach grid[i][j], init with 1

    

    for i = 0 ... m - 1
        for j = 0 ... n - 1
            if grid[i][j] == 1
                dp[i][j] = 0
            else
                dp[i][j] += dp[i][j-1] + dp[i-1][j]

    return dp[m-1][n-1]

[0 1]
[0 0]

[1 1]
[1 1]

*/

#include <iostream>
#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));

    if (obstacleGrid[0][0] == 1)
        return 0;

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];

        }
    }

    return dp[m-1][n-1];
}


int main() {
    std::cout << "Case 1:\n";
    std::vector<std::vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    std::cout << uniquePathsWithObstacles(grid) << "\n"; // 2

    grid = {
        {0,1}, {0,0}
    };
    std::cout << "Case 2:\n";
    std::cout << uniquePathsWithObstacles(grid) << "\n"; // 1

    grid = {{0, 1}};
    std::cout << "Case 3:\n";
    std::cout << uniquePathsWithObstacles(grid) << "\n"; // 0

    grid = {{1, 0}};
    std::cout << "Case 4:\n";
    std::cout << uniquePathsWithObstacles(grid) << "\n"; // 0

    grid = {{1, 0}, {0, 0}};
    std::cout << "Case 5:\n";
    std::cout << uniquePathsWithObstacles(grid) << "\n"; // 0

    return 0;
}