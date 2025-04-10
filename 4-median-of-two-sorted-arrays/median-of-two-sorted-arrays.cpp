class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int> nums(n+m);
        int i=0;
        int j=0;
        int k=0;
        while(i<n&& j<m){
            if(nums1[i]<nums2[j]){
                nums[k++]=nums1[i++];
            }else{
                nums[k++]=nums2[j++];
            }
        }
        while(i<n){
                nums[k++]= nums1[i++];
            }
        while(j<m){
                nums[k++]=nums2[j++];
            }
        int median=(n+m)/2;
        double ans= 0;
        if((n+m)%2==0)ans=(nums[median]+nums[median-1])/2.0;
        else ans=nums[median];

        return ans;
    }
};