#include <algorithm> // For std::max
#include <climits>   // For INT_MIN

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
private:
    // This variable will store the maximum path sum found across the entire tree.
    int max_sum;

    /**
     * Helper function to compute the maximum "gain" from a subtree.
     * The gain is defined as the maximum path sum starting at 'node'
     * and going downwards.
     */
    int maxGain(TreeNode* node) {
        // Base case: A null node contributes 0 to the path sum.
        if (node == nullptr) {
            return 0;
        }

        // 1. Recursively find the max gain from the left and right subtrees.
        //    We use std::max(0, ...) because we don't want to include
        //    paths with a negative sum. It's better to take nothing (0).
        int left_gain = std::max(0, maxGain(node->left));
        int right_gain = std::max(0, maxGain(node->right));

        // 2. Update the global maximum path sum.
        //    The best path *at this node* (using it as the "split")
        //    is its own value plus the gains from both children.
        //    This is a candidate for the overall maximum.
        int current_path_sum = node->val + left_gain + right_gain;
        max_sum = std::max(max_sum, current_path_sum);

        // 3. Return the max gain for the parent node.
        //    A parent node can only use *one* of its children's paths,
        //    not both (otherwise it wouldn't be a valid path).
        //    So, we return the node's value plus the *better* of the two
        //    child gains.
        return node->val + std::max(left_gain, right_gain);
    }

public:
    int maxPathSum(TreeNode* root) {
        // Initialize max_sum to the smallest possible integer value,
        // as node values can be negative.
        max_sum = INT_MIN;
        
        // Start the recursive process.
        // We don't care about the return value of the *first* call,
        // as the 'max_sum' variable will be updated by reference.
        maxGain(root);
        
        // After the recursion is complete, max_sum holds the answer.
        return max_sum;
    }
};