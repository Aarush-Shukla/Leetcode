class Solution {
public:
    int solve(int ind, int buy, int k, int n, vector<int>& arr,vector<vector<vector<int>>>& dp) {
        if (ind == n || k == 0)
            return 0;
        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];

        int profit = 0;
        if (buy == 1) {
            int take = -arr[ind] + solve(ind + 1, 0, k, n, arr, dp);
            int not_take = solve(ind + 1, 1, k, n, arr, dp);
            profit = max(take, not_take);
        } else {
            int take = arr[ind] + solve(ind + 1, 1, k - 1, n, arr, dp);
            int not_take = solve(ind + 1, 0, k, n, arr, dp);
            profit = max(take, not_take);
        }

        return dp[ind][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, n, prices, dp);
    }
};
