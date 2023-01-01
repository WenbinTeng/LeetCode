#include <vector>

class Solution {
public:
    int minimumScore(std::vector<int> &nums, std::vector<std::vector<int>> &edges) {
        adj = std::vector<std::vector<int>>(nums.size());

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int x : nums) {
            xorSum1 ^= x;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j : adj[i]) {
                xorSum2 = dfs1(nums, i, -1, j);
                dfs2(nums, i, -1, j);
            }
        }

        return res;
    }

private:
    std::vector<std::vector<int>> adj;
    int res = 2e9;
    int xorSum1 = 0;
    int xorSum2 = 0;

    int dfs1(std::vector<int> &nums, int currNode, int prevNode, int ban) {
        int ret = nums[currNode];

        for (int n : adj[currNode]) {
            if (n != prevNode && n != ban) {
                ret ^= dfs1(nums, n, currNode, ban);
            }
        }

        return ret;
    }

    int dfs2(std::vector<int> &nums, int currNode, int prevNode, int ban) {
        int ret = nums[currNode];

        for (int fn : adj[currNode]) {
            if (fn != prevNode && fn != ban) {
                int x = dfs2(nums, fn, currNode, ban);
                ret ^= x;
                int y = xorSum2 ^ x;
                int z = xorSum1 ^ xorSum2;
                if (x > y)
                    std::swap(x, y);
                if (x > z)
                    std::swap(x, z);
                if (y > z)
                    std::swap(y, z);
                res = std::min(res, z - x);
            }
        }

        return ret;
    }
};