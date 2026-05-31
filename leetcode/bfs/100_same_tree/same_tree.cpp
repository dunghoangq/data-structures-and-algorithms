/*
SAME TREE

Given the roots of two binary trees p and q, write a function to chekc if they are considered the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

e.g.1,

Input: p = [1,2,3], q = [1,2,3]
Output: true

e.g.2,

Input: p = [1,2], q = [1,null,2]
Output: false

e.g.3,

Input: p = [1,2,1], q = [1,1,2]
Output: false

--------------------------------------

BFS traversal, stores pairs of nodes in queue
queue = [(p_root, q_root)]

ALGO

IS_SAME_TREE(p, q)
    queue to store (p, q)

    while queue not empty
        node1, node2 = queue.pop()

        if node1 == Node2 == null
            continue
        if node1 == null || node2 == null
            return false
        if node1 != node2
            return true
        push(left1, left2)
        push(righ1, right2)

    return true
*/

#include <iostream>
#include <queue>

// Binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Main
bool is_same_tree(TreeNode* p, TreeNode* q) {
    // Enqueue nodes
    std::queue<TreeNode*> nodes;
    nodes.push(p);
    nodes.push(q);

    // Comparison Loop
    while (!nodes.empty()) {
        TreeNode* node1 = nodes.front();
        nodes.pop();

        TreeNode* node2 = nodes.front();
        nodes.pop();

        // Compare node1 and node2
        if (node1 == nullptr && node2 == nullptr)
            continue;
        if (node1 == nullptr || node2 == nullptr)
            return false;
        if (node1->val != node2->val) {
            return false;
        }

        // Push new nodes
        nodes.push(node1 -> left);
        nodes.push(node2 -> left);

        nodes.push(node1 -> right);
        nodes.push(node2 -> right);
    }
    return true;
}