class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            int remaining = target - nums[i];
            // Check if the complement is already in the map and it's not the same index
            if(mpp.find(remaining) != mpp.end()) {
                ans.push_back(mpp[remaining]); // Index of the complement
                ans.push_back(i); // Current index
                break;
            }
            // Store the index of the current element
            mpp[nums[i]] = i;
        }
        return ans;
    }
};
