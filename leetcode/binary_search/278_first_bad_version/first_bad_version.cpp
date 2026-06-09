/*
FIRST BAD VERSION

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails to quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2,..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimise the number of calls to the API.

e.g.1,

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

e.g.2,

Input: n = 1, bad = 1
Output: 1

-------------------------------------------

ALGORITHM: Binary search

FIRST_BAD_VERSION(n)
    if n = 1 and bad = 1:
        return 1
    
    i = 1
    j = n

    while i < j + 1:
        mid = i + (j-i)//2
        if isBadVersion(mid) == true:
            j = mid
        else:
            i = mid

    return j

COMPLEXITY

- Time: O(log n)
- Space: O(1) for pointers

*/

#include <iostream>

bool isBadVersion(int version) {
    return true;
}

int first_bad_version(int n) {
    int i = 1;
    int j = n;

    while (i < j) {
        int mid = i + (j - i)/2;
        if (isBadVersion(mid) == true) j = mid;
        else i = mid + 1;
    }

    return i;
}