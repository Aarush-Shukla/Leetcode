class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
    int sum = 0;
    int i, j;
    int n=nums.size();
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += nums[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool dp[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        dp[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        dp[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= nums[j - 1])
                dp[i][j] = dp[i][j]
                             || dp[i - nums[j - 1]][j - 1];
        }
    }

    return dp[sum / 2][n];

    }
};