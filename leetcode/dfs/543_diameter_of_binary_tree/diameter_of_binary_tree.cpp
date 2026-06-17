/*
DIAMETER OF BINARY TREE

Given the root of a binary tree, return the length of the diameter of the tree.

Th diameter of a binary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

e.g.1,

Input: root = [1,2,3,4,5]
Output: 3

Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

e.g.2,

Input: root = [1,2]
Output: 1

---------------------------

ALGORITHM

DIAMETER_OF_BINARY_TREE(root)
    stack = [root]
    diameter = 0
    visited = {}

    while stack not empty
        node, height = stack.top
        left = node.left
        right = node.right
        left_done = left in visited
        right_done = right in visited

        if left == NULL and right == NULL
            visited[node] = 0
        if left_done and right_done
            stack.pop
            visited[node] = max(visited[left], visited[right]) + 1
            diameter = max(
                diameter,
                visited[node],
                visited[left] + visited[right] + 2
            )
        
        if left and !left_done
            stack.push(left)
        if right and !right_done
            stack.push(right)
    
    return diameter


COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int diameter_of_binary_tree(TreeNode* root) {
    int diameter = 0;
    if (!root) return diameter;

    std::stack<TreeNode*> stack;
    stack.push(root);
    std::unordered_map<TreeNode*, int> lengths;

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        bool left_done = (left == nullptr) || (lengths.find(left) != lengths.end());
        bool right_done = (right == nullptr) || (lengths.find(right) != lengths.end());

        if (left_done && right_done) {
            stack.pop();
            int left_len = lengths[left];
            int right_len = lengths[right];

            diameter = std::max(diameter, left_len + right_len);
            lengths[node] = std::max(left_len, right_len) + 1;
        }
        else {
            if (left && !left_done) stack.push(left);
            if (right && !right_done) stack.push(right);
        }
    }

    return diameter;
}