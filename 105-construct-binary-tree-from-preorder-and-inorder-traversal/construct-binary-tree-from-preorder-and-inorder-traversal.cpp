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
    int findposition(int element,vector<int>& inorder,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element)
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& preindex, int instart,int inend,int n){
        if(preindex >= n || instart > inend)return NULL;
        int element=preorder[preindex++];
        TreeNode* root=new TreeNode(element);
        int position=findposition(element,inorder,n);

        root->left=solve(preorder,inorder,preindex,instart,position-1,n);
        root->right=solve(preorder,inorder,preindex,position+1,inend,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preindex=0;
        TreeNode* ans= solve(preorder,inorder,preindex,0,n-1,n);
        return ans;
    }
};