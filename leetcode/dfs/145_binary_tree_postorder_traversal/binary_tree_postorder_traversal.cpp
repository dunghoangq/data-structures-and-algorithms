/*
BINARY TREE POSTORDER TRAVERSAL

Given the root of a binary tree, return the postorder traversal of its nodes' values.

e.g.1,

Input: root = [1,null,2,3]
Output: [3,2,1]

e.g.2,

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]

e.g.3,

Input: root = []
Output: []

e.g.4,

Input: root = [1]
Output: [1]

-----------------------------------

ALGORITHM

POSTORDER_TRAVERSAL(root)
    result = []    
    if root == NULL
        return result

    stack = [root]
    visited = [NULL]

    while stack not empty
        node = stack.top
        left = node.left
        right = node.right
        left_done = left in visited
        right_done = right in visited

        if left_done and right_done
            result.append(node)
            visited.append(node)
            stack.pop

        if right and !right_done
            stack.push(right)
        if left and !left_done
            stack.push(left)
    
    return result

COMPLEXITY

- Time: O(n)
- Space: O(n)

*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<int> postorder_traversal(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> stack;
    stack.push(root);
    std::vector<TreeNode*> visited;
    visited.push_back(nullptr);

    while (!stack.empty()) {
        TreeNode* node = stack.top();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        bool left_done = std::find(visited.begin(), visited.end(), left) != visited.end();
        bool right_done = std::find(visited.begin(), visited.end(), right) != visited.end();

        if (left_done && right_done) {
            result.push_back(node->val);
            visited.push_back(node);
            stack.pop();
        }

        if (right && !right_done) stack.push(right);
        if (left && !left_done) stack.push(left);
    }

    return result;
}