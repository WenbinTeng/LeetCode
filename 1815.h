#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxHappyGroups(int batchSize, std::vector<int> &groups) {
        int res = 0;
        long long state = 0;

        for (const auto &v : groups) {
            int i = v % batchSize;
            res += i == 0;
            if (i) {
                state += 1ll << (i * 5);
            }
        }

        return res + dfs(batchSize, state, 0);
    }

private:
    std::unordered_map<long long, int> memo;

    int dfs(int batchSize, long long state, int mod) {
        if (memo.count(state))
            return memo[state];

        int res = 0;
        int x = mod == 0;

        for (int i = 1; i < batchSize; ++i) {
            if (state >> (i * 5) & 31) {
                int t = dfs(batchSize, state - (1ll << (i * 5)), (mod + i) % batchSize);
                res = std::max(res, t + x);
            }
        }

        return memo[state] = res;
    }
};