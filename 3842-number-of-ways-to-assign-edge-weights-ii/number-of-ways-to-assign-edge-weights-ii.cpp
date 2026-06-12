class Solution {//copilot failed , so chat gpt's code
public:
    static constexpr long long MOD = 1000000007LL;

    vector<int> depth;
    vector<vector<int>> up;
    int LOG;

    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    void dfs(int u, int p, vector<vector<int>>& adj) {
        up[0][u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                a = up[j][a];
            }
        }

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }

        return up[0][a];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1));

        dfs(1, 1, adj);

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[j][i] = up[j - 1][ up[j - 1][i] ];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            long long dist =
                (long long)depth[u] + depth[v] - 2LL * depth[w];

            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)modPow(2, dist - 1));
            }
        }

        return ans;
    }
};