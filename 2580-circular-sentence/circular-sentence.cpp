class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool ans = false;
        if (sentence[0] == sentence[sentence.size() - 1]) {
            ans = true;
        }
        for (int i = 0; i < sentence.size() - 1; i++) {
            if (sentence[i] == ' ') { // Use single quotes for comparison with char
                if (sentence[i - 1] != sentence[i + 1]) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};
