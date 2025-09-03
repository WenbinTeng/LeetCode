#include <string>

class Solution {
  public:
    std::string truncateSentence(std::string s, int k) {
        int index = 0;

        for (int i = 0; i < k; ++i) {
            index = s.find_first_of(' ', index + 1);
        }

        if (index == -1)
            return s;

        s.erase(index);

        return s;
    }
};