/*
MINIMUM COST TO MOVE CHIPS TO THE SAME POSITION

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

- position[i] + 2 or position[i] - 2 with cost = 0.
- position[i] + 1 or position[i] - 1 with cost = 1.

Return the minimum cost needed to move all the chips to the same position.

e.g.1,



e.g.2,



e.g.3,



-------------------------------------------------

ALGORITHM

MIN_COST_TO_MOVE_CHIPS(position)
    odds = 0
    evens = 0

    for i = 0 = position.length - 1
        if position[i] % 2 == 0
            evens++
        else
            odds++
    return min(odds, evens)
        

COMPLEXITY

- Time: O(n)
- Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int min_cost_to_move_chips(std::vector<int>& position) {
    int odds = 0;
    int evens = 0;

    for (int i = 0; i < position.size(); i++) {
        if (position[i] % 2 == 0) evens++;
        else odds++;
    }

    return std::min(odds, evens);
}
