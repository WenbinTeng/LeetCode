#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
        for (auto& row : A)
        {
            std::reverse(row.begin(), row.end());
            
            for (auto& ele : row)
            {
                ele = !ele;
            }
        }

        return A;
    }
};