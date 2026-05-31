/*
Input: String s
Output: length of the longest palindrome.

abccccdd -> dccaccd palindrome

GREEDY::PROOF

Greedy Rule: Take possible pairs immediately. Plus one for odd remainder in the centre.

- Locally optimal: Every pair found is fit in mirrored position -> globally optimal solution.
- Remaining optimal: If we take a pair, the remaining letters will form another optimal. Because we try to find the longest palindrome.

CORRECTNESS

- Remain xx in the string s -> Place on both ends, palindrome's length increases by 2.
- Remain single letters a,b,... -> Can only place in one in the centre.

-> Optimal solution contains:
  - Every possible pair
  - At most one extra character
(QED.)

COMPLEXITY
- Time: O(n)
- Space: O(k) (with k = # alphabet chars)
*/
#include <iostream>
#include <string>

int longest_palindrome(std::string s) {
  int freq[128] = {0};

  for (char c:s) {
    freq[(int)c]++;
  }
  int length = 0;
  bool has_odd = false;

  for (int i=0; i < 128; i++) {
    length += (freq[i] /2)*2;

    if (freq[i] % 2 == 1) {
      has_odd = true;
    }
  }

  if (has_odd) {
    length++;
  }

  return length;
}


int main(int argc, char* argv[]) {
  std::string input = argv[1];
  std::cout << longest_palindrome(input);
  return 0;
}