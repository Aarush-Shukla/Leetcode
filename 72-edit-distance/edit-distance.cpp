// class Solution {
// public:

//     int LCS(string a,int n,string b,int m){
//         if(n==0 || m==0)return 0;
//         if(a[n-1]==b[m-1]){
//             return 1+LCS(a,n-1,b,m-1);
//         }else{
//             return max(LCS(a,n-1,b,m),LCS(a,n,b,m-1));
//         }
        
//     }

//     int minDistance(string word1, string word2) {
//         if(word2.size()>word1.size())int deletions=(word1.size()-word2.size());
//         int n=a.size();
//         int m=b.size();
//         int insertions=
//     }
// };
class Solution {
public:

    
    int f(int i,int j,string& word1, string& word2, vector<vector<int>>& dp)
    {
        if(i<0 && j<0)
        {
            return 0;
        }
        if(j<0)
        {
            return i+1;
        }
        if(i<0)
        {
            return j+1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(word1[i]==word2[j])
        {
            return dp[i][j]= f(i-1,j-1,word1,word2,dp);
        }
        // abcd
        // abcd
        else
        {
            return dp[i][j] = 1+min({f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp),f(i,j-1,word1,word2,dp)});
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1-1,n2-1,word1,word2,dp);
    }
};