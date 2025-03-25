#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int numberOfComponents(std::vector<std::vector<int>>& properties, int k) {
        int n = properties.size();
        int m = properties[0].size();
        int res = 0;
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
        std::unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            std::unordered_set<int> dict1;
            for (auto num : properties[i]) {
                dict1.insert(num);
            }
            for (int j = i + 1; j < n; j++) {
                std::unordered_set<int> dict2;
                for (auto num : properties[j]) {
                    dict2.insert(num);
                }
                int cnt = 0;
                for (auto num : dict2) {
                    if (dict1.count(num)) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited.count(i)) {
                continue;
            }
            std::queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                visited.insert(u);
                for (int v = 0; v < n; v++) {
                    if (graph[u][v] == 1 && !visited.count(v)) {
                        q.push(v);
                    }
                }
            }
            res++;
        }

        return res;
    }
};