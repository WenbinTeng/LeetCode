#include <vector>

class Solution {
  public:
    int minDays(std::vector<int> &bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k)
            return -1;

        int l = 0;
        int r = 1e+9;

        auto checkInterval = [&](int days, int start) -> bool {
            for (int i = 0; i < k; i++) {
                if (start + i >= bloomDay.size())
                    return false;
                if (bloomDay[start + i] > days)
                    return false;
            }
            return true;
        };

        auto checValid = [&](int days) -> bool {
            int start = 0;
            int r = m;
            while (r && start < bloomDay.size()) {
                if (checkInterval(days, start)) {
                    start += k;
                    r--;
                } else {
                    while (start < bloomDay.size() && bloomDay[start] <= days) {
                        start++;
                    }
                    while (start < bloomDay.size() && bloomDay[start] > days) {
                        start++;
                    }
                }
            }
            return r == 0;
        };

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (checValid(mid))
                r = mid;
            else
                l = mid + 1;
        }

        return r;
    }
};