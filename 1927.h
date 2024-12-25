#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int sumDiff = getSumDiff(num);
        int cntDiff = getCntDiff(num);

        if (sumDiff > 0 && cntDiff >= 0)
            return true;
        if (sumDiff < 0 && cntDiff <= 0)
            return true;
        if (sumDiff != 0 && cntDiff == 0)
            return true;

        sumDiff = std::abs(sumDiff);
        cntDiff = std::abs(cntDiff);

        if (cntDiff % 2 == 1)
            return true;
        
        return sumDiff != (cntDiff / 2) * 9;
    }

private:
    int getSumDiff(std::string &num) {
        int n = num.size();
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?')
                sum1 += num[i] - '0';
            if (num[i + n / 2] != '?')
                sum2 += num[i + n / 2] - '0';
        }
        return sum1 - sum2;
    }

    int getCntDiff(std::string &num) {
        int n = num.size();
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                cnt1++;
            if (num[i + n / 2] == '?')
                cnt2++;
        }
        return cnt1 - cnt2;
    }
};  