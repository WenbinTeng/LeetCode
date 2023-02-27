#include <vector>

class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        int res = 0;
        int prev = 0;
        int last = 0;
        std::vector<int> rMax(n + 1);

        for (int i = 0; i < rMax.size(); ++i) {
            rMax[i] = i;
        }

        for (int i = 0; i <= n; i++) {
            int start = std::max(0, i - ranges[i]);
            int end = std::min(n, i + ranges[i]);
            rMax[start] = std::max(rMax[start], end);
        }
        
        for (int i = 0; i < n; i++) {
            last = std::max(last, rMax[i]);
            if (i == last) {
                return -1;
            }
            if (i == prev) {
                res++;
                prev = last;
            }
        }
        
        return res;
    }
};