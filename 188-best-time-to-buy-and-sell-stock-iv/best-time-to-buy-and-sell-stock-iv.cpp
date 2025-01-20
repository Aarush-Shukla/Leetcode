class Solution {
public:
    int solve(int ind, int buy, int cap, int n, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        if (ind == n || cap == 0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if (buy == 1) {
            int take = -arr[ind] + solve(ind + 1, 0, cap, n, arr, dp);
            int not_take = solve(ind + 1, 1, cap, n, arr, dp);
            profit = max(take, not_take);
        } else {
            int take = arr[ind] + solve(ind + 1, 1, cap - 1, n, arr, dp);
            int not_take = solve(ind + 1, 0, cap, n, arr, dp);
            profit = max(take, not_take);
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));
        return solve(0, 1, cap, n, prices, dp);
    }
};
