#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        std::vector<std::vector<int>> res(m, std::vector<int>(n, -1));
        int i = 0;
        int j = 0;
        enum Direction { LEFT,
                         RIGHT,
                         UP,
                         DOWN } dir;
        dir = RIGHT;

        while (head) {
            switch (dir) {
            case LEFT:
                if (j < 0 || res[i][j] != -1) {
                    i -= 1;
                    j += 1;
                    dir = UP;
                } else {
                    res[i][j] = head->val;
                    head = head->next;
                    j -= 1;
                }
                break;
            case RIGHT:
                if (j >= n || res[i][j] != -1) {
                    i += 1;
                    j -= 1;
                    dir = DOWN;
                } else {
                    res[i][j] = head->val;
                    head = head->next;
                    j += 1;
                }
                break;
            case UP:
                if (i < 0 || res[i][j] != -1) {
                    i += 1;
                    j += 1;
                    dir = RIGHT;
                } else {
                    res[i][j] = head->val;
                    head = head->next;
                    i -= 1;
                }
                break;
            case DOWN:
                if (i >= m || res[i][j] != -1) {
                    i -= 1;
                    j -= 1;
                    dir = LEFT;
                } else {
                    res[i][j] = head->val;
                    head = head->next;
                    i += 1;
                }
                break;

            default:
                break;
            }
        }

        return res;
    }
};