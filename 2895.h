#include <vector>
#include <algorithm>

class Solution {
public:
    int minProcessingTime(std::vector<int>& processorTime, std::vector<int>& tasks) {
        int res = 0;

        std::sort(processorTime.begin(), processorTime.end());
        std::sort(tasks.begin(), tasks.end(), std::greater<int>());

        for (int i = 0; i < processorTime.size(); i++)
            res = std::max(res, processorTime[i] + tasks[i * 4]);

        return res;
    }
};