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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;//hd,lvl,node val
        queue<pair<TreeNode*,pair<int,int>>> q;//node,hd,lvl
        vector<vector<int>> ans;
        if(root==NULL)return {};
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
           pair<TreeNode*,pair<int,int>> temp=q.front();
           q.pop();
            TreeNode* front=temp.first; 
           int hd=temp.second.first;
           int lvl=temp.second.second;
           mp[hd][lvl].push_back(front->val);
            if (front->left) {
                q.push({front->left, {hd - 1, lvl + 1}});
            }
            if (front->right) {
                q.push({front->right, {hd + 1, lvl + 1}});
            }
        }

        for (auto i : mp) { // Iterate over horizontal distances
        vector<int> res;
        for (auto j : i.second) { // Iterate over levels
        auto& nodes = j.second;
        sort(nodes.begin(), nodes.end()); // Sort nodes at the same level
        res.insert(res.end(), nodes.begin(), nodes.end());
            }
        ans.push_back(res);
        }
    return ans;
    }
};