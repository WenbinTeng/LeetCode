#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    int unhappyFriends(int n, std::vector<std::vector<int>>& preferences, std::vector<std::vector<int>>& pairs) {
        std::set<int> s;
        std::vector<std::unordered_map<int, int>> preferencesTable(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                preferencesTable[i][preferences[i][j]] = n - 1 - j;
            }
        }

        auto unhappy = [&](int x, int y, int u, int v) {
            if ((preferencesTable[x][u] > preferencesTable[x][y]) && (preferencesTable[u][x] > preferencesTable[u][v]))
                return true;
            return false;
        };

        for (int i = 0; i < n / 2; i++) {
            for (int j = i + 1; j < n / 2; j++) {
                int x = pairs[i][0];
                int y = pairs[i][1];
                int u = pairs[j][0];
                int v = pairs[j][1];

                if (unhappy(x, y, u, v) || unhappy(x, y, v, u))
                    s.insert(x);
                if (unhappy(y, x, u, v) || unhappy(y, x, v, u))
                    s.insert(y);
                if (unhappy(u, v, x, y) || unhappy(u, v, y, x))
                    s.insert(u);
                if (unhappy(v, u, x, y) || unhappy(v, u, y, x))
                    s.insert(v);
            }
        }

        return s.size();
    }
};