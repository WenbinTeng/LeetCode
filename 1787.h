#include <vector>
#include <unordered_map>

class Solution {
public:
    int minChanges(std::vector<int>& nums, int k) {
        std::vector<std::vector<int>> mem(2000, std::vector<int>(2000, -1));
        std::vector<std::unordered_map<int, int>> groups(k);
        std::vector<int> numCnt(nums.size(), 0);
        std::vector<int> maxVal(nums.size(), 0);
        int res = INT_MAX;

        for (int i = 0; i < k; ++i)
        {
            for (int j = i; j < nums.size(); j += k)
            {
                ++numCnt[i];
                ++groups[i][nums[j]];
            }
        }

        for (int i = 0; i < k; ++i)
        {
            for (const auto& [num, cnt] : groups[i])
            {
                maxVal[i] = std::max(maxVal[i], cnt);
            }
        }

        for (int i = 0; i < k; ++i)
        {
            int cur = 0;

            for (int j = 0; j < k; ++j)
            {
                cur += i == j ? numCnt[j] : numCnt[j] - maxVal[j];
            }

            res = std::min(res, cur);
        }

        return std::min(res, dfs(mem, groups, numCnt, 0, k, 0));
    }

private:
    int dfs(std::vector<std::vector<int>>& mem, std::vector<std::unordered_map<int, int>>& groups, std::vector<int>& numCnt, int index, int k, int last)
    {
        if (index == k) {return last == 0 ? 0 : INT_MAX;}

        if (mem[index][last] != -1) return mem[index][last];

        int res = INT_MAX;
        int rec = INT_MAX;

        for (const auto& [num, cnt] : groups[index])
        {
            rec = dfs(mem, groups, numCnt, index + 1, k, last ^ num);
            res = rec == INT_MAX ? res : std::min(res, numCnt[index] - cnt + rec);
        }

        return mem[index][last] = res;
    }
};