#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int reachableNodes(int n, std::vector<std::vector<int>> &edges, std::vector<int> &restricted) {
        int res = 1;
        std::unordered_set<int> r;
        std::unordered_set<int> visit;
        std::unordered_map<int, std::vector<int>> um;
        std::queue<int> q;
        q.push(0);

        for (const auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];

            um[a].push_back(b);
            um[b].push_back(a);
        }

        for (const auto u : restricted) {
            r.insert(u);
        }

        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i) {
                int front = q.front();
                q.pop();
                visit.insert(front);
                for (const auto u : um[front]) {
                    if (visit.count(u) || r.count(u))
                        continue;
                    q.push(u);
                    ++res;
                }
            }
        }

        return res;
    }
};