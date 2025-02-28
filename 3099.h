class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        auto sumDigit = [](int num) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        int s = sumDigit(x);
        return x % s == 0 ? s : -1;
    }
};