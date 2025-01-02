#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> cnt;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (auto num : arr) {
            cnt[num]++;
        }

        for (auto &[_, c] : cnt) {
            pq.push(c);
        }

        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();
            if (k < c) {
                c -= k;
                pq.push(c);
                break;
            }
            k -= c;
        }

        return pq.size();
    }
};