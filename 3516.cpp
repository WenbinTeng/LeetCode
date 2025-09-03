#include <algorithm>

class Solution {
  public:
    int findClosest(int x, int y, int z) {
        int dist1 = std::abs(x - z);
        int dist2 = std::abs(y - z);
        if (dist1 > dist2)
            return 2;
        else if (dist1 < dist2)
            return 1;
        return 0;
    }
};