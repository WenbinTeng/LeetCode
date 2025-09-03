#include <algorithm>
#include <vector>

class Solution {
  public:
    long long maximumBeauty(std::vector<int> &flowers, long long newFlowers,
                            int target, int full, int partial) {
        long long res = 0;
        std::vector<long long> prevSum(flowers.size() + 1);

        std::sort(flowers.begin(), flowers.end());

        if (flowers.front() >= target)
            return flowers.size() * (long long)full;

        for (int i = 0; i < flowers.size(); ++i) {
            prevSum[i + 1] = prevSum[i] + flowers[i];
        }

        for (int i = flowers.size() - 1; i >= 0; --i) {
            if (flowers[i] >= target)
                continue;

            int l = flowers[0];
            int r = target - 1;

            while (l <= r) {
                int mid = (l + r) / 2;

                if (check(flowers, newFlowers, prevSum, mid, i + 1)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            res = std::max(res, (long long)(flowers.size() - i - 1) * full +
                                    (long long)(l - 1) * partial);
            newFlowers -= target - flowers[i];
            if (newFlowers <= 0)
                return res;
        }

        if (newFlowers > 0)
            res = std::max(res, (long long)flowers.size() * full);

        return res;
    }

  private:
    bool check(std::vector<int> &flowers, long long newFlowers,
               std::vector<long long> &prevSum, int value, int index) {
        long long p =
            std::lower_bound(flowers.begin(), flowers.begin() + index, value) -
            flowers.begin();
        return newFlowers >= p * value - prevSum[p];
    }
};