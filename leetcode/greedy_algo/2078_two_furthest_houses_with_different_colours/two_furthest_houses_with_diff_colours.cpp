/*
TWO FURTHEST HOUSES WITH DIFFERENT COLOURS

There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the i-th house.

Return the maximum distance between two houses with different colors.

The distance between two houses i-th and j-th is abs(i - j).

e.g.1,

Input: colors = [1,1,1,6,1,1,1]
Output: 3

Explanation: In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.

e.g.2,

Input: colors = [1,8,3,8,3]
Output: 4

Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.

e.g.3,

Input: colors = [0,1]
Output: 1
Explanation: The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.

-------------------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(1)

MAX-DISTANCE(colors)
    max_dist = 0
    n = colors.length

    for j = n - 1 ... 1
        for i = 0 ... n - 2
            if colors[i] != colors[j]
                max_dist = j - i
                break all loops
    return max_dist
*/

#include <iostream>
#include <vector>
#include <cmath>

int maxDistance(std::vector<int>& colors) {
    int max_dist = 0;
    int n = colors.size();

    for (int j = n - 1; j > 0; j--){
        for (int i = 0; i < j; i++) {
            if (colors[i] != colors[j] && j - i > max_dist) {
                max_dist = j - i;
            }
        }
    }

    return max_dist;
}