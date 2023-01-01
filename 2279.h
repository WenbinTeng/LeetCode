#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumBags(std::vector<int> &capacity, std::vector<int> &rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); ++i) {
            capacity[i] -= rocks[i];
        }

        std::sort(capacity.begin(), capacity.end());

        for (int i = 0; i < capacity.size(); ++i) {
            if (capacity[i] <= additionalRocks) {
                additionalRocks -= capacity[i];
            } else {
                return i;
            }
        }

        return capacity.size();
    }
};