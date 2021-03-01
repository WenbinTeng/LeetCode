#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) return "";

        int minSize = INT_MAX;
        for (auto &iter : strs)
        {
            minSize = minSize < iter.size() ? minSize : iter.size();
        }
        for (int i = 0; i < minSize; i++)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        
        return strs[0].substr(0, minSize);
    }
};