#include <map>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<long long> findMaxSum(std::vector<int> &nums1,
                                      std::vector<int> &nums2, int k) {
        int n = nums1.size();
        std::vector<long long> res(n);
        std::map<int, std::vector<int>> dict;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        long long kSum = 0;

        for (int i = 0; i < n; i++) {
            dict[nums1[i]].push_back(i);
        }

        while (!dict.empty()) {
            auto &[val, vec] = *dict.begin();
            for (auto index : vec) {
                res[index] = kSum;
            }
            for (auto index : vec) {
                pq.push(nums2[index]);
                kSum += nums2[index];
                if (pq.size() > k) {
                    kSum -= pq.top();
                    pq.pop();
                }
            }
            dict.erase(dict.begin());
        }

        return res;
    }
};