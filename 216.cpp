#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        dfs(res, path, n, k, 1, 0);
        return res;
    }

  private:
    void dfs(std::vector<std::vector<int>> &res, std::vector<int> &path, int n,
             int k, int index, int sum) {
        if (path.size() == k) {
            if (sum == n)
                res.push_back(path);
            return;
        }

        for (int i = index; i <= 9; ++i) {
            path.push_back(i);
            dfs(res, path, n, k, i + 1, sum + i);
            path.pop_back();
        }
    }
};