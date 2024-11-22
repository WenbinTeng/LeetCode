#include <vector>
#include <tuple>

class Solution {
public:
    std::vector<int> timeTaken(std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> g(edges.size() + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        std::vector<std::tuple<int, int, int>> nodes(g.size());
        auto dfs = [&](auto&& dfs, int x, int parent) -> int {
            int max_d = 0, max_d2 = 0, my = 0;
            for (int y : g[x]) {
                if (y == parent) {
                    continue;
                }
                int depth = dfs(dfs, y, x) + 2 - y % 2;
                if (depth > max_d) {
                    max_d2 = max_d;
                    max_d = depth;
                    my = y;
                } else if (depth > max_d2) {
                    max_d2 = depth;
                }
            }
            nodes[x] = {max_d, max_d2, my};
            return max_d;
        };
        dfs(dfs, 0, -1);

        std::vector<int> ans(g.size());
        auto reroot = [&](auto&& reroot, int x, int parent, int from_up) -> void {
            auto& [max_d, max_d2, my] = nodes[x];
            ans[x] = std::max(from_up, max_d);
            for (int y : g[x]) {
                if (y != parent) {
                    reroot(reroot, y, x, std::max(from_up, (y == my ? max_d2 : max_d)) + 2 - x % 2);
                }
            }
        };
        reroot(reroot, 0, -1, 0);

        return ans;
    }
};