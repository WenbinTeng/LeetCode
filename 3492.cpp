#include <vector>

class Solution {
  public:
    int maxContainers(int n, int w, int maxWeight) {
        return std::min(n * n, maxWeight / w);
    }
};