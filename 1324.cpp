#include <sstream>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> printVertically(std::string s) {
        std::vector<std::string> res;
        std::vector<std::string> word;
        std::istringstream iss(s);
        std::string buff;

        while (std::getline(iss, buff, ' ')) {
            word.push_back(buff);
        }

        bool isNull = false;
        for (int i = 0; !isNull; i++) {
            std::string s;
            isNull = true;
            for (int j = 0; j < word.size(); j++) {
                if (i >= word[j].size()) {
                    s.push_back(' ');
                } else {
                    s.push_back(word[j][i]);
                    isNull = false;
                }
            }
            if (!isNull) {
                res.push_back(s);
            }
        }

        for (auto &s : res) {
            while (!s.empty() && s.back() == ' ') {
                s.pop_back();
            }
        }

        return res;
    }
};