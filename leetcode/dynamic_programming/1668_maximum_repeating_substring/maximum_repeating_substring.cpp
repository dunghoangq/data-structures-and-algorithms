/*
MAXIMUM REPEATING SUBSTRING

For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence.
The words's maximum k-repeating value is the highest value k where word is k-repeating in sequence. if word is not a substring in a sequence, word's maximum k-repeating value is 0.

Given strings sequence an word, return the maximum k-repeating value of word in sequence.

e.g.1,

Input: sequence = "ababc", word = "ab"
Output: 2
Explanation: "abab" is a substring in "ababc".

e.g.2,

Input: sequence = "ababc", word = "ba"
Output: 1
Explanation: "ba" is a substring in "ababc". "baba" is not a substring in "ababc".

e.g.3,

Input: sequence = "ababc", word = "ac"
Output: 0
Explanation: "ac" is not a substring in "ababc".

-------------------------------

ALGORITHM

MAX_REPEATING(sequence, word)
    k = 0
    
    return k

COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>
#include <string>

// This approach is not ELEGANT!
// int max_repeating(std::string sequence, std::string word) {
//     int n = sequence.size();
//     int w = word.size();
//     int k = 0;
//     if (n < w) return k;

//     std::vector<int> idx;

//     for (int i = 0; i < n - w + 1; i++) {
//         if (sequence.substr(i, w) == word) idx.push_back(i);
//     }

//     int idx_length = idx.size();

//     std::cout << "# words found: " << idx_length << "\n";
//     for (int i = 0; i < idx_length; i++) {
//         std::cout << idx[i];
//         if (i != idx_length - 1) std::cout << ", ";
//     }
//     std::cout << "\n";

//     if (idx_length) k = 1;
//     if (idx_length > 1) {
//         for (int i = 0; i < idx_length - 1; i++) {
//             if (idx[i] == idx[i+1] - w) k++;
//         }
//     }

//     return k;
// }

// This ELEGANT version provided by ChatGPT
// int max_repeating(std::string sequence, std::string word) {
//     int k = 0;
//     std::string current = word;

//     while (sequence.find(current) != std::string::npos) {
//         k++;
//         current += word;
//     }
//     return k;
// }

// DP approach
int max_repeating(std::string sequence, std::string word) {
    int n = sequence.size();
    int w = word.size();
    std::vector<int> dp(n+1, 0);

    int best = 0;
    for (int i=w; i <= n; i++) {
        if (sequence.substr(i - w, w) == word) dp[i] = dp[i-w] + 1;
        else dp[i] = 0;
        best = std::max(best, dp[i]);
    }
    return best;
}

int main() {
    std::cout << max_repeating("ababc", "ab") << "\n";
    std::cout << max_repeating("aaa", "a") << "\n";
    std::cout << max_repeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba") << "\n";
}