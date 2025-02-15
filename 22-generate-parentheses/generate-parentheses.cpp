class Solution {
public:

    void solve(string temp,int open,int close,vector<string>& ans,int n){
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if(open==close){
            string temp1=temp;
            temp1+="(";
            solve(temp1,open-1,close,ans,n);
        }else if(open==0){
            string temp1=temp;
            temp1+=")";
            solve(temp1,open,close-1,ans,n);
        }
        else if(close==0){
            string temp1=temp;
            temp1+="(";
            solve(temp1,open-1,close,ans,n);
        } else{
            string temp1=temp;
            string temp2=temp;
            temp1+="(";
            temp2+=")";
            solve(temp1,open-1,close,ans,n);
            solve(temp2,open,close-1,ans,n);
        }
    }

    vector<string> generateParenthesis(int n) {
       int open=n;
       int close=n;
       string temp="";
       vector<string> ans;
       solve(temp,open,close,ans,n); 
       return ans;
    }
};