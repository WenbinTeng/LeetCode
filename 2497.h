#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    int maxStarSum(std::vector<int>& vals, std::vector<std::vector<int>>& edges, int k) {
        int res = -INT_MAX + 1;
        std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::less<int>>> dict;

        for (int i = 0; i < vals.size(); i++) {
            dict[i].push(-1);
        }

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            dict[u].push(vals[v]);
            dict[v].push(vals[u]);
        }

        for (auto &[u, pq] : dict) {
            int sum = vals[u];
            for (int i = 0; i < k && !pq.empty() && pq.top() > 0; i++) {
                sum += pq.top();
                pq.pop();
            }
            res = std::max(res, sum);
        }

        return res;
    }
};