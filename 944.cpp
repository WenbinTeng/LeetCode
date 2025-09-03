#include <string>
#include <vector>

class Solution {
  public:
    int minDeletionSize(std::vector<std::string> &strs) {
        int res = 0;

        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] < strs[j - 1][i]) {
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};