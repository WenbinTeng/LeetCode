#include <vector>

class NumArray {
  public:
    NumArray(std::vector<int> &nums) {
        n = nums.size();
        tree = std::vector<int>(n * 4);
        init(1, nums, 0, n - 1);
    }

    void update(int index, int val) { myUpdate(1, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return mySumRange(1, 0, n - 1, left, right);
    }

  private:
    int n;
    std::vector<int> tree;

    void init(int node, std::vector<int> &nums, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        int lnode = node * 2;
        int rnode = node * 2 + 1;

        init(lnode, nums, start, mid);
        init(rnode, nums, mid + 1, end);

        tree[node] = tree[lnode] + tree[rnode];
    }

    void myUpdate(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        int lnode = node * 2;
        int rnode = node * 2 + 1;

        if (index <= mid)
            myUpdate(lnode, start, mid, index, val);
        else
            myUpdate(rnode, mid + 1, end, index, val);

        tree[node] = tree[lnode] + tree[rnode];
    }

    int mySumRange(int node, int start, int end, int left, int right) {
        if (start >= left && end <= right)
            return tree[node];
        if (start > right || end < left)
            return 0;

        int mid = (start + end) / 2;
        int lnode = node * 2;
        int rnode = node * 2 + 1;
        int sum = 0;

        sum += mySumRange(lnode, start, mid, left, right);
        sum += mySumRange(rnode, mid + 1, end, left, right);

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */