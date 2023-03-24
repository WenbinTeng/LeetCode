#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> res;
        int maxCandies = *std::max_element(candies.begin(), candies.end());

        for (const auto candy : candies) {
            res.push_back(candy + extraCandies >= maxCandies);
        }

        return res;
    }
};