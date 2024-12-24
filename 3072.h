#include <vector>
#include <unordered_map>
#include <algorithm>

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }

private:
    std::vector<int> tree;
    
    int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> arr1;
        std::vector<int> arr2;
        std::vector<int> sortedNums(nums);
        std::unordered_map<int, int> index;

        std::sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < n; i++) {
            index[sortedNums[i]] = i + 1;
        }

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        BinaryIndexedTree tree1(n);
        BinaryIndexedTree tree2(n);
        tree1.update(index[nums[0]], 1);
        tree2.update(index[nums[1]], 1);

        for (int i = 2; i < n; i++) {
            int cnt1 = arr1.size() - tree1.query(index[nums[i]]);
            int cnt2 = arr2.size() - tree2.query(index[nums[i]]);
            if (cnt1 > cnt2 || (cnt1 == cnt2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                tree1.update(index[nums[i]], 1);
            } else {
                arr2.push_back(nums[i]);
                tree2.update(index[nums[i]], 1);
            }
        }

        for (auto num : arr2) {
            arr1.push_back(num);
        }
        
        return arr1;
    }
};