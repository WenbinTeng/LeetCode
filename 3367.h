#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximizeSumOfWeights(std::vector<std::vector<int>>& edges, int K) {
        int n = edges.size() + 1;
        std::vector<int> e[n], v[n];
        for (auto &edge : edges) {
            e[edge[0]].push_back(edge[1]);
            v[edge[0]].push_back(edge[2]);
            e[edge[1]].push_back(edge[0]);
            v[edge[1]].push_back(edge[2]);
        }

        long long dp[n][2];
        auto dfs = [&](auto &&self, int sn, int fa, int from) -> void {
            std::vector<long long> vec;
            long long base = 0;
            for (int i = 0; i < e[sn].size(); i++) {
                int fn = e[sn][i];
                if (fn == fa)
                    continue;
                self(self, fn, sn, v[sn][i]);
                base += dp[fn][0];
                vec.push_back(dp[fn][1] - dp[fn][0]);
            }

            std::sort(vec.begin(), vec.end(), std::greater<long long>());

            long long sm = 0;
            for (int i = 0; i < K - 1 && i < vec.size(); i++)
                if (vec[i] > 0)
                    sm += vec[i];
            dp[sn][1] = base + sm + from;
            if (vec.size() >= K && vec[K - 1] > 0)
                sm += vec[K - 1];
            dp[sn][0] = base + sm;
        };
        
        dfs(dfs, 0, -1, 0);
        return dp[0][0];
    }
};