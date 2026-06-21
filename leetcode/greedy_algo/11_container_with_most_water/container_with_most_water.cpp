/*
CONTAINER WITH MOST WATER

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis from a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

e.g.1,

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

e.g.2,

Input: height = [1,1]
Output: 1

-------------------------

ALGORITHM

Greedy: What is the optimal substructure???


MAX_AREA(height)
    i = 0    
    j = height.length - 1
    max_area = min(height[i], height[j]) * (j - i)
    
    while height[i] < height[j]
        if i < j
            i++
        else
            j--
        
        area = min(height[i], height[j]) * (j - i)
        if area > max_area
            max_area = area

    return max_area

COMPLEXITY

- Time: O(n)
- Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int max_area(std::vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int max_area = std::min(height[i], height[j]) * (j - i);
    int area;

    while (i < j) {
        if (height[i] < height[j]) i++;
        else j--;

        area = std::min(height[i], height[j]) * (j - i);
        if (area > max_area) max_area = area;
    }

    return max_area;
}

int main() {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << max_area(height) << "\n";
    return 0;
}