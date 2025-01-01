class Solution {
public:

    bool cantake(vector<int>& piles, int mid, int h){
        int sum=0;
        for(auto x: piles){
            sum+= x/mid;
            if( x % mid != 0){
                sum++;
            }
        }
        return sum<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(piles.begin(),piles.end());

        while(l<r){
            int mid=l+(r-l)/2;
            if(cantake(piles,mid,h)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};