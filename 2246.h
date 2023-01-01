#include <string>
#include <vector>

class Solution {
public:
    int longestPath(std::vector<int> &parent, std::string s) {
        std::vector<std::vector<int>> children(parent.size());

        for (int i = 1; i < parent.size(); ++i) {
            children[parent[i]].push_back(i);
        }

        dfs(children, s, 0);

        return res + 1;
    }

private:
    int res = 0;

    int dfs(std::vector<std::vector<int>> &children, std::string &s, int u) {
        int max = 0;

        for (const auto v : children[u]) {
            int len = dfs(children, s, v) + 1;

            if (s[u] != s[v]) {
                res = std::max(res, max + len);
                max = std::max(max, len);
            }
        }

        return max;
    }
};