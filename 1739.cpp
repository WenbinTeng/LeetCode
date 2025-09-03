class Solution {
  public:
    int minimumBoxes(int n) {
        int level;
        int boxes;

        for (boxes = 0, level = 1; boxes <= n;
             boxes += (level + 1) * level / 2, level++)
            ;

        level--;
        boxes -= (level + 1) * level / 2;
        level--;
        int s = (level + 1) * level / 2;

        for (int i = 1; boxes < n; boxes += i, i++, s++)
            ;

        return s;
    }
};