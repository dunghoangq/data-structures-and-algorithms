/*
REMOVE DUPLICATE LETTERS

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure the result is the smallest in lexicographical order among all possible results.

Lexicographically Smaller
A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
If the first min(a.length, b.length) characters do not differ, then the shorter string is the lexicographically smaller one.

e.g.1,

Input: s = "bcabc"
Output: "abc"

e.g.2,

Input: s = "cbacdcbc"
Output: "acdb"

-----------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(1)

Monotonic Stack:
    - If current character < top and top appears latter -> Remove top

REMOVE-DUPLICATE-LETTERS(s)
    stack = [s[0]]
    seen = []
    last = {char: index}
    i = 1

    Store last index of each character in s into last

    while stack
        top = stack.top
        node = s[i]
        if top > node and last[node] > i
            stack.pop
        if node not in seen
            stack.push(s[i])
            seen.push(node)
        
        i++

    result = ""
    for letter in stack
        add letter to result
    return result
*/

#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>

std::string removeDuplicateLetters(std::string s) {
    std::set<char> seen;
    std::unordered_map<char, int> last;
    for (int i = 0; i < s.size(); i++)
        last[s[i]] = i;

    std::stack<char> stack;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (seen.contains(c)) continue;

        while (!stack.empty() && stack.top() >= c && last[stack.top()] > i) {
            char node = stack.top();
            stack.pop();
            seen.erase(stack.top());
        }
        stack.push(c);
        seen.insert(c);
    }

    std::string result;
    while (!stack.empty()) {
        char c = stack.top();
        stack.pop();
        result = c + result;
    }
    return result;
}

int main() {
    std::cout << removeDuplicateLetters("bcabc");
    return 0;
}