#include <string>
#include <unordered_map>

class Solution {
  public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> s2t, t2s;

        for (int i = 0; i < s.size(); i++) {
            if ((s2t.count(s[i]) && s2t[s[i]] != t[i]) ||
                (t2s.count(t[i]) && t2s[t[i]] != s[i])) {
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }

        return true;
    }
};