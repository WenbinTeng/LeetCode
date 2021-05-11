#include <vector>

class Solution {
public:
    int maximumPopulation(std::vector<std::vector<int>>& logs) {
        int res = 0;
        int max = 0;
        int sum = 0;
        
        for (int i = 1950; i <= 2050; ++i)
        {
            for (const auto& log : logs)
            {
                if (i >= log[0] && i < log[1]) ++sum;
            }

            if (max < sum)
            {
                max = sum;
                res = i;
            }

            sum = 0;
        }

        return res;
    }
};