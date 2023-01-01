#include <algorithm>
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
    int largestPathValue(std::string colors, std::vector<std::vector<int>> &edges) {
        int n = colors.size();
        int res = 0;
        std::vector<int> deg(n);
        std::vector<std::vector<int>> adj(n);

        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ++deg[v];
            adj[u].push_back(v);
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0)
                q.push(i);
        }

        std::vector<int> rec;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            rec.push_back(top);
            for (int v : adj[top])
                if (--deg[v] == 0)
                    q.push(v);
        }

        if (rec.size() != n)
            return -1;

        for (int color = 0; color < 26; ++color) {
            std::vector<int> dp(n);

            for (int i = n - 1; i >= 0; --i) {
                int top = rec[i];
                for (int v : adj[top]) {
                    dp[top] = std::max(dp[top], dp[v]);
                }
                if (colors[top] - 'a' == color)
                    ++dp[top];

                res = std::max(res, dp[top]);
            }
        }

        return res;
    }
};