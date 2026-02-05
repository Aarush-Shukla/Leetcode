class Solution {
public:
    int trailingZeroes(int n) {
        int nums=n;
        int ans=0;
        for(int i=1;i<n;i++){
            if(pow(5,i)>=pow(10,4))break;
            ans+=n/pow(5,i);
        }
        return ans;
    }
};