/*
CAN PLACE FLOWERS

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerber containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

e.g.1,

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

e.g.2,

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

----------------------------------

ALGORITHM

CAN_PLACE_FLOWERS(flowerbed, n)
    m = flowerbed.length
    count = 0

    for i = 0  to m-1
        if i == 0 or flowerbed[i-1] == 0
            left_empty = true
        if i == m-1 or flowerbed[i+1] == 0
            right_empty = true
        
        if flowerbed[i] == 0 and left_empty and right_empty
            flowerbed[i] = 1
            count++
    
    return count >= n


COMPLEXITY

- Time: O(m)
- Space: O(1)
*/

#include <iostream>
#include <vector>

bool can_place_flowers(std::vector<int>& flowerbed, int n) {
    int count = 0;
    int m = flowerbed.size();

    for (int i = 0; i < m; i++) {
        bool left_empty = (i == 0) || (flowerbed[i-1] == 0);
        bool right_empty = (i == m-1) || (flowerbed[i+1] == 0);

        if (flowerbed[i] == 0 && left_empty && right_empty) {
            flowerbed[i] = 1;
            count++;

            if (count >= n) return true;
        }
    }
    return count >= n;
}

int main() {
    std::vector<int> flowerbed = {1,0,0,0,1};
    std::cout << can_place_flowers(flowerbed, 1) << "\n"; // true
    std::cout << can_place_flowers(flowerbed, 2) << "\n"; // false
    return 0;
}