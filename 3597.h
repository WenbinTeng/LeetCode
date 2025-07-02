#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::vector<std::string> partitionString(std::string s) {
        std::vector<std::string> res;
        std::unordered_set<std::string> dict;

        for (int i = 0; i < s.size();) {
            std::string buff;
            for (int j = i; j < s.size(); j++) {
                buff.push_back(s[j]);
                if (!dict.count(buff)) {
                    dict.insert(buff);
                    res.push_back(buff);
                    i = j + 1;
                    buff.clear();
                    break;
                }
            }
            if (!buff.empty()) {
                if (!dict.count(buff)) {
                    res.push_back(buff);
                }
                break;
            }
        }

        return res;
    }
};