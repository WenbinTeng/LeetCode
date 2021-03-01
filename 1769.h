#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        std::vector<int> res(boxes.size());
        int lcnt = 0;
        int lsum = 0;
        int rcnt = 0;
        int rsum = 0;

        for (int i = 0; i < boxes.size(); ++i)
        {
            if (boxes[i] == '1')
            {
                rcnt += 1;
                rsum += i;
            }
        }

        res[0] = rsum;
        
        for (int i = 0; i < boxes.size() - 1; ++i)
        {
            if (boxes[i] == '1')
            {
                ++lcnt;
                --rcnt;
            }
            lsum += lcnt;
            rsum -= rcnt;
            res[i + 1] = lsum + rsum;
        }

        return res;
    }
};