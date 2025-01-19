class Solution {
public:

    int solve(int index,int n,vector<int>& nums,vector<int>& dp){
        if(index>=n-1)return 0;
        if(dp[index]!=-1)return dp[index];
        int mini= 1e8;
        for(int i=1;i<=nums[index];i++){
            mini=min(1+solve(i+index,n,nums,dp),mini);
        }
        return dp[index]= mini;
    } 

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};