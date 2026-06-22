/*
VALIDATE BINARY SEARCH TREE

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

- The left subtree of a node contains only nodes with keys strictly less than the node's key.
- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

e.g.1,

Input: root = [2,1,3]
Output: true

e.g.2,

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

-------------------------------

ALGORITHM

Dfs - Inorder traverse
- Time: O(n)
- Space: O(h)

INORDER_TRAVERSAL(root)
    if root == NULL
        return []
    
    order = []

    order.append(INORDER_TRAVERSAL(root.left))
    order.append(root.val)
    order.append(INORDER_TRAVERSAL(root.right))

    return order

IS_VALID_BST(root)

    order = INORDER_TRAVERSAL(root)
    curr_val = 0

    for i = 0 to order.length - 1
        if order[i] > curr_val
            curr_val = order[i]
        else
            return false

    return true
    
*/

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// void inorder_traversal(TreeNode* root, std::vector<int>& order) {
//     if (!root) return;

//     inorder_traversal(root->left, order);
//     order.push_back(root->val);
//     inorder_traversal(root->right, order);
// }

// bool is_valid_bst(TreeNode* root) {
//     std::vector<int> order;
//     inorder_traversal(root, order);
//     if (order.size() == 1) return true;

//     int curr_val = order[0];
//     for (int i = 1; i < order.size(); i++) {
//         if (order[i] > curr_val) curr_val = order[i];
//         else return false;
//     }

//     return true;
// }

// Better Approach

bool inorder_traversal(TreeNode* root, TreeNode* prev) {
    if (!root) return true;
    inorder_traversal(root->left, prev);

    if (!inorder_traversal(root->left, prev))
        return false;

    if (prev && root->val <= prev->val)
        return false;

    prev = root;

    if (!inorder_traversal(root->right, prev))
        return false;
        
    return true;
}

bool is_valid_bst(TreeNode* root) {
    TreeNode* prev = nullptr;

    return inorder_traversal(root, prev);
}
