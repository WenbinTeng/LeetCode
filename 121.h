#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int dp = 0;
        int minPrice = prices[0];
        int maxPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (minPrice > prices[i]) {
                minPrice = prices[i];
                maxPrice = prices[i];
            }
            if (maxPrice < prices[i]) {
                maxPrice = prices[i];
            }
            if (dp < maxPrice - minPrice) {
                dp = maxPrice - minPrice;
            }
        }
        
        return dp;
    }
};