class Solution {
public:
    bool isPalindrome(int x) {
        // string temp= to_string(x);
        // if(temp.length()==1) return true;
        // int i=0;
        // int j=temp.length()-1;
        // while(i<j){
        //     if(temp[i]==temp[j]){
        //         i++;
        //         j--;
        //     }else{
        //         return false;
        //     }
        // }
        // return true;

        if(x<0)return false;
        int num=x;
        long rev=0;
        while(num>0){
            rev= (rev*10) + (num%10);
            num = num/10;
        }

        return x==rev;
    }
};