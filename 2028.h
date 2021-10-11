#include <vector>

class Solution {
public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long long currSum = 0;
        long long missSum = 0;
        std::vector<int> res(n);

        for (const auto& roll : rolls)
        {
            currSum += roll;
        }

        if (currSum + n * 6 < mean * (n + m) || currSum + n > mean * (n + m)) return {};

        missSum = mean * (n + m) - currSum - n;

        for (int i = 0; i < n; ++i)
        {
            if (missSum > 0)
            {
                if (missSum >= 5)
                {
                    res[i] = 6; missSum -= 5;
                }
                else
                {
                    res[i] = 1 + missSum; missSum = 0;
                }
            }
            else
            {
                res[i] = 1;
            }
        }

        return res;
    }
};