class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> st;
        int n=A.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            int cnt=0;
            for(int j=0;j<=i;j++){
                if(st.find(B[j])!=st.end())cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};