#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings) {
        int res = 0;
        std::unordered_map<int, std::set<int>> xDict;
        std::unordered_map<int, std::set<int>> yDict;

        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            xDict[x].insert(y);
            yDict[y].insert(x);
        }

        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            auto& xSet = xDict[x];
            auto& ySet = yDict[y];
            if (xSet.lower_bound(y)     != xSet.begin() &&
                xSet.lower_bound(y + 1) != xSet.end()   &&
                ySet.lower_bound(x)     != ySet.begin() &&
                ySet.lower_bound(x + 1) != ySet.end()) {
                    res++;
                }
        }
        
        return res;
    }
};