/*
PATH SUM

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

e.g.1,

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

e.g.2,

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

e.g.3,

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

------------------------------

ALGORITHM

HAS_PATH_SUM(root, targetSum)
    if root == NULL:
        return false
    
    queue q = [(root, targetSum)]

    while q is not empty:
        node, remain = q.pop

        if remain == node.val and node.left == nullptr and node.right == nullptr:
            return true
        
        if root.left:
            q.push((root.left, remain - root.val))
        if right.right
            q.push((root.right, remain - root.val))
    
    return false

COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <queue>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool has_path_sum_bfs(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, targetSum});

    while (!q.empty()) {
        auto [node, remain] = q.front();
        q.pop();

        if (remain == node->val 
            && node->left == nullptr
            && node->right == nullptr) return true;
        if (node->left) q.push({node->left, remain - node->val});
        if (node->right) q.push({node->right, remain - node->val});
    }
    return false;
}

// Although this problem is categoried in BFS.
// DFS is more efficient.

bool has_path_sum_dfs(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right)
        return targetSum == root->val;
    return
        has_path_sum_dfs(root->left, targetSum - root->val)
        || has_path_sum_dfs(root->right, targetSum - root->val);
}