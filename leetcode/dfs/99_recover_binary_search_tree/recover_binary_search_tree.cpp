/*
RECOVER BINARY SEARCH TREE

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

e.g.1,

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]

Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.


e.g.2,

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]

Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

---------------------------------

ALGORITHM

Dfs
- Time: 
- Space: 

INORDER-TRAVERSAL(root, order)
    if root == NULL
        return
    
    INORDER_TRAVERSAL(root.left)
    order.append(root)
    INORDER_TRAVERSAL(root.right)


RECOVER_TREE
    order = []
    INORDER_TRAVERSAL(root, order)

    if order.length == 1 or NULL
        return
    
    n = order.length
    node1
    node2

    for i = 1 ... n - 1
        if order[i - 1].val < order[i].val
            continue
        else if !node1
            node1 = order[i-1]
        node2 = order[i]
    
    SWAP(node1.val, node2.val)
    
*/

#include <iostream>
#include <vector>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inorder_traversal(TreeNode* root, std::vector<TreeNode*>& order) {
    if (!root) return;

    inorder_traversal(root->left, order);
    order.push_back(root);
    inorder_traversal(root->right, order);
}

void recoverTree(TreeNode* root) {
    std::vector<TreeNode*> order;
    inorder_traversal(root, order);

    if (order.size() <= 1) return;

    TreeNode* node1;
    TreeNode* node2;

    for (int i = 1; i < order.size(); i++) {
        if (order[i - 1]->val < order[i]->val) continue;
        else if (!node1) node1 = order[i - 1];
        node2 = order[i];
    }

    std::swap(node1->val, node2->val);
    return;
}