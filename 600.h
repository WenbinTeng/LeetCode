class Solution {
public:
    int findIntegers(int n) {
        res = 1;
        max = n;
        dfs(1);
        return res;
    }

private:
    int res;
    int max;

    void dfs(int num) {
        if (num > max)
            return;
        else
            ++res;

        if (num & 1) {
            dfs(num << 1);
        } else {
            dfs((num << 1) + 0);
            dfs((num << 1) + 1);
        }
    }
};