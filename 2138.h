#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> res;

        for (int i = k; i <= s.size(); i += k) {
            res.push_back(s.substr(i - k, k));
        }

        if (s.size() % k != 0) {
            res.push_back(s.substr(s.size() - (s.size() % k)));

            for (int i = 0; i < k - (s.size() % k); ++i) {
                res.back().push_back(fill);
            }
        }

        return res;
    }
};