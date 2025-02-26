class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {
        
        int currentMaxSum=nums[0];
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
           int currSum=max(nums[i],currSum + nums[i]);
           maxi=max(maxi,currSum);
        }

        int currentMinSum=nums[0];
        int mini=nums[0];
        for(int i=0;i<nums.size();i++){
           int currSum=min(nums[i],currSum + nums[i]);
           mini=min(mini,currSum);
        }

        return max(maxi,abs(mini));

    }
};