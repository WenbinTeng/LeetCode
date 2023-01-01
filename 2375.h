#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        std::string res = "0";
        std::stack<char> s;

        pattern.push_back('I');
        for (int i = 0; i < pattern.size(); ++i) {
            if (pattern[i] == 'I') {
                auto back = *std::max_element(res.begin(), res.end());
                while (!s.empty()) {
                    res.push_back(back + s.size() + 1);
                    s.pop();
                }
                res.push_back(back + 1);
            } else {
                s.push('D');
            }
        }

        res.erase(res.begin());

        return res;
    }
};