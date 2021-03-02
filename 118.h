#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res(numRows);

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0) {res[i].push_back(1); continue;}
                if (j == i) {res[i].push_back(1); continue;}

                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }

        return res;
    }
};