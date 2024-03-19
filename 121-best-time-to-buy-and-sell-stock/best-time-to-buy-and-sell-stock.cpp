class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi = 0;
        int minimum = prices[0];
        for (int i=0; i< n; i++ ){
        minimum = min(minimum ,prices[i]);
        maxi = max(maxi ,prices[i] - minimum );
        }
        return maxi;
    }
};