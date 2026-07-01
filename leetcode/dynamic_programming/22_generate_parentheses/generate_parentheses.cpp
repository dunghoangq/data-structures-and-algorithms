/*
GENERATE PARENTHESES

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

e.g.1,

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

e.g.2,

Input: n = 1
Output: ["()"]

---------------------------------

ALGORITHM

Dp
( A ) B
A = k         := # pairs in A
B = n - 1 - k := # pairs in B

- Time: O(C_n * n) (C_n := Catalan number)
- Space: O(C_n * n)

GENERATE-PARENTHESES(n)
    dp[i] := all valid parenthesis strings containing i pairs, size = n + 1
    dp[0] = [""]

    dp[1] = ["()"] // only k = 1, ( dp[0] ) dp[0]

    dp[2] = ["(())", "()()"] // k = 0, k = 1

    for i = 2 to n
        for k = 0 to i - 1
            for A in dp[k]
                for B in dp[i - 1 - k]
                    dp[i].extend("(" + A + ")" + B)
    
    return dp[n]
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> generatePerentheses(int n) {
    std::vector<std::vector<std::string>> dp(n + 1);
    
    dp[0] = {""};
    if (n == 0) return dp[n];
    dp[1] = {"()"};
    if (n == 1) return dp[n];

    for (int i = 2; i <= n; i++) {
        for (int k = 0; k < i; k++) {
            for (std::string A : dp[k]) {
                for (std::string B : dp[i - 1 - k]) {
                    dp[i].push_back('(' + A + ')' + B);
                }
            }
        }
    }

    return dp[n];
}

int main() {
    std::cout << '[';
    for (auto item : generatePerentheses(3)) {
        std::cout << item << ", ";
    }
    std::cout << ']' << "\n"; // ["((()))","(()())","(())()","()(())","()()()"]
    std::cout << '[';
    for (auto item : generatePerentheses(1)) {
        std::cout << item << ", ";
    }
    std::cout << ']' << "\n"; // ["()"]
}