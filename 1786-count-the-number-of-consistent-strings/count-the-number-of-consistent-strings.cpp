class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size(); // Get the size of the vector 'w' (number of words)
        int cnt = 0; // Initialize a counter to count the number of consistent strings

        // Loop through each word in the vector 'w'
        for(int i = 0; i < n; i++)
        {
            // Create a set of unique characters in the current word 'w[i]'
            set<char> st(words[i].begin(), words[i].end());

            bool flag = true; // Assume the word is consistent initially

            // Check if all characters in the set 'st' exist in the string 'all'
            for(auto x : st)
            {
                // If the character 'x' is not found in 'all', set flag to false
                auto it = find(allowed.begin(), allowed.end(), x);
                if(it == allowed.end()) // If character not found in 'all'
                {
                    flag = false; // Mark the word as inconsistent
                    break; // Break out of the loop as we found an invalid character
                }
            }

            // If the word is consistent (flag remains true), increment the counter
            if(flag) cnt++;
        }

        return cnt; // Return the count of consistent strings
    }
};