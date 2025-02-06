class Solution {
public:

    bool solve(string &s, int i, int j){
        if(i>=j)return true;

        if(s[i]==s[j])return solve(s,i+1,j-1);

        return false;
    }

    string longestPalindrome(string s) {
      int n=s.size();
      int maxlen=0;
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