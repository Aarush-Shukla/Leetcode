class Solution {
public:

    int canMakeBouquet(vector<int>& bloomDay, int mid, int k){
        int bouquet=0;
        int consecutive_bouquet=0;

        for(int i=0;i<bloomDay.size();i++){

            if(bloomDay[i]<=mid){
                consecutive_bouquet++;
            }else{
                consecutive_bouquet=0;
            }

            if(consecutive_bouquet == k){
                bouquet++;
                consecutive_bouquet=0;
            }
        }

        return bouquet;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int startDate=*min_element(bloomDay.begin(),bloomDay.end());
        int endDate=*max_element(bloomDay.begin(),bloomDay.end());
        int minDays=-1;
        while(startDate<=endDate){
            int mid=startDate+(endDate-startDate)/2;
            if(canMakeBouquet(bloomDay,mid,k)>=m){
                minDays=mid;
                endDate=mid-1;
            }else{
                startDate=mid+1;
            }
        }
        return minDays;
    }
};