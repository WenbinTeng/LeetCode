#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string res;
        std::vector<std::string> rec;
        rec.push_back("/");
        int prev = 1;
        int next = 1;
        while (next < path.size()) {
            while (path[next] != '/' && next < path.size())
                ++next;

            std::string dir = path.substr(prev, next - prev + 1);

            prev = next + 1;
            next = next + 1;

            if (dir == "../" || dir == "..") {
                if (rec.size() > 1)
                    rec.pop_back();
                continue;
            }
            if (dir == "./" || dir == ".")
                continue;
            if (dir == "/" || dir == "")
                continue;

            rec.push_back(dir);
        }

        res = std::accumulate(rec.begin(), rec.end(), std::string(""));

        if (res.size() > 1 && res.back() == '/')
            res.pop_back();

        return res;
    }
};