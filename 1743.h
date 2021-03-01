#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) {
        std::unordered_map<int, std::vector<int>> um;
        std::vector<int> res;

        for (const auto& iter : adjacentPairs)
        {
            um[iter[0]].push_back(iter[1]);
            um[iter[1]].push_back(iter[0]);
        }

        for (const auto& iter : um)
        {
            if (iter.second.size() == 1)
            {
                int tempKey;
                int prevKey;
                int nextKey;
                for (tempKey = 0, prevKey = iter.first, nextKey = iter.second[0]; um[nextKey].size() == 2;)
                {
                    res.push_back(prevKey);

                    tempKey = nextKey;
                    nextKey = um[nextKey][0] != prevKey ? um[nextKey][0] : um[nextKey][1];
                    prevKey = tempKey;
                }
                res.push_back(prevKey);
                res.push_back(nextKey);

                break;
            }
        }

        return res;
    }
};