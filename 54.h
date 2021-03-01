#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        int m = matrix   .size();
        int n = matrix[0].size();
        int limit_u = -1;
        int limit_d =  m;
        int limit_l = -1;
        int limit_r =  n;
        int row = 0;
        int col = 0;

        enum class State {L2R, U2D, R2L, D2U};
        State state = State::L2R;

        while (true)
        {
            switch (state)
            {
            case State::L2R:
                while (col < limit_r)
                {
                    res.push_back(matrix[row][col++]);
                }
                --col;
                ++row;
                ++limit_u;
                state = State::U2D;
                break;

            case State::U2D:
                while (row < limit_d)
                {
                    res.push_back(matrix[row++][col]);
                }
                --col;
                --row;
                --limit_r;
                state = State::R2L;
                break;

            case State::R2L:
                while (col > limit_l)
                {
                    res.push_back(matrix[row][col--]);
                }
                ++col;
                --row;
                --limit_d;
                state = State::D2U;
                break;

            case State::D2U:
                while (row > limit_u)
                {
                    res.push_back(matrix[row--][col]);
                }
                ++col;
                ++row;
                ++limit_l;
                state = State::L2R;
                break;

            default:;
            }

            if (limit_l + 1 == limit_r || limit_u + 1 == limit_d) break;
        }

        return res;
    }
};