/*
BEST TIME TO BUY AND SELL STOCK II

You are given an integer array prices where prices[i] is the price of a given stock on the i-th day.

On each day, eyou may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than on share of the stock.

Find and return the maximum profit you can achieve.

e.g.1,

Input: prices = [7,1,5,3,6,4]
Output: 7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

e.g.2,

Input: prices = [1,2,3,4,5]
Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

e.g.3,

Input: prices = [7,6,4,3,1]
Output: 0

Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

-------------------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(n)

MAX-PROFIT(prices)
    n = prices.length
    dp[i] = max profit on day i-th
    dp[0] = 0
    current_profit = 0
    current_price = prices[0]
    have_stock = false

    for i = 1 ... n - 1
        dp[i] = max(dp[i-1], dp[i-1] + prices[i] - current_price)
        if dp[i] == dp[i-1]
            current_price = min(current_price, prices[i])
        else
            current_price = prices[i]

    return dp[n-1]            
        
*/

#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> dp(n);
    dp[0] = 0;
    int current_price = prices[0];

    for (int i = 1; i < n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-1] + prices[i] - current_price);

        if (dp[i] == dp[i-1])
            current_price = std::min(current_price, prices[i]);
        else
            current_price = prices[i];
    }

    return dp[n-1];
}

int main() {
    std::vector<int> prices = {7,1,5,3,6,4}; // 7
    std::cout << maxProfit(prices) << "\n";
}