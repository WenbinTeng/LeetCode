#include <cmath>
#include <string>
#include <unordered_set>

class Solution {
  public:
    std::string crackSafe(int n, int k) {
        max = std::pow(10, n - 1);
        dfs(0, k);
        res += std::string(n - 1, '0');
        return res;
    }

  private:
    int max;
    std::string res;
    std::unordered_set<int> visited;

    void dfs(int u, int k) {
        for (int i = 0; i < k; ++i) {
            int v = u * 10 + i;
            if (!visited.count(v)) {
                visited.insert(v);
                dfs(v % max, k);
                res += (i + '0');
            }
        }
    }
};