#include <vector>

class Solution {
  public:
    std::vector<int> occurrencesOfElement(std::vector<int> &nums,
                                          std::vector<int> &queries, int x) {
        std::vector<int> res;
        std::vector<int> pos;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                pos.push_back(i);
            }
        }

        for (auto query : queries) {
            if (query <= pos.size()) {
                res.push_back(pos[query - 1]);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};