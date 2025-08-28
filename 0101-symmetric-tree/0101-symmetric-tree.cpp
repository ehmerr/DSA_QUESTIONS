/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to check if two subtrees are mirrors
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both nodes are null, they are mirrors
        if (!t1 && !t2) return true;
        
        // If one is null but the other isn't, they are not mirrors
        if (!t1 || !t2) return false;
        
        // Check if values are equal and subtrees are mirrors
        return (t1->val == t2->val)
            && isMirror(t1->right, t2->left)
            && isMirror(t1->left, t2->right);
    }

    bool isSymmetric(TreeNode* root) {
        // A tree is symmetric if its left and right subtrees are mirrors of each other.
        // The isMirror function handles the null root case implicitly.
        return isMirror(root, root);
    }
};