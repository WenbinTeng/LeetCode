#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::string> uncommonFromSentences(std::string s1,
                                                   std::string s2) {
        std::unordered_map<std::string, int> um;

        std::stringstream ss1(s1);
        std::string t1;
        while (ss1 >> t1) {
            um[t1]++;
        }

        std::stringstream ss2(s2);
        std::string t2;
        while (ss2 >> t2) {
            um[t2]++;
        }

        std::vector<std::string> res;
        for (const auto &[str, cnt] : um) {
            if (cnt == 1) {
                res.push_back(str);
            }
        }

        return res;
    }
};