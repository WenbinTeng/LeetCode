#include <string>

class Solution {
public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        auto convert = [](std::string& s){
            for (auto& c : s)
            {
                c = c - 'a' + '0';
            }

            return std::stoll(s);
        };

        return convert(firstWord) + convert(secondWord) == convert(targetWord);
    }
};