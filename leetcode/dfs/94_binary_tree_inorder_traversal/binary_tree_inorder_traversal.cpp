/*
BINARY TREE INORDER TRAVERSAL

Given the root of a binary tree, return the inorder traversal of its nodes' values.

e.g.1,

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

e.g.2,

Input: root = []
Output: []

e.g.3,

Input: root = [1,null,2,3]
Output: [1,3,2]

e.g.4,

Input: root = [1]
Output: [1]

------------------------------

ALGORITHM

INORDER_TRAVERSAL(root)
    result = []
    if root == NULL:
        return result
    
    stack s = [root]
    node = root

    while node not empty or s not empty:
        while node not empty:
            s.push(node)
            node = node->left
        node = s.top
        s.pop
        result.push(node->val)
        node = node->right

    return result

COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<int> inorder_traversal(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) return result;

    std::stack<TreeNode*> st;
    TreeNode* node = root;

    while (node || !st.empty()) {
        while (node) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        result.push_back(node->val);
        node = node->right;
    }
    return result;
}