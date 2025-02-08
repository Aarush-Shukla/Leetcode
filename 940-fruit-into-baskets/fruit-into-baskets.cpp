class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        int k=2;
        int maxi=INT_MIN;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[fruits[j]]++;
            if(mpp.size()<k){
                j++;
            }
            else if(mpp.size()==k){
                maxi=max(maxi, j-i+1);
                j++;
            }
            else if(mpp.size()>k){
                while(mpp.size()>k){
                    if(mpp.find(fruits[i])!=mpp.end()){
                        mpp[fruits[i]]--;
                        if(mpp[fruits[i]]==0){
                            mpp.erase(fruits[i]);
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        if(mpp.size()<k) return n;
        else return maxi;
    }
};