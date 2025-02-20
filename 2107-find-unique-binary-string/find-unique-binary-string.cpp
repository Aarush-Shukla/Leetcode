class Solution {
public:

    void genpum(int n, string temp,vector<string>& all){
        if(n==temp.size()){
            all.push_back(temp);
            return;
        }

        for(char c:{'0','1'}){
            temp.push_back(c);
            genpum(n,temp,all);
            temp.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        vector<string> all;
        string temp="";
        string ans="";
        genpum(n,temp,all);
        sort(nums.begin(),nums.end());
        sort(all.begin(),all.end());
        for(int i = 0; i < all.size(); i++) {
            if(i >= nums.size() || nums[i] != all[i]) {
                return all[i]; 
            }
        }

        return ans;

    }
};