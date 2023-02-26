#include <string>
#include <vector>

class Solution {
public:
    int maxScoreWords(std::vector<std::string> &words, std::vector<char> &letters, std::vector<int> &score) {
        int res = 0;
        std::vector<int> letterCnt(26);

        for (auto c : letters) {
            letterCnt[c - 'a']++;
        }

        for (int s = 1; s < (1 << words.size()); s++) {
            int sum = 0;
            bool legal = true;
            std::vector<int> wordCnt(26);

            for (int k = 0; k < words.size(); k++) {
                if ((s & (1 << k)) == 0) {
                    continue;
                }
                for (auto c : words[k]) {
                    wordCnt[c - 'a']++;
                }
            }

            for (int i = 0; i < 26; i++) {
                sum += score[i] * wordCnt[i];
                legal = legal && (wordCnt[i] <= letterCnt[i]);
            }

            if (legal) {
                res = std::max(res, sum);
            }
        }

        return res;
    }
};