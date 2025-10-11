#include <vector>
#include <algorithm>

class Solution {
  public:
    int numRescueBoats(std::vector<int> &people, int limit) {
        const int n = people.size();
        int res = 0;
        int left = 0;
        int right = n - 1;

        std::sort(people.begin(), people.end());

        while (left < right) {
            if (people[left] + people[right] > limit) {
                right--;
                res++;
            } else {
                left++;
                right--;
                res++;
            }
        }

        if (left == right) {
            res++;
        }

        return res;
    }
};