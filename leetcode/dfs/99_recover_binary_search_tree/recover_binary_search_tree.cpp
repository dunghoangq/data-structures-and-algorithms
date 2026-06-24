/*
RECOVER BINARY SEARCH TREE

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

e.g.1,

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]

Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.


e.g.2,

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]

Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

---------------------------------

ALGORITHM

Dfs
- Time: 
- Space: 

INORDER_TRAVERSAL(root, order)
    if root == NULL
        return
    
    INORDER_TRAVERSAL(root.left)
    order.append(root)
    INORDER_TRAVERSAL(root.right)

RECOVER_TREE
    order = []
    INORDER_TRAVERSAL(root, order)

    if order.length == 1 or NULL
        return
    
    n = order.length
    node1_idx
    node2_idx

    for i = 0 to n - 1
        if order[i].val < order[i +1].val
            i++
        else
            node1_idx = i+1
            break
    
    for j = n - 1 to 0
        if order[j].val > order[j-1].val
            j--
        else
            node2_idx = j-1
            break

    
*/