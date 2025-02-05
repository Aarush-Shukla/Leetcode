class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
  unordered_map<int, int> mpp;
        for (auto it : arr) {
            mpp[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        while (k > 0 && !pq.empty()) {
            auto [freq, num] = pq.top();  // Extract smallest frequency element
            pq.pop();
            k -= freq;  // Use k to remove this entire frequency

            if (k < 0) {  // If k goes negative, it means we can't remove this number entirely
                pq.push({-k, num});  // Push back with the remaining frequency
                break;
            }
        }
        return pq.size();
    }
};