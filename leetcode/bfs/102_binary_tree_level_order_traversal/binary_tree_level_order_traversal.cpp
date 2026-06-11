/*
BINARY TREE LEVEL ORDER TRAVERSAL

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

e.g.2,

Input: root = [1]
Output: [[1]]

e.g.3,

Input: root = []
Output: []

---------------------------------------------------

PSEUDOCODE

LEVEL_ORDER(root)
    if root = NULL:
        return []
    
    order = []
    queue q = [[root]]

    while q not empty:
        curr_level = q.pop_head
        order.append(curr_level)
        next_level = []

        for node in curr_level:
            left = node.left
            right = node.right

            if left != NULL:
                next_level.append(left)
            if right != NULL:
                next_level.append(right)
            
        if next_level not NULL:
            queue.push(next_level)

    return order

COMPLEXITY

- Time: O(n)
- Space: O(n)

*/

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Use queue to wrap batches of nodes
std::vector<std::vector<int>> level_order_old(TreeNode* root) {
    std::vector<std::vector<int>> order = {};
    if (root == nullptr) return order;

    std::queue<std::vector<TreeNode*>> q;
    q.push({{root}});

    while (!q.empty()) {
        std::vector<TreeNode*> curr_level = q.front();
        q.pop();
        std::vector<int> curr_level_val;
        
        std::vector<TreeNode*> next_level;

        for (TreeNode* node : curr_level) {
            curr_level_val.push_back(node->val);
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if (left != nullptr) next_level.push_back(left);
            if (right != nullptr) next_level.push_back(right);
        }

        if (!curr_level_val.empty()) order.push_back(curr_level_val);
        if (!next_level.empty()) q.push(next_level);
    }
    return order;
}

// Use queue as it's supposed to be.

std::vector<std::vector<int>> level_order(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) return result;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int level_size = q.size();
        std::vector<int> curr_level;

        for (int i=0; i < level_size; i++) {
            TreeNode* node = q.front();
            q.pop();

            curr_level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(curr_level);
    }
    return result;
}