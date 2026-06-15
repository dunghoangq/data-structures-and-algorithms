/*
BINARY TREE LEVEL ORDER TRAVERSAL II

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

e.g.2,

Input: root = [1]
Output: [[1]]

e.g.3,

Input: root = []
Output: []

----------------------------------------

ALGORITHM

LEVEL_ORDER_BOTTOM(root)
    result = [[]]
    if root == NULL
        return result
    
    queue q = [root]

    while q not empty
        lvl_size = q.length
        values = []

        for i = 0 to lvl_size - 1
            node = q.pop
            values.append(node.val)

            if node.left
                q.push(node.left)
            if node.right
                q.push(node.right)
        
        result.push_back(values)
    
    REVERSE(result)
    return result
    
COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> level_order_bottom(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int lvl_size = q.size();
        std::vector<int> values;
        values.reserve(lvl_size); // reserve space for the current level

        for (int i = 0; i < lvl_size; i++) {
            TreeNode* node = q.front();
            q.pop();

            values.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(values);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

