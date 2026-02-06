class Solution {
public:
    int mySqrt(int n) {
    if (n<2) return n;
      int left=1;
      int right=n/2;
      int ans=0;
      while(right>=left){
        int mid=left+(right-left)/2;
        if((long long)mid*mid<=n){
            left=mid+1;
            ans=mid;
        }
        else{
            right=mid-1;
        }
      }
      return ans;
    }
};