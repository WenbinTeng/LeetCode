#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix.size() == 1) return;

        int n = matrix.size() - 1;

        for (int i = 0; i < (n + 1) / 2; i++)
        {
            std::vector<std::pair<int, int>> pos(4);
            pos[0] = std::make_pair(0 + i, 0 + i);
            pos[1] = std::make_pair(0 + i, n - i);
            pos[2] = std::make_pair(n - i, n - i);
            pos[3] = std::make_pair(n - i, 0 + i);

            for (int j = 0; j < n - 2 * i; j++)
            {
                int temp = matrix[pos[3].first][pos[3].second];
                matrix[pos[3].first][pos[3].second] = matrix[pos[2].first][pos[2].second];
                matrix[pos[2].first][pos[2].second] = matrix[pos[1].first][pos[1].second];
                matrix[pos[1].first][pos[1].second] = matrix[pos[0].first][pos[0].second];
                matrix[pos[0].first][pos[0].second] = temp;

                pos[0].second++;
                pos[1].first++;
                pos[2].second--;
                pos[3].first--;
            }
        }

        return;
    }
};