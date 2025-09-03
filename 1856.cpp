#include <stack>
#include <vector>

class Solution {
  public:
    int maxSumMinProduct(std::vector<int> &nums) {
        long long res = 0;
        int n = nums.size();
        std::vector<long long> sum(n + 1);
        std::vector<int> l(n, 0);
        std::vector<int> r(n, n - 1);
        std::stack<int> s;

        for (int i = 0; i <= n; ++i) {
            sum[i] = i == 0 ? nums[0]
                            : (long long)sum[i - 1] + (long long)nums[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                r[s.top()] = i - 1;
                s.pop();
            }
            s.push(i);
        }

        s = std::stack<int>();

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                l[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < n; ++i) {
            res = std::max(res, (long long)(sum[r[i] + 1] - sum[l[i]]) *
                                    (long long)nums[i]);
        }

        return res % (int)(1e+9 + 7);
    }
};