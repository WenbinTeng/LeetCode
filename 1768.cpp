#include <string>

class Solution {
  public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string res;
        int i;
        for (i = 0; i < word1.size() && i < word2.size(); ++i) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }
        res += word1.substr(i) + word2.substr(i);

        return res;
    }
};