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
    TreeNode* Node_Parent_Mapping(TreeNode* root,map<TreeNode*, TreeNode*>& mpp,int start){
        mpp[root]=NULL;
        TreeNode* res=NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->val==start)res=front;
            if(front->left){
                q.push(front->left);
                mpp[front->left]=front;
            }
              if(front->right){
                q.push(front->right);
                mpp[front->right]=front;
            }
        }
        return res;
    }

    int solve(TreeNode* root,map<TreeNode*, TreeNode*>& mpp,int start){
        unordered_map<TreeNode*,bool> visited;
        int ans=0;
        queue<TreeNode*> q;
        visited[root]=1;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                 TreeNode* bt=q.front();
                 q.pop();
                if(bt->left && !visited[bt->left]){
                    flag=1;
                    q.push(bt->left);
                    visited[bt->left]=1;
                }
                if(bt->right && !visited[bt->right]){
                    flag=1;
                    q.push(bt->right);
                    visited[bt->right]=1;
                }
                if(mpp[bt] && !visited[mpp[bt]]){
                    flag=1;
                    q.push(mpp[bt]);
                    visited[mpp[bt]]=1;
                }
            }
            if (flag==1)ans++;
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* temp=Node_Parent_Mapping(root,mpp,start);
        int ans=solve(temp,mpp,start);
        return ans;
    }
};