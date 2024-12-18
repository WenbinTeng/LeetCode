#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

class Solution {
  public:
    std::vector<int> minReverseOperations(int n, int p, std::vector<int> &banned, int k) {
        std::vector<int> res(n, -1);
        if (k == 1) {
            res[p] = 0;
            return res;
        }

        std::unordered_set<int> ban;
        for (int x : banned)
            ban.insert(x);

        std::set<int> s[2];
        for (int i = 0; i < n; i++)
            if (i != p && ban.count(i) == 0)
                s[i % 2].insert(i);

        std::queue<int> q;
        q.push(p);
        res[p] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            int left, right;
            left = std::max(-(k - 1), k - 1 - now * 2);
            right = std::min(k - 1, -(k - 1) + (n - now - 1) * 2);

            int x = (now + (k - 1)) % 2;
            auto it = s[x].lower_bound(now + left);
            while (it != s[x].end()) {
                if (*it > now + right)
                    break;
                res[*it] = res[now] + 1;
                q.push(*it);
                it = s[x].erase(it);
            }
        }

        return res;
    }
};