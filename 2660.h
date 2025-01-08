#include <vector>

class Solution {
public:
    int isWinner(std::vector<int>& player1, std::vector<int>& player2) {
        int score1 = 0;
        int score2 = 0;

        auto cnt = [&](std::vector<int> &player) -> int {
            int score = 0;
            for (int i = 0; i < player.size(); i++) {
                if (i >= 2 && player[i - 2] == 10)
                    score += 2 * player[i];
                else if (i >= 1 && player[i - 1] == 10)
                    score += 2 * player[i];
                else
                    score += player[i];
            }
            return score;
        };

        score1 = cnt(player1);
        score2 = cnt(player2);

        return score1 == score2 ? 0 : (score1 > score2 ? 1 : 2);
    }
};