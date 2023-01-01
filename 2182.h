#include <string>
#include <vector>

class Solution {
public:
    std::string repeatLimitedString(std::string s, int repeatLimit) {
        std::string res;
        std::vector<int> alphabet(26);

        for (const auto c : s) {
            ++alphabet[c - 'a'];
        }

        for (int i = 25; i >= 0; --i) {
            while (alphabet[i]) {
                if (alphabet[i] > repeatLimit) {
                    int lowerLetter = getLowerLetter(alphabet, i);

                    alphabet[i] -= repeatLimit;

                    for (int j = 0; j < repeatLimit; ++j) {
                        res.push_back(i + 'a');
                    }

                    if (lowerLetter == -1)
                        return res;

                    --alphabet[lowerLetter];

                    res.push_back(lowerLetter + 'a');
                } else {
                    --alphabet[i];

                    res.push_back(i + 'a');
                }
            }
        }

        return res;
    }

private:
    int getLowerLetter(std::vector<int> &alphabet, int index) {
        for (int i = index - 1; i >= 0; --i) {
            if (alphabet[i] > 0)
                return i;
        }

        return -1;
    }
};