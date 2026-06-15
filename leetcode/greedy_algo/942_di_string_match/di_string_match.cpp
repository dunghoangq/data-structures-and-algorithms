/*
DI STRING MATCH

A permutation perm of n+1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == "I" if perm[i] < perm[i+1], and
- s[i] == "D" if perm[i] > perm[i+1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

e.g.1,

Input: s = "IDID"
Output: [0,4,1,3,2]

e.g.2,

Input: s = "III"
Output: [0,1,2,3]

e.g.3,

Input: s = "DDI"
Output: [3,2,0,1]

------------------------------------------

ALGORITHM

DI_STRING_MATCH(s)
    n = s.length
    perm = []
    l = 0
    r = n

    for i = 0 to n-1
        if s[i] == "I"
            perm.append(l)
            l++
        if s[i] == "D"
            perm.append(r)
            r--
    return perm


COMPLEXITY

- Time: O(n)
- Space: O(N)

*/

#include <iostream>
#include <vector>
#include <string>

std::vector<int> di_string_match(std::string s) {
    int n = s.size();
    std::vector<int> perm;
    int l = 0;
    int r = n;

    for (int i = 0; i < n; i++) {
        if (s.substr(i, 1) == "I") {
            perm.push_back(l);
            l++;
        }
        if (s.substr(i, 1) == "D") {
            perm.push_back(r);
            r--;
        }
    }
    perm.push_back(r);

    return perm;
}