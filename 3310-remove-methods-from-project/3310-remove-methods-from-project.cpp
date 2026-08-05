class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1;

        for (int next : graph[node]) {
            if (!vis[next]) {
                dfs(next, graph, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Build adjacency list
        vector<vector<int>> graph(n);

        for (auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        // vis[i] == 1 means method i is suspicious
        vector<int> vis(n, 0);

        // Find every suspicious method
        dfs(k, graph, vis);

        // Check if a healthy method invokes a suspicious one
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return all healthy methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};