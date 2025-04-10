class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int m = items.size();
        vector<int> maxBeauty(m);
        maxBeauty[0] = items[0][1]; 
        
        for (int i = 1; i < m; i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]); 
        }

        vector<int> ans;
        for (int query : queries) {
            int left = 0, right = m - 1, idx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (items[mid][0] <= query) {
                    idx = mid;
                    left = mid + 1; 
                } else {
                    right = mid - 1; 
                }
            }
            ans.push_back(idx == -1 ? 0 : maxBeauty[idx]);
        }

        return ans;
    }
};
