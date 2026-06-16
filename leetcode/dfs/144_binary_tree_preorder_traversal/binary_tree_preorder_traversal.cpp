/*
BINARY TREE PREORDER TRAVERSAL

Given the root of a binary tree, return the preorder traversal of its nodes' values.

e.g.1,

Input: root = [1,null,2,3]
Output: [1,2,3]

e.g.2,

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]

e.g.3,

Input: root = []
Output: []

e.g.4,

Input: root = [1]
Output: [1]

-----------------------------------

ALGORITHM

PREORDER_TRAVERSAL(root)
    result = [[]]
    if root == NULL
        return result
    
    stack = [root]
    visited = [NULL]

    while stack not empty
        node = stack.top
        stack.pop

        result.append(node.val)

        if node.right
            stack.push(node.right)
        if node.left
            stack.push(node.left)
    
    return result


COMPLEXITY

- Time: O(n)
- Space: O(n)

*/

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<int> preorder_traversal(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();

        result.push_back(node->val);

        if (node->right) stack.push(node->right);
        if (node->left) stack.push(node->left);
    }

    return result;
}