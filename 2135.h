#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int wordCount(std::vector<std::string>& startWords, std::vector<std::string>& targetWords) {
        int res = 0;

        std::unordered_set<int> alphabet;

        auto wordHash = [](const std::string& word)
        {
            int num = 0;

            for (const auto c : word)
            {
                num = num ^ (1 << (c - 'a'));
            }

            return num;
        };

        for (const auto& word : startWords)
        {
            alphabet.insert(wordHash(word));
        }

        for (const auto& word : targetWords)
        {
            for (const auto c : word)
            {
                if (alphabet.count(wordHash(word) ^ (1 << (c - 'a'))))
                {
                    ++res;
                    break;
                }
            }
        }

        return res;
    }
};