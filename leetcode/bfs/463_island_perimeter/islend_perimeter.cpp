/*
ISLAND PERIMETER

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

e.g.1,

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image above.

e.g.2,

Input: grid = [[1]]
Output: 4

e.g.3,

Input: grid = [[1,0]]
Output: 4

---------------------------

ALGORITHM

Bfs
- Time: O(m*n)
- Space: O(m*n)

ISLAND_PERIMETER(grid)
    m = grid.length
    n = grid[0].length
    node_count = 0
    edges_shared = 0

    queue = []

    for i = 0 to m - 1
        for j = 0  to n - 1
            if grid[i][j] == 1
                queue.push((i, j))
                grid[x][y] = -1
                break

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    while queue not empty
        x, y = queue.front
        queue.pop();
        node_count++

        for i = 0 to 3
            next_x = x + dx[i]
            next_y = y + dx[i]

            if 0 <= next_x <= m - 1 and 0 <= next_y <= n - 1
                if grid[next_x][next_y] == 1
                    queue.push((next_x, next_y))
                    grid[next_x][next_y] = -1
                if grid[next_x][next_y] == -1
                    edges_shared++

    return 4 * node_count - 2 * edges_shared

*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// BFS - Slow

// int island_perimeter(std::vector<std::vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     int node_count = 0;
//     int edges_shared = 0;

//     std::queue<std::pair<int, int>> queue;

//     for (int i =0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (grid[i][j] == 1) {
//                 queue.push({i, j});
//                 grid[i][j] = -1;
//                 goto end_of_loops;
//             }
//         }
//     }
//     end_of_loops:

//     while (!queue.empty()) {
//         auto [x, y] = queue.front();
//         queue.pop();
//         node_count++;

//         std::vector<int> dx = {-1, 1, 0, 0};
//         std::vector<int> dy = {0, 0, -1, 1};

//         for (int i = 0; i < 4; i++) {
//             int next_x = x + dx[i];
//             int next_y = y + dy[i];

//             if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n) {
//                 if (grid[next_x][next_y] == 1) {
//                     queue.push({next_x, next_y});
//                     grid[next_x][next_y] = -1;
//                 }
//                 if (grid[next_x][next_y] == -1)
//                     edges_shared++;
//             }
//         }
//     }

//     return 4 * node_count - edges_shared;
// }

// ChatGPT approach - Super fast

int island_perimeter(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int perimeter = 0;

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                perimeter += 4;

                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                        perimeter--;
                }

                /*
                Or use

                if (i > 0 && grid[i-1][j] == 1)
                    perimeter -= 2;
                if (j > 0 && grid[i][j-1] == 1)
                    perimeter -= 2;
                */
            }
        }
    }

    return perimeter;
}