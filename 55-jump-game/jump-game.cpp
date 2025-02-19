class Solution {
public:

    bool solve(int index,int n,vector<int>& nums,vector<int>& dp){
        if(index==n-1)return true;
        if(index>n)return false;

        if(dp[index]!=-1)return dp[index];
        for(int i=1;i<=nums[index];i++){
            if(solve(index+i,n,nums,dp)==true){
                return true;
            }
        }
        return dp[index]=false;
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};