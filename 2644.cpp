#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxDivScore(std::vector<int> &nums, std::vector<int> &divisors) {
        std::vector<int> quotient(divisors.size());

        for (int i = 0; i < divisors.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (divisors[i] == 0)
                    break;
                if (nums[j] % divisors[i] == 0) {
                    ++cnt;
                }
            }
            quotient[i] = cnt;
        }

        int maxIndex = 0;
        int maxValue = quotient[0];
        for (int i = 1; i < quotient.size(); ++i) {
            if (maxValue < quotient[i] ||
                (maxValue == quotient[i] && divisors[maxIndex] > divisors[i])) {
                maxValue = quotient[i];
                maxIndex = i;
            }
        }

        return divisors[maxIndex];
    }
};