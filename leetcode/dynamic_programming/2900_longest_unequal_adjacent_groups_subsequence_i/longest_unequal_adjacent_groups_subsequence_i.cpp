/*
LONGEST UNEQUAL ADJACENT GROUPS SUBSEQUENCE I

You are given a string array words and a binary array groups both of length n.

A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements at the same indices in groups are different (that is, there cannot be consecutive 0 or 1).

Your task is to select the longest alternating subsequence from words.
Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elementes in words are distinct.

e.g.1,

Input: words = ["e","a","b"], groups = [0,0,1]
Output: ["e","b"]

Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.

e.g.2,

Input: words = ["a","b","c","d"], groups = [1,0,1,1]
Output: ["a","b","c"]

Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.

---------------------------------

ALGORITHM

GET_LONGEST_SUBSEQUENCE(words, groups)
    n = words.length
    if n == 0 or 1:
        return words
    
    result = []
    result[0] = words[0]

    for i = 1 to n-1:
        if groups[i] != groups[i-1]:
            result.append(words[i])

    return result

COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> get_longest_subsequence(std::vector<std::string>& words, std::vector<int>& groups) {
    int n = groups.size();
    if (n == 0 || n == 1) return words;

    std::vector<std::string> result;
    result.push_back(words[0]);

    for (int i = 1; i < n; i++) {
        if (groups[i] != groups[i-1]) result.push_back(words[i]);
    }

    return result;
}