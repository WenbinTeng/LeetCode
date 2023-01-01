#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> groupStrings(std::vector<std::string> &words) {
        std::unordered_set<int> us;
        std::unordered_map<int, int> um;

        for (const auto &word : words) {
            int bitStr = 0;

            for (const auto &c : word) {
                bitStr |= (1 << (c - 'a'));
            }

            ++um[bitStr];
        }

        int grpCnt = 0;
        int strCnt = 0;

        for (const auto &[k, v] : um) {
            if (us.count(k))
                continue;

            int sum = v;
            std::queue<int> q;
            q.push(k);
            us.insert(k);

            while (!q.empty()) {
                int s = q.front();
                q.pop();
                for (int t : bfs(s)) {
                    if (um.count(t) && !us.count(t)) {
                        q.push(t);
                        us.insert(t);
                        sum += um[t];
                    }
                }
            }
            grpCnt = grpCnt + 1;
            strCnt = std::max(strCnt, sum);
        }

        return {grpCnt, strCnt};
    }

private:
    std::vector<int> bfs(int bitStr) {
        std::vector<int> adj;

        for (int i = 0; i < 26; ++i) {
            adj.push_back(bitStr ^ (1 << i));
        }

        for (int i = 0; i < 26; ++i) {
            if (bitStr & (1 << i)) {
                for (int j = 0; j < 26; ++j) {
                    if (!(bitStr & (1 << j))) {
                        adj.push_back(bitStr ^ (1 << i) ^ (1 << j));
                    }
                }
            }
        }

        return adj;
    }
};