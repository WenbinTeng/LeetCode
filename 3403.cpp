#include <string>

class Solution {
  public:
    std::string answerString(std::string word, int numFriends) {
        if (numFriends == 1)
            return word;
        int len = word.size() - numFriends + 1;
        std::string res = word.substr(0, len);
        for (int i = 1; i < word.size(); i++) {
            res = std::move(compareLargerString(
                res, word.substr(i, std::min((size_t)len, word.size() - i))));
        }
        return res;
    }

  private:
    std::string compareLargerString(std::string &a, std::string b) {
        int n = std::min(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i])
                return a;
            else if (a[i] < b[i])
                return b;
        }
        return a.size() > b.size() ? a : b;
    }
};