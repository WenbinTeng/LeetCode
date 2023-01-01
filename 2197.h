#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> replaceNonCoprimes(std::vector<int> &nums) {
        std::vector<int> res;

        for (const auto num : nums) {
            res.push_back(num);

            int n = res.size();
            int t = n >= 2 ? std::__gcd(res[n - 2], res[n - 1]) : 0;

            while (t > 1) {
                res[n - 2] *= res[n - 1] / t;
                res.pop_back();
                --n;
                t = n >= 2 ? std::__gcd(res[n - 2], res[n - 1]) : 0;
            }
        }

        return res;
    }
};