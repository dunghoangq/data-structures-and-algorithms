/*
PATH SUM II

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Eaqch path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node.

e.g.1,

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]

Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

e.g.2,

Input: root = [1,2,3], targetSum = 5
Output: []

e.g.3,

Input: root = [1,2], targetSum = 0
Output: []

-------------------------------

ALGORITHMS

DFS / BFS
- Time: O(n)
- Space: O(n log n) or O(n^2)

DFS(node, remain_sum, curr_path, result)

    if not node
        if remain_sum == 0
            result.append(curr_path)
        return

    left = node.left
    right = node.right

    if left
        DFS(left, remain_sum - left.val, curr_path.append(left.val))
    if right
        DFS(right, remain_sum - right.val, curr_path.append(right.val))
    
    return

PATH-SUM(root, targetSum)
    remain_sum = targetSum - root.val
    curr_path = [root.val]
    result = []

    DFS(root, remain_sum, curr_path, result)

    return result
*/

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* node, int curr_sum, std::vector<int>& path, std::vector<std::vector<int>>& result) {
    if (!node) return;

    path.push_back(node->val);
    curr_sum -= node->val;
    
    if (!node->left && !node->right) {
        if (curr_sum == 0) result.push_back(path);
    }
    else {
        if (node->left) dfs(node->left, curr_sum, path, result);
        if (node->right) dfs(node->right, curr_sum, path, result);
    }

    path.pop_back();
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;

    dfs(root, targetSum, path, result);
    return result;
}