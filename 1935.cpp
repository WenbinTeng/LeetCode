#include <sstream>
#include <string>
#include <unordered_set>

class Solution {
  public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        int res = 0;
        std::unordered_set<char> dict;
        std::istringstream iss(text);
        std::string token;

        for (auto c : brokenLetters) {
            dict.insert(c);
        }

        while (std::getline(iss, token, ' ')) {
            bool valid = true;
            for (auto c : token) {
                if (dict.count(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res++;
            }
        }

        return res;
    }
};