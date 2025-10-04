#include <queue>
#include <vector>

class MedianFinder {
  public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
            if (minHeap.size() + 1 < maxHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }

  private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int> maxHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */