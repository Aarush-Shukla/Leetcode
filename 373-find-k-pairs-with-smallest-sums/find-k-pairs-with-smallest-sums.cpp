class Solution {
public:
typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> ans;
        set<pair<int,int>> st;
        int sum=nums1[0]+ nums2[0];
        pq.push({sum,{0,0}});
        st.insert({0,0});

        while(k-- && !pq.empty()){
            auto it=pq.top();
            pq.pop();

            int i=it.second.first;
            int j=it.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<n && st.find({i,j+1})==st.end()) {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
            if(i+1<m && st.find({i+1,j})==st.end()) {
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
            }                                                                                                             
        }

   
        return ans;
    }
};