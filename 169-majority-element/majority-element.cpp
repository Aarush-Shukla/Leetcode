class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& it: nums)
            mp[it]++;
        int max = INT_MIN;
        int ans = 0;
        for(auto& it: mp){
            if(it.second>max){
                max = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};