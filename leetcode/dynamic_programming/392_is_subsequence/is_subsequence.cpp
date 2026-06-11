/*
IS SUBSEQUENCE

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

e.g.1,

Input: s = "abc", t = "ahbgdc"
Output: true

e.g.2,

Input: s = "axc", t = "ahbgdc"
Output: false

-----------------------------------------

ALGORITHM

IS_SUBSEQUENCE(s, t)
    i = j = 0 // pointers for s and t

    while j < t.length:
        if i == s.length:
            return true
        if s[i] == t[j]:
            i++
        j++
    return false

COMPLEXITY

- Time: O(|t|)
- Space: O(1)

*/

#include <iostream>
#include <string>

bool is_subsequence(std::string s, std::string t) {
    int i = 0;

    for (int j=0; j < t.size() && i < s.size(); j++) {
        if (s[i] == t[j]) i++;
    }
    if (i == s.size()) return true;
    else return false;
}