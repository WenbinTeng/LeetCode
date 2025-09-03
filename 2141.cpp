#include <algorithm>
#include <vector>

class Solution {
  public:
    long long maxRunTime(int n, std::vector<int> &batteries) {
        std::vector<long long> prev(batteries.size() + 1);

        std::sort(batteries.begin(), batteries.end());

        for (int i = 0; i < batteries.size(); ++i) {
            prev[i + 1] = prev[i] + batteries[i];
        }

        auto check = [&](long long mid) {
            int k = std::upper_bound(batteries.begin(), batteries.end(), mid) -
                    batteries.begin();
            return prev[k] + mid * (batteries.size() - k) >= mid * n;
        };

        long long l = 0;
        long long r = prev.back() / n;
        while (l <= r) {
            long long mid = (l + r) / 2;

            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }
};