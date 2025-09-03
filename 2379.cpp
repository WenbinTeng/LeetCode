#include <string>

class Solution {
  public:
    int minimumRecolors(std::string blocks, int k) {
        int res = 0;
        int cnt = 0;

        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++cnt;
            }
        }

        res = cnt;
        for (int i = k; i < blocks.size(); ++i) {
            if (blocks[i - k] == 'W' && blocks[i] == 'B') {
                --cnt;
            }
            if (blocks[i - k] == 'B' && blocks[i] == 'W') {
                ++cnt;
            }
            res = std::min(res, cnt);
        }

        return res;
    }
};