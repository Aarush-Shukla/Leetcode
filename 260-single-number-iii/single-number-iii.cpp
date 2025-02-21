class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor = 0;
        for(int num:nums){
            overall_xor^=num;
        }

        int rightmost= (overall_xor & -(unsigned int)overall_xor); //rightmost set bit which is different(as we are doing overall_xor and if the result is 1 then for both the numbers that would be different) in both of the elements 
        int b1=0;
        int b2=0; 
        for(int num:nums){
            if(num & rightmost){
                b1 ^= num;
            }
            else{
                b2^=num;
            }
        }  
    return {b1,b2};
    }
};