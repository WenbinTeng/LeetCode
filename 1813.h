#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        auto s1 = splitSentence(sentence1);
        auto s2 = splitSentence(sentence2);
        int l = 0;
        int r = 0;

        while (l < s1.size() && l < s2.size() && s1[l] == s2[l])
            ++l;

        while (r < s1.size() - l && r < s2.size() - l && s1[s1.size() - r - 1] == s2[s2.size() - r - 1])
            ++r;

        return l + r == std::min(s1.size(), s2.size());
    }

private:
    std::vector<std::string> splitSentence(std::string sentence) {
        std::vector<std::string> ret;
        std::istringstream ss(sentence);
        std::string temp;

        while (ss.good()) {
            ss >> temp;
            ret.push_back(temp);
        }

        return ret;
    }
};