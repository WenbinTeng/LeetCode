#include <algorithm>
#include <string>

class Solution {
  public:
    std::string decodeString(std::string s) {
        std::string res;

        for (auto c : s) {
            if (c == ']') {
                std::string t;
                while (res.back() != '[') {
                    t.push_back(res.back());
                    res.pop_back();
                }
                res.pop_back();
                std::reverse(t.begin(), t.end());
                std::string n;
                while (!res.empty() && std::isdigit(res.back())) {
                    n.push_back(res.back());
                    res.pop_back();
                }
                std::reverse(n.begin(), n.end());
                int cnt = std::stoi(n);
                for (int i = 0; i < cnt; i++) {
                    res += t;
                }
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};