class Solution {
public:

    // int solve(vector<int>& nums,int n){
            
    //     if(n<0){
    //         return 0;
    //     }
    //     return max(solve(nums,n-2)+nums[n],solve(nums,n-1));
    // }

    // int rob(vector<int>& nums) {
    //  return solve(nums,nums.size()-1);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int not_pick=dp[i-1];
            dp[i]=max(pick,not_pick);
        }
        return dp[n-1];
    }
};