class Solution {
public:
    void dfs(int start, vector<int> adj[], vector<int> &vis) {
        vis[start] = 1;
        for (int neighbor : adj[start]) { // Traverse neighbors of `start`
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n]; // Adjacency list to represent the graph

        // Build the adjacency list from the `isConnected` matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) { // Only add connected edges
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0); // Visited array to track visited nodes
        int count = 0;

        // Traverse each node and perform DFS if not visited
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis); // Explore the connected component
            }
        }

        return count; // Return the number of connected components
    }
};
