class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int maxi=0;
        int index=0;
        int cntone=0;
        vector<int> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j])cntone++;
            }
            if(cntone>maxi){
                index=i;
                maxi=cntone;
            }
            cntone=0;
        }
        return{index,maxi};
    }
};