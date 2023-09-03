class Solution {
public:

   int minFallingPathSum(vector<vector<int>>& matrix) {
  int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
         vector<int> prev(m, 0);
        for (int j=0; j<m; j++){
            prev[j] = matrix[0][j];
        }
       
        for (int i=1; i<n; i++) {
            vector<int>curr(m, 0);
            for (int j=0; j<m; j++) {
                
                int up = matrix[i][j] + prev[j];
                int ldiag = matrix[i][j];
                if(j-1 >= 0) ldiag += prev[j-1];
                else ldiag += 1e9;
                int rdiag = matrix[i][j];
                if(j+1 < m)  rdiag += prev[j+1];
                else rdiag += 1e9;
                curr[j] = min(up, min(ldiag, rdiag));
            }
            prev=curr;
        }
        for (int j=0; j<m; j++) {
            ans = min(ans, prev[j]);
        }
        return ans;
    }
};