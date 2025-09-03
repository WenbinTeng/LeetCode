#include <string>

class Solution {
  public:
    int countVowelSubstrings(std::string word) {
        int res = 0;

        for (int k = 0; k < word.size(); ++k) {
            bool a = false;
            bool e = false;
            bool i = false;
            bool o = false;
            bool u = false;

            for (int j = k; j < word.size(); ++j) {
                switch (word[j]) {
                case 'a':
                    a = true;
                    break;
                case 'e':
                    e = true;
                    break;
                case 'i':
                    i = true;
                    break;
                case 'o':
                    o = true;
                    break;
                case 'u':
                    u = true;
                    break;
                default:
                    a = e = i = o = u = false;
                    break;
                }

                if (a & e & i & o & u)
                    ++res;

                if (!(a | e | i | o | u))
                    break;
            }
        }

        return res;
    }
};