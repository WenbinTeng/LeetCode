class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0 || x > 0 && x % 10 == 0)
            return false;

        int cmpNum = 0;

        while (x > cmpNum) {
            cmpNum = cmpNum * 10 + x % 10;
            x = x / 10;
        }

        return cmpNum == x || cmpNum / 10 == x;
    }
};