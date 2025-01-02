#include <vector>
#include <algorithm>

class Solution {
public:
    long long minimumTotalCost(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        long long res = 0;
        int swapCnt = 0;
        std::vector<int> cnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                res += i;
                swapCnt++;
                cnt[nums1[i]]++;
            }
        }

        int mode = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
        int modeCnt = cnt[mode];

        for (int i = 0; i < n && modeCnt * 2 > swapCnt; i++) {
            int x = nums1[i];
            int y = nums2[i];
            if (x != y && x != mode && y != mode) {
                res += i;
                swapCnt++;
            }
        }

        return modeCnt * 2 > swapCnt ? -1 : res;
    }
};