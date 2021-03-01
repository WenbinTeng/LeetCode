#include <string>
#include <algorithm>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1[0] == '0' || num2[0] == '0') return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        std::string res = "0";
        for (int i = n2 - 1; i >= 0; i--)
        {
            int carry = 0;
            int digit = 0;
            std::string buffer = "";

            for (int k = 0; k < n2 - 1 - i; k++) buffer += '0';

            for (int j = n1 - 1; j >= 0; j--)
            {
                digit = ((int)(num2[i] - '0') * (int)(num1[j] - '0') + carry) % 10;
                carry = ((int)(num2[i] - '0') * (int)(num1[j] - '0') + carry) / 10;

                buffer += digit + '0';
            }
            if (carry)
            {
                buffer += carry + '0';
            }

            std::reverse(buffer.begin(), buffer.end());
            
            res = add(res, buffer);
        }

        return res;
    }

private:
    std::string add(std::string num1, std::string num2)
    {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;

        int n1 = num1.size();
        int n2 = num2.size();
        std::string buffer = "";

        int carry = 0;
        int digit = 0;
        for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0; i--, j--)
        {
            if (i >= 0 && j >= 0)
            {
                digit = (num1[i] - '0' + num2[j] - '0' + carry) % 10;
                carry = (num1[i] - '0' + num2[j] - '0' + carry) / 10;
            }
            else if (i < 0)
            {
                digit = (num2[j] - '0' + carry) % 10;
                carry = (num2[j] - '0' + carry) / 10;
            }
            else if (j < 0)
            {
                digit = (num1[i] - '0' + carry) % 10;
                carry = (num1[i] - '0' + carry) / 10;
            }

            buffer += digit + '0';
        }
        if (carry)
        {
            buffer += carry + '0';
        }

        std::reverse(buffer.begin(), buffer.end());

        return buffer;

    }
};