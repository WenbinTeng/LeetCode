#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int distributeCookies(std::vector<int>& cookies, int k) {
        std::vector<int> alloc(k);

        std::sort(cookies.begin(), cookies.end());

        alloc[0] = cookies.back();
        cookies.pop_back();

        dfs(cookies, alloc, 0, alloc[0]);

        return res;
    }

private:
    int res = 0x3f3f3f3f;

    void dfs(std::vector<int>& cookies, std::vector<int>& alloc, int index, int value)
    {
        if (index == cookies.size())
        {
            res = std::min(res, value);
            return;
        }

        for (int i = 0; i < alloc.size(); ++i)
        {
            alloc[i] += cookies[index];
            dfs(cookies, alloc, index + 1, std::max(value, alloc[i]));
            alloc[i] -= cookies[index];
        }
    }
};