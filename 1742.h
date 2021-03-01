#include <unordered_map>

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        std::unordered_map<int, int> um;
        int maxValue = 0;
        int sum;
        int num;

        for (int i = lowLimit; i <= highLimit; i++)
        {
            sum = 0;
            num = i;

            while (num)
            {
                sum = sum + num % 10;
                num = num / 10;
            }

            um[sum]++;
        }

        for (const auto& iter : um) maxValue = std::max(maxValue, iter.second);

        return maxValue;
    }
};