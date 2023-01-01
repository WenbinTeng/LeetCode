#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumGroups(std::vector<int> &grades) {
        for (int i = 1; i < 1e+5; ++i) {
            if ((1 + i) * i / 2 > grades.size())
                return i - 1;
        }

        return 1;
    }
};