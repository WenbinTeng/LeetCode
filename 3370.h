#include <vector>

class Solution {
public:
    int smallestNumber(int n) {
        std::vector<int> dict = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

        for (int i = 0; i < dict.size(); i++) {
            if (n < dict[i]) {
                return dict[i] - 1;
            }
        }

        return 1023;
    }
};