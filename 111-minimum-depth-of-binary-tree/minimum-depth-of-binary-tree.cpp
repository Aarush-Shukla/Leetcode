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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if(root->left==NULL && root->right==NULL)return 1;
        
        // If one of the children is NULL, consider the depth of the other child only
        if (root->left == NULL) return 1 + minDepth(root->right);
        if (root->right == NULL) return 1 + minDepth(root->left);
        
        // If both children are present, take the minimum of both depths
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};