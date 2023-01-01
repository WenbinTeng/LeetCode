#include <queue>
#include <vector>

class Solution {
public:
    int getNumberOfBacklogOrders(std::vector<std::vector<int>> &orders) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> buyHeap;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> sellHeap;

        for (const auto &order : orders) {
            if (order[2] == 0) {
                int price = order[0];
                int amount = order[1];
                while (true) {
                    if (sellHeap.empty() || price < sellHeap.top().first) {
                        buyHeap.push({price, amount});
                        break;
                    } else if (sellHeap.top().second > amount) {
                        auto minSell = sellHeap.top();
                        sellHeap.pop();
                        minSell.second -= amount;
                        sellHeap.push(minSell);
                        break;
                    } else {
                        amount -= sellHeap.top().second;
                        sellHeap.pop();
                    }
                }
            } else {
                int price = order[0];
                int amount = order[1];

                while (true) {
                    if (buyHeap.empty() || price > buyHeap.top().first) {
                        sellHeap.push({price, amount});
                        break;
                    } else if (buyHeap.top().second > amount) {
                        auto maxBuy = buyHeap.top();
                        buyHeap.pop();
                        maxBuy.second -= amount;
                        buyHeap.push(maxBuy);
                        break;
                    } else {
                        amount -= buyHeap.top().second;
                        buyHeap.pop();
                    }
                }
            }
        }

        int res = 0;

        while (!buyHeap.empty()) {
            res = (res + buyHeap.top().second) % (int)(1e+9 + 7);
            buyHeap.pop();
        }
        while (!sellHeap.empty()) {
            res = (res + sellHeap.top().second) % (int)(1e+9 + 7);
            sellHeap.pop();
        }

        return res;
    }
};