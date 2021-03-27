#include <vector>
#include <algorithm>

class Solution {
public:
	int countPairs(std::vector<int>& nums, unsigned short low, unsigned short high) {
        int* a = nums.data();
        int  n = nums.size();
        int  d = 0;
        int  res = 0;
        
        std::sort(a, a + n);

        for (int *i = a, *end = i + n; i != end; ++i)
        {
            if (i > a && *i == *(i - 1)) {res += d; continue;}

            int *j = i + 1;
            for (d = 0; j < end - 8; j += 8)
            {
                unsigned short x  = *i ^ *(j + 0),
                               x1 = *i ^ *(j + 1),
                               x2 = *i ^ *(j + 2),
                               x3 = *i ^ *(j + 3),
                               x4 = *i ^ *(j + 4),
                               x5 = *i ^ *(j + 5),
                               x6 = *i ^ *(j + 6),
                               x7 = *i ^ *(j + 7);
                
                d += (x  >= low && x  <= high) 
                   + (x1 >= low && x1 <= high) 
                   + (x2 >= low && x2 <= high)
                   + (x3 >= low && x3 <= high)
                   + (x4 >= low && x4 <= high)
                   + (x5 >= low && x5 <= high)
                   + (x6 >= low && x6 <= high) 
                   + (x7 >= low && x7 <= high);
            }

            for (; j < end; ++j) d += (*i ^ *j) >= low && (*i ^ *j) <= high;

            res += d;
        }
        return res;
    }
};