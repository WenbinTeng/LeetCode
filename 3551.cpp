#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minSwaps(std::vector<int> &nums) {
        int n = nums.size();

        auto sumDigits = [](int num) -> int {
            int sum = 0;
            while (num) {
                sum += (num % 10);
                num /= 10;
            }
            return sum;
        };

        std::vector<std::pair<int, int>> digitsVec(n);
        for (int i = 0; i < n; i++) {
            digitsVec[i] = {sumDigits(nums[i]), nums[i]};
        }

        std::sort(digitsVec.begin(), digitsVec.end());

        std::unordered_map<int, int> posDict;
        for (int i = 0; i < n; i++) {
            posDict[nums[i]] = i;
        }

        int loops = 0;
        std::vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = posDict[nums[i]];
                }
                loops++;
            }
        }

        return n - loops;
    }
};