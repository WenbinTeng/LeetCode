#include <unordered_set>
#include <vector>

class Solution {
  public:
    int findMaximumXOR(std::vector<int> &nums) {
        int res = 0;
        int rec = 0;

        for (int i = 30; i >= 0; --i) {
            std::unordered_set<int> us;

            for (const auto &num : nums) {
                us.insert(num >> i);
            }

            res = res * 2;
            rec = res + 1;

            for (const auto &num : nums) {
                if (us.find(rec ^ (num >> i)) != us.end()) {
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};