#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        auto pos = word.find_first_of(ch);

        if (pos != word.size())
        {
            std::reverse(word.begin(), word.begin() + pos + 1);
        }
        
        return word;
    }
};