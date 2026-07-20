/*
MINIMUM COST OF BUYING CANDIES WITH DISCOUNT

A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

e.g.1,

Input: cost = [1,2,3]
Output: 5

Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.

e.g.2,

Input: cost = [6,5,7,9,2,2]
Output: 23

Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.

e.g.3,

Input: cost = [5,5]
Output: 10

Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
Hence, the minimum cost to buy all candies is 5 + 5 = 10.

------------------------------------

ALGORITHM

Greedy
- Time: O(n log n)
- Space: O(1)

MINUMUM-COST(cost)
    if cost.length < 3
        return SUM(cost)
    
    SORT(cost, reversed)
    min_cost = 0

    for i = 0 ... cost.length - 1
        if i%3 != 2
            min_cost += cost[i]
    return min_cost
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int minimumCost(std::vector<int>& cost) {
    std::sort(cost.begin(), cost.end(), std::greater<int>());
    int min_cost = 0;

    for (int i = 0; i < cost.size(); i++) {
        if (i%3 != 2) min_cost += cost[i];
    }
    return min_cost;
}