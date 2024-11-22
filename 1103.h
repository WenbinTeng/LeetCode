#include <vector>

class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> res(num_people, 0);
        int iterSum = (1 + num_people) * num_people / 2;
        int iterNum = 0;

        while (candies > 0) {
            int t1 = iterSum + iterNum * num_people * num_people;
            if (candies < t1) {
                for (int i = 0; i < num_people; i++) {
                    int t2 = (i + 1) + num_people * iterNum;
                    if (candies >= t2) {
                        res[i] += (i + 1) * (iterNum + 1) + num_people * (1 + iterNum) * iterNum / 2;
                        candies -= t2;
                    } else if (candies > 0) {
                        res[i] += (i + 1) * iterNum + num_people * iterNum * (iterNum - 1) / 2 + candies;
                        candies = 0;
                    } else {
                        res[i] += (i + 1) * iterNum + num_people * iterNum * (iterNum - 1) / 2;
                    }
                }
            }
            candies -= t1;
            iterNum++;
        }

        return res;
    }
};