#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int difference) {
        int res = 0;
        std::unordered_map<int, std::set<int>> posRec;
        std::unordered_map<int, int> lenRec; 

        for (int i = 0; i < arr.size (); i++) {
            posRec[arr[i]].insert(i);
        }

        for (int i = 0; i < arr.size(); i++) {
            int cnt = 1;
            int p = i;
            std::vector<int> path(1, i);
            while (1) {
                int v = arr[p] + difference;
                if (posRec.count(v) == 0)
                    break;
                if (lenRec.count(p)) {
                    cnt += lenRec[p];
                    break;
                }
                auto& s = posRec[v];
                auto it = s.upper_bound(p);
                if (it != s.end()) {
                    p = *it;
                    path.push_back(p);
                    cnt++;
                } else
                    break;
            }
            for (int i = 0; i < path.size(); i++) {
                lenRec[path[i]] = cnt - i - 1;
            }
            res = std::max(res, cnt);
        }

        return res;
    }
};