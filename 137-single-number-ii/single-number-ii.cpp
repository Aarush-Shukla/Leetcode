class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int cntzeroes=0;
            int cntones=0;
            for(auto num : nums){
                if((num & temp)==0){ // checking if Kth bit is 0 or 1
                    cntzeroes++;
                }else{
                    cntones++;
                }
            }

            if(cntones%3 !=0 ){ //set the bit
                result= (result | temp);
            }
        }
        return result;
    }
};