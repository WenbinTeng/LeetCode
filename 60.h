#include <vector>
#include <string>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::string res;
        std::vector<bool> used(n + 1, false);
        std::vector<int> factorial(n + 1, 1);

        for (int i = 1; i <= n; ++i)
        {
            factorial[i] = factorial[i - 1] * i;
        }

        dfs(res, used, factorial, 0, n, k);

        return res;
    }

private:
    void dfs(std::string& res, std::vector<bool>& used, std::vector<int>& factorial, int index, int n, int k)
    {
        if (index == n) return;

        for (int i = 1; i <= n; ++i)
        {
            if (used[i]) continue;

            if (k > factorial[n - 1 - index])
            {
                k -= factorial[n - 1 - index]; continue;
            }

            res.push_back(i + '0');
            used[i] = true;
            dfs(res, used, factorial, index + 1, n, k);

            return;
        }
    }
};