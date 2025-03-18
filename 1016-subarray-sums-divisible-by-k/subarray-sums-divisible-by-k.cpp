class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<int> prefixsum(n);
        // prefixsum[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     prefixsum[i]=nums[i]+prefixsum[i-1];
        // }

        // int cnt=0;

        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum= (i==0) ? prefixsum[j] : prefixsum[j] -prefixsum[i-1];

        //         if(sum % k == 0) cnt++;
        //     }
        // }
        // return cnt;

        int n=nums.size();
        int result=0;
        int sum=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mpp.find(rem)!=mpp.end()){
                result+=mpp[rem];
            }
            mpp[rem]++;
        }
        return result;
    }
};