class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefixsum=0;
        int count=0;
        mp.insert({0,1});
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            count+=mp[prefixsum-k];
            mp[prefixsum]++;
        }
        return count;
    }
};