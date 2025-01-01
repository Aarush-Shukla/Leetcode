class Solution {
public:

    int max_kadane(vector<int>& nums, int n){
        int ans=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
           sum=max(sum+nums[i],nums[i]);
           ans=max(sum,ans);
        }
    return ans;
    }

      int min_kadane(vector<int>& nums, int n){
        int ans=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
           sum=min(sum+nums[i],nums[i]);
           ans=min(sum,ans);
        }
    return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        //1 Sum
        int total=accumulate(nums.begin(),nums.end(),0);

        //2 max_subarray_sum

        int max_sum=max_kadane(nums,n);

        //3 

        int min_sum=min_kadane(nums,n);

        int circular_sum=total-min_sum;

        if(max_sum>0)return max(max_sum,circular_sum);
        return max_sum;
        
       
    }
};