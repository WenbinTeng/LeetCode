#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> res;
        dfs(res, n);
        return res;
    }

private:
    void dfs(std::vector<int>& res, int n)
    {
        if (n == 1)
        {
            res.push_back(0);
            res.push_back(1);
            return;
        }

        dfs(res, n - 1);

        for (int i = res.size() - 1; i >= 0; --i)
        {
            res.push_back((1 << n - 1) | res[i]);
        }
    }
};