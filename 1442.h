#include <vector>

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int res = 0;
        std::vector<int> pre(arr.size() + 1);

        for (int i = 0; i < arr.size(); ++i)
        {
            pre[i + 1] = pre[i] ^ arr[i];
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = i + 1; j < arr.size(); ++j)
            {
                for (int k = j; k < arr.size(); ++k)
                {
                    if (pre[i] == pre[k + 1]) ++res;
                }
            }
        }

        return res;
    }
};