#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(rowIndex + 1, 0);

        res[0] = 1;

        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = i; j > 0; --j)
            {
                res[j] += res[j - 1];
            }
        }

        return res;
    }
};