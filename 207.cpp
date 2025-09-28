#include <unordered_map>
#include <vector>

class Solution {
  public:
    bool canFinish(int numCourses,
                   std::vector<std::vector<int>> &prerequisites) {
        bool valid = true;
        std::vector<int> visited(numCourses, 0);
        std::unordered_map<int, std::vector<int>> adj;

        for (auto &req : prerequisites) {
            adj[req[1]].push_back(req[0]);
        }

        auto dfs = [&](auto &&self, int u) -> void {
            visited[u] = 1;
            for (auto v : adj[u]) {
                if (!visited[v]) {
                    self(self, v);
                    if (!valid) {
                        return;
                    }
                } else if (visited[v] == 1) {
                    valid = false;
                    return;
                }
            }
            visited[u] = 2;
        };

        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(dfs, i);
            }
        }

        return valid;
    }
};