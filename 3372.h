#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        std::vector<int> res(n);
        std::unordered_map<int, std::vector<int>> edgeDict1;
        std::unordered_map<int, std::vector<int>> edgeDict2;

        for (auto& edge : edges1) {
            int u = edge[0];
            int v = edge[1];
            edgeDict1[u].push_back(v);
            edgeDict1[v].push_back(u);
        }
        for (auto& edge : edges2) {
            int u = edge[0];
            int v = edge[1];
            edgeDict2[u].push_back(v);
            edgeDict2[v].push_back(u);
        }

        auto bfs = [](int n, int k, std::unordered_map<int, std::vector<int>>& edgeDict) {
            std::vector<int> nodeCnt(n);
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                std::vector<int> queue(1, i);
                std::vector<int> visited(n, 0);
                visited[i] = 1;
                for (int depth = 0; depth < k && !queue.empty(); depth++) {
                    std::vector<int> children;
                    for (auto u : queue) {
                        for (auto v : edgeDict[u]) {
                            if (visited[v] == 0) {
                                children.push_back(v);
                                visited[v] = 1;
                            }
                        }
                    }
                    cnt += children.size();
                    queue = children;
                }
                nodeCnt[i] = cnt;
            }
            return nodeCnt;
        };

        auto nodeCnt1 = bfs(n, k, edgeDict1);
        auto nodeCnt2 = bfs(m, k - 1, edgeDict2);

        int maxCnt = *std::max_element(nodeCnt2.begin(), nodeCnt2.end());

        for (int i = 0; i < n; i++) {
            res[i] = nodeCnt1[i] + (k > 0 ? maxCnt : 0);
        }

        return res;
    }
};