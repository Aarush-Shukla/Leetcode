class Solution {
public:

    bool check(int index, int currsum,string s, int num){
        if(index==s.size()){
            return currsum==num;
        }

        bool possible=false;

        for(int j=index;j<s.size();j++){
            string temp=s.substr(index,j-index+1);
            int val=stoi(temp);
            possible = possible || check(j+1,currsum+val,s,num);
            if(possible==true){
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punish=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            if(check(0,0,s,i)){
                punish+=sq;
            }
        }
        return punish;
    }
};