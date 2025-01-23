class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n); // Correct initialization
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> ans(n); // Correct initialization
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top(); // Assign only when index is valid
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElement(vector<int>& heights, int n) {
    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[i] >= heights[st.top()]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextGreaterElement(vector<int>& heights, int n) {
    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[i] >= heights[st.top()]) {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0; // Handle empty input

        vector<int> prev = prevSmallerElement(heights, n);
        vector<int> next = nextSmallerElement(heights, n);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int res = heights[i] * (next[i] - prev[i] - 1);
            maxi = max(maxi, res);
        }
        return maxi;
    }
};
