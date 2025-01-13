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
        vector<int> temp1;
        vector<int> temp2;
        int n=nums.size();
        if (n==0)return 0;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=n-1){
                temp1.push_back(nums[i]);
            }
        }

         for(int i=0;i<n;i++){
            if(i!=0){
                temp2.push_back(nums[i]);
            }
        }

        int ind1=temp1.size()-1;
        int ind2=temp2.size()-1;
        return max(maxLogic(ind1,temp1),maxLogic(ind2,temp2));
    }
};