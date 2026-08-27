/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (!root) return 0;
        
        // If it's a leaf node and it is a left child
        if (!root->left && !root->right && isLeft) {
            return root->val;
        }
        
        // Recurse for left and right children
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
