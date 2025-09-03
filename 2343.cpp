#include <string>
#include <vector>

class Solution {
  public:
    std::vector<int>
    smallestTrimmedNumbers(std::vector<std::string> &nums,
                           std::vector<std::vector<int>> &queries) {
        int m = nums.size();
        int n = nums[0].size();
        std::vector<int> res;
        std::vector<std::vector<int>> radixSort(n + 1);

        for (int i = 0; i < m; ++i) {
            radixSort[0].push_back(i);
        }

        for (int k = 1; k <= n; ++k) {
            std::vector<std::vector<int>> bar(10);

            for (const auto i : radixSort[k - 1]) {
                bar[nums[i][n - k] - '0'].push_back(i);
            }

            for (int j = 0; j < 10; ++j) {
                for (const auto i : bar[j]) {
                    radixSort[k].push_back(i);
                }
            }
        }

        for (const auto &query : queries) {
            res.push_back(radixSort[query[1]][query[0] - 1]);
        }

        return res;
    }
};