#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> findSubstring(std::string s,
                                   std::vector<std::string> &words) {
        if (s.empty() || words.empty())
            return {};

        bool finded = true;
        int wordNum = words.size();
        int wordLen = words[0].size();
        std::unordered_map<std::string, int> hashTable;
        std::unordered_map<std::string, int> hashCount;
        std::vector<int> res;

        for (auto &iter : words) {
            hashTable[iter] = hashTable.find(iter) == hashTable.end()
                                  ? 1
                                  : hashTable[iter] + 1;
        }

        for (int i = 0; i <= (int)s.size() - wordNum * wordLen; i++) {
            hashCount = hashTable;
            for (int j = 0; j < wordNum; j++) {
                if (hashCount.find(s.substr(i + j * wordLen, wordLen)) ==
                        hashTable.end() ||
                    --hashCount[s.substr(i + j * wordLen, wordLen)] < 0) {
                    finded = false;
                    break;
                }
            }
            if (finded)
                res.push_back(i);
            else
                finded = true;
        }

        return res;
    }
};