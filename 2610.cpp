#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> findMatrix(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> cnt(201, 0);

        for (auto num : nums) {
            cnt[num]++;
        }

        bool inserted = true;
        while (inserted) {
            std::vector<int> line;
            inserted = false;
            for (int i = 1; i <= 200; i++) {
                if (cnt[i] > 0) {
                    line.push_back(i);
                    inserted = true;
                    cnt[i]--;
                }
            }
            if (inserted) {
                res.emplace_back(line);
            }
        }

        return res;
    }
};