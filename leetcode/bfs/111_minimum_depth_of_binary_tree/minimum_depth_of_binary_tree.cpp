/*
MINIMUM DEPTH OF BINARY TREE

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: 2

e.g.2,

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

-----------------------------------------

ALGORITHM

MIN_DEPTH(root)
    depth = 0
    if root == NULL:
        return depth
    
    queue q
    
    while q is not empty:
        depth++
        level_size = q.length

        for i = 0 to level_size - 1:
            node = q.pop

            if node.left == q.right == NULL:
                break
            if node.left != NULL:
                q.push(node.left)
            if node.right != NULL:
                q.push(node.right)
    return depth


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

int min_depth(TreeNode* root) {
    int depth = 0;
    if (root == nullptr) return depth;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        depth++;
        int level_size = q.size();

        for (int i = 0; i < level_size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (!node->left && !node->right) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}