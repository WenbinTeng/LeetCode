#include <queue>
#include <unordered_map>
#include <vector>

class DualHeap {
  public:
    DualHeap(int k) : k(k), smallSize(0), largeSize(0) {}

    void insert(int data) {
        if (smallHeap.empty() || data <= smallHeap.top()) {
            smallHeap.push(data);
            smallSize++;
        } else {
            largeHeap.push(data);
            largeSize++;
        }

        balance();
    }

    void remove(int data) {
        deleteTable[data]++;

        if (data <= smallHeap.top()) {
            smallSize--;
            if (data == smallHeap.top())
                prune(smallHeap);
        } else {
            largeSize--;
            if (data == largeHeap.top())
                prune(largeHeap);
        }

        balance();
    }

    double getMedium() {
        return k % 2 != 0 ? smallHeap.top()
                          : (double)(smallHeap.top() + largeHeap.top()) / 2;
    }

  private:
    std::unordered_map<int, int> deleteTable;
    std::priority_queue<int, std::vector<int>, std::less<int>> smallHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> largeHeap;
    int smallSize;
    int largeSize;
    int k;

    void balance() {
        if (smallSize >= largeSize + 2) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
            largeSize++;
            smallSize--;
            prune(smallHeap);
        }
        if (smallSize <= largeSize - 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
            smallSize++;
            largeSize--;
            prune(largeHeap);
        }
    }

    template <typename T> void prune(T &heap) {
        while (!heap.empty()) {
            if (deleteTable[heap.top()]) {
                deleteTable[heap.top()]--;
                heap.pop();
            } else
                break;
        }
    }
};

class Solution {
  public:
    std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<double> res;

        DualHeap dh(k);
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }

        res.push_back(dh.getMedium());

        for (int i = k; i < n; i++) {
            dh.insert(nums[i]);
            dh.remove(nums[i - k]);
            res.push_back(dh.getMedium());
        }

        return res;
    }
};