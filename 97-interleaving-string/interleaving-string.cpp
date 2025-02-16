class Solution {
public:

    bool checkInterleave(string s1, string s2,string s3,int i,int j, int k,vector<vector<int>>& dp){
       if(i==s1.size() && j==s2.size() && k==s3.size()){
        return true;
       }
       if(dp[i][j]!=-1) return dp[i][j];
       bool possible = false;
       if(i<s1.size() && s1[i]==s3[k]){
            possible=checkInterleave(s1,s2,s3,i+1,j,k+1,dp);
            if(possible){
                return dp[i][j]=true;
            }
        }
        if(j<s2.size() && s2[j]==s3[k]){
            possible=checkInterleave(s1,s2,s3,i,j+1,k+1,dp);
            if(possible){
                return dp[i][j]=true;
            }
        }
        return dp[i][j]=false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return checkInterleave(s1,s2,s3,0,0,0,dp);               
    }
};