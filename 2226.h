#include <numeric>
#include <vector>

class Solution {
public:
    int maximumCandies(std::vector<int> &candies, long long k) {
        int res = 0;
        long long l = 1;
        long long r = (int)1e7;

        while (l <= r) {
            long long mid = (l + r) / 2;

            if (validAlloc(candies, k, mid)) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }

private:
    bool validAlloc(std::vector<int> &candies, long long k, long long alloc) {
        for (int i = 0; i < candies.size(); ++i) {
            k -= candies[i] / alloc;
            if (k <= 0)
                return true;
        }

        return k <= 0;
    }
};