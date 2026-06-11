/*
MAXIMUM DEPTH OF BINARY TREE

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: 3

e.g.2,

Input: root = [1,null,2]
Output: 2

-------------------------------------------------

PSEUDOCODE

MAX_DEPTH(root)
    if root == NULL:
        return 0

    level = 0
    queue q = [root]

    while q is not empty:
        level_size = q.length
        level++

        for i = 0 to level_size - 1:
            curr_node = q.pop
            if curr_node.left:
                q.push(left)
            if curr_node.right:
                q.push(right)
    return level

COMPLEXITY

- Time: O(n)
- Space: O(n)

*/

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int max_depth(TreeNode* root) {
    if (root == nullptr) return 0;

    std::queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int level_size = q.size();
        depth++;

        for (int i = 0; i < level_size; i++) {
            TreeNode* curr_node = q.front();
            q.pop();

            if (curr_node->left) q.push(curr_node->left);
            if (curr_node->right) q.push(curr_node->right);
        }
    }
    return depth;
}