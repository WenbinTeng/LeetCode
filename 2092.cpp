#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<int> findAllPeople(int n,
                                   std::vector<std::vector<int>> &meetings,
                                   int firstPerson) {
        std::vector<int> res;
        std::unordered_set<int> known;

        known.insert(0);
        known.insert(firstPerson);

        auto cmp = [](std::vector<int> &a, std::vector<int> &b) {
            if (a[2] == b[2]) {
                if (a[1] == b[1]) {
                    return a[0] < b[0];
                } else {
                    return a[1] < b[1];
                }
            } else {
                return a[2] < b[2];
            }
        };

        std::sort(meetings.begin(), meetings.end(), cmp);

        int t = meetings[0][2];
        int i = 0;

        while (i < meetings.size()) {
            std::unordered_set<int> member;

            while (i < meetings.size() && t == meetings[i][2] &&
                   (member.empty() || member.count(meetings[i][0]) ||
                    member.count(meetings[i][1]))) {
                member.insert(meetings[i][0]);
                member.insert(meetings[i][1]);
                ++i;
            }
            if (i < meetings.size()) {
                t = meetings[i][2];
            }

            for (const auto m : member) {
                if (known.count(m)) {
                    known.insert(member.begin(), member.end());
                    break;
                }
            }
        }

        for (const auto p : known) {
            res.push_back(p);
        }

        return res;
    }
};