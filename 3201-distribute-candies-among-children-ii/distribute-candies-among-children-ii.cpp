class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long firstMax=min(limit,n);
        long long firstMin=max(0,n-2*limit);
        long long ans=0;
        for(int i=firstMin;i<=firstMax;i++){
            long long secondMax= min(limit,n-i);
            long long secondMin= max(0,n-i-limit);
            ans+=secondMax-secondMin+1;
        }
        return ans;
    }
};