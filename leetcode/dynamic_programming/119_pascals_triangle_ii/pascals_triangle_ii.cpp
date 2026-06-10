/*
PASCAL'S TRIANGLE II

Given an integer rowIndex, return the rowIndex-th (0-indexed) row of the Pascal's Triangle.
(Each number is the sum of the two numbers directly above it as shown.)

e.g.1,

Input: rowIndex = 3
Output: [1,3,3,1]

e.g.2,

Input: rowIndex = 0
Output: [1]

e.g.3,

Input: rowIndex = 1
Output: [1,1]

--------------------------------------------------------------

ALGO - Iterative (bottom-up) DP

GET_ROW(rowIndex)
    if rowIndex == 0
        return [1]
    if rowIndex == 1
        return [1, 1]

    triangle = [[1], [1, 1]]
    for i = 2 to rowIndex
        row = []
        for j = 1 to j
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        triangle.append([1] + row + [1])
    
    return triangle[-1]

COMPLEXITY

- Time: O(n^2)
- Space: O(n^2)

-> Too Costly

ALGO VER. 2

One vector only

GET_ROW(rowIndex)
    row = [rowIndex + 1, 0]
    row[0] = 1

    for i = 1 to row_index
        for j = 1 to 1
            row[j] += row[j-1]
    
    return row

COMPLEXITY

- Time: still O(n^2)
- Space: O(n)
*/


#include <iostream>
#include <vector>

// std::vector<int> get_row(int row_index) {
//     // Edge Cases
//     if (row_index == 0)
//         return {1};
//     if (row_index == 1)
//         return {1, 1};
    
//     // Iteration
//     std::vector<std::vector<int>> triangle = {{1}, {1, 1}};

//     for (int i=2; i <= row_index; i++) {
//         std::vector<int> row;

//         for (int j=1; j < i; j++) {
//             row.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
//         }
//         row.insert(row.begin(), 1);
//         row.push_back(1);
//         triangle.push_back(row);
//     }
//     return triangle.back();
// }


std::vector<int> get_row(int row_index) {
    std::vector<int> row(row_index, 0); // vector of size {0, 0, 0, 0, 0}
    row[0] = 1;

    for (int i=1; i <= row_index; i++) {
        for (int j = i; j >= 1; j--) {
            row[j] += row[j-1];
        }
    }
    return row;
}