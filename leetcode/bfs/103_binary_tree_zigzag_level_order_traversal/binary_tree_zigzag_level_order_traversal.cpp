/*
BINARY TREE ZIGZAG LEVEL ORDER TRAVERSAL

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values (i.e., from left to right, then right to left for the next level and alternate between).

e.g.1,

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

e.g.2,

Input: root = [1]
Output: [[1]]

e.g.3,

Input: root = []
Output: []

----------------------------------------

ALGORITHM

ZIGZAG_LEVEL_ORDER(root)
    values = [[]]
    if root == NULL
        return values
    
    values.append([root.val])
    queue q = [root]
    is_left = true

    while q not empty
        lvl_size = q.length
        curr_val = [] size  = lvl_size

        for i = 0 to lvl_size - 1
            node = q.pop
            index = is_left ? i : lvl_size - 1 - i

            curr_val[index] = node.val

            if node.left
                q.push(node.left)
            if node.right
                q.push(node.right)
            
        result.append(curr_val)
        is_left = !is_left
    
    return values

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

std::vector<std::vector<int>> zigzag_level_order(TreeNode* root) {
    std::vector<std::vector<int>> values;
    if (root == nullptr) return values;

    std::queue<TreeNode*> q;
    q.push(root);
    bool is_left = false;

    while (!q.empty()) {
        int lvl_size = q.size();
        std::vector<int> curr_val(lvl_size);

        for (int i = 0; i < lvl_size; i++) {
            TreeNode* node = q.front();
            q.pop();
            int index = is_left ? i : lvl_size - 1 - i;

            curr_val[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        values.push_back(curr_val);
        is_left = !is_left;
    }

    return values;
}