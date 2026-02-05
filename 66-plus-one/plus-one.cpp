class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    vector<int> nums=digits;
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
        if(nums[i]<9){
            nums[i]++;
            return nums;
            }
        nums[i]=0;
        }
    nums.insert(nums.begin(),1);
    return nums;
    }
};