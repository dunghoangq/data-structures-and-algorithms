/*
INVERT BINARY TREE

Given the root of a binary tree, invert the tree, and return its root.

e.g.1,

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

e.g.2,

Input: root = [2,1,3]
Output: [2,3,1]

e.g.3,

Input: root = []
Output: []

------------------------------

ALGORITHM

INVERT_TREE(root)
    queue = [root]

    while queue not empty
        node = queue.front
        queue.pop
        left = node.left
        right = node.right

        if left != NULL and right != NULL
            temp = left
            node.left = right
            node.right = temp
        if left
            queue.push(left)
        if right
            queue.push(right)
    
    return root
    

COMPLEXITY

- Time: O(n)
- Space: O(n)

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

TreeNode* invert_tree(TreeNode* root) {
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;

        node->left = right;
        node->right = left;

        if (left) queue.push(left);
        if (right) queue.push(right);
    }

    return root;
}
