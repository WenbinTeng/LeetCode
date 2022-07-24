class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        
        int acc = 0;

        for (int i = 1; i <= 10; ++i)
        {
            acc += k;
            if (acc <= num && (acc % 10) == (num % 10)) return i;
        }

        return -1;
    }
};