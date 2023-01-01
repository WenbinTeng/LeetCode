#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries) {
        std::vector<int> res;
        std::vector<int> pre(arr.size() + 1, 0);

        for (int i = 0; i < arr.size(); i++) {
            pre[i + 1] = pre[i] ^ arr[i];
        }

        for (const auto &query : queries) {
            res.push_back(pre[query[0]] ^ pre[query[1] + 1]);
        }

        return res;
    }
};