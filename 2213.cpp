#include <map>
#include <set>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<int> longestRepeating(std::string s,
                                      std::string queryCharacters,
                                      std::vector<int> &queryIndices) {
        std::vector<int> res;
        std::multiset<int> len;
        std::map<int, int> sec;

        s = " " + s + " ";

        for (int i = 0, j = 0; i < s.size(); i = j) {
            for (j = i; j < s.size(); ++j) {
                if (s[i] != s[j])
                    break;
            }
            len.insert(j - i);
            sec[i] = j - 1;
        }

        for (int i = 0; i < queryCharacters.size(); ++i) {
            auto qc = queryCharacters[i];
            auto qi = queryIndices[i] + 1;
            auto it = --sec.upper_bound(qi);

            if (qc != s[it->first]) {
                int l = it->first;
                int r = it->second;

                len.erase(len.find(r - l + 1));
                sec.erase(it);

                if (qi != l) {
                    len.insert(qi - l);
                    sec[l] = qi - 1;
                }
                if (qi != r) {
                    len.insert(r - qi);
                    sec[qi + 1] = r;
                }

                len.insert(1);
                auto [pos, _] = sec.insert({qi, qi});
                it = pos;
            }

            auto prevIt = std::prev(it);
            if (s[prevIt->first] == qc) {
                len.erase(len.find(prevIt->second - prevIt->first + 1));
                len.erase(len.find(it->second - it->first + 1));
                prevIt->second = it->second;
                len.insert(prevIt->second - prevIt->first + 1);
                sec.erase(it);
                it = prevIt;
            }

            auto nextIt = std::next(it);
            if (s[nextIt->first] == qc) {
                len.erase(len.find(nextIt->second - nextIt->first + 1));
                len.erase(len.find(it->second - it->first + 1));
                it->second = nextIt->second;
                len.insert(it->second - it->first + 1);
                sec.erase(nextIt);
                it = nextIt;
            }

            s[qi] = qc;
            res.push_back(*len.rbegin());
        }

        return res;
    }
};