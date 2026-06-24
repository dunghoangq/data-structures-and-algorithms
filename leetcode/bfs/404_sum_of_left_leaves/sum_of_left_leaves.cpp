/*
SUM OF LEFT LEAVES

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

e.g.2,

Input: root = [1]
Output: 0

-----------------------------

ALGORITHM

Bfs
- Time: 
- Space: 

SUM_OF_LEFT_LEAVES(root)
    queue = [root]

    while queue not empty
        node = queue.front
        queue.pop

        if node.left
            queue.push(node.left)

            if node.left.left == NULL and node.left.right == NULl
                sum += node.left.val
        if node.right
            queue.push(node.right)
    
    return sum
*/

#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int sum_of_left_leaves(TreeNode* root) {
    int sum = 0;
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();

        if (node->left) {
            queue.push(node->left);
            if (!node->left->left && !node->left->right)
                sum += node->left->val;
        }
        if (node->right)
            queue.push(node->right);
    }

    return sum;
}