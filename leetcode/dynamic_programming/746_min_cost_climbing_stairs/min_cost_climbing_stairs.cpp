/*
MIN COST CLIMBING STAIRS

You are given an integer array cost where cost[i] is the cost of i-th step on a staircase. Once you pay for the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

e.g.1,

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

e.g.2,

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

---------------------------

ALGORITHM

Optimal substructure
dp[i] = min{dp[i-2], dp[i-1]} + cost[i] // take one step or two steps to reach i.

MIN_COST_CLIMBING_STAIRS(cost)
    n = cost.length
    if n == 0 or 1:
        return 0
    
    dp = [0, cost[0]] // stores min cost to reach i-th step, length = n + 1

    for i = 2 to n:
        dp[i] = min{dp[i-2], dp[i-1]} + cost[i]
    
    return min{dp[n-1], dp[n]}


COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>

int min_cost_climbing_stairs(std::vector<int>& cost) {
    int n = cost.size();
    if (n == 0 || n == 1) return 0;

    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;

    for (int i=2; i <= n; i++)
        dp[i] = std::min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
    
    return dp[n];
}

std::vector<std::vector<int>> costs = {
    {10, 15, 20},
    {1,100,1,1,1,100,1,1,100,1}
};

int main() {
    for (auto cost : costs)
        std::cout << min_cost_climbing_stairs(cost) << "\n";
}