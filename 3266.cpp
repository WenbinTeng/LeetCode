#include <algorithm>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> getFinalState(std::vector<int> &nums, int k,
                                   int multiplier) {
        if (multiplier == 1)
            return nums;

        const int mod = 1e+9 + 7;
        int n = nums.size();
        std::vector<int> res(n);
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<std::pair<long long, int>>>
            pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int maxValue = *std::max_element(nums.begin(), nums.end());

        while (k > 0) {
            auto [x, index] = pq.top();
            if (x * multiplier > maxValue)
                break;
            pq.pop();
            pq.push({x * multiplier, index});
            k--;
        }

        int times = k / n;
        int rests = k % n;

        while (!pq.empty()) {
            auto [x, index] = pq.top();
            pq.pop();
            x = (x * quickMult(multiplier, times, mod)) % mod;
            if (rests > 0) {
                x = (x * multiplier) % mod;
                rests--;
            }
            res[index] = x;
        }

        return res;
    }

  private:
    int quickMult(long long multiplier, int times, int mod) {
        int res = 1;
        while (times > 0) {
            if (times % 2 == 1)
                res = (res * multiplier) % mod;
            times /= 2;
            multiplier = (multiplier * multiplier) % mod;
        }
        return res;
    }
};