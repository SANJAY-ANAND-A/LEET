class Solution {//Copilot
public:
    const int MOD = 1e9 + 7;

    int modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return (int)result;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }


        vector<int> depth(n + 1, 0);
        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        int maxDepth = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    depth[v] = depth[u] + 1;
                    maxDepth = max(maxDepth, depth[v]);
                    q.push(v);
                }
            }
        }

    
        if (maxDepth == 0) return 0; 
        return modPow(2, maxDepth - 1);
    }
};
