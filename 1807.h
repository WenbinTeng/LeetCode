#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>> &knowledge) {
        std::unordered_map<std::string, int> um;

        for (int i = 0; i < knowledge.size(); ++i)
            um.insert({knowledge[i][0], i});

        for (int i = 0; i < s.size();) {
            int l = s.find_first_of('(', i);
            int r = s.find_first_of(')', i);

            if (l != -1 && r != -1) {
                std::string index = s.substr(l + 1, r - l - 1);
                std::string place = um.find(index) == um.end() ? "?" : knowledge[um[index]][1];
                s.replace(l, r - l + 1, place);
                i = (r + 1) + place.size() - (r - l + 1);
            } else {
                break;
            }
        }

        return s;
    }
};