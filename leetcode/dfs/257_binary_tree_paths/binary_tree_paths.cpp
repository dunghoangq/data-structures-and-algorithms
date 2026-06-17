/*
BINARY TREE PATHS

Given the root of a binary tree, return all root-to-leaf paths in any order.

e.g.1,

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

e.g.2,

Input: root = [1]
Output: ["1"]

----------------------------

ALGORITHM

BINARY_TREE_PATHS(root)
    paths = []
    
    stack = [(root, "root.val")]
    visited = [NULL]

    while stack not empty
        node = stack.top[0]
        path = stack.top[1]
        left = node.left
        right = node.right
        left_done = left in visited
        right_done = right in visited

        if left == NULL and right == NULL
            paths.append(path)
        
        if left_done and right_done
            stack.pop
        
        if left != NULl and !left_done
            stack.push((left, path + "->" + left.val))
        if right != NULL and !right_done
            stack.push((right, path + "->" + right.val))

    return paths

COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm> // for find()
#include <utility> // for pair

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<std::string> binary_tree_paths(TreeNode* root) {
    std::vector<std::string> paths;

    std::stack<std::pair<TreeNode*, std::string>> stack;
    stack.push({root, std::to_string(root->val)});
    std::vector<TreeNode*> visited;
    visited.push_back(nullptr);

    while (!stack.empty()) {
        auto [node, path] = stack.top();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        bool left_done = std::find(visited.begin(), visited.end(), left) != visited.end();
        bool right_done = std::find(visited.begin(), visited.end(), right) != visited.end();

        if (!left && !right) paths.push_back(path);
        if (left_done && right_done) {
            stack.pop();
            visited.push_back(node);
        }

        if (left && !left_done)
            stack.push({left, path + "->" + std::to_string(left->val)});
        if (right && !right_done)
            stack.push({right, path + "->" + std::to_string(right->val)});
    }

    return paths;
}
