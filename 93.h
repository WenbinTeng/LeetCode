#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        std::vector<std::string> rec;
        dfs(res, rec, s, 0);
        return res;
    }

private:
    void dfs(std::vector<std::string> &res, std::vector<std::string> &rec, std::string &s, int index) {
        if (rec.size() == 4) {
            if (index == s.size()) {
                rec.back().pop_back();
                res.push_back(std::accumulate(rec.begin(), rec.end(), std::string("")));
            }
            return;
        }

        if (index == s.size() || (s.size() - index) > (4 - rec.size()) * 3)
            return;

        if (s[index] == '0') {
            rec.push_back("0.");
            dfs(res, rec, s, index + 1);
            rec.pop_back();
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (std::stoi(s.substr(index, i)) < 256) {
                rec.push_back(s.substr(index, i) + '.');
                dfs(res, rec, s, index + i);
                rec.pop_back();
            } else {
                break;
            }
        }
    }
};