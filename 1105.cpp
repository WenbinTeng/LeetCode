#include <vector>

class Solution {
  public:
    int minHeightShelves(std::vector<std::vector<int>> &books, int shelfWidth) {
        std::vector<int> dp(books.size() + 1, 1000000);
        dp[0] = 0;

        for (int i = 0; i < books.size(); i++) {
            int maxH = 0;
            int w = 0;
            for (int j = i; j >= 0; j--) {
                w += books[j][0];
                if (w > shelfWidth)
                    break;
                maxH = std::max(maxH, books[j][1]);
                dp[i + 1] = std::min(dp[i + 1], dp[j] + maxH);
            }
        }

        return dp[books.size()];
    }
};