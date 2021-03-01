#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> um;
        for (const auto& iter : strs)
        {
            auto key = iter;
            std::sort(key.begin(), key.end());
            um[key].push_back(iter);
        }
        
        std::vector<std::vector<std::string>> res;
        for (const auto& iter : um)
        {
            res.push_back(iter.second);
        }

        return res;
    }
};