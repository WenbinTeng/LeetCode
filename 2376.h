#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int countSpecialNumbers(int n) {
        int res = 0;
        bool repeated = false;
        std::string num = std::to_string(n);
        std::vector<int> cnt(11);
        std::unordered_set<char> visited;

        cnt[0] = 0;
        cnt[1] = 9;
        cnt[2] = 9 * 9;
        cnt[3] = 9 * 9 * 8;
        cnt[4] = 9 * 9 * 8 * 7;
        cnt[5] = 9 * 9 * 8 * 7 * 6;
        cnt[6] = 9 * 9 * 8 * 7 * 6 * 5;
        cnt[7] = 9 * 9 * 8 * 7 * 6 * 5 * 4;
        cnt[8] = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3;
        cnt[9] = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;
        cnt[10] = 9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

        for (int i = 1; i < num.size(); ++i)
        {
            res += cnt[i];
        }
        res += (num[0] - 1 - '0') * perm(num.size() - 1, 9);
        visited.insert(num[0]);

        for (int i = 1; i < num.size(); ++i)
        {
            int avail = 0;

            for (char j = '0'; j < num[i]; ++j)
            {
                if (!visited.count(j))
                {
                    ++avail;
                }
            }

            res += avail * perm(num.size() - 1 - i, 10 - i - 1);

            if (visited.count(num[i]))
            {
                repeated = true;
                break;
            }

            visited.insert(num[i]);
        }

        return repeated ? res : res + 1;

    }

private:
    int perm(int d, int n)
    {
        int ret = 1;

        for (int i = n; d > 0; --i, --d)
        {
            ret *= i;
        }

        return ret;
    }
};