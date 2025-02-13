#include <vector>
#include <algorithm>

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        std::vector<int> cnt(46, 0);

        auto sumDigit = [](int num) -> int {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        for (int i = lowLimit; i <= highLimit; i++)
            cnt[sumDigit(i)]++;

        return *std::max_element(cnt.begin(), cnt.end());
    }
};