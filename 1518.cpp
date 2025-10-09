class Solution {
  public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;

        while (numBottles >= numExchange) {
            int exchange = numBottles / numExchange;
            numBottles = numBottles % numExchange;
            res += exchange;
            numBottles += exchange;
        }

        return res;
    }
};