class Solution {
public:
    long long minimumSteps(string s) {
        long n=s.length();
        long ans=0;
        long no_one=0;
        for(long i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=no_one;
            }else if(s[i]=='1'){
                no_one++;
            }
        }
        return ans;
    }
};