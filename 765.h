#include <vector>

class Solution {
public:
    int minSwapsCouples(std::vector<int> &row) {
        int res = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i];
            int b = a ^ 1;

            if (row[i + 1] == b)
                continue;

            for (int j = i + 2; j < row.size(); j++) {
                if (row[j] == b) {
                    std::swap(row[j], row[i + 1]);
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};