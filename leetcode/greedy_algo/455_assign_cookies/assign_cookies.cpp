/*
ASSIGN COOKIES

Assume you're a parent wanting to give your children some cookies, at most one for each.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign cookie j to the child i, and the child will be content.

Your goal is to:
- Maximise # content children
- Output the maximum number

e.g. 1,

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

e.g. 2,

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

---------------------------------

ALGO

Sort g and s (O(mlogm) + O(nlogn))

pointers: i = j = 0

while i < g.length and j < g.length:
    If s[j] >= g[i]:
        count++
        j++
    i++
return count

CORRECTNESS

Greedy: Assign smallest cookie to the least greedy child. -> The remaining chilren and cookies are optimal.

Assume we have found cookie x for child c.
And another cookie y >= x is found and assigned to c.
Since x <= y, we can exchange y for x -> y is available for other children.

-> Exists an optimal solution using greedy's first choice. After the first choice, remaining problem is identical but smaller.

(QED.)

COMPLEXITY

- Time: O(mlogm) + O(nlogn)
    - O(mlogm) + O(nlogn) for sorting and 
    - O(m + n) for pointers.
*/

#include <iostream>
#include <vector>

int content_children(std::vector<int>& g, std::vector<int>& s) {
    // Sort first
    std::sort(g.begin(), g.end());  // Introsort
    std::sort(s.begin(), s.end());

    int count = 0;
    int i = 0;  // pointer for children
    int j = 0;  // pointer for cookies

    while (i < static_cast<int>(g.size()) 
            && j < static_cast<int>(s.size())) {
        if (g[i] <= s[j]) {
            count++;
            i++;
            j++;
        }
        else j++;
    }
    return count;
}