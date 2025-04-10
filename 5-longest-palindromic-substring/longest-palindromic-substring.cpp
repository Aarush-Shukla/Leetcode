class Solution {
public:

    int t[1001][1001];

    bool solve(string &s, int i, int j){
        if(i>=j)return t[i][j]=1;

        if(t[i][j]!=-1)return t[i][j];

        if(s[i]==s[j])return t[i][j]= solve(s,i+1,j-1);

        return t[i][j]=0;
    }

    string longestPalindrome(string s) {
      int n=s.size();
      int maxlen=0;
      memset(t,-1,sizeof(t));
      int sp=0;  //starting point
      for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(j-i+1>maxlen && solve(s,i,j)){
                maxlen=j-i+1;
                sp=i;
            }
        }
      }

      return s.substr(sp,maxlen); // s.substr(starting index, length)
    }
};