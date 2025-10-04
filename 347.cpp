#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::vector<int> res;
        std::unordered_map<int, int> freq;
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        for (auto num : nums) {
            freq[num]++;
        }

        for (auto &[num, cnt] : freq) {
            if (pq.size() == k) {
                if (pq.top().first < cnt) {
                    pq.pop();
                    pq.push({cnt, num});
                }
            } else {
                pq.push({cnt, num});
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};