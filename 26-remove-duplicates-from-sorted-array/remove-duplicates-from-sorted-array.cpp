class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int num:nums){
            s.insert(num);
        }
        nums.clear();
        for(int ele:s){
            nums.push_back(ele);
        }
        return s.size();
    }
};