class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int delrow[], int delcol[], int color, int row, int col, int inicolor) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != color) {
                dfs(image, ans, delrow, delcol, color, nrow, ncol, inicolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        if (inicolor == color) return image; // No need to proceed if the initial color is the same as the new color
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(image, ans, delrow, delcol, color, sr, sc, inicolor);
        return ans;
    }
};
