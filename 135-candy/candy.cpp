class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
     vector<int>L2R(n,1);
     vector<int>R2L(n,1);
     vector<int> ans(n,0);
     for(int i=0;i<n-1;i++){
        if(ratings[i]<ratings[i+1]){
            L2R[i+1]=L2R[i]+1;
        }
     }   
        for(int i=n-1;i>0;i--){
        if(ratings[i-1]>ratings[i]){
            R2L[i-1]=R2L[i]+1;
        }
     } 

     for(int i=0;i<n;i++){
        ans[i]=max(L2R[i],R2L[i]);
     }
     int temp=accumulate(ans.begin(),ans.end(),0);
     return temp;
    }
};