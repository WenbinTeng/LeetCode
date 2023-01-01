#include <queue>
#include <vector>

class Solution {
public:
    int minimumOperations(std::vector<int> &nums, int start, int goal) {
        std::vector<bool> vis(1001, false);
        std::queue<int> q;
        q.push(start);
        int res = 0;

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front();
                q.pop();

                if (curr == goal)
                    return res;

                for (const auto &num : nums) {
                    auto a = curr + num;
                    auto b = curr - num;
                    auto c = curr ^ num;

                    if (a == goal || b == goal || c == goal)
                        return res + 1;

                    if (a >= 0 && a <= 1000 && !vis[a]) {
                        vis[a] = true;
                        q.push(a);
                    }
                    if (b >= 0 && b <= 1000 && !vis[b]) {
                        vis[b] = true;
                        q.push(b);
                    }
                    if (c >= 0 && c <= 1000 && !vis[c]) {
                        vis[c] = true;
                        q.push(c);
                    }
                }
            }

            ++res;
        }

        return -1;
    }
};