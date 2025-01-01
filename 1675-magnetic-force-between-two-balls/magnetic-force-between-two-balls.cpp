class Solution {
public:

    bool canWePlace(vector<int>& position, int mid,int m){
        int n=position.size();
        int ball_pos=position[0];
        int cnt_ball=1;;
        for(int i=1;i<position.size();i++){
            if(position[i]-ball_pos>=mid){
                ball_pos=position[i];
                cnt_ball++;
            }
            if(cnt_ball>=m)return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+ (high-low)/2;
            if(canWePlace(position,mid,m)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
    }
};