#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> solveQueries(std::vector<int> &nums,
                                  std::vector<int> &queries) {
        int n = nums.size();
        std::vector<int> res(queries.size());
        std::unordered_map<int, std::vector<int>> samePos;

        for (int i = 0; i < nums.size(); i++) {
            samePos[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++) {
            int pos = queries[i];
            int val = nums[pos];
            if (samePos[val].size() == 1) {
                res[i] = -1;
                continue;
            } else {
                auto &vec = samePos[val];
                int vecSize = vec.size();
                int posIndex =
                    std::lower_bound(vec.begin(), vec.end(), pos) - vec.begin();
                int prevPosIndex = (posIndex - 1 + vecSize) % vecSize;
                int nextPosIndex = (posIndex + 1) % vecSize;
                res[i] = std::min((pos + n - vec[prevPosIndex]) % n,
                                  (vec[nextPosIndex] + n - pos) % n);
            }
        }

        return res;
    }
};