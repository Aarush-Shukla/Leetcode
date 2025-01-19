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
    // void inorder(TreeNode* root, vector<int>& ans){
    //     if(root==NULL)return;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }

    void solve(TreeNode* root,int& cnt,int& ans, int k){
        if(root==NULL)return;
        solve(root->left,cnt,ans,k);
        cnt++;
        if(cnt==k){
            ans=root->val;
            
        }
        solve(root->right,cnt,ans,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // vector<int>ans; 
        // inorder(root,ans);
        // sort(ans.begin(),ans.end());
        // return ans[k-1];

       int cnt=0;
       int ans;
       solve(root,cnt,ans,k);
       return ans;

    }
};