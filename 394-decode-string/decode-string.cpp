class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string curr_string="";
                while(!st.empty() && st.top()!='['){
                    curr_string= st.top() + curr_string;
                    st.pop();
                }
                st.pop();
                string number="";
                while(!st.empty() && isdigit(st.top())){
                    number=st.top()+number;
                    st.pop();
                }
                int k=stoi(number);
                while(k--){
                    for(int j=0;j<curr_string.size();j++){
                        st.push(curr_string[j]);
                    }
                }
            }
        }
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
    }
};