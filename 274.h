#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());

        for (int h = citations.size(); h > 0; h--) {
            if (citations[h - 1] >= h) {
                return h;
            }
        }

        return 0;
    }
};