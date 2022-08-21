#include <vector>
#include <unordered_map>

class Solution {
public:
    int edgeScore(std::vector<int>& edges) {
        long long maxIndex = -1;
        long long maxValue = -1;
        std::unordered_map<int, long long> score;

        for (int i = 0; i < edges.size(); ++i)
        {
            score[edges[i]] += (long long)i;
        }

        for (const auto [k, v] : score)
        {
            if (maxValue < v)
            {
                maxValue = v;
                maxIndex = k;
            }
            else if (maxValue == v && maxIndex > k)
            {
                maxIndex = k;
            }
        }

        return maxIndex;
    }
};