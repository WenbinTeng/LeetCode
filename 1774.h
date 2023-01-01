#include <vector>

class Solution {
public:
    int closestCost(std::vector<int> &baseCosts, std::vector<int> &toppingCosts, int target) {
        for (auto &base : baseCosts)
            if (res == target)
                return res;
            else
                dfs(toppingCosts, base, 0, target);
        return res;
    }

private:
    int res = INT_MAX;

    void dfs(std::vector<int> &toppingCosts, int sum, int index, int target) {
        if (std::abs(sum - target) < std::abs(res - target))
            res = sum;
        if (std::abs(sum - target) == std::abs(res - target) && sum < res)
            res = sum;

        if (sum >= target || index == toppingCosts.size())
            return;

        dfs(toppingCosts, sum + 0 * toppingCosts[index], index + 1, target);
        dfs(toppingCosts, sum + 1 * toppingCosts[index], index + 1, target);
        dfs(toppingCosts, sum + 2 * toppingCosts[index], index + 1, target);
    }
};