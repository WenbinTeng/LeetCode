#include <string>
#include <unordered_set>

class Solution {
public:
    int countOfSubstrings(std::string word, int k) {
        int res = 0;
        const std::unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < word.size(); i++) {
            int consonants = 0;
            std::unordered_set<int> s;
            for (int j = i; j < word.size(); j++) {
                if (vowels.count(word[j])) {
                    s.insert(word[j]);
                } else {
                    consonants++;
                }
                if (vowels.size() == s.size() && consonants == k)
                    res++;
            }
        }

        return res;
    }
};