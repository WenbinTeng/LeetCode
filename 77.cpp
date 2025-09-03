#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;

        dfs(res, path, n, k, 1);

        return res;
    }

  private:
    void dfs(std::vector<std::vector<int>> &res, std::vector<int> &path, int n,
             int k, int index) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = index; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(res, path, n, k, i + 1);
            path.pop_back();
        }
    }
};