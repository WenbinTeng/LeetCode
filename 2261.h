#include <set>
#include <vector>

class Solution {
public:
    int countDistinct(std::vector<int> &nums, int k, int p) {
        int res;
        std::set<std::vector<int>> s;

        for (int i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            std::vector<int> tmp;

            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % p == 0)
                    ++cnt;
                if (cnt > k)
                    break;
                tmp.push_back(nums[j]);
                s.insert(tmp);
            }
        }

        return s.size();
    }
};