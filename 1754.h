#include <string>

class Solution {
public:
    std::string largestMerge(std::string word1, std::string word2) {
        std::string merge = "";
        int index1 = 0;
        int index2 = 0;

        while (!word1.empty() && !word2.empty())
        {
            index1 = 0;
            index2 = 0;

            while (word1[index1] == word2[index2])
            {
                ++index1;
                ++index2;
                if (index1 == word1.size()) break;
                if (index2 == word2.size()) break;
            }
            
            if (index1 == word1.size() || word1[index1] < word2[index2])
            {
                merge.push_back(word2.front());
                word2.erase(0, 1);
                continue;
            }
            if (index2 == word2.size() || word1[index1] > word2[index2])
            {
                merge.push_back(word1.front());
                word1.erase(0, 1);
                continue;
            }
        }

        return merge + word1 + word2;
    }
};