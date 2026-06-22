/*
WORD SEARCH

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

e.g.1,

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

e.g.2,

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

e.g.3,

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

-----------------------------------------

ALGORITHM

Dfs
- Time: O(m*n)
- Space: O(1)

DFS(row, col, visited, word_index)
    if word_index == word.length - 1
        return true

    temp = visited[row][col]
    visited[row][col] = 1
    neighbours = [up, down, left, right]

    for (x, y) in neighbours
        if board[x][y] == word[word_index + 1] and (x, y) not in visited
            if DFS(x, y, visited, word_index + 1)
                return true
    
    visited[row][col] = temp
    return false

EXIST(board, word)
    m = board.length
    n = board[0].length

    visited = [[]] size (m, n)
    for i = 0 to m - 1
        for j = 0 to n - 1
            if board[i][j] == word[0]
                DFS(i, j, visited, 0)

    
*/

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <utility>

bool dfs(int row, int col, int row_num, int col_num, std::vector<std::vector<char>>& board, std::string& word, int word_idx) {
    if (word_idx == word.size() - 1) return true;

    char temp = board[row][col];
    board[row][col] = '#';

    int d_row[] = {-1, 1, 0, 0};
    int d_col[] = {0, 0, -1, 1};

    for (int d = 0; d < 4; d++) {
        int nei_row = row + d_row[d];
        int nei_col = col + d_col[d];

        if (nei_row >= 0 && nei_row < row_num && nei_col >= 0 && nei_col < col_num) {
            if (board[nei_row][nei_col] == word[word_idx + 1]) {
                if (dfs(nei_row, nei_col, row_num, col_num, board, word, word_idx + 1)) {
                    board[row][col] = temp;
                    return true;
                }  
            }
        }
    }

    board[row][col] = temp;
    return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    int m = board.size();
    int n = board[0].size(); 

    if (m * n < word.size()) return false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(i, j, m, n, board, word, 0))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    std::cout << exist(board, "ABCCED") << "\n"; // true
    std::cout << exist(board, "ABCB") << "\n"; // false

    return 0;
}