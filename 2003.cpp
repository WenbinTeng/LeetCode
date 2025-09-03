#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<int> smallestMissingValueSubtree(std::vector<int> &parents,
                                                 std::vector<int> &nums) {
        int n = nums.size();
        this->mex = std::vector<int>(n, 1);
        this->adj = std::vector<std::vector<int>>(n);
        this->rec = std::vector<std::unordered_set<int>>(n);
        for (int i = 1; i < parents.size(); ++i) {
            adj[parents[i]].push_back(i);
        }
        dfs(nums, 0, -1);
        return mex;
    }

  private:
    std::vector<int> mex;
    std::vector<std::vector<int>> adj;
    std::vector<std::unordered_set<int>> rec;

    void dfs(std::vector<int> &nums, int current, int parent) {
        for (auto v : adj[current]) {
            if (v != parent) {
                dfs(nums, v, current);

                mex[current] = std::max(mex[current], mex[v]);

                if (rec[v].size() > rec[current].size()) {
                    std::swap(rec[v], rec[current]);
                }

                for (auto i : rec[v]) {
                    rec[current].insert(i);
                }
            }
        }

        rec[current].insert(nums[current]);

        while (rec[current].count(mex[current]))
            ++mex[current];
    }
};