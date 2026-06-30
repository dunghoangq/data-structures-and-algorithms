/*
MINIMUM TIME TO TYPE WORD USING SPECIAL TYPEWRITER

There is a special typewriter with lowercase English letter 'a' to 'z' arranged in a circle with a pointer. A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.

Each second, you may performt one of the following operations:

- Move the pointer on character counterclockwise or clockwise.
- Type the character the pointer is currently on.

Given a string word, return the minimum number of seconds to type out the characters in word.

e.g.1,

Input: word = "abc"
Output: 5

Explanation: 
The characters are printed as follows:
- Type the character 'a' in 1 second since the pointer is initially on 'a'.
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer clockwise to 'c' in 1 second.
- Type the character 'c' in 1 second.

e.g.2,

Input: word = "bza"
Output: 7

Explanation:
The characters are printed as follows:
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer counterclockwise to 'z' in 2 seconds.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'a' in 1 second.
- Type the character 'a' in 1 second.

e.g.3,

Input: word = "zjpc"
Output: 34

Explanation:
The characters are printed as follows:
- Move the pointer counterclockwise to 'z' in 1 second.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'j' in 10 seconds.
- Type the character 'j' in 1 second.
- Move the pointer clockwise to 'p' in 6 seconds.
- Type the character 'p' in 1 second.
- Move the pointer counterclockwise to 'c' in 13 seconds.
- Type the character 'c' in 1 second.

------------------------------

ALGORITHM

Greedy
- Time: O(n)
- Space: O(1)

MIN-TIME-TO-TYPE(word)
    map = {'a': 1, 'b': 2, ... , 'z': 26}
    n = word.length
    pointer = 'a'
    seconds = 0

    for i = 0 ... n-1
        if word[i] == pointer
            seconds++
        else
            seconds += min(abs(map[word[i]] - map[pointer]), 26 - abs(map[word[i]] - map[pointer])) + 1
            pointer = word[i]
    return seconds
*/

#include <iostream>
#include <string>
#include <algorithm>    // for min
#include <cmath>        // for absolute
#include <unordered_map>// for map of alphabet

int minTimeToType(std::string word) {
    char pointer = 'a';
    int seconds = 0;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == pointer) seconds++;
        else {
            seconds += std::min(
                std::abs(word[i] - pointer),
                26 - std::abs(word[i] - pointer)
            ) + 1;
            pointer = word[i];
        }
    }

    return seconds;
}
