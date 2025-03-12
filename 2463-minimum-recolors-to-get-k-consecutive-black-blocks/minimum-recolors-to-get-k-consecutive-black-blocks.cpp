class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;
        int cnt=0;
        int mini=INT_MAX;
        while(j<blocks.size()){
            if(blocks[j]=='B')cnt++;
            if(j-i+1==k){
            mini=min(mini,k-cnt);
            if(blocks[i]=='B')cnt--;
            i++;
            }
            j++;
        }
        return mini;
    }
};