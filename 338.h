#include <vector>

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> res(num + 1, 0);

        for (int i = 0; i <= num; ++i) res[i] = i % 2 == 0 ? res[i / 2] : res[i - 1] + 1;

        return res;
    }
};