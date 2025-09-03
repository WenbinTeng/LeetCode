#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minimumCoins(std::vector<int> &prices) {
        std::unordered_map<int, int> memo;

        auto dp = [&](auto &&self, int index) -> int {
            if (2 * index + 2 >= prices.size())
                return prices[index];
            if (!memo.count(index)) {
                int minValue = INT_MAX;
                for (int i = index + 1; i <= 2 * index + 2; i++) {
                    minValue = min(minValue, self(self, i));
                }
                memo[index] = prices[index] + minValue;
            }
            return memo[index];
        };

        return dp(dp, 0);
    }
};