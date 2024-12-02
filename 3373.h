#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
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

        auto dfs = [](auto &&self, int parent, int node, int color, std::unordered_map<int, std::vector<int>>& edgeDict, std::vector<int>& colorVec, std::vector<int>& nodeCnt) -> void {
            colorVec[node] = color;
            nodeCnt[color]++;
            for (auto next : edgeDict[node]) {
                if (next != parent) {
                    self(self, node, next, color ^ 1, edgeDict, colorVec, nodeCnt);
                }
            }
        };
        
        std::vector<int> colorVec1(n);
        std::vector<int> nodeCnt1(2, 0);
        std::vector<int> colorVec2(m);
        std::vector<int> nodeCnt2(2, 0);

        dfs(dfs, -1, 0, 0, edgeDict1, colorVec1, nodeCnt1);
        dfs(dfs, -1, 0, 0, edgeDict2, colorVec2, nodeCnt2);

        for (int i = 0; i < n; i++) {
            res[i] = nodeCnt1[colorVec1[i]] + (m > 1 ? std::max(nodeCnt2[0], nodeCnt2[1]) : 0);
        }

        return res;
    }
};