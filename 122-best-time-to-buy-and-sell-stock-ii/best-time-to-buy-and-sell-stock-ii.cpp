class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int start=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>start){
                profit+= prices[i]-start;
            }
            start=prices[i];
        }

        return profit;
    }
};