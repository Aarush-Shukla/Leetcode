class Solution {
   static bool comp(int a,int b){
    return a>b;
}
public:

    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> pq;
       for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
       }
    for(int i=0;i<nums.size()-k;i++){
        pq.pop();
       }
       return pq.top();
    }
};