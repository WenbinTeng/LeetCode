#include <string>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int minDeletion(std::string s, int k) {
        int res = 0;
        std::unordered_map<char, int> dict;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (auto c : s) {
            dict[c]++;
        }

        for (auto& [_, cnt] : dict) {
            pq.push(cnt);
        }

        while (pq.size() > k) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};