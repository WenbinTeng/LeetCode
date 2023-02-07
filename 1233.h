#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string> &folder) {
        std::vector<std::string> res;

        std::sort(folder.begin(), folder.end());

        res.push_back(folder[0]);
        for (int i = 1; i < folder.size(); ++i) {
            if (!(res.back().size() < folder[i].size() && res.back() == folder[i].substr(0, res.back().size()) && folder[i][res.back().size()] == '/'))
                res.push_back(folder[i]);
        }

        return res;
    }
};