#include <string>
#include <vector>

class Solution {
  public:
    int numberOfBeams(std::vector<std::string> &bank) {
        int res = 0;
        std::vector<int> nums;

        for (int i = 0; i < bank.size(); ++i) {
            int cnt = 0;

            for (int j = 0; j < bank[0].size(); ++j) {
                if (bank[i][j] == '1')
                    ++cnt;
            }

            if (cnt)
                nums.push_back(cnt);
        }

        for (int i = 1; i < nums.size(); ++i) {
            res += nums[i - 1] * nums[i];
        }

        return res;
    }
};