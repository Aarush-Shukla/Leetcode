class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(!pq.empty()){
        long long first=pq.top();
        pq.pop();
        if(first>=k){
            break;
        }
        long long second=pq.top();
        pq.pop();
        long long insert=min(first,second)*2 + max(first,second);
        pq.push(insert);
        cnt++;
        }
        return cnt;
    }
};