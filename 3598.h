#include <vector>
#include <string>
#include <queue>

class Solution {
public:
    std::vector<int> longestCommonPrefix(std::vector<std::string>& words) {
        if (words.size() == 1)
            return { 0 };

        auto getCommonPrefix = [](std::string& a, std::string& b) -> int {
            int size = std::min(a.size(), b.size());
            for (int i = 0; i < size; i++) {
                if (a[i] != b[i])
                    return i;
            }
            return size;
        };

        const int n = words.size();
        std::vector<int> res(n, 0);

        std::vector<int> neibour1(n, 0);
        std::vector<int> neibour2(n, 0);
        for (int i = 0; i < n - 1; i++) {
            neibour1[i] = getCommonPrefix(words[i], words[i + 1]);
        }
        for (int i = 0; i < n - 2; i++) {
            neibour2[i] = getCommonPrefix(words[i], words[i + 2]);
        }

        std::priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({neibour1[i], i});
        }

        for (int i = 0; i < n; i++) {
            auto [maxLen, index] = pq.top();
            if (i == index) {
                pq.pop();
                res[i] = pq.top().first;
                if (i > 0)
                    res[i] = std::max(res[i], neibour2[i - 1]);
                pq.push({maxLen, index});
            } else if (i == index + 1) {
                pq.pop();
                if (i == pq.top().second) {
                    pq.pop();
                    if (!pq.empty())
                        res[i] = pq.top().first;
                    pq.push({neibour1[i], i});
                } else {
                    res[i] = pq.top().first;
                }
                res[i] = std::max(res[i], neibour2[i - 1]);
                pq.push({maxLen, index});
            } else {
                res[i] = maxLen;
                if (i > 0)
                    res[i] = std::max(res[i], neibour2[i - 1]);
            }
        }

        return res;
    }
};