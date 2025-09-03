#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
  public:
    long long countOfSubstrings(std::string word, int k) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        auto count = [&](int m) -> long long {
            int n = word.size();
            int consonants = 0;
            long long res = 0;
            std::unordered_map<char, int> occur;

            for (int i = 0, j = 0; i < n; i++) {
                while (j < n &&
                       (consonants < m || occur.size() < vowels.size())) {
                    if (vowels.count(word[j])) {
                        occur[word[j]]++;
                    } else {
                        consonants++;
                    }
                    j++;
                }
                if (consonants >= m && occur.size() == vowels.size()) {
                    res += n - j + 1;
                }
                if (vowels.count(word[i])) {
                    occur[word[i]]--;
                    if (occur[word[i]] == 0) {
                        occur.erase(word[i]);
                    }
                } else {
                    consonants--;
                }
            }

            return res;
        };

        return count(k) - count(k + 1);
    }
};