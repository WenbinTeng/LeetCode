class Solution {
public:
    int countEven(int num) {
        int res = 0;

        for (int i = 1; i <= num; ++i)
        {
            int number = i;
            int digits = 0;

            while (number)
            {
                digits += number % 10;
                number /= 10;
            }

            if (digits % 2 == 0 && digits <= num) ++res;
        }

        return res;
    }
};