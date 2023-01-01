#include <string>
#include <unordered_map>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return dfs(s, p, 0, 0);
    }

private:
    std::unordered_map<long long, bool> um;

    bool dfs(std::string &s, std::string &p, int si, int pi) {
        long long id = ((long long)si << 32) | pi;

        if (um.find(id) != um.end())
            return um[id];

        if (si == s.size()) {
            if (pi == p.size()) {
                return um[id] = true;
            } else {
                while (pi < p.size() && p[pi] == '*')
                    pi++;
                return um[id] = pi == p.size();
            }
        } else {
            if (pi == p.size())
                return false;

            if (s[si] == p[pi] || p[pi] == '?') {
                return um[id] = dfs(s, p, si + 1, pi + 1);
            } else if (p[pi] == '*') {
                while (pi + 1 < s.size() && p[pi + 1] == '*')
                    pi++;

                return um[id] = dfs(s, p, si + 1, pi) ||
                                dfs(s, p, si, pi + 1);
            } else {
                return um[id] = false;
            }
        }

        return um[id] = false;
    }
};