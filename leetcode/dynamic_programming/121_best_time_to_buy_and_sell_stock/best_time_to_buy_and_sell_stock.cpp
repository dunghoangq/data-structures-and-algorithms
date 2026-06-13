/*
BEST TIME TO BUY AND SELL STOCK

You are given an array prices where prices[i] if the price of a given stock on the i-th day.
You want to maximise our profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

e.g.1,

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

e.g.2,

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

-----------------------------------------

ALGORITHM

MAX_PROFIT(prices)
    if prices is empty or prices.length == 1:
        return 0
    
    bought = prices[0]
    max_profit = 0

    for i = 1 to prices.length - 1:
        if prices[i-1] < bought:
            bought = prices[i-1]
        if prices[i] - bought > max_profit:
            max_profit = prices[i] - bought
    return max_profit


COMPLEXITY

- Time: O(n)
- Space: O(1)

*/

#include <iostream>
#include <vector>

int max_profit(std::vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || n == 1) return 0;

    int bought = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i-1] < bought) bought = prices[i-1];
        if (prices[i] - bought > max_profit)
            max_profit = prices[i] - bought;
    }
    return max_profit;
}

int main() {
    std::vector<int> prices = {7,1,5,3,6,4};

    std::cout << max_profit(prices);
}