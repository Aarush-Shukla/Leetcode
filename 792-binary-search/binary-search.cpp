class Solution {
public:

int solve(vector<int>& nums, int target,int s,int e){
 if (s>e){
     return -1;
 }
  
          int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                return solve(nums,target,s,mid-1);
            }else{
                return solve(nums,target,mid+1,e);
            }
    
       
    }




    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int ans= solve(nums,target,0,n-1);
       return ans;
    }
};