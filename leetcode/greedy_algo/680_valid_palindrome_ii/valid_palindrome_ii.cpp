/*
VALID PALINDROME II

Given a string s, return true if s can be palindrome after deleting at most one character from it.

e.g.1,

Input: s = "aba"
Output: true

e.g.2,

Input: s = "abca"
Output: true

Explanation: You could delete the character 'c'.

e.g.3,

Input: s = "abc"
Output: false

------------------------------------

ALGORITHM

VALID_PALINDROME(s)
    i = 0
    j = s.length - 1
    cache_i = cache_j = -1
    attempt = 1

    while i <= j
        if s[i] == s[j]
            i++
            j--
        else if attempt > 0
            cache_i = i
            cache_j = j
            i++
            attempt--
        else if attempt == 0
            i = cache_i
            j = cache_j
            j--
        else
            return false

    return true

COMPLEXITY

- Time: O(log n)
- Space: O(1)

*/

#include <iostream>
#include <string>

bool valid_palindrome(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    int cache_i;
    int cache_j;
    int attempt = 1;

    
    std::cout << "Loop started!!!\n";
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else if (attempt > 0) {
            cache_i = i;
            cache_j = j;
            i++;
            attempt--;
        }
        else if (attempt == 0) {
            i = cache_i;
            j = cache_j;
            j--;
            attempt--;
        }
        else return false;
    }
    std::cout << "Loop done!!!\n";
    return true;
}

int main() {
    std::cout << "=================\naba\n" << valid_palindrome("aba") << "\n"; // true
    std::cout << "=================\nabca\n" << valid_palindrome("abca") << "\n"; // true
    std::cout << "=================\nabc\n" << valid_palindrome("abc") << "\n"; // false
    std::cout << "=================\nacxcybycxcxa\n" << valid_palindrome("acxcybycxcxa") << "\n"; // true

    std::cout << "=================\naguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga\n" << valid_palindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << "\n"; // true

    std::string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    std::cout << s.substr(0, 21) << "\n";
    std::cout << s.substr(21, 80 - 21 + 1) << "\n";
    std::cout << s.substr(81, s.size() - 1) << "\n";
    return 0;
}