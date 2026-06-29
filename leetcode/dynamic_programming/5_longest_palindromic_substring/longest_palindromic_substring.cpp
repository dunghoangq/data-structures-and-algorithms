/*
LONGEST PALINDROMIC SUBSTRING

Given a string s, return the longest palindromic substring in s.

A substring is a contiguous non-empty sequence of characters within a string.

e.g.1,

Input: s = "babad"
Output: "bab"

Explanation: "aba" is also a valid answer.

e.g.2,

Input: s = "cbbd"
Output: "bb"

--------------------------------

ALGORITHM

Brute force
- Time: O(n^3)
- Space: O(1)

IS-PALINDROME(s, left, right)
    i = left
    j = right

    while i < j
        if s[i] == s[j]
            i++
            j--
        else
            return false
    return true

LONGEST-PALINDROME(s)
    if s.length == 1
        return s
    
    length = s.length

    while length >= 1
        for i = 0 ... s.length - length
            if s[i:i + length] is not palindrome
                length--
            else
                return s[i:i + length]
    return first character

--------------------------

Dp

optimal substructure
dp[i][j] is palindrome if dp[i+1][j-1] is palindrome

- Time: O(n^2)
- Space: O(n^2)

LONGEST-PALINDROME(s)
    dp[i][j] with i and j are start-end indexes
    fill diagonal with 1 dp[i][i] = 1

    max_len = 1
    start_idx = 0
    
    // length = 2
    for i = 0 ... s.length - 2
        dp[i][i+1] = s[i] == s[i+1]

    for i = 0 ... s.length - 3
        for j = i + 2 to s.length - 1
            dp[i][j] = (s[i] == dp[j]) && (dp[i+1][j-1] == 1)
    
    Keep track of max_len to return the substring

-------------------------

Expansion
- Time: O(n^2)
- Space: O(1)

EXPAND(left, right)
    while left >= 0 and right < n and s[left] == s[right]
        left--
        right++
    return left, right

LONGEST-PALINDROME-EXPANSION(s)
    for each character index i
        EXPAND(left = i, right = i)
    for each gap index i
        EXPAND(left = i, right = i + 1)

    return the longest

------------------------------------

Manacher
- Time: O(n)
- Space: O(n)

LONGEST-PALINDROME(s)
    // Transform gaps in s
    T = "^"

    for char in s
        T += "#"
        T += char
    
    T += "#$"

    n = T.length

    P = [0] * n

    C = 0 // centre
    R = 0 // right boundary
    for i = 1 ... n - 2
        mirror = 2*C - i

        if i < R
            P[i] = min(R - i, P[mirror])
        
        while T[i + 1 + P[i]] == T[i - 1 - P[i]]
            P[i]++

        if i + P[i] > R
            C = i
            R = i + P[i]

    max_len = 0
    centre = 0

    for i = 1 ... n - 2
        if P[i] > max_len
            max_len = P[i]
            centre = i

    start = (centre - max_len) / 2
    return s[start:start + max_len]

e.g.,

abacaba

Centre 0 -> radius 0
Centre 1 -> radius 1
Centre 2 -> radius 0
Centre 3 -> radius 3
Centre 4 -> radius 0
Centre 5 -> radius 1
Centre 6 -> radius 0

P[i] := stores radius of each centre.

Since the entire big palindrome is symmetric, whatever exists around 2 must also exist around 4.

If 2 only matches itself,

then 4 only matches itself.

So P[2] = P[4] = 0

*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>


std::string longest_palindrome_dp(std::string s) {
    int n = s.size();
    if (n < 2) return s;

    int max_len = 1;
    int start = 0;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // Length 1
    for (int i = 0; i < n; i++) dp[i][i] = 1;

    // Length 2
    for (int i = 0; i < n - 1; i ++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            start = i;
            max_len = 2;
        }
    }

    // Length > 2
    for (int length = 3; length < n + 1; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = (dp[i+1][j-1]) && (s[i] == s[j]);

            if (dp[i][j] == 1 && length > max_len) {
                max_len = length;
                start = i;
            }
        }
    }

    return s.substr(start, max_len);
}

// Expansion

std::pair<int, int> expand(std::string& s, int n, int left, int right) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return {left + 1, right - 1};
}

std::string longest_palindrome_expansion(std::string s) {
    int n = s.size();
    if (n < 2) return s;

    int max_len = 1;
    int start = 0;

    // For each character
    for (int i = 0; i < n; i++) {
        auto [left, right] = expand(s, n, i, i);
        if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            start = left;
        }
    }

    // For each gap
    for (int i = 0; i < n - 1; i++) {
        auto [left, right] = expand(s, n, i, i+1);
        if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            start = left;
        }
    }

    return s.substr(start, max_len);
}


// Manacher

std::string longest_palindrome_manacher(std::string s) {
    // Transform
    std::string T = "^";

    for(char c : s)
    {
        T += "#";
        T += c;
    }

    T += "#$";

    int n = T.size();

    std::vector<int> P(n,0);

    int C = 0;
    int R = 0;

    for(int i=1;i<n-1;i++)
    {
        int mirror = 2*C - i;

        if(i < R)
            P[i] = std::min(R-i, P[mirror]);

        while(T[i+1+P[i]] == T[i-1-P[i]])
            P[i]++;

        if(i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0;
    int center = 0;

    for(int i=1;i<n-1;i++)
    {
        if(P[i] > maxLen)
        {
            maxLen = P[i];
            center = i;
        }
    }

    int start = (center - maxLen) / 2;

    return s.substr(start, maxLen);
}