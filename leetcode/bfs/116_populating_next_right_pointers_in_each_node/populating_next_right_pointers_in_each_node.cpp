/*
POPULATING NEXT RIGHT POINTERS IN EACH NODE

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

e.g.1,

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]

Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

e.g.2,

Input: root = []
Output: []

----------------------------------------

ALGORITHM

CONNECT(root)
    if root == NULL
        return root
    
    queue q = [root]

    while q not empty
        lvl_size = q.length

        for i = 0 to lvl_size - 1
            node = q.pop

            if lvl_size == 1 or i = lvl_size - 1
                node.next = NULL
            else
                node.next = q.front()
            
            if node.left
                q.push(node.left)
            if node.right
                q.push(node.right)
    return root

COMPLEXITY

- Time: O(n)
- Space: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {} 
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root) return root;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int lvl_size = q.size();

        for (int i = 0; i < lvl_size; i++) {
            Node* node = q.front();
            q.pop();

            if (lvl_size == 1 || i == lvl_size - 1)
                node->next = NULL;
            else node->next = q.front();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return root;
}