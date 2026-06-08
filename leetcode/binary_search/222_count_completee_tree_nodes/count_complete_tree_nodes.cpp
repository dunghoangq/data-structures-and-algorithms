/*
COUNT COMPLETE TREE NODES

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

e.g.1,

Input: root = [1,2,3,4,5,6]
Output: 6

e.g.2,

Input: root = []
Output: 0

e.g.3,

Input: root = [1]
Output: 1

------------------------------------

ALGORITHM

COUNT_NODES(root)
    if root.val == NULL:
        return 0
    
    hl = hr = 1     // left and right subtrees' height
    left = root.left
    right = root.right
    while left != NULL:
        hl++
        left = left.left 
    while right != NULL:
        hr++
        right = right.right
    
    if hl == hr:
        return 2^hl - 1
    else:
        return 1 + COUNT_NODES(root.left) + COUNT_NODES(root.right)

COMPLEXITY

- time:
    for case 1 hl == hr: it is O(1)
    for case hl != hr:
        which means hl > hr (complete binary tree)
        which means the left subtree takes O(n/2) to traverse,
                    the right subtree takes O(log n) (fully complete subtree)
            T(n) = T(n/2) + T(log n) = O((log n)^2) << O(n)
 */

#include <iostream>

struct TreeNode {
    int      val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int count_nodes(TreeNode* root) {
    if (root == nullptr) return 0;

    // Recursive
    int hl = 1;
    int hr = 1;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    while (left != nullptr) {
        hl++;
        left = left->left;
    }
    while (right != nullptr) {
        hr++;
        right = right->right;
    }

    if (hl == hr) return (1 << hl - 1);
    else return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), nullptr)
        );

    std::cout << count_nodes(root);
}