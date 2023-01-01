#include <algorithm>
#include <vector>

class Solution {
public:
    int minimizedMaximum(int n, std::vector<int> &quantities) {
        int l = 1;
        int r = *std::max_element(quantities.begin(), quantities.end());

        while (l <= r) {
            int mid = (l + r) / 2;
            long long need = 0;
            for (const auto quantity : quantities) {
                need += (quantity - 1) / mid + 1;
            }
            if (need > n) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};