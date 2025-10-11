#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
  public:
    int maxFreqSum(std::string s) {
        int maxVowel = 0;
        int maxCons = 0;
        std::unordered_map<char, int> dict;
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (auto c : s) {
            dict[c]++;
        }

        for (auto [ch, cnt] : dict) {
            if (vowels.count(ch)) {
                maxVowel = std::max(maxVowel, cnt);
            } else {
                maxCons = std::max(maxCons, cnt);
            }
        }

        return maxVowel + maxCons;
    }
};