/*
SUM OF ROOT TO LEAF BINARY NUMBERS

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

- For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

e.g.1,

Input: root = [1,0,1,0,1,0,1]
Output: 22

Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

e.g.2,

Input: root = [0]
Output: 0

-----------------------------------

ALGORITHM

Dfs
- Time: O(n)
- Space: O(h*2^h)

SUM_ROOT_TO_LEAF(root)
    stack = [(root, string(root.val))]
    paths = []
    
    while stack not empty
        node, path = stack.top
        stack.pop
        left = node.left
        right = node.right

        if left
            stack.push((left, path + left.val))
        if right
            stack.push((right, path + right.val))
    
    sum = 0
    for path in paths
        sum += TO_INT(path)

    return sum
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// int sum_root_to_leaf(TreeNode* root) {
//     if (!root) return 0;
//     std::stack<std::pair<TreeNode*, std::string>> stack;
//     stack.push({root, std::to_string(root->val)});
//     int sum = 0;

//     while (!stack.empty()) {
//         auto [node, path] = stack.top();
//         stack.pop();
//         TreeNode* left = node->left;
//         TreeNode* right = node->right;
//         if (!left && !right) sum += std::stoull(path, nullptr, 2);

//         if (left)
//             stack.push({left, path + std::to_string(left->val)});
//         if (right)
//             stack.push({right, path + std::to_string(right->val)});
//     }

//     return sum;
// }

// Faster way - no string
int sum_root_to_leaf(TreeNode* root) {
    if (!root) return 0;
    std::stack<std::pair<TreeNode*, int>> stack;
    stack.push({root, root->val});
    int sum = 0;

    while (!stack.empty()) {
        auto [node, curr_val] = stack.top();
        stack.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if (!left && !right) sum += curr_val;

        if (left)
            stack.push({left, (curr_val << 1) | left->val}); // curr_val << 1 := shift left by 1, |left->val := either bit is 1 return 1, else 0.
        if (right)
            stack.push({right, (curr_val << 1) | right->val});
    }

    return sum;
}
