#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> dict;

        for (auto &str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            dict[key].push_back(str);
        }

        for (auto [_, vec] : dict) {
            res.push_back(vec);
        }

        return res;
    }
};