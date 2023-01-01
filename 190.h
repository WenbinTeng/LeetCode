#include <algorithm>
#include <string>

class Solution {
public:
    unsigned int reverseBits(unsigned int n) {
        std::string res;
        for (int i = 0; i < 32; ++i) {
            res.push_back(n % 2 + '0');
            n = n >> 1;
        }

        return std::stoul(res, 0, 2);
    }
};