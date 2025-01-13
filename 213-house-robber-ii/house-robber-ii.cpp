class Solution {
public:

        int maxLogic(int ind, vector<int>& temp) {
        if (temp.empty()) return 0; 
        
        vector<int> dp(ind + 1, 0);
        dp[0] = temp[0];
        if (ind > 0) dp[1] = max(temp[0], temp[1]); 
        
        for (int i = 2; i <= ind; i++) { 
            int pick = temp[i] + dp[i - 2];
            int not_pick = dp[i - 1];
            dp[i] = max(pick, not_pick);
        }
        return dp[ind];
    }

    int rob(vector<int>& nums) {
          int n = nums.size();
        if (n == 0) return 0;       
        if (n == 1) return nums[0];
        
        vector<int> temp1(nums.begin(), nums.end() - 1); 
        vector<int> temp2(nums.begin() + 1, nums.end()); 
        
        return max(maxLogic(temp1.size() - 1, temp1), maxLogic(temp2.size() - 1, temp2));
    }
};