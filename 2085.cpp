#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int countWords(std::vector<std::string> &words1,
                   std::vector<std::string> &words2) {
        int res = 0;
        std::unordered_map<std::string, int> dict1;
        std::unordered_map<std::string, int> dict2;

        for (auto &word : words1) {
            dict1[word]++;
        }
        for (auto &word : words2) {
            dict2[word]++;
        }

        for (auto &[word, cnt] : dict1) {
            if (cnt == 1 && dict2[word] == 1)
                res++;
        }

        return res;
    }
};