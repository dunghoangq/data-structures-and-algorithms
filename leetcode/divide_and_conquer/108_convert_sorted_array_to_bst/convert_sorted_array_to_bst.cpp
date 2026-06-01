/*
CONVERT SORTED ARRAY TO BINARY SEARCH TREE

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

e.g.1,

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

e.g.2,

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

--------------------------------------------

ALGO::BFS (iterative)


ARRAY_TO_BST(nums)
    if nums = null
        return null

    mid = (nums.length - 1)/2
    root = nums[mid]

    init queue q with (root, left = index 0, right = index nums.length - 1)

    while q not empty
        curr = q.front
        q.pop

        l = curr.left
        r = curr.right
        current_mid = l + (r - 1) / 2

        // Left subtree
        if l <= current_mid -1
            left_mid = l + (current_mid - 1 - l)/2
            assign l to current node
            q.push({new node, l, current_mid -1})

        // Right subtree
        if current_mid + 1 <= r
            right_mid = current_mid + 1 + (r - (current_mid + 1))/2
            assign r to current node
            q.push({new node, current_mid + 1, r})
    return root

ALGO::Divide and Conquer (recursive)

ARRAY_TO_BST(nums)
    // Edges
    if nums is empty
        return null
    
    // Build tree - Divide and Conquer
    _BUILD_TREE(nums, left, right)
        // Base Case
        if left > right
            return null
        
        mid = left + (right - left) / 2
        root = nums[mid]

        root->left = _BUILD_TREE(nums, left, mid-1)
        root->right = _BUILD_TREE(nums, mid+1, right)

        return root
    
    // Main
    return _BUILD_TREE(nums, 0, nums.size - 1)

COMPLEXITY
- Time: O(n)
- Space: O(log n) for heap storing

*/

#include <iostream>
#include <vector>
#include <queue>    // for BFS
#include <functional>   // for Lambda Recursion

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//----------------------BFS----------------------//

TreeNode* sorted_array_to_bst(std::vector<int>& nums) {
    
    // State for BFS
    struct State {
        TreeNode* node;
        int left;
        int right;
    };

    // Edges
    if (nums.empty())
        return nullptr;
    
    int mid = (nums.size() - 1) / 2;

    TreeNode* root = new TreeNode(nums[mid]);

    std::queue<State> q;
    q.push({root, 0, static_cast<int>(nums.size()) - 1});

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int l = curr.left;
        int r = curr.right;
        int current_mid = l + (r - l)/2;

        // Left subtree
        if (l <= current_mid - 1) {
            int left_mid = l + (current_mid - 1 - l)/2;
            curr.node->left = new TreeNode(nums[left_mid]);
            q.push({curr.node->left, l, current_mid - 1});
        }

        // Right subtree
        if (current_mid + 1 <= r) {
            int right_mid = current_mid + 1 + (r - (current_mid + 1))/2;
            curr.node->right = new TreeNode(nums[right_mid]);
            q.push({curr.node->right, current_mid + 1, r});
        }
    }

    return root;
}

//----------------------Divide & Conquer----------------------//
TreeNode* build_tree(std::vector<int>& nums, int left, int right) {
    // Base
    if (left > right)
        return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    // Subtrees
    root->left = build_tree(nums, left, mid - 1);
    root->right = build_tree(nums, mid + 1, right);

    return root;
}

TreeNode* sorted_array_to_bst(std::vector<int>& nums) {
    // Edges
    if (nums.empty())
        return nullptr;
    
    // Build tree helper - Divide and Conquer
    // TODO - This should not be nested

    // Main
    return build_tree(nums, 0, nums.size() - 1);
}

//----------------------Lambda Recursion----------------------//

/*
Lambda Recursion

Function knows how to call itself. We store a function inside a variable so the lambda can see itself

std::function<...> build

*/
TreeNode* sorted_array_to_bst(std::vector<int>& nums) {

    if (nums.empty())
        return nullptr;

    std::function<TreeNode*(int, int)> build =
        [&](int left, int right) -> TreeNode* {

            if (left > right)
                return nullptr;

            int mid =
                left + (right - left) / 2;

            TreeNode* root =
                new TreeNode(nums[mid]);

            root->left =
                build(left, mid - 1);

            root->right =
                build(mid + 1, right);

            return root;
        };

    return build(0, nums.size() - 1);
}