#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> removeAnagrams(std::vector<std::string>& words) {
        for (int i = 0; i < words.size() - 1; )
        {
            if (words[i].size() == words[i + 1].size())
            {
                std::unordered_map<char, int> um;

                for (int j = 0; j < words[i].size(); ++j)
                {
                    ++um[words[i][j]];
                    --um[words[i + 1][j]];
                }

                bool same = true;

                for (const auto [_, cnt] : um)
                {
                    if (cnt != 0)
                    {
                        same = false;
                        break;
                    }
                }

                if (same)
                {
                    words.erase(words.begin() + i + 1);
                }
                else
                {
                    ++i;
                }
            }
            else
            {
                ++i;
            }
        }

        return words;
    }
};