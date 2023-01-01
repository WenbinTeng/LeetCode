#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res = {1};

        for (int i = 1; i <= rowIndex; i++) {
            std::vector<int> tmp = {1};

            for (int j = 1; j < res.size(); j++) {
                tmp.push_back(res[j - 1] + res[j]);
            }
            tmp.push_back(1);

            res = tmp;
        }

        return res;
    }
};