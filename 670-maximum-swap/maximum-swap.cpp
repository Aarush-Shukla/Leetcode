class Solution {
public:
    int maximumSwap(int num) {
        string ans = to_string(num);
        string sortedAns = ans;      
    
        sort(sortedAns.begin(), sortedAns.end(), greater<char>());

        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] != sortedAns[i]) {
                for (int j = ans.size() - 1; j > i; --j) {
                    if (ans[j] == sortedAns[i]) {
                        swap(ans[i], ans[j]); 
                        return stoi(ans);   
                    }
                }
            }
        }
        return num;  
    }
};
