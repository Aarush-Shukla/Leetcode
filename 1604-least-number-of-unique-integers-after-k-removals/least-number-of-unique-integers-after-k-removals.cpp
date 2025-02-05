class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        while(k>0){
            int temp=pq.top().second;
            int freq=mpp[temp];
            
                freq--;
                k--;
            
            if(freq==0)pq.pop();
            
                mpp[temp]=freq;
            
        }
        int ans=0;
          for(auto it: mpp){
            if(mpp[it.first]!=0)ans++;
        }
        return ans;
    }
};