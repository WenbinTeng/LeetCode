#include <sstream>
#include <string>

class Solution {
  public:
    std::string reverseWords(std::string s) {
        std::string res;
        std::string word;
        std::istringstream iss(s);

        while (std::getline(iss, word, ' ')) {
            if (!word.empty()) {
                res = word + " " + res;
            }
        }

        res.pop_back();
        return res;
    }
};