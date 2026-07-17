/*
LONGEST NICE SUBSTRING

A string s is nice if, for every vector of the alphabet that s contains, it appears boath in uppercase and lowercase. 

For example, "abABB" is nice. However, "abA" is not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurence. If there are none, return an empty string.

e.g.1,

Input: s = "Bb"
Output: "Bb"

Explanation: "Bb" is a nice string b.ecause both 'B' and 'b' appear. The whole string is a substring

e.g.2,

Input: s = "YazaAay"
Output: "aAa"

Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.

e.g.3,

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.

--------------------------------------

ALGORITHM

What does uppercase and lowercase mean to a computer?

ASCII: 'a' = 97, 'A' = 65 -> Have to teach computer the relationship.
- 'a' - 'A' = 32

Lemma: If s[i] is a character whose case-partner never appears anywhere in s, then s[i] can never be part of any nice substring.


Divide and conquer
- Time: O(n^2)
- Space: O(n)


LONGEST-NICE-SUBSTRING(s)
    lower_pegs = [0] size 26 for 26 lowercase chars
    upper_pegs = [0] size 26 for 26 uppercase chars

    for i = 0 ... s.length - 1
        c = s[i]
        if c lowercase
            lower_pegs[(c & 31) - 1] = 1
        else
            upper_pegs[(c & 31) - 1] = 1
    
    is_nice = false
    for i = 0 ... 25
        if lower_pegs[i] == upper_pegs[i] == 1
            is_nice = true
    
    if is_nice == false
        return ""
    
    for i = 0 ... s.length - 1
        c = s[i]
        if lower_pegs[(c & 31) - 1] != upper_pegs[(c & 31) - 1]
            left = substring(s, 0, i)
            right = substring(s, i+1, s.length)

            nice_left = LONGEST-NICE-SUBSTRING(left)
            nice_right = LONGEST-NICE-SUBSTRING(right)

            if nice_left.length >= nice_right.length
                return nice_left
            else
                return nice_right
    return s

*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string longestNiceSubstring(std::string s) {
    std::vector<bool> lower_pegs(26, false);
    std::vector<bool> upper_pegs(26, false);

    int n = s.size();

    if (n < 2) return "";

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (std::isupper(static_cast<unsigned char>(c)))
            upper_pegs[(c & 31) -1] = 1;
        else lower_pegs[(c & 31) - 1] = 1;
    }

    bool is_nice = false;
    for (int i = 0; i < 26; i++) {
        if (lower_pegs[i] && upper_pegs[i])
            is_nice = true;
    }

    if (is_nice == false) return "";

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (lower_pegs[(c & 31) - 1] != upper_pegs[(c & 31) - 1]) {
            std::string left = s.substr(0, i);
            std::string right = s.substr(i+1, n-i-1);
            
            std::string nice_left = longestNiceSubstring(left);
            std::string nice_right = longestNiceSubstring(right);

            if (nice_left.size() >= nice_right.size())
                return nice_left;
            else return nice_right;
        }
    }

    return s;
}

int main() {
    std::cout << longestNiceSubstring("YazaAay") << "\n";
    std::cout << longestNiceSubstring("Bb") << "\n";
    return 0;
}