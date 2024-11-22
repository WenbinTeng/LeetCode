#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> pathInZigZagTree(int label) {
        std::vector<int> res;
        int mask = 0x40000000;
        
        while ((label & mask) == 0)
            mask = mask >> 1;

        res.push_back(1);
        mask = mask >> 1;

        for (int i = 1; mask > 0; i++) {
            res.push_back(label & mask ? (res.back() << 1) | 1 : res.back() << 1);
            mask = mask >> 1;
        }

        for (int i = 0; i < res.size(); i++) {
            if (i % 2 == res.size() % 2) {
                // x+y+1-(2^(i-1))=2^i
                res[i] = (3 << i) - 1 - res[i];
            }
        }

        return res;
    }
};