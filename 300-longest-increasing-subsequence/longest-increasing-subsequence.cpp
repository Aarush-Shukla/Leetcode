class Solution {
public:

    int solve(int prev,int index,vector<int>& nums,vector<vector<int>>& dp){
        if(index>=nums.size())return 0;
        int take=0;
        if(prev !=-1 && dp[prev][index]!=-1)return dp[prev][index];
        if(prev==-1 || nums[prev] < nums[index]){
            take= 1+solve(index,index+1,nums,dp);
        }
        int not_take=solve(prev,index+1,nums,dp);
        if(prev!=-1) dp[prev][index]=max(take,not_take);
        return max(take,not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2501,vector<int>(2501,-1));
        return solve(-1,0,nums,dp);
    }
};