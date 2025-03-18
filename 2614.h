#include <vector>
#include <cmath>

class Solution {
public:
    int diagonalPrime(std::vector<std::vector<int>>& nums) {
        int n = nums.size();
        int res = 0;

        auto isPrime = [&](int n) -> bool {
            if (n <= 1)
                return false;
            for (int i = 2; i <= std::sqrt(n); i++) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i]))
                res = std::max(res, nums[i][i]);
            if (isPrime(nums[i][n - i - 1]))
                res = std::max(res, nums[i][n - i - 1]);
        }

        return res;
    }
};