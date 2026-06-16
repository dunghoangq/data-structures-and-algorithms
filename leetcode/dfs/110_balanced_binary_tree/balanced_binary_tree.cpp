/*
BALANCED BINARY TREE

Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: true

e.g.2,

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

e.g.3,

Input: root = []
Output: true

-----------------------------------

ALGORITHM
    if root == NULL
        return true
    
    stack = [root]
    heigths = {TreeNode*: int} // dictionary/map to store heights
    heights[NULL] = 0

    while stack
        node = stack.top

        if node.left in heights and node.right in heights
            stack.pop(node)
            left_height = heights[node.left]
            right_height = heights[node.right]
            
            if abs(left_height - right_height) > 1
                return false
            else
                heights[node] = 1 + max(left_height, right_height)

        if node.left and node.left not in heights
            stack.push(node.left)
        if node.right and node.right not in heights
            stack.push(node.right)
        
    
    return true


COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool is_balanced(TreeNode* root) {
    if (!root) return true;

    std::stack<TreeNode*> stack;
    stack.push(root);

    std::unordered_map<TreeNode*, int> heights;
    heights.insert({nullptr, 0});

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        TreeNode* left_node = node->left;
        TreeNode* right_node = node->right;
        bool left_done = heights.find(left_node) != heights.end();
        bool right_done = heights.find(right_node) != heights.end();

        if (left_done && right_done) {
            stack.pop();
            int left_height = heights[left_node];
            int right_height = heights[right_node];

            if (std::abs(left_height - right_height) > 1)
                return false;
            else heights[node] = 1 + std::max(left_height, right_height);
        }
        else {
            if (left_node && !left_done)
                stack.push(left_node);
            if (right_node && !right_done)
                stack.push(right_node);
        }
    }
    return true;
}