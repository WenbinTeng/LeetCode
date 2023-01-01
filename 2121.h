#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<long long> getDistances(std::vector<int> &arr) {
        std::vector<long long> res(arr.size());
        std::unordered_map<int, std::vector<int>> indexMap;

        for (int i = 0; i < arr.size(); ++i) {
            indexMap[arr[i]].push_back(i);
        }

        for (const auto &[key, indexes] : indexMap) {
            for (int i = 1; i < indexes.size(); ++i) {
                res[indexes[0]] += indexes[i] - indexes[0];
            }
            for (int i = 1; i < indexes.size(); ++i) {
                long long diff = indexes[i] - indexes[i - 1];
                long long prev = i - 1;
                long long next = indexes.size() - 1 - i;
                res[indexes[i]] = res[indexes[i - 1]] + prev * diff - next * diff;
            }
        }

        return res;
    }
};