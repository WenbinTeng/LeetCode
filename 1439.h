#include <vector>
#include <queue>
#include <tuple>

typedef std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<std::tuple<int, int, int>>> queue_t;

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& mat, int k) {
        std::vector<int> a = {0};
        for (auto &row : mat) {
            a = std::move(kSmallestPairs(row, a, k));
        }
        return a.back();
    }

private:
        std::vector<int> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        std::vector<int> ret;
        queue_t pq;
        int m = nums1.size();
        int n = nums2.size();

        pq.emplace(nums1[0] + nums2[0], 0, 0);
        while (!pq.empty() && ret.size() < k) {
            auto [_, i, j] = pq.top();
            pq.pop();
            ret.push_back(nums1[i] + nums2[j]);
            if (j == 0 && i + 1 < m)
                pq.emplace(nums1[i + 1] + nums2[0], i + 1, 0);
            if (j + 1 < n)
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
        }
        
        return ret;
    }
};