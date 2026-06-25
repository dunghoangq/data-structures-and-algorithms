/*
MAXIMUM UNITS ON A TRUCK

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxes i, numberOfUnitsPerBox i]:

- numberOfBoxes i is the number of boxes of type i.
- numberOfUnitsPerBox i is the number of units in each box of the type i.

You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

e.g.1,

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8

Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

e.g.2,

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91

----------------------------------

ALGORITHM

Greedy
- Time: O(n log n)
- Space: O(n)

MAXIMUM_UNITS(boxTypes, truckSize)
    SORT(boxTypes) by numberOfUnitsPerBox

    slots = truckSize
    max_units = 0

    for i = idx_list.length - 1 to 0
        boxes, units = boxTypes[idx_list[i]]

        if slots == 0
            break
        
        if boxes < slots
            slots -= boxes
            max_units += units * boxes
        else
            max_units += units * slots
            slots = 0
    
    return max_units
*/

#include <iostream>
#include <vector>
#include <algorithm>

int max_units(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    // Sort boxTypes by number of units per box
    std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
    });

    int slots = truckSize;
    int max_units = 0;

    for (int i = 0; i < boxTypes.size(); i ++) {
        if (slots == 0) break;

        int boxes = boxTypes[i][0];
        int units = boxTypes[i][1];

        if (boxes < slots) {
            max_units += boxes * units;
            slots -= boxes;
        }
        else {
            max_units += slots * units;
            slots = 0;
        }
    }

    return max_units;
}