/*
FIND NODE IN BINARY SEARCH TREE

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occured element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follow:
- The left subtree of a node contains only nodes with keys less than or equal to the node's key.
- The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
- Both the left and right subtrees must also be binary search trees.

e.g.1,

Input: root = [1,null,2,2]
Output: [2]

e.g.2,

Input: root = [0]
Output: [0]

-----------------------------------

ALGORITHM

FIND_MODE(root)
    modes = []
    stack = [root]
    visited = [NULL]
    values = {}

    while stack not empty
        node = stack.top
        val = node.val
        left = node.left
        right = node.right
        left_done = left in visited
        right_done = right in visited

        if left_done and right_done
            stack.pop
            if val in values
                values[val]++
            else
                values[val] = 1
        
        if left and !left_done
            stack.push(left)
        if right and !right_done
            stack.push(right)

    max_val = 0
    for key, value in values
        if value > max_val
            modes = []
            max_val = value
            modes.append(key)
        if value == max_val
            modes.append(key)
    
    return modes
    
COMPLEXITY

- Time: O(n)
- Space: O(n)

*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<int> find_mode(TreeNode* root) {
    std::stack<TreeNode*> stack;
    stack.push(root);
    std::unordered_map<int, int> values;

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();

        values[node->val]++;

        if (node->left) stack.push(node->left);
        if (node->right) stack.push(node->right);
    }

    std::vector<int> modes;
    int max_val = 0;
    for (auto [key, val] : values) {
        if (val > max_val) {
            modes = {};
            max_val = val;
            modes.push_back(key);
        }
        else if (val == max_val)
            modes.push_back(key);
    }

    return modes;
}