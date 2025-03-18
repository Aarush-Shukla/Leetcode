class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        
        unordered_map<int, int> mpp;
        mpp[0] = -1; // Initialize to -1 to correctly handle subarrays starting from index 0
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) rem += k; // Ensure positive remainder

            if (mpp.find(rem) != mpp.end()) {
                // Check if the subarray length is at least 2
                if (i - mpp[rem] > 1) return true;
            } else {
                // Store the first occurrence of this remainder
                mpp[rem] = i;
            }
        }
        return false;
    }
};
