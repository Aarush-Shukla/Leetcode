class Solution {
public:

    unordered_set<string> st;
    int n;
    int dp[301];


    bool solve(int index, string& s){
        n=s.length();
        if(index>=n)return true;
        if(st.find(s)!=st.end())return true;

        if(dp[index]!=-1)return dp[index];

        for(int i=1;i<=n;i++){
            string temp=s.substr(index,i);
            if(solve(index+i,s) && st.find(temp)!=st.end())return dp[index]= true;
        }
        return dp[index]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for(string word: wordDict){st.insert(word);}
        return solve(0,s);
    }
};