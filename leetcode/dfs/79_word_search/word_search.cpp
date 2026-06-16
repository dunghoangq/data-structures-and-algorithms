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

EXIST(board, word)
    m = board.length
    n = board[0].length
    p = word.length

    stack = []

    // Init sources
    for i = 0 to m-1
        for j = 0 to n-1
            if board[i][j] == word[0]
                stack.top((i,j))
    if stack is empty
        return false
    
    states = [[0 * n] * m]
    
    // DFS
    while stack not empty
        c = 0 // pointer to point to each character in word
        node = stack.back
        c++
        neighbours = [
            (node[0] - 1, node[1]), // up
            (node[0] + 1, node[1]), // down
            (node[0], node[1] - 1), // left
            (node[0], node[1] + 1)  // right
        ]
        
        for neighbour in neibours
            i = neighbour[0]
            j = neighbour[1]
            if 0 <= i <= m-1 and 0 <= j <= n - 1
                if board[i][j] == word[c] and states[i][j] == 0
                    stack.top((i, j))


COMPLEXITY

- Time: 
- Space: 


*/