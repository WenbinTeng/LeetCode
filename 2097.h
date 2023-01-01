#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> validArrangement(std::vector<std::vector<int>> &pairs) {
        std::vector<std::vector<int>> res;
        std::unordered_map<int, std::vector<int>> adj;
        std::unordered_map<int, int> indegree;

        for (const auto p : pairs) {
            adj[p[0]].push_back(p[1]);
            ++indegree[p[1]];
        }

        int start = pairs[0][0];

        for (const auto [v, n] : adj) {
            if (n.size() == indegree[v] + 1) {
                start = v;
            }
        }

        dfs(start, adj);

        std::reverse(rec.begin(), rec.end());

        for (int i = 1; i < rec.size(); ++i) {
            res.push_back({rec[i - 1], rec[i]});
        }

        return res;
    }

private:
    std::vector<int> rec;

    void dfs(int v, std::unordered_map<int, std::vector<int>> &adj) {
        auto &n = adj[v];

        while (!n.empty()) {
            auto t = n.back();
            n.pop_back();
            dfs(t, adj);
        }

        rec.push_back(v);
    }
};