/*
SYMMETRIC TREE

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its centre).

e.g.1,

Input: root = [1,2,2,3,4,4,3]
Output: true

e.g.2,

Input: root = [1,2,2,null,3,null,3]
Output: false

-----------------------------------

PSEUDOCODE

IS_SYMMETRIC(root)
    if root is NULL:
        return true

    left_deque = [root.left]     // left subtree
    right_deque = [root.right]    // right subtree

    while left_deque and right_deque not empty:
        l_root = left_deque.pop_head
        r_root = right_deque.pop_head

        if l_root is NULL and r_root is NULL:
            continue
        else if l_root != r_root:
            return false
        else:
            left_deque.push(l_root.left)
            left_deque.push(l_root.right)
            right_deque.push_head(r_root.right)
            right_deque.push_head(r_root.left)
        
    return true
        
COMPLEXITY

- Time: O(n)
- Space: O(n)

*/

#include <iostream>
#include <deque>
#include <utility> // for pair type

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool is_symmetric(TreeNode* root) {
    if (root == nullptr) return true;
    
    std::deque<TreeNode*> left_dq = {root->left};
    std::deque<TreeNode*> right_dq = {root->right};

    while (!left_dq.empty() && !right_dq.empty()) {
        TreeNode* l_root = left_dq.front();
        left_dq.pop_front();
        TreeNode* r_root = right_dq.back();
        right_dq.pop_back();

        if (!l_root && !r_root) continue;
        else if (!l_root || !r_root) return false;
        else if (l_root->val != r_root->val) return false;
        
        left_dq.push_back(l_root->left);
        left_dq.push_back(l_root->right);
        right_dq.push_front(r_root->right);
        right_dq.push_front(r_root->left);
    }

    return left_dq.empty() && right_dq.empty();
}


// One deque version

bool is_symmetric(TreeNode* root) {
    if (root == nullptr) return true;

    std::queue<std::pair<TreeNode*, TreeNode*>> q;
    q.push({root->left, root->right});

    while (!q.empty()) {
        auto [l, r] = q.front();
        q.pop();

        if (!l && !r) continue;
        if (!l || !r) return false;
        if (l->val != r->val) return false;

        q.push({l->left, r->right});
        q.push({l->right, r->left});
    }

    return q.empty();
}