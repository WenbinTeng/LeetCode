#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minSetSize(std::vector<int> &arr) {
        int res = 0;
        int len = 0;
        std::unordered_map<int, int> cnt;
        std::priority_queue<int, std::vector<int>, std::less<int>> pq;

        for (auto num : arr) {
            cnt[num]++;
        }

        for (auto &[_, c] : cnt) {
            pq.push(c);
        }

        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();
            len += c;
            res++;
            if (len >= (arr.size() + 1) / 2) {
                break;
            }
        }

        return res;
    }
};