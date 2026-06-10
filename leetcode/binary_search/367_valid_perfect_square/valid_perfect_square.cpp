/*
VALID PERFECT SQUARE

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

e.g.1,

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

e.g.2,

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

------------------------------------------

ALGORITHM

IS_PERFECT_SQUARE(num)
    i = 1
    j = num

    while i <= j:
        mid = i + (j - i)//2

        if mid*mid == num:
            return true
        if mid*mid < num:
            i = mid + 1
        else:
            j = mid - 1
    
    return false

COMPLEXITY

- Time: O(log n)
- Space: O(1)

*/

#include <iostream>
#include <vector>

bool is_perfect_square(int num) {
    int i = 1; // use long long i for int-64
    int j = num;

    while (i <= j) {
        int mid = i + (j - i)/2;

        if (mid == num/mid && num%mid == 0) return true;
        if (mid < num/mid) i = mid + 1;
        else j = mid - 1;
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 14, 16, 1000052910};

    std::vector<int> result;
    for (const auto& num : nums) {
        if (is_perfect_square(num)) result.push_back(1);
        else result.push_back(0);
    }

    std::cout << "[";
    for (int i=0; i < result.size(); i++) {
        if (i != result.size() - 1) std::cout << result[i] << ", ";
        else std::cout << nums[i] << ":" << result[i];
    }
    std::cout << "]";
}