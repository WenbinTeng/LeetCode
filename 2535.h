#include <numeric>
#include <vector>

class Solution {
public:
    int differenceOfSum(std::vector<int> &nums) {
        return (int)std::abs(getElementSum(nums) - getDigitSum(nums));
    }

private:
    long long getElementSum(std::vector<int> &nums) {
        return std::accumulate(nums.begin(), nums.end(), 0);
    }

    long long getDigitSum(std::vector<int> &nums) {
        int ret = 0;

        for (auto num : nums) {
            while (num) {
                ret += num % 10;
                num = num / 10;
            }
        }

        return ret;
    }
};